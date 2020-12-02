# Weighted-Graph
Weighted Graph application using Dijkstra Shortest Path and Breadth First Search

This application contains a weighted graph which uses matrix of integers. If there is an edge, then
the location in the matrix holds the weight value of that edge, otherwise, the value holds the 
defined INT_MAX (which is just the largest number an integer can hold). 

The static const int MAX_VERTECIES defines how large the matrix needs be. (It should be left at 
a value of at least 10)

The BreadthFirstSearch() function will display all of the nodes visited in the search.

The DijkstraShortestPath() function will display the shortest distance starting from whichever vertex 
is given as the parameter to each other vertex in the map, including each vertex visited in the path.
