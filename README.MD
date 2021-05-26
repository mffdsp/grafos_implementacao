<div align="center">
	<h1>
	<a href = "https://github.com/mffdsp/grafos_implementacao/tree/b_final">
	 Implementação de algoritmos - Teoria dos Grafos
	</a> 
	</h1>

<p align="center">
	<a href="https://github.com/mffdsp/grafos_implementacao/blob/b_final/dijkstra.cpp">Dijkstra</a>&nbsp;&nbsp;&nbsp;
	<a href="https://github.com/mffdsp/grafos_implementacao/blob/b_final/fordfulkerson.cpp">FordFulkerson</a>&nbsp;&nbsp;&nbsp;
	<a href="https://github.com/mffdsp/grafos_implementacao/blob/b_final/kruskal.cpp">Kruskal</a>&nbsp;&nbsp;&nbsp;
	<a href="https://github.com/mffdsp/grafos_implementacao/blob/b_final/prim.cpp">Prim</a>&nbsp;&nbsp;&nbsp;
</p>


<p align="center">
	<a href="mailto:mffsp@ic.ufal.br" >Mateus Felismino</a>&nbsp;&nbsp;&nbsp;
  <a href="mailto:hgms@ic.ufal.br" >Hugo Gabriel</a>&nbsp;&nbsp;&nbsp;

</p>
</div>
</br>

<div align="center">
	<h1> Descrição simplificada dos algoritmos implementados: </h1>
</div>

<h2>Dijkstra</h2>

A entrada é dada por um grafo não direcionado, retorna os menores caminhos entre a fonte e os demais vértices.

<h2>Kruskal</h2>

A entrada é dada por um grafo não direcionado, retorna as arestas que formam a árvore geradora mínima e o custo da mesma.

<h2>Prim</h2>

A entrada é dada por um grafo não direcionado, retorna as arestas que formam a árvore geradora mínima e o custo da mesma, similar ao Kruskal.

<h2>Fordfulkerson</h2>

A entrada é dada por um grafo não direcionado, retorna  fluxo máximo entre fonte e sumidouro.

<div align="center">
	<h1> Compilação utilizando makefile no linux: </h1>
</div>

Compilar todos os algoritmos:
```
make all
```

Compilar cada algoritmo individualmente:
```
make dijkstra
make prim
make fordf
make kruskal
```
Obs. Caso esteja utilizando windows, baixe o <a href="https://ubuntu.com/download">ubuntu</a>! ☺. Ou compile manualmente para cada \<algoritmo\>:
	
```
g++ <algoritmo>.cpp -o <algoritmo>.exe

```


<div align="center">
	<h1> Entrada: </h1>
</div>

A entrada deve ser dada num arquivo colocado na pasta raiz, nomeado como "data.txt", na seguinte configuração:

```
n m
v1 v2 p1             // Aresta v1-v2 com peso p1
.
.
.
vn v4 p2            // Aresta vn-v4 com peso p2

```

obs. Vértices iniciando em 1 até n.


<div align="center">
	<h1> Execução: </h1>
</div>

Prim:
```
./prim 
```

Fordfulkerson:
```
./fordfulkerson 
```

Kruskal:
```
./kruskal 
```

Dijkstra:
```
./dijkstra 
```
