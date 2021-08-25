#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <set>

class ListGraph {
public:
    explicit ListGraph(size_t _verticesCount) : verticesCount(_verticesCount) {
        graph.resize(verticesCount);
    }

    ~ListGraph() = default;

    // Добавление ребра от from к to.
    void AddEdge(int from, int to, int weight) {
        graph[from].push_back({weight, to});
    }

    int VerticesCount() const { return verticesCount; }

    std::vector<std::pair<int, int>> GetNextVertices(int vertex) const {
        std::vector<std::pair<int, int>> result;
        result.resize(graph[vertex].size());
        std::copy(graph[vertex].begin(), graph[vertex].end(), result.begin());
        return result;
    }

private:
    std::vector<std::vector<std::pair<int, int>>> graph;
    size_t verticesCount;
};

int dijkstra(const ListGraph& graph, int from, int to) {
    std::vector<int> d(graph.VerticesCount(), INT_MAX);
    std::vector<int> pi(graph.VerticesCount(), -1);
    d[from] = 0;
    std::set<std::pair<int, int>> q;
    q.insert({0, from});
    while (!q.empty()) {
        int u = q.begin()->second;
        q.erase(q.begin());
        for (auto v : graph.GetNextVertices(u)) {
            if (d[v.second] == INT_MAX) {
                d[v.second] = d[u] + v.first;
                pi[v.second] = u;
                q.insert({v.first, v.second});
            } else if (d[v.second] > d[u] + v.first) {
                q.erase({d[v.second], v.second});
                d[v.second] = d[u] + v.first;
                pi[v.second] = u;
                q.insert({d[v.second], v.second});
            }
        }
    }
    return d[to];
}

int main() {
    int a, b, m, x, y;
    std::cin >> a >> b >> m >> x >> y;
    ListGraph lg(m);
    for (int i = 0; i < m; ++i) {
        lg.AddEdge(i, (i + 1) % m, a);
        lg.AddEdge(i, (i * i + 1) % m, b);
    }
    std::cout << dijkstra(lg, x, y);
    return 0;
}
