#include <string>
#include <stack>
#include <climits>

class Graph
{
public:
	Graph();

	void AddEdge(std::string source, std::string target, int weight);
	void AddVertex(std::string label);

	int GetIndex(std::string label) const; // -1 if label is not found
	bool IsEdge(int sourceIndex, int targetIndex) const;
	int GetWeight(int sourceIndex, int targetIndex) const;

	void BreadthFirstSearch(std::string startingVertex) const;
	void BreadthFirstSearch(std::string startingVertex, int visited[]) const;

	void DijkstraShortestPath(std::string startingVertex) const;
	void DijkstraShortestPath(std::string startingVertex, int distance[], int prevVertex[]) const;
	int closestVertex(bool visited[], int distance[]) const;
	void printPath(int index, int prevVertex[]) const;

	void PrintGraph() const;

	static const int MAX_VERTECIES = 10;


private:
	int numVertices = 0;
	std::string vertices[MAX_VERTECIES];
	int matrix[MAX_VERTECIES][MAX_VERTECIES] = { 0 };
};
	 