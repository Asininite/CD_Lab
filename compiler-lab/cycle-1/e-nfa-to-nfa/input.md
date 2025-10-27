# Sample input for e-nfa-to-nfa (e_nfa_to_nfa)

This program computes epsilon-closures and produces an equivalent NFA without epsilon transitions.

Sample stdin (paste these lines when prompted):

3
0
1
2
0
3
0 0 0
0 e 1
1 1 1
1 e 2
2 0 2

Explanation:
- 3 -> number of alphabets (e.g., 0,1,e)
- next lines: alphabets (one per line)
- number of states (3)
- start state (0)
- number of final states (1)
- final state(s) (2)
- number of transitions (5)
- transitions in the form: <from> <symbol> <to>

Expected brief output: epsilon closures and the equivalent NFA transitions (see `output.md`).

To run:

gcc e_nfa_to_nfa.c -o e_nfa_to_nfa
./e_nfa_to_nfa

Then paste the sample stdin above when the program asks for inputs.