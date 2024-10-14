# fundatmental graph algorithms.
Having an arbitrage allows us to maybe have arbitrage opportunities. 
Leet code: number of islands problem
    - you need to find the number of islands in the grid. 1 is marked land, 0 is water. you need to find a collection of 1s. we will need to use  algos to solve this. depth first search is great. flip islands to 0 if we visited it. 

shortest path python
(map/ directions)
operate on edge weighted diagraphs. shotrest path is the sum. 
starting from a single source, we find the shorted path between between all pairs of vertices.

Restrictions on edge weights
- nonnegative weighs
- no direct nor negative cycles.

we have to assume that there is always a shortest path that exists.
- we are just trying to find the shortest paths from s to every vertex.
Goal: find shortest path from s to every other vertex
observation 1. the shortest path is from s to v is simple,
observation 2. shortest path tree solution exists.
consequence: we can represent SPT with two vertex indexed arrays:
-   separate them into edgeto array and disto array.

most algos work on the concept of edge relaxation
if there is some edge that can give a shorter path through another node, we have 
to account both distto and edgeto. 

framework for shortest paths algorith.
-   for each vertex v: distTo[v] = infiite
for each vertext v: edgeTo[v] = null
disTo[s] = 0.
repeat until disto[v] values converge.
    - relax any edge
go through the whole algo and keep doing it until no more edges relaxes
edge can only decrease.

Dijkstra's algo
- we are going to consider vertices in increasing order of distance from s. Then we add vertex to tree and relax all edges point from that vertex.
- first vertices are the one step away vertices. by setting the other vertices as greater, there's no other way to point.

total performance cost is E log V for dijkstra algo using binary heap. 

what is there are no directed cycles with my digraph?
- its easier to find vertices in topological order and relax all edges point from that vertex.
- it could be a e+v run time. If the edge weights are negative, it won't be possible to run the algo. 
if we can find the shorted path, we can also find the longest path. 
The application is parallel job scheduling. we can create graphs that contains constraints.
the longest path will be jobs that has dependencies. 

Bellman-Ford Algorithm.
basically the same as the other algo but it can take negative values.by doing this over v times, all the edges will eventually be relaxed. 
When there is a negative cycke where bellman ford gets stuck in the loop. this could lead to delays.
- if any v is updated in phase v, there is a cycle to check for negative weight cycles. 