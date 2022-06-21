#include <stdio.h>
#define V 5
#define INF 9999999

typedef struct edge {
  int u, v, w;
} edge;

edge elist[V * V];
int edgeno = 0;
edge slist[V * V];
int spanno = 0;
int parent[V];
int rank[V];

void makeSet() {
  for (int i = 0; i < V; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}


void kruskalAlgo();
int findPar(int vertex);
void applyUnion(int v1, int v2);
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo(int Graph[V][V]) {

  // int edgeno = 0;
  for (int i = 0; i < V - 1; i++) {
    for (int j = i + 1; j < V; j++) {
      elist[edgeno].u = i + 1;
      elist[edgeno].v = j + 1;
      if (Graph[i][j] != 0)
        elist[edgeno++].w = Graph[i][j];
    }
  }

  sort();
  makeSet();

  for (int i = 0; i < V * V; i++) {
    int u = findPar(elist[i].u);
    int v = findPar(elist[i].v);

    if (u != v) {
      slist[spanno++] = elist[i];
      applyUnion(u, v);
    }
  }
}

int findPar(int vertex) {
  if (vertex == parent[vertex])
    return vertex;
  else
    return parent[vertex] = findPar(parent[vertex]);
}

void applyUnion(int v1, int v2) {
  if (rank[v1] > rank[v2])
    parent[v2] = v1;
  else if (rank[v1] < rank[v2])
    parent[v1] = v2;
  else {
    parent[v2] = v1;
    rank[v1]++;
  }
}

// Sorting algo
void sort() {
  edge temp;

  for (int i = 0; i < edgeno - 1; i++) {
    for (int j = i + 1; j < edgeno; j++) {
      if (elist[i].w > elist[j].w) {
        temp = elist[i];
        elist[i] = elist[j];
        elist[j] = temp;
      }
    }
  }
  for (int i = 0; i < edgeno; i++)
    printf("%d - %d : %d\n", elist[i].u, elist[i].v, elist[i].w);
}

// Printing the result
void print() {
  int cost = 0;
  for (int i = 0; i < spanno; i++) {
    printf("\n%d - %d : %d", slist[i].u, slist[i].v, slist[i].w);
    cost += slist[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}

int main() {

  int Graph[V][V] = { { 0, 2, 0, 6, 0 },
    { 2, 0, 3, 8, 5 },
    { 0, 3, 0, 0, 7 },
    { 6, 8, 0, 0, 9 },
    { 0, 5, 7, 9, 0 }
  };

  kruskalAlgo(Graph);
  print();
}