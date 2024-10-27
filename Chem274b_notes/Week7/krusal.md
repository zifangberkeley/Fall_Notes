Edges are in ascending order of weight. add next edge to tee T unless doing so would create a cycle.
basically: if edge v-w to tree T would create a cycle, do not add.

It will run DFS from v, check if w is reachable. log*V use the union find data structure. 
The union is the connection between two objects.
find/connected query: is there a path connecting the two objects.
we are going to assume connect to is an equivalent relation
- reflexive: p is connected to p
- symmetric: if p is connected to q, then q is connected to p.
- transitive: if p is connected to q andd q is connected to r, then p is connected to r. 

find query: checks if two objects are in the same component.
union command. replace components containing two objects with their union.

Goal: design efficient data structure for union find.
number of operations M can be huge
find queries and union commands may be intermixed.

Terms:
disjoint sets: a collection of sets containing N elements, with each element in eaxctly one set
Leader. each set designates one of its elements as leader to uniquely identify the set
-   there's no restriction on designated leader, but leader of set can't change unless set changes.
class description
UF(n) -> initiallize union find class with N singleton sets (0 to N-1)
union(p,q) -> Merge sets containing elements p and q
find(p) -> return the leader of set containing element p.

How to implement Kruskal MST

class KruskalMST:
    def __init__(self, G: Edgeweightedgraph):
        self.mst = []
        edges = list(G.edges())
        edges.sort(key=lambda e: e.weight) //hit the lowest weight edges first.
        uf = UnionFind(G.v())

        for edge in edges: // greedily add edges to MST
            v = edge.either()
            w = edge.other(v)
            if uf.union(v,w): // if won't create cycle, okay to add to mst. 
                self.mst.append(edge) 
                if len(self.mst == G.V()- 1) //by definition, this is done as the edges is vertices -1.
                    break
    def edges(self) -> iterable[Edge]:
        return self.mst
    
    def weight(self) -> float:
        return sum(e.weight for e in self.mst)

Worst case it will run E log e due to priority queue building.
