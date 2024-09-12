# Quicksort
divide and conqueror algo that will shuffle the array and partition  the array so that we will have a pivot where everything to the left is lesser than the pivot and the right is larger. then it sorts and repeats.

scan i from left to right as long as a[i] < a[pivot]
scan j from left to right as long as a[j] > a[pivot]

exchange a[i] with a[j] if the both cases fails.

it's typical for the pivot to be the first element. 

when j and i cross, we are going to exhange the pivot with where j is. 
each subarray is sortted again and then finally merged to come up with a a sorted list. This algo does partitioning in place. but its not worth the cost.

quick sort is a good algo that could be very benefitical. 
- randomized algo that guaranteed to be correct.
- often, purpose of sort is to being values together.
when all the values have the same keys, the algorithm will go quadratic unless partitioning stops on equal keys. 

3 way partitioning.
- this will group the similar keys together. left elements are less, middle is equal and right is greater than. This is called the Dijkstra 3-way partitioning demo.
algo will stop when indecies have stablized. now we have a sorted array. 
- stability is: sorting it multiple time will always be the same order. 

# priority queue.
it's a collection of a data type tht stores a group of items
- stacks
    - core operations: push and pop
    - remove most recently added item
- queue
    - remove lease recently added item
random queue
    - remove a random item
priotity queue
    - remove largest or smallest item

applications:
lots! 

prlbem: find the largest M items in a stream of N items(N huge, M large)
you won't have memory to store M items because N is huge. 

# binary tree
node with links to left and right binary trees .
a complete tree is perfectly balanced except for bottom level and has a property of NlogN
Binary heap is an array reresentation of a heap ordered complete binary tree.
- heap ordered binary tree has keys in nodes and parent keys are no smaller than children's keys.

Array representation:
 indicies start at 1
 it can be stored as an array due to its binary heap properties. parent of node at k is at k/2. children of node at k are at 2k and 2k+1. 

 what happens when the child's key is bigger than the parent's key.
 - need to avoid at all cost where children are less than parents,
 - we have to exchange key in child with key in parent and repeat until heap order is restored.
 swim = swims up the heap.
 sink = key moves down.
 delete max exhanges root with node at the end, then sink it down. 

 Heap sort.
 heap construct and then sortdown to repeatly remove the largest key. this is called the bottom up method.

 Introsort:
 first runs a quicksort,
 then cutoff to heapsort if stack depth exceeds 2log N
 CUTOFF TO INSERTION sort for N=16. 

 Even driven simulation codes are provided.

 Just know how different they are in terms of use case and in terms of time.