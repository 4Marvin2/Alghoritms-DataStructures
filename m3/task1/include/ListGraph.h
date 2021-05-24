//
// Created by marvin on 24.05.2021.
//

#include <vector>

#include "IGraph.h"

#ifndef TASK1_LISTGRAPH_H
#define TASK1_LISTGRAPH_H

class ListGraph : public IGraph {
 public:
  explicit ListGraph(size_t _verticesCount);
  explicit ListGraph(const IGraph& _graph);

  ~ListGraph() override = default;

  // Добавление ребра от from к to.
  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;

 private:
  std::vector<std::vector<int>> graph;
  size_t verticesCount;
};

#endif  // TASK1_LISTGRAPH_H
