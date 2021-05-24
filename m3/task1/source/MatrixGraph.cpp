//
// Created by marvin on 24.05.2021.
//

#include "../include/MatrixGraph.h"

#include <algorithm>
#include <iostream>

MatrixGraph::MatrixGraph(size_t _verticesCount)
    : verticesCount(_verticesCount),
      graph(_verticesCount, std::vector<int>(_verticesCount, 0)) {}

MatrixGraph::MatrixGraph(const IGraph &_graph)
    : MatrixGraph(_graph.VerticesCount()) {
  for (int i = 0; i < graph.size(); i++) {
    std::vector<int> current = _graph.GetNextVertices(i);
    for (int j : current) {
      graph[i][j] = 1;
    }
  }
}

void MatrixGraph::AddEdge(int from, int to) { graph[from][to] = 1; }

int MatrixGraph::VerticesCount() const { return verticesCount; }

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
  std::vector<int> result;
  for (int i = 0; i < graph.size(); ++i) {
    if (graph[vertex][i] == 1) {
      result.push_back(i);
    }
  }
  return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
  std::vector<int> result;
  for (int i = 0; i < graph.size(); ++i) {
    if (graph[i][vertex] == 1) {
      result.push_back(i);
    }
  }
  return result;
}
