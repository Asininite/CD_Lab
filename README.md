
# CD_Lab

This repository contains the lab assignments and example code for the Compiler Design course (compiler-lab). It collects lexical analyzers, parsers, finite automata code, intermediate code generation and related exercises organized by lab cycle.

## Repository layout

- `compiler-lab/` — main folder containing lab cycles and exercises.
	- `cycle-1/` — basic automata and lexical-analysis exercises (e-closure, NFA/DFA conversion, lexical analyzer, DFA minimization).
	- `cycle-2/` — lex/yacc exercises and example scanners/parsers (many subfolders with `.l` and `.y` files and generated artifacts).
	- `cycle-3/` — parsing algorithms: FIRST/FOLLOW, recursive-descent, operator-precedence, shift-reduce, etc.
	- `cycle-4/` — intermediate code generation exercises.

Many subfolders contain an `output.md` or `TO RUN` file describing sample runs and expected output.

## Prerequisites

- A Unix-like shell (Linux, WSL, macOS).
- GCC (for compiling C programs).
- flex (Fast lexical analyzer generator) and bison (or yacc) for lex/yacc examples.

Install on Debian/Ubuntu-ish systems:

```bash
sudo apt update
sudo apt install build-essential flex bison
```

## How to run examples

General patterns you can use for examples in the repo:

- Compile and run a plain C program:

```bash
gcc path/to/file.c -o program
./program
```

- Build a pure `flex` lexer (no yacc):

```bash
flex lexer.l        # generates lex.yy.c
gcc lex.yy.c -lfl -o lexer
./lexer < input.txt
```

- Build a `bison` (yacc) parser + `flex` lexer:

```bash
bison -d parser.y   # generates parser.tab.c and parser.tab.h (or y.tab.c/y.tab.h)
flex lexer.l         # generates lex.yy.c
gcc lex.yy.c parser.tab.c -lfl -o parser
./parser < input.txt
```

Notes:
- Some folders already include generated C files (`lex.yy.c`, `y.tab.c`, `*.tab.c`) and ready-to-run binaries. Check the folder's `TO RUN` or `output.md` for specific commands.
- When filenames differ (for example `y.tab.c` vs `parser.tab.c`), adapt the gcc command accordingly.

## Helpful tips

- Look for `input.txt` and `output.md` files inside exercise directories for sample inputs and expected outputs.
- If you see `Makefile` in a folder, prefer `make` to build the exercise.

## Contributing

If you want to add improvements (README clarifications, extra examples, or fixes), open a branch and submit a pull request. Keep changes small and include a short description of how to run any new code.

## License

This repository does not include an explicit license file. Add a `LICENSE` if you want to publish under an OSI-approved license (e.g., MIT) and mention it here.

## Contact

If you need help understanding a lab or want me to add run scripts / Makefiles for specific folders, tell me which folder and I can add them.
