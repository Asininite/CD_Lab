# Sample input for e-closure (e_closure)

This program computes the epsilon (e) closure of states in an e-NFA.

Sample stdin (enter interactively or paste all at once):

2
0 e
3
3
1 e 2
2 e 3
2 0 1

Explanation of lines:
- 2 -> number of alphabets
- "0 e" -> the alphabets (e must be last if present)
- 3 -> number of states
- 3 -> number of transitions
- following lines: transitions in the format: <from> <symbol> <to>

Expected output (example):

E-closures of states:
----------------------
e-closure(q1): {q1, q2, q3}
e-closure(q2): {q2, q3}
e-closure(q3): {q3}

To run:

gcc e_closure.c -o e_closure
./e_closure

Then paste the sample stdin above and press Enter (or type interactively when prompted).