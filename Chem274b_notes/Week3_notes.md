# linked list
    series linked by pointers to nodes. 
    They are good for dynamic lists and it' useful when you can set.
# what are linear data structures:
    they are how data gets incorporated to be organized.

In stack operations: pop deletes the most recently item
 The pop function can delete the head node and return the data.
 base operations: insert, remove, iterate and test if empty.
 last in first out data structure.

In a queue operation: we are removing things that are least recently added
- first in, first out.

## Client, implementation and interface
    - interface - description of data type and abstract operations which it supports
    - implementation - the implementation of these operations
    - client - program using operations defined in interface. whatever stack it's importing, it's supports the bare minimal operations since it's a stack. client doens't need to know how it's implemented. but behaviour needs to be consisten
Abstract data types(ADTS)
- allows modular, reusable libraries to build our algo from
    - changing the adt doesn not affect program correctness but there's different performance trade-offs
    - use optimized implementation where it matters for performance. 
Benefits:
- client doesn't know details, but they have a choice
- implementation shouldn't be designed for a single client. this allows many client to reuse the same implementation. 

There's also a push function where you can save a link to the list
- creates a new node for the begining and set the instance variavbles in the new node.

## Stack: linked list performance:
- maintain pointer to the first node in a link list. whenever we insert or remove it'll be at the first.
    - when we add something to the front, we will have to have a pointer to the next node. 
    - we first create a class node and create a link list adn pointers. 
    - pop, pops off first item
    - push: what it's doing is it will save a link to the list and it will automatically link the new first item to the old list.
## Stacks: array representation:
    - stacks are easily represented as an array, with push/pop incrementing/decrementing a counter
    - push: add new item at s[N]
    - pop: remove item from s[N-1]
   we need to account for underflow, guard rail on pop when our stack is empty.
   overflow protection amount of item is equal to capacity. when we push and there's no space, we will have to resize the array. 
   - should the client need to know the capacity in the first place?
If we are implementing this, how do we grow and shrink the array.
    - we can double the array size, everytime we run out of space, appending is still going to be constant time. However, some cases it will be linear time.
- Time costs. every operation takes constant time in the worst case
- Memory costs, a stack with N items uses ~40 * N bytes
    - This only accounts for the memory of the stack and not the memory for the strings themselves.
    - Stacks are more easily represented as an array. Push and pop incrementing/decrementing a counter
        - we can push to a certain index by s[N]
        - pop to remove certain index s[n-1]
Stack underflow: pop from an empty stack
overflow: N index exceeds capacity of the array.
Loitering, holding a reference to an object when it is no longer needed. There are garbage collectors that automates the collection of memory.

Dynamic array: automatically grows when making an insertion with no space left for new item. usually by doubling the array in size.
what is the cost of m appends
- it's the cost of any doubling, it converges to 2m and on average each individual append is in the order1. The worst case cost is still 0(N).

resizing array vs linked list
- linked list
    - every operation takes constant time
    - uses extra time and space to deal with the links
- resizing-array
    - operation takes constant amortized time
    - less wasted space. 

queue: maintain pointer to the first and last nodes in a linked list.
    - dequeue(q). return and remove the front item from the queue q
        - delets the first node
        - identical to list pop
    - enqueue(x,q) insert item x at the back of the queue.
        - first it saves link to the last node, then creates a new node for the end and then it links the new node to the end of the list.
Implementation with circular buffer
- uses array q[] to store items in queue.
    - enqueue to add item at tail
    - dequeue to remove item at the head.

deque return a new deque object initilaized left to right using append() with data from iterable , if iterable is not specific, deque is empty.
- deques are generalization of stacks and queues that supprots thread-safe and memory efficient appends and pops with ~O(1) performance in either direction.
- they support similar operations and are optmized for fast fixed-length operations and incur O(n) memory movement costs for pop(0) and insert (0,v)

recursion is a technique where the function calls itself repeatly.
Every recursion function case has two parts. a recursive case and a base case.
a recursive case is the condition under which the function calls itself
a base case is the condition under which the function doesn't call itself again.
### Three laws:
1. a recursive algo must have a base
2. a recursive algo changes its state and move toward base case
3. a recursive algo must call itself recursively.
We can prove recursive programs via induction
- to prove a statement involving N, assuming that the statement is true for all positive integers less than N, use that fact to prove it for N.
Or we can prove it through GCD. where we find the most common denominator.
there's no convergence guaranteed. it might never stop.

it could be ineffient and have overlapping subproblems that are solved repeatedly.
recursion tree: one node for each recursive call. label node with return value after children are labelled. 
Exponentail waste
- number of recursive calls grows exponentially
- overlapping subproblems are repeatidly calculated wasting memory. 
    - exess time to program completion and could result in memory overflow.
Memoization: keep a record of the results for the given inputs
- before computing the result for a given input, check if we already have it
- ensures that a function doesn't run for the same input more than once.
instead of recursive solutions we can use iterative solutions. 

# sorting problem
Sorting: placing elements from a collection in some kind of order.
    - for example, sort words alphabetically by length or other properties.
importance: how sorting a collection of objects can improve downstream efficiency for downstream purposes.

Selection sort
- for iteration i, find index min of smallest remaining entry. swap a[i] and a[min].
Insertion sort
in iteration i, swap a[i] with each larger entry to its left.
worst case is 1/2(N^2). how does it operate paartially sorted arrays.
- for partially sorted arrays, insertion sort runs in linear time. for example, merging the list. 