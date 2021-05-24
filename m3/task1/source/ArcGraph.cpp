//
// Created by marvin on 24.05.2021.
//

#include "../include/ArcGraph.h"

#include <algorithm>
#include <iostream>

ArcGraph::ArcGraph(size_t _verticesCount) : verticesCount(_verticesCount) {}

ArcGraph::ArcGraph(const IGraph &_graph) : ArcGraph(_graph.VerticesCount()) {
  for (int i = 0; i < verticesCount; i++) {
    std::vector<int> current = _graph.GetNextVertices(i);
    for (int j : current) {
      graph.emplace_back(i, j);
    }
  }
}

void ArcGraph::AddEdge(int from, int to) { graph.emplace_back(from, to); }

int ArcGraph::VerticesCount() const { return verticesCount; }

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
  std::vector<int> result;
  for (const auto &i : graph) {
    if (i.first == vertex) {
      result.push_back(i.second);
    }
  }
  return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
  std::vector<int> result;
  for (const auto &i : graph) {
    if (i.second == vertex) {
      result.push_back(i.first);
    }
  }
  return result;
}
