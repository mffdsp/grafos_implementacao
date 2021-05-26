#include <fstream> 
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <queue>
using namespace std;
  
typedef pair<int, int> edge;
  
//Implementação clássica de grafo em C++, utilizando lista de adjacência como representação.
class Graph{
public:  

    int V;
    list< pair<int, int> > *adj;

    Graph(int V);
    void addEdge(int u, int v, int w);
    void dijkstra(int src, int sink);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<edge> [V];
}
  
void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
  
void Graph::dijkstra(int src, int sink=-1){

    cout << "Executando o algoritmo de Dijkstra..." << endl; 

    priority_queue< edge, vector <edge> , greater<edge> > pq;
  
    vector<int> dist(V, INT_MAX);
  
    pq.push(make_pair(0, src));
    dist[src] = 0;
  
    while (!pq.empty()){

        int u = pq.top().second;
        pq.pop();
  
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i){

            int v = (*i).first;
            int weight = (*i).second;
  
            if (dist[v] > dist[u] + weight){
                
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    cout << "Vertice \t Distancia em relacao a fonte" << endl;
    //Todas as distâncias
    if(sink == -1){
    for (int i = 0; i < V - 1; ++i){
            cout << i + 1 << "\t \t " << dist[i + 1] << endl;
        }
    }else {
        //Apenas uma distancia, entre src e sink
        cout << sink << "\t \t " << dist[sink] << endl;
    }
    
}

Graph fileReader(){
    
    cout << "Lendo arquivo de entrada..." << endl;
    ifstream file;
    file.open("data.txt");

    int n, m, lineReader[3];

    file >> n >> m;

    Graph g(n + 1);

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
    //Arquivo de entrada data.txt
    Graph g = fileReader();
    //menor distancia entre todos e a fonte
    g.dijkstra(1);
    //menor distância entre v1 e a fonte
    //g.dijkstra(1, 6);
    return 0;
}