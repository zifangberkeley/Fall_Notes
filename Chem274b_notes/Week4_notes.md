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
While constant b is determined by `system independent` effects such as the algo and codes themselves.
## 2.4 Memory, Arrays, Lists

### Memory and space trade-offs. 
    - on many occasions, we may sacrifice space to gain time and vice versa.
    - solutions can run in linear time but using additional storage for two lists of atom counts
        - this amount of extra space is not significant 
        - if there are millions of characters, solution will be a concern.
    - memory usuage is a function of the following:
        - primitive types: TK bytes for int or float
        - object reference: pointers and object takes up memory
        - Array: bytes + memory for each array entry. (for a list, each object in list has its own memory)
            - shallow or deep memory, establishing pointer or copying everything.
    Your computer is like a giant set of drawers.
        - address associated with some slot inside the memory. you tell the computer you want to store something, it will check and give you an address. to reference back to the storage, you point to the address.
        - using an array, it means all our tasks are stored contiguously (right next to eachother)
        - When you add a fourth task it could be a big pain as you have to basically hold seats for arrays.
            - it could waste memory, you could need more later on.
    An alternative way is a linked list. they can stored anywhere, each address stores information for the next item. 
In the worst case, linked lists are o(N) for read operations.
    - for a linked list, if we want to get to the last item, we can't just read it. we have to go through all the other items to get the pointer for the last item. terrible if you have to jump around randomly.

#### Trade-offs
    Arrays: we know the address for every item in our array

    Reading run time:
        - array: O(1)
        - linked-list: O(N)
    insertion run time:
        - arrays: O(N)
        - linked list: O(1)
    Deletion:
        - arrays: O(N), everything will need to be moved up say if we want to remove the first element.
        - linked list: O(1), its nuainces.
#### When to use what
    Arrays:
        allows for random access and jump directly to element of interest.
    Linked-list: 
        Sequential access: Linked lists can only do sequential access. reading elements one by one.

Doubly linked elist.
    - relatively complex to implement.
        - we are not just changing the next pointer, we are also changing the previous pointers.
        - larger memory footprint and it will have double the pointers.
    - allows us to iterate reverse, start going from the end as we have access to both ends. it make sures we retain constant operation time.

#### Why do we care:
    - It impacts how we implement a solution in code.
        - the python's list implementations is very fast.
        indexing and assigning to an index position 
        - using the append method is O(1)
        - using concat is O(k) where k is the size of the object.
    - using pop, when pop removes an item in the beginning, it will have to move the whole list forward.
    if we are doing more insertions, linked list is better. if we are doing more reads, array is better.  

## 2.5 Search Algorithms and Selection Sort
    Search algorithms and sorting algorithms
    - Searching: pretty easy to ask in python.
        ex: 15 in [1,2,3] = False
    the common 3-Sum problem. what three numbers in N disctinc integers sum exactly zero.
        - the indicies have to be unique indexes.
        - given a collection of molecular fragments and a target molecular weights. How many combinations sum up to the molecular weights.
    or we can do something like a combination that will equal to x binding affinity.
    The bruteforce solution is to check all combinations with constant space complexity. which we ccan use itertools to compute, the end combo is added to the results.

    A more intelligent solution is go through binary search.
        - sort freatgments by weight(once at the beginning) -> O(NlogN)
        - for each pair of fragments(i,j), calculate their combined weight -> O(N^2)
        Then use binary search to find the third fragment that when added to the pair is close to the target eight -> O(logN)

        Bisect conducts binary search operations.
        - given a sorted array and a key, find the index of the key inside the array.
        The first iteration has two definitions, low = lowest index. high = highest index and compute the mid. Then compare, how does the middle index look compared to our search index. (33 must be on the left half of the list).
        high is then moved to mid - 1.
        we compare, then we see that 33 is larger then 25. the remaining part of where we need to search for is between mid and hi.
        we do lo + 1 . in the last iteration, lo, mid and hi will be equal to the target. 
        It took 4 iterations. This is a logN search. 
    Sorting is a fundamental operation that we will continue studying. How do we know that the algos are at their run times. 

### Selection sort
- the idea is : in interation i, find the index min of smallest remaining entry within list a, swap [i] and [min]


drug modeling. maintaining drug efficiency while maintaining low toxicity. 
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