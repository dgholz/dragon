#!/bin/sh

test_input_empty() {
    echo '# ε'
    assertTrue "echo '' | exercise_2_6_1"
}

test_lexer() {
  exec 9<&0 <<EOT
2-1     0 [ NUM, 2 ], [ PUNCT, - ], [ NUM, 1 ], [ ENDOFINPUT ], 
EOT
  while read input exit_value output
  do
      echo "${input}" | egrep -v '^\s*(#|$)' >/dev/null || continue
      echo "# ${input}"
      o=$(echo "${input}" | exercise_2_6_1)
      assertEquals ${exit_value} $?
      echo ${o}
      assertEquals "${output}" "${o}"
  done
  exec 0<&9
}

. shunit2
