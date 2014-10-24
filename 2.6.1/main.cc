#include <ostream>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <boost/regex.hpp>

#include "Tag.h"
#include "Token.h"
#include "Lexeme.h"
#include "Lookahead.h"

std::vector<Lexeme<char>> const static lexemes({
    Lexeme<char>(
        "[\\d]+",
        Tag::NUM
    ),
    Lexeme<char>(
        "[\\-+]",
        Tag::PUNCT
    ),
});

template<typename T> struct Tokenizer {
    typedef std::unordered_map<const Lexeme<T>, std::basic_string<T>> mlex_match;
    typedef std::pair<const Lexeme<T>, std::basic_string<T>> pair_lex_match;

    Lookahead<T> p;
    std::vector<Lexeme<T>> const lexemes;
    std::basic_stringstream<T> buf;
    mlex_match best_matches;

    Tokenizer() : p(), lexemes(), buf(), best_matches() {};
    Tokenizer(Lookahead<T> &_p, std::vector<Lexeme<T>> const &_lexemes): p(_p), lexemes(_lexemes), buf(), best_matches() {};

    bool operator==(Tokenizer<T> const  &t) const {
        return p.no_more_input() == t.p.no_more_input() && buf.str() == t.buf.str();
    }

    bool operator!=(Tokenizer<T> const &t) const {
        return !(this->operator==(t));
    }

    bool add_one_char() {
        if(!p.no_more_input()) {
            buf << *p;
            p++;
            return true;
        }
        return false;
    };

    void cleanup_match(const std::basic_string<T> &matching_text) {
        best_matches = mlex_match();
        buf.str(buf.str().erase(0, matching_text.length()));
        buf.seekp(0, std::ios_base::end);
    };

    bool all_partial_match(mlex_match const &ml, std::string::size_type const &l) {
        return !ml.empty() && std::all_of(ml.begin(), ml.end(), [&l](pair_lex_match const &plm) { return plm.second.length() != l; });
    }

    bool try_matching() {
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

    Token<T> next() {
        if(p.no_more_input()){
            if(buf.str().empty()) {
                return Token<T>(Tag::END_OF_INPUT);
            }
        }
        while(!all_partial_match(best_matches, buf.str().length()) && add_one_char()) {
            if(!try_matching()) {
                auto t = Token<T>(Tag::END_OF_INPUT, buf.str());
                cleanup_match(buf.str());
                return t;
                // throw NoToken(buf.str());
            }
        }

        if(best_matches.empty()) {
            // no match?
            auto t = Token<T>(Tag::END_OF_INPUT, buf.str());
            cleanup_match(buf.str());
            return t;
            // throw NoToken(buf.str());
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
};


int main(int argc, char* *argv) {
    auto p = Lookahead<char>(std::cin);
    Tokenizer<char> t(p, lexemes);
    Tokenizer<char> tend;

    while(t != tend) {
        std::cout << t.next() << ", ";

    }
    std::cout << std::endl;

    return 0;
}
