#!/bin/sh

test_input_empty() {
  exec 9<&0 <<EOT
#\ ε     0 [ END_OF_INPUT ], 
EOT
  while read input exit_value output
  do
      echo "${input}"
      input=""
      o=$(/bin/echo -n "${input}" | exercise_2_6_1)
      assertEquals ${exit_value} $?
      /bin/echo ${o}
      assertEquals "${output}" "${o}"
  done
  exec 0<&9
}

test_lexer() {
  exec 9<&0 <<EOT
2-1       0 [ NUM, 2 ], [ PUNCT, - ], [ NUM, 1 ], [ END_OF_INPUT ], 
a         1 [ END_OF_INPUT, a ], 
abc       1 [ END_OF_INPUT, a ], 
EOT
  while read input exit_value output
  do
      echo "${input}" | egrep -v '^\s*(#|$)' >/dev/null || continue
      echo "# ${input}"
      o=$(/bin/echo -n "${input}" | exercise_2_6_1)
      assertEquals ${exit_value} $?
      /bin/echo ${o}
      assertEquals "${output}" "${o}"
  done
  exec 0<&9
}

test_lexer_with_newline() {
  exec 9<&0 <<EOT
22-11       1 [ NUM, 22 ], [ PUNCT, - ], [ NUM, 11 ], [ END_OF_INPUT, \\\\n ], 
EOT
  while read input exit_value output
  do
      echo "${input}" | egrep -v '^\s*(#|$)' >/dev/null || continue
      echo "# ${input}"
      o=$(echo "${input}" | exercise_2_6_1)
      assertEquals ${exit_value} $?
      /bin/echo "${o}"
      assertEquals "${output}" "${o}"
  done
  exec 0<&9
}

. shunit2
