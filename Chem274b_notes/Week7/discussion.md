We can consider our DNA search algo by representing it as a tree.
how do we go from the pattern and build the graph. then how to use it.
- find is using substring search. This is also how search works for word documnets etc.
substring search. walking fine line because it only looks for certain text. 

brute force is note good enough. We need to avoid backup streams when we are running algo.
worst case theres repeats of patterns. best case there's no repeat and it just matches.

Knuth Morris Pratt algo: no back up needed. if the mismatch is somewhere with in the next, why not just start the search at the next step?
how to construct the DFA for KMP substring
