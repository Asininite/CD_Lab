# Sample input for `bnf-to-yacc` examples

This folder contains lex/yacc conversion examples. Use a small token stream or grammar fragment.

Sample stdin (tokens or grammar sentences):

id = id + id

Or a small grammar fragment if the tool expects grammar input:

E -> E + T | T
T -> T * F | F
F -> ( E ) | id

To run: follow compilation steps in this folder (if any), then provide one of the sample lines as stdin.
