#!/bin/sh

test_grammar_c_empty() {
    echo '# ε'
    assertFalse "echo '' | exercise_2_4_1 c"
}

test_grammar_c() {
  exec 9<&0 <<EOT
01        0
1         1
0         1
10        1
0011      0
001       1
00110     1
00        1
11        1
000111    0
EOT
  while read input exit_value
  do
      echo "${input}" | egrep -v '^\s*(#|$)' >/dev/null || continue
      echo "# ${input}"
      echo "${input}" | exercise_2_4_1 c
      assertEquals ${exit_value} $?
  done
  exec 0<&9
}

. shunit2
