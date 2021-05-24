#include <fstream> 
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <queue>
using namespace std;

int Gsize = 0;

bool bfs(int **rGraph, int parent[], int size, int src, int sink){

    bool visited[size];
    memset(visited, 0, sizeof(visited));
 
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < size; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {

                if (v == sink) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

void fordFulkerson(int **grafo, int src, int sink){

    cout << "Executando o algoritmo de Ford-Fulkerson..." << endl;
    cout << "Source: " << src << endl << "Sink: " << sink << endl;

    int p[Gsize], max = 0;
    int v, u;

    while(bfs(grafo, p, Gsize, src, sink)){
      
        int path = INT_MAX;

        for(v = sink; v != src; v = p[v]){
            u = p[v];
            path = min(path, grafo[u][v]);
        }
        for (v = sink; v != src; v = p[v]){
            u = p[v];
            grafo[u][v] -= path;
            grafo[v][u] += path;
        }
        max += path;
        
    }
    cout << "O fluxo máximo é dado por: " << max << endl;
}
 
int **fileReader(){
    
    cout << "Lendo arquivo de entrada..." << endl;
    ifstream file;
    file.open("data.txt");

    int n, m, lineReader[3];

    file >> n >> m;
    Gsize = n;
    int **graph = (int**) malloc(sizeof(int*)*n);

    for(int i = 0; i < n; i += 1){
        graph[i] = (int*) malloc(sizeof(int)*n);
    }
 
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < n; j += 1){
            graph[i][j] = 0;
        }
    }
    
    cout << "Montando matriz de adjacencia..." << endl;
    while(m--){
        file >> lineReader[0] >> lineReader[1] >> lineReader[2];

        int v1 = lineReader[0];
        int v2 = lineReader[1];
        int w = lineReader[2];

        graph[v1][v2] = w;

    }
    return graph;
 
}
void printGraph(int **graph){

    for(int i = 0; i < Gsize; i++){
        for(int  j = 0; j < Gsize; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
  
}
void freeGraph(int **graph){

    for(int i = 0; i < Gsize; i += 1){
        int* currentIntPtr = graph[i];
        free(currentIntPtr);
    }

}

int main(){
        
    int **graph = fileReader();
    
    //printGraph(graph);
    fordFulkerson(graph, 0, Gsize - 1);
    freeGraph(graph);
  
    return 0;
}