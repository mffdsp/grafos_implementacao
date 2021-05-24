#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <queue>

using namespace std;
int Gsize = 0;

int minKey(int key[], bool mstSet[]){ 

    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < Gsize; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
  
    return min_index; 
} 
  
void printResult(int parent[], int **graph){ 

    int mincost = 0;
    cout << "Arvore geradora minima:\nEdge(v1, v2) \tWeight\n"; 

    for (int i = 1; i < Gsize; i++){
        int w = graph[i][parent[i]];
        mincost += w;
        cout << parent[i] << " " << i << " \t\t" << w << "\n"; 
    }
    
    cout << "Custo minimo: " << mincost << endl;

} 
 
void prim(int **graph){ 

    cout << "Executando o algoritmo de Prim..." << endl; 

    int parent[Gsize], key[Gsize]; 
    bool mstSet[Gsize]; 
  
    for (int i = 0; i < Gsize; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
   
    key[0] = 0; 
    parent[0] = -1; 

    for (int count = 0; count < Gsize - 1; count++)
    { 
        
        int u = minKey(key, mstSet); 
  
        mstSet[u] = true; 
        for (int v = 0; v < Gsize; v++) {
            
            if (mstSet[v] == false && graph[u][v] < key[v]){
                 parent[v] = u, key[v] = graph[u][v]; 
            }
        }
            
    } 
    printResult(parent, graph); 

} 

int ** fileReader(int **graph){
    
    cout << "Lendo arquivo de entrada..." << endl;
    ifstream file;
    file.open("data.txt");

    int n, m, lineReader[3];

    file >> n >> m;
    Gsize = n;
    graph = (int**) malloc(sizeof(int*)*n);

    for(int i = 0; i < n; i += 1){
        graph[i] = (int*) malloc(sizeof(int)*n);
    }
 
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < n; j += 1){
            graph[i][j] = INT_MAX;
        }
    }
    
    cout << "Montando matriz de adjacencia..." << endl;
    while(m--){
        file >> lineReader[0] >> lineReader[1] >> lineReader[2];

        int v1 = lineReader[0];
        int v2 = lineReader[1];
        int w = lineReader[2];

        graph[v1][v2] = w;
        graph[v2][v1] = w;
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

    int **graph  = fileReader(graph);
    //printGraph(graph, size);
    prim(graph);
    freeGraph(graph);

    return 0;
}