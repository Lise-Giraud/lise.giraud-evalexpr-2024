#!/bin/sh

REF_OUT="fesse"
TEST_OUT="evalexpr.out"

echo "1 + 1" | ./evalexpr > "$REF_OUT"
echo "1 1 + p" | dc > "$TEST_OUT"

diff "$REF_OUT" "$TEST_OUT"

echo "1 1 +" | ./evalexpr -rpn > "$REF_OUT"
echo "1 1 + p" | dc > "$TEST_OUT"

diff "$REF_OUT" "$TEST_OUT"

echo "5 2 2 ^ 3 + *" | ./evalexpr -rpn > "$REF_OUT"
echo "5 2 2 ^ 3 + * p" | dc > "$TEST_OUT"

diff "$REF_OUT" "$TEST_OUT"

echo "5 * (2^2 + 3)" | ./evalexpr > "$REF_OUT"
echo "5 2 2 ^ 3 + * p" | dc > "$TEST_OUT"

diff "$REF_OUT" "$TEST_OUT"

rm -rf $REF_OUT
rm -rf $TEST_OUT

exit 0
