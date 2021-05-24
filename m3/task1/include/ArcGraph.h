//
// Created by marvin on 24.05.2021.
//

#include <vector>

#include "IGraph.h"

#ifndef TASK1_ARCGRAPH_H
#define TASK1_ARCGRAPH_H

class ArcGraph : public IGraph {
 public:
  explicit ArcGraph(size_t _verticesCount);
  explicit ArcGraph(const IGraph& _graph);

  ~ArcGraph() override = default;

  // Добавление ребра от from к to.
  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;

 private:
  std::vector<std::pair<int, int>> graph;
  size_t verticesCount;
};

#endif  // TASK1_ARCGRAPH_H
