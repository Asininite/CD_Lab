# Sample input for `name` (name_4_letters)

This program checks 4-letter names.

Sample stdin (each line is a separate test run):

ashwin
ashw
assh

Expected behavior:
- `ashwin` -> rejected (not 4 letters)
- `ashw`  -> rejected (only 4 letters but not matching rule in example)
- `assh`  -> accepted (4 letters and passes lexer rules)

To run (from this folder):

1. flex name.l
2. gcc lex.yy.c -o name -lfl
3. ./name

Then enter one of the sample lines above and press Enter.
