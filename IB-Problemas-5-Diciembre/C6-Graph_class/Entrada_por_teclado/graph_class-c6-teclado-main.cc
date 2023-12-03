/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Francisco Gabriel Ruiz Ruiz
  * @date Dec 3
  * @brief The program reads from user keyboard input a graph, checks if it is
  *        a valid one and prints it.
  * @bug There are no known bugs
  * @see Hoja 4 Classes ULL
  *      (Exercise C6)
  * @contact alu0101618586@ull.edu.es
  */

#include <iostream>

#include "graph_class-c6-teclado.h"

int main() {
  int graph_vertexes;
  int graph_edges;
  ReadUserInitialGraphData(graph_vertexes, graph_edges);
  if (!ValidInitialGraphData(graph_vertexes, graph_edges)) {
    PrintProgramPurpose();
    return 1;
  }
  Graph user_graph{graph_vertexes, graph_edges};
  ReadUserPairOfVertexes(user_graph);
  if (!ValidPairs(user_graph)) {
    return 2;
  }
  std::cout << user_graph << '\n' << "Su grafo es válido." << '\n';
  return 0;
}