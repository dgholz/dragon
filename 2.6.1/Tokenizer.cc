#include <sstream>

#include <boost/regex.hpp>

#include "Tokenizer.h"
#include "Tag.h"

template<typename T>
bool Tokenizer<T>::add_one_char() {
    if(!p.no_more_input()) {
        buf << *p;
        p++;
        return true;
    }
    return false;
}

template<typename T>
void Tokenizer<T>::cleanup_match(const std::basic_string<T> &matching_text) {
    best_matches = mlex_match();
    buf.str(buf.str().erase(0, matching_text.length()));
    buf.seekp(0, std::ios_base::end);
}

template<typename T>
bool Tokenizer<T>::all_partial_match(mlex_match const &ml, std::string::size_type const &l) {
    return !ml.empty() && std::all_of(ml.begin(), ml.end(), [&l](pair_lex_match const &plm) { return plm.second.length() != l; });
}

template<typename T>
bool Tokenizer<T>::try_matching() {
    bool new_matches = false;
    boost::match_flag_type flags = boost::match_continuous | boost::match_partial;
    boost::match_results<const T*> match;
    for(auto lex : lexemes) {
        if(boost::regex_search(buf.str().c_str(), match, lex.pattern, flags)) {
            best_matches[lex] = std::basic_string<T>(match[0]);
            new_matches = true;
        }
    }
    return new_matches;
}

template<typename T>
Token<T> Tokenizer<T>::next() {
    if(buf.str().empty()) {
        if(p.no_more_input()){
            return Token<T>(Tag::END_OF_INPUT);
        }
    }
    while(!all_partial_match(best_matches, buf.str().length()) && add_one_char()) {
        if(!try_matching()) {
            auto t = Token<T>(Tag::END_OF_INPUT, buf.str());
            cleanup_match(buf.str());
            p = Lookahead<T>();
            return t;
        }
    }

    if(best_matches.empty()) {
        // no match?
        auto t = Token<T>(Tag::END_OF_INPUT, buf.str());
        cleanup_match(buf.str());
        p = Lookahead<T>();
        return t;
    }

    // find longest lexeme which matches some of buf

    auto lm_cmp = [](const pair_lex_match &a, const pair_lex_match &b) {
        return a.second.length() > b.second.length();
    };
    auto longest = std::max_element(best_matches.begin(), best_matches.end(), lm_cmp)->second.length();

    for(auto lex: lexemes) {
        auto lm_itr = best_matches.find(lex);
        if(lm_itr != best_matches.end()) {
            if(lm_itr->second.length() == longest) {
                auto token = lm_itr->first( lm_itr->second );
                cleanup_match(lm_itr->second);
                return token;
            }
        }
    }
    return Token<T>(Tag::END_OF_INPUT);
}

template class Tokenizer<char>;
template class Tokenizer<wchar_t>;
