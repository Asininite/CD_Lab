# Sample input for `calc` (calculator)

This is a simple arithmetic expression parser. Provide expressions on separate lines.

Sample stdin:

3+4
12*(3+2)
(10 - 2) / 4

Expected behavior:
- `3+4` -> evaluates/recognizes as an expression
- `12*(3+2)` -> evaluates/recognizes parentheses and multiplication
- `(10 - 2) / 4` -> recognizes parentheses and division

To run (from this folder):

bison -d calc.y
flex calc.l
gcc calc.tab.c lex.yy.c -o calc -lfl
./calc

Then enter any of the sample expressions and press Enter.
