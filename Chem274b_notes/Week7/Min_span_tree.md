# Spanning Trees

how to apply these data structures to solve actual problems.
-   given undirect graph G with positive edge weights (connected)
-   a spanning tree is both a tree (connected and acyclic) and spanning ( includes all the vertices)
-   find a min weight spanning tree.

a min spanning tree have to be connected. But it has to be acyclic. Can be anything that is modeled as a network.

# Greedy algo:
simplifying assumptions:
-   edge weights are distinct(ensures uniqueness. There is only one minimum spanning tree)
-   graph is connected (ensures mst)
not fundamental blockers but just guidlines. 

a cut property:
how to we select the crossing that connects one node to another.
we can use the cut property. 
a cut in a graph is a partition of its vertices into two non-empty sets
a crossing edge connects a vertext in one set with a vertex in the other 
-   given any cut, the corssing edge of min weights is in the mst.

prove is that:
if there is an existing link, and you add in a link that has a lower weight, this results in a contradiction.
removing existing link and then add a link of lower weight. 

Greedy Algorithm:
- heuristic approach to solving many optimization problems for which a local optimal choice exists.
-   applying a series of local optimal solutions, we can approximate a global solution.
make choice that is best in the present moment without solving other subproblems.

How do we choose a cut? using algos
we can now remove two simplifying assumptions.
-    what if the edge weights are not distinct. doesn't matter since it's still minimum.
what if graph is not connected
-   we can independently compute each tree.

In the weighted edge interface: 

class Edge:
    def __init__(self, v : int, w: int, weight : float):
        self.v = v
        self.w = w
        self.weight = weight

    def either(self) -> int:
    # retrieve either endpoints.
        return self.v

    def other(self, vertex:int) -> int:
    # retrieve the endpoint that is not vertex
        if vertext == self.v:
            return self.w
        elif vertext == self.w:
            return self.v
        else:
            raise valueerror

    def __it__(self, other: 'Edge') -> bool:
    # edge comparison
        return self.weight < other.weight
    def __eq__(self, other:'Edge) -> bool:
        return self.weight == other.weight
    
    def __str__(self) -> str:
        return f'{self.v} - {self.w} {self.weight: .2f}'

We also have to coinsider self-loops and parallel edges. 
    class edgeweight graphs
        def __init(self, v:int)
            self.v = v
            self.e = 0
            self.adj : list[list[edge]] = [[ ] foor _ in range V]
        def v(self) -> int
            return self.v
        def e(self) -> int
            return self.e
        def addedge(self, e:edge) -> None:
            v = e.either() get self edge
            w = e.other() get other edge of edge
            self.adj[v].append(e) add edge to both adjacency list
            self.adj[w].append(e)
            self.e +=1

        def adj(self, v : int) -> iterable[edge]:
            returns all of the edges that are incident to v. return a list of all those edges
            return self.adj[v] index the adjacency list with the iterable v
        def edge(self) -> iterable[edge]
            return all of the edges in the graph
            all_edge = set()
            for v in range(self.v)
                for e in self.adj[v] keep moving along these
                    all edges.add(e)
            return all_edges

        def __str__(self) -> str
            return the graph as a string.
            retrun f'graph with {self.v} vertices and self.e edges\n' + \ 
            "\n".join...



