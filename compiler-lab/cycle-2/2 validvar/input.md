# Sample input for `varcheck` (validvar)

This program checks if a token is a valid identifier/variable name.

Sample stdin (each line is a separate token to check):

myVar
_var
1var
var$

Expected behavior:
- `myVar` -> accepted
- `_var`  -> accepted (if underscore allowed at start)
- `1var`  -> rejected (starts with digit)
- `var$`  -> rejected (invalid char)

To run (from this folder):

bison -d var.y
flex var.l
gcc var.tab.c lex.yy.c -o varcheck -lfl
./varcheck

Then type or paste a token and press Enter.
