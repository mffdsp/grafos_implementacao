 FOO = $PATH

dijkstra:
	g++ dij.cpp -o dij
	@echo "Algoritmo de Dijkstra compilado com sucesso!"
	
prim:
	g++ prim.cpp -o prim
	@echo "Algoritmo de Prim compilado com sucesso!"
	
fordf:
	g++ fordf.cpp -o fordf
	@echo "Algoritmo de Ford-Fulkerson compilado com sucesso!"
kruskal:
	g++ kruskal.cpp -o kruskal 
	@echo "Algoritmo de Kruskal compilado com sucesso !"
	
	
all: dijkstra prim fordf kruskal
