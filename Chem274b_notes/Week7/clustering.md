k-clustering: divide a set of objects classify into k coherent groups
distance function: numeric value specifying closeness of two objects
goal: divide into clusters so that objects in different clusters are far apart

Application:
routing in mobile and hoc networks
document categorization for web search

Single link clustering
- distance between cluster is the closeness of two objects
-    given an interger k, find a k-clustering that maximizes the distance between two clusters

Well known clustering is: v clusters
-   find closest pair of objects such that each object is in a different cluster, merge the two clusters.

Hiearchical clustering
- vertex = cancer tissue.
- edges weight is dissimilarity
this allows us to cluster together tumors that are related.