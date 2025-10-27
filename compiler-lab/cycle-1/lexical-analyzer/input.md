# Sample input for lexical-analyzer (lexical_analyzer)

This program performs lexical analysis on a source file. A sample file `input.txt` is already present in this folder.

To run:

gcc lexical_analyzer.c -o lexical_analyzer
# either run and type the filename when prompted:
./lexical_analyzer
# then enter: input.txt

Or run directly by piping the filename:
# start program and then type/paste the filename when it prompts

Sample file content (`input.txt` in this folder):

int main() {
    int x = 10;
    float y = x + 20;
    return 0;
}

Expected output (tokenized):

Keyword: int
Identifier: main
Symbol: (
Symbol: )
Symbol: {
Keyword: int
Identifier: x
Operator: =
Number: 10
... and so on (see `output.md`).