#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include "graph.h"
using namespace std;

Graph::Graph()
{
	numVertices = 0;
	for (int i = 0; i < MAX_VERTECIES; i++)
	{
		for (int j = 0; j < MAX_VERTECIES; j++)
		{
			matrix[i][j] = INT_MAX;
		}
	}
}

void Graph::AddEdge(std::string source, std::string target, int weight)
{
	int fromIndex = GetIndex(source);
	int toIndex = GetIndex(target);
	if (fromIndex == -1 or toIndex == -1)
		return;

	matrix[fromIndex][toIndex] = weight; 

	return;
}

void Graph::AddVertex(std::string label)
{
	if (numVertices >= MAX_VERTECIES)
	{
		return;
	}

	vertices[numVertices++] = label;
	return;
}

int Graph::GetIndex(std::string label) const
{
	for (int i = 0; i < numVertices; i++)
	{
		if (vertices[i] == label)
			return i;
	}
	return -1;
}

bool Graph::IsEdge(int sourceIndex, int targetIndex) const
{
	if (matrix[sourceIndex][targetIndex] < INT_MAX)
		return true;
	else
		return false;
}

int Graph::GetWeight(int sourceIndex, int targetIndex) const
{
	return matrix[sourceIndex][targetIndex];
}

void Graph::BreadthFirstSearch(std::string startingVertex) const
{  
	int startingIndex = GetIndex(startingVertex);
	cout << "starting BFS with vertex " << vertices[startingIndex] << endl;

	if (startingIndex != -1)
	{
		int visited[MAX_VERTECIES];
		for (int i = 0; i < MAX_VERTECIES; i++)
		{
			visited[i] = -1;
		}
		
		BreadthFirstSearch(startingVertex, visited);		

		for (int i = 0; i < numVertices; i++)
		{ 
			int next = visited[i];
			if (visited[i] > -1)
			{
				cout << "\t" << " visited " << vertices[next] << endl;
			}
		}
		cout << endl;
	}
}

void Graph::BreadthFirstSearch(std::string startingVertex, int visited[]) const
{
	int currentV = GetIndex(startingVertex);
	int order = 0;

	bool discovered[MAX_VERTECIES];
	for (int i = 0; i < numVertices; i++)
	{
		discovered[i] = false;
	}
	discovered[currentV] = true;

	queue<int> frontierQueue;
	frontierQueue.push(currentV);
	
	while (frontierQueue.empty() != true)
	{
		currentV = frontierQueue.front();
		visited[order] = currentV;

		for (int i = 0; i < numVertices; i++)
		{
			if (matrix[currentV][i] < INT_MAX)
			{
 				if (discovered[i] == false)
				{
					discovered[i] = true;
					frontierQueue.push(i);
				}
			}
		}
		frontierQueue.pop();
		order++;
	}

}

void Graph::DijkstraShortestPath(std::string startingVertex) const
{
	cout << "Shortest Distance starting from vertex " << startingVertex << endl;
	int startingIndex = GetIndex(startingVertex);

	if (startingIndex != -1)
	{
		int distance[MAX_VERTECIES];
		int prevVertex[MAX_VERTECIES];
		
		DijkstraShortestPath(startingVertex, distance, prevVertex);

		for (int i = 0; i < numVertices; i++)
		{
			cout << "\t" << "to: " << vertices[i] << "\t";
			if (distance[i] == INT_MAX)
			{
				cout << "no path" << endl;
			}
			else
			{
				cout << distance[i];
				printPath(i, prevVertex);
			}
		}
	}
	cout << endl;
}

void Graph::DijkstraShortestPath(std::string startingVertex, int distance[], int prevVertex[]) const
{
	int currentV = GetIndex(startingVertex);

	for (int i = 0; i < numVertices; i++)
	{
		distance[i] = INT_MAX;
	}

	bool visited[MAX_VERTECIES];
	for (int i = 0; i < numVertices; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < numVertices; i++)
	{
		prevVertex[i] = -1;
	}

	visited[currentV] = true;
	distance[currentV] = 0;

	while (currentV != -1)
	{
			for (int i = 0; i < numVertices; i++)
			{
				if (matrix[currentV][i] < 20)
				{
					if ((distance[currentV] + matrix[currentV][i]) < distance[i])
					{
						distance[i] = (distance[currentV] + matrix[currentV][i]);
						prevVertex[i] = currentV;
					}
				}
			}
		currentV = closestVertex(visited, distance);
		if (currentV > -1)
		{
			visited[currentV] = true;
		}
	}
}

void Graph::printPath(int index, int prevVertex[]) const
{
	cout << "" << "\t" << "Path: ";
	
	while (prevVertex[index] != -1)
	{
		cout << vertices[index] << ", ";
		index = prevVertex[index];
	}
	
	cout << vertices[index] << endl;

}

int Graph::closestVertex(bool visited[], int distance[]) const
{
	int min = INT_MAX;
	int min_index = -1;

	for (int k = 0; k < numVertices; k++)
	{
		if (visited[k] == false and distance[k] < min)
		{
			min = distance[k];
			min_index = k;
		}
	}
	return min_index;
}

void Graph::PrintGraph() const
{	cout << "numVerticies: " << numVertices << endl;

	for (int i = 0; i < numVertices; i++)
	{
		cout << "\t" << vertices[i];
	}
	cout << endl;

	for (int j = 0; j < numVertices; j++)
	{
		cout << vertices[j];
		for (int i = 0; i < numVertices; i++)
		{
			if (matrix[j][i] < INT_MAX)
				cout << "\t" << matrix[j][i];
			else
				cout << "\t";
		}
		cout << endl;
	}
}
