#!/bin/sh

test_grammar_b_empty() {
    echo '# ε'
    assertTrue "echo '' | exercise_2_4_1 b"
}

test_grammar_b() {
  exec 9<&0 <<EOT
()         0
()()       0
(          1
)          1
(())       0
())()(     1
(()())     0
()()()()() 0
)(         1
EOT
  while read input exit_value
  do
      echo "${input}" | egrep -v '^\s*(#|$)' >/dev/null || continue
      echo "# ${input}"
      echo "${input}" | exercise_2_4_1 b
      assertEquals ${exit_value} $?
  done
  exec 0<&9
}

. shunit2
