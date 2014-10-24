#!/bin/sh

test_input_empty() {
    echo '# ε'
    assertTrue "echo '' | exercise_2_6_1"
}

test_lexer() {
  exec 9<&0 <<EOT
2-1       0 [ NUM, 2 ], [ PUNCT, - ], [ NUM, 1 ], [ END_OF_INPUT ], 
22-11\\\\n  0 [ NUM, 22 ], [ PUNCT, - ], [ NUM, 11 ], [ END_OF_INPUT, \\n ], 
a         1 [ END_OF_INPUT, a ], 
abc       1 [ END_OF_INPUT, a ], 
EOT
  while read input exit_value output
  do
      echo "${input}" | egrep -v '^\s*(#|$)' >/dev/null || continue
      echo "# ${input}"
      o=$(/bin/echo -e -n "${input}" | exercise_2_6_1)
      assertEquals ${exit_value} $?
      echo ${o}
      assertEquals "${output}" "${o}"
  done
  exec 0<&9
}

. shunit2
