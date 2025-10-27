# Sample input for `yacc-valid-var`

This folder contains a yacc example to validate variable names.

Sample stdin:

validVar
_invalid
2bad

Expected behavior: `validVar` accepted, `_invalid` accepted (if underscores allowed), `2bad` rejected.

To run: compile the yacc/lex files in this folder and run the resulting program, then type/paste sample tokens.
