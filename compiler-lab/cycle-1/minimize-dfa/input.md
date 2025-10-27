# Sample input for minimize-dfa (minimize_dfa)

This program constructs the Myhill-Nerode table and prints the minimized DFA grouping.

Sample stdin (paste when prompted):

3
ABC
2
ab
1
C
6
A a B
A b C
B a A
B b C
C a C
C b C

Explanation of lines in order:
- 3 -> number of states
- ABC -> state names (characters for each state, e.g., A B C)
- 2 -> size of alphabet
- ab -> alphabet characters (no spaces)
- 1 -> number of final states
- C -> final state name(s) (single char each)
- 6 -> number of transitions
- transitions (format: <FromStateChar> <SymbolChar> <ToStateChar>)

Expected behavior: program prints the initial distinguishable pairs table and the minimized DFA transitions.

To run:

gcc minimize_dfa.c -o minimize_dfa
./minimize_dfa

Then paste the sample stdin above.