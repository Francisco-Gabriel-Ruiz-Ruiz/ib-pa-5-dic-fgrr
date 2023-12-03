/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Francisco Gabriel Ruiz Ruiz
  * @date Dec 3
  * @brief The program
  * @bug There are no known bugs
  * @see Hoja 4 Classes ULL
  *      (Exercise C6)
  * @contact alu0101618586@ull.edu.es
  */

#ifndef GRAPH_CLASS_C6_TECLADO_H
#define GRAPH_CLASS_C6_TECLADO_H

#include <iostream>
#include <vector>
#include <unordered_set> // To keep track of unique numbers in a vertex

class Graph {
 public:
  Graph(int vertex_number, int edge_number);
  friend std::ostream& operator<<(std::ostream& out, const Graph& user_graph);
  int GetVertexNumber() const {
    return vertex_number_;
  }
  int GetEdgeNumber() const {
    return edge_number_;
  }
  std::vector<int> GetStartingGraphValues() const {
    return starting_graph_values_;
  }
  std::vector<int> GetEndingGraphValues() const {
    return ending_graph_values_;
  }
  void InsertPairOfVertexes(int starting_value, int ending_value);
  void PrintPairOfVertexes(std::ofstream& output_file) const;
 private:
  int vertex_number_;
  int edge_number_;
  std::vector<int> starting_graph_values_;
  std::vector<int> ending_graph_values_;
};

void ReadUserInitialGraphData(int& graph_vertexes, int& graph_edges,
                              std::ifstream& user_input_file);
bool ValidInitialGraphData(int graph_vertexes, int graph_edges);
void ReadUserPairOfVertexes(Graph& user_graph, std::ifstream& user_input_file);
std::unordered_set<int> ObtainUniqueValuesFromPairs(const Graph& user_graph);
int ObtainAmountOfPairs(const Graph& user_graph);
bool ValuesOfPairsInRange(std::unordered_set<int> unique_pair_values,
                          const Graph& user_graph,
                          std::vector<int>& infraction_numbers);
void PrintInfractionNumbers(const std::vector<int>& infraction_numbers);
bool ValidPairs(const Graph& user_graph);
void PrintProgramPurpose();
void PrintFileHelp();
bool CanOpenFile(const std::string& user_file_name, std::ifstream& user_file);

#endif