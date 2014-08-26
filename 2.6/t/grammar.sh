#!/bin/sh

test_grammar_empty() {
    echo '# ε'
    assertFalse "echo '' | exercise_2_6_1"
}

test_grammar() {
  exec 9<&0 <<EOT
2-1     0 21-
3+5-2   1 35+
1       1 1
1-      1 1
a       1
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
