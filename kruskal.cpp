#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <queue>
using namespace std;

typedef pair<int, int> edge;

struct Graph{

	int V, E;
	vector< pair<int, edge> > edges;

	Graph(int V, int E);
    void addEdge(int u, int v, int w);
	
	void kruskal();
};

Graph::Graph(int V, int E){
    this->V = V;
    this->E = E;
}

void Graph::addEdge(int u, int v, int w){
	edges.push_back({w, {u, v}});
}
typedef struct DisjointSets{

	int *parent, *rnk;
	int n;

	DisjointSets(int n);
	int find(int u);
	//Union
	void merge(int x, int y);

}DisjointSets; 

DisjointSets::DisjointSets(int n){

    this->n = n;
    parent = new int[n+1];
    rnk = new int[n+1];

    for (int i = 0; i <= n; i++){
        rnk[i] = 0;
        parent[i] = i;
    }
}

int DisjointSets::find(int u){
    if (u != parent[u]){
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void DisjointSets::merge(int x, int y){

    x = find(x), y = find(y);

    if (rnk[x] > rnk[y]){
        parent[y] = x;
    }
    else{
        parent[x] = y;
    }
    if (rnk[x] == rnk[y]){
        rnk[y]++;
    }
}

void Graph::kruskal(){

    cout << "Executando o algoritmo de Kruskal..." << endl; 

	int mincost = 0; 
	sort(edges.begin(), edges.end());
	DisjointSets ds(V);

	vector< pair<int, edge> >::iterator it;
    
    cout << "Arvore geradora minima:\nEdge(v1, v2) \tWeight\n"; 

	for (it=edges.begin(); it!=edges.end(); it++){

		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if (set_u != set_v){

            cout << u << " " << v << " \t\t" << it->first << endl; 
			mincost += it->first;
			ds.merge(set_u, set_v);
		}
	}
    cout << "Custo minimo: " << mincost << endl;
}

Graph fileReader(){
    
    cout << "Lendo arquivo de entrada..." << endl;
    ifstream file;
    file.open("Big_G.txt");

    int n, m, lineReader[3];

    file >> n >> m;
    Graph g(n, m);

    cout << "Montando lista de adjacencia..." << endl;
    while(m--){
        file >> lineReader[0] >> lineReader[1] >> lineReader[2];

        int v1 = lineReader[0];
        int v2 = lineReader[1];
        int w = lineReader[2];

        g.addEdge(v1, v2, w);
    }
    return g;
 
}

int main(){
	Graph g = fileReader();
    
	g.kruskal();

	return 0;
}
