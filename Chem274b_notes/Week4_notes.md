## switch sections

# Week2

## algorithmic success

We are trying to predict any algo we arrived and guarantees the performance characteristics.
- avoid memory overflows and to understand the theortical basis of algorithms.
some examples:
    - discrete frourie transform. breaking down waveform of samples into periodic environments.
    brute force solution is N^2 steps
    the FFT algo is a linear rhymic solution. NlogN.
    This allowed N body simulations.
        enabling new advances

Scientific method:
    observe, hypothesize, predict, verify and validate.
Principles:
    experiments are reproducible and the hypotheses themselves are non-falsifible.
Through empirical analysis we can predict the time it might take for future system to run
    - oncce we have the empirical data, we can plot the running time on the Y axis against the input size on the x axis, plotting it through a log log graph,
    we can get a running time in an order of growth. 
we need to have enough datapoints before we can run it.
exponent b is determined by `system independent` effects such as algorithm and input data.
we will rely on approximations. for a given number of N we are going to have an order of N^3. for quadratic, we can find a clever way to turn it into a linear.
The following describes the order of each algo.
- l: statement (add two numbers) = statment
- logN: divide in half is a logarithemic operation thas'S for algo like binary search
- N: linear. for things like loop that are good for finding propertise of a system.
- N log N: for a divide and conquer mergesort
- N^3 cubic: for multiple nested loops. things like checking all triples
- 2^N expeonential: exhaustive search for checking all subsets.

Best case: lower bound on cost
    - easiest input and provides a goal for all inputs
worst case: upper bound on cost
    - most difficult input but guarantee for all inputs
average case: expected cost for random input
    - model for random input and provides a way to predict performance. 

Big O notation is the notation to tell how fast an algo is. this is the worst case run time.
When there are multiple operations, we look for the slowest step as the big0 notation.


Tilde Notation is the estimation of running time as a function of input size.
when N is large, we can ignore the lower term.

from a log/constant to a linear there will be a huge jump in time.

constant a in powerlaw is determined by `system dependent` effects such as hardware, software and the system itself.        
drug modeling. maintaining drug efficiency while maintaining low tixucuty. 
Hybrid models combining attention-based and state pace based.

Due dates will be moved back.

Week4 - discussion 
- introduction
    we have directed graph structures. why do we need it and the difference between undirected and directed.
- digraph interface
    the edges have directionality to them. they point in one direction.
    you can use a digraph to represent road ways. 
Implication graph and combinatiorial circuits can be modeled through digraphs.
Word net graphs.
digraph is good for maybe finding out the shortest path. 
or maybe a topologcial sort where we draw a digraph 
there will be a node text file that will point to other nodes. 
Digraph interface:
how to initialize the digraph. 
- digraph search
    we must consider reachability of our nodes.
    every undirected graphs are just digraphs. 
depth first search marks vertexs as visted and then recursivelty vist all unmarked vertices pointing from v
every program is based on reachability, this allows for dead code elimnination and infinite loop detection. Every program actually is a digraphs.   

- topological sort

- strong components
- molecules as graphs.