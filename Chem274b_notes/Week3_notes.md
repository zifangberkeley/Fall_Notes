# linked list
    series linked by pointers to nodes. 
    They are good for dynamic lists and it' useful when you can set.

In stack operations: pop delets the first node.
 The pop function can delete the head node and return the data.

There's also a push function where you can save a link to the list
- creates a new node for the begining and set the instance variavbles in the new node.

Stack: linked list performance:
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

