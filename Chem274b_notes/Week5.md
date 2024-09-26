# Exploration of the Tree concepts
What are some geometric application of trees. Consider intersection between objects. 
- Binary search trees can be used on data bases.

in a 1d range search. seaching and deleting is 1 operation.
when you need to search or count, you have to do two operations: finding all keys between k1 and k2. 
- this allows you to do a database queries. ie. looking at range of solubility and pIs.

We can interpret this geometrically by interpreting keys as points on a line. finding count/points in a given 1d interval basically 

if we have an unordered list, we can have fast insert but slow range search.
In an ordered array, slow insert(finding where to insert the letter) but fast range search. 

A binary search tree implementation will allow us to have fast insert and fast search. 
in the first search, we can eliminate the node that is to the left of it less than. so we can trim down the searches. 

Orthogonal line segment intersection:
there could be quadratic algos like checking all pairs of segments for intersection
we have to assume nondegeneracy assumption, where all x and y coordinates are distinct. there's no over lap to the start of certain lines. 
we can illustrate each line as its BST. 

Sweep-line algorith mtakes time proportional to N log N + R. 
every operation, insertion, deletion and searches are NlogN. 

In a 2-d orthogonal range search. it works similarly as you are just looking for it in 2 dimensions.
keys are points in the plane
to find and count points in a given h-v rectangle: we have to assume rectangle is axis-aligned.
- We can use a grid based implementation
- divide the space into M by M grid of squares
- create list of points contained in each square
- use 2d array to directly index relevant square
- insert: add(x,y) to list for corresponding square 
- Range search: examine only squares that intersect 2d range query and just process the poitns within those squares.
# Space-time tradeoff.
- space: M^2 + N
    - size of grid plus a linked list element for each point.
    - on average the time it's going to take to search each square it's on average the same time. 
    - the trade off is that if M is too big, there will be too much space. if M is too small, it doesn't make sense to build this out. 
Points are not going to be evenly distributed usually. It won;t make sense if the points are clustered.
- how do we adapt to the distribution of the data?
    - we can use space partitioning trees
        - grid: divide space uniformly into squares
        - 2d tree: recursively divide space into two halfplanes
        - quadtree: recursively divide space into four qquardrants
        - bsp tree divide space into two regions.
2d tree implementation
data structure:
- anything to the left of the node is on the left side of the plane. the nodes alternate between x and y coordinates. 
if the intersection is going through a box, you'll have to keep search the left and right hand side of the line going through it.

nearest neightbor search in a 2d tree analysis is logN. the worst case is N. finding the nearest tree allows the pruning of the second part of the tree.

Tries:

stroing characters in nodes,
each node has R children, one for each possible character
it will store values in the nodes corresponding to last charactesr in keys. the values are important because it tells the machine where the tree is associated with what value durign retrival operation.

