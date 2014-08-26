#!/bin/sh

test_grammar_a_empty() {
    echo '# ε'
    assertFalse "echo '' | exercise_2_4_1 a"
}

test_grammar_a() {
  exec 9<&0 <<EOT
abc        1
a          0
-aa        0
-a+aa      0
-+aaa      0
+a-a+aa    0
-a         1
+a         1
-aaa       1
+aaaa      1
EOT
  while read input exit_value
  do
      echo "${input}" | egrep -v '^\s*(#|$)' >/dev/null || continue
      echo "# ${input}"
      echo "${input}" | exercise_2_4_1 a
      assertEquals ${exit_value} $?
  done
  exec 0<&9
}

. shunit2
