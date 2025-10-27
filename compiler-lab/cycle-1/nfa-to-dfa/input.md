# Sample input for nfa-to-dfa (nfa_to_dfa)

This program converts an NFA (with possible epsilon 'e') to an equivalent DFA using subset construction.

Sample stdin (paste when prompted):

3
0
1
e
3
5
0 0 0
0 e 1
1 1 1
1 e 2
2 0 2
0
1
2

Explanation (line by line):
- 3 -> number of alphabets
- next lines: the alphabets (one char per line). Put 'e' last if present.
- 3 -> number of states
- 5 -> number of transitions
- transitions lines: <from> <symbol> <to>
- 0 -> start state
- 1 -> number of final states
- 2 -> final state(s)

Expected output: epsilon closures, constructed DFA transition table and final DFA states (similar to `e-nfa-to-nfa` example).

To run:

gcc nfa_to_dfa.c -o nfa_to_dfa
./nfa_to_dfa

Then paste the sample stdin above when prompted.