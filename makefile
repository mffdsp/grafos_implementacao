 FOO = $PATH

dijkstra:
	g++ dijkstra.cpp -o dijkstra
	@echo "Algoritmo de Dijkstra compilado com sucesso!"
	
prim:
	g++ prim.cpp -o prim
	@echo "Algoritmo de Prim compilado com sucesso!"
	
fordf:
	g++ fordfulkerson.cpp -o fordfulkerson
	@echo "Algoritmo de Ford-Fulkerson compilado com sucesso!"
kruskal:
	g++ kruskal.cpp -o kruskal 
	@echo "Algoritmo de Kruskal compilado com sucesso !"
	
	
all: dijkstra prim fordf kruskal
