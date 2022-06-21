#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 5

void display(int parent[], int graph[V][V])
{
	printf("Edge \tWeight\n");
	for (int i = 0; i < V; i++)
		printf("%d - %d \t%d \n", parent[i] + 1, i + 1, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
	// Array to store constructed MST
	int parent[V];
	// Key values used to pick minimum weight edge in cut
	int key[V];
	// To represent set of vertices included in MST
	bool mstSet[V];
	int min_index = 0;

	for (int initial = 0; initial < V; initial++)
		key[initial] = INT_MAX, mstSet[initial] = false;

	key[0] = 0;
	parent[0] = -1; // First node is always root of MST


	for (int count = 0; count < V - 1; count++) {
		int min = INT_MAX;

		for (int i = 0; i < V; i++)
			if (mstSet[i] == false && key[i] < min)
				min = key[i], min_index = i;

		mstSet[min_index] = true;


		for (int v = 0; v < V; v++) {
			if (graph[min_index][v] != 0 && mstSet[v] == false && graph[min_index][v] < key[v])
				parent[v] = min_index, key[v] = graph[min_index][v];
		}

	}
	display(parent, graph);
}

int main() {
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
		{ 2, 0, 3, 8, 5 },
		{ 0, 3, 0, 0, 7 },
		{ 6, 8, 0, 0, 9 },
		{ 0, 5, 7, 9, 0 }
	};

	primMST(graph);

	return 0;
}