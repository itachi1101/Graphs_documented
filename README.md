# Graphs_documented
A Graph is a data structure that consists of the following two components:
A finite set of vertices also called nodes.
A finite set of ordered pair of the form (u, v) called as edge. The pair is ordered because (u, v) is not the same as (v, u) in case of a directed graph(digraph). The pair of the form (u, v) indicates that there is an edge from vertex u to vertex v. The edges may contain weight/value/cost.

Graphs are used to represent many real-life applications:
     Graphs are used to represent networks. The networks may include paths in a city or telephone network or circuit network. For example Google GPS
     Graphs are also used in social networks like linkedIn, Facebook. For example, in Facebook, each person is represented with a vertex(or node). Each node is a structure and contains information like person id, name, gender and locale.

                                                          Directed and Undirected Graphs
Directed Graphs: The Directed graphs are such graphs in which edges are directed in a single direction.
For Example, the below graph is a directed graph:

Undirected Graphs: Undirected graphs are such graphs in which the edges are directionless or in other words bi-directional. That is, if there is an edge between vertices u and v then it means we can use the edge to go from both u to v and v to u.
Following is an example of an undirected graph with 5 vertices:
Implementation Is There in the Codes:

                                                         Traversals
The Breadth First Traversal or BFS traversal of a graph is similar to that of the Level Order Traversal of Trees.
The BFS traversal of Graphs also traverses the graph in levels. It starts the traversal with a given vertex, visits all of the vertices adjacent to the initially given vertex and pushes them all to a queue in order of visiting. Then it pops an element from the front of the queue, visits all of its neighbours and pushes the neighbours which are not already visited into the queue and repeats the process until the queue is empty or all of the vertices are visited.
The BFS traversal uses an auxiliary boolean array say visited[] which keeps track of the visited vertices. That is if visited[i] = true then it means that the i-th vertex is already visited.

The Depth-First Traversal or the DFS traversal of a Graph is used to traverse a graph depth wise. That is, it in this traversal method, we start traversing the graph from a node and keep on going in the same direction as far as possible. When no nodes are left to be traversed along the current path, backtrack to find a new possible path and repeat this process until all of the nodes are visited.
We can implement the DFS traversal algorithm using a recursive approach. While performing the DFS traversal the graph may contain a cycle and the same node can be visited again, so in order to avoid this we can keep track of visited array using an auxiliary array. On each step of the recursion mark, the current vertex visited and call the recursive function again for all the adjacent vertices.
