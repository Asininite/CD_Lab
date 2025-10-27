# Sample input for `bnf` (bnf)

This folder contains a parser/lexer for BNF-style grammar input or sample language constructs.

Sample input (a small grammar snippet or expression depending on program behavior):

<expr> ::= <term> "+" <expr> | <term>
<term> ::= <factor> "*" <term> | <factor>
<factor> ::= "(" <expr> ")" | id

If the program accepts language sentences, try a small test (if it expects tokens):

id + id * id

To run: compile the provided files as the project README/TO RUN suggests, then paste the grammar or a sentence above as the stdin input.
