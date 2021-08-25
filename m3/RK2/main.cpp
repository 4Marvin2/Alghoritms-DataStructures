#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <vector>

class ListGraph {
public:
    explicit ListGraph(size_t _verticesCount) : verticesCount(_verticesCount) {
        graph.resize(verticesCount);
    }

    ~ListGraph() = default;

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int VerticesCount() const { return verticesCount; }

    std::vector<int> GetNextVertices(int vertex) const {
        std::vector<int> result;
        result.resize(graph[vertex].size());
        std::copy(graph[vertex].begin(), graph[vertex].end(), result.begin());
        return result;
    }
    std::vector<int> GetPrevVertices(int vertex) const {
        std::vector<int> result;
        for (int parent = 0; parent < graph.size(); ++parent) {
            for (int child : graph[parent]) {
                if (child == vertex) {
                    result.push_back(parent);
                }
            }
        }
        return result;
    }

private:
    std::vector<std::vector<int>> graph;
    size_t verticesCount;
};

int bfs(const ListGraph& graph, int from, int to) {
    std::vector<int> pi(graph.VerticesCount());
    std::vector<int> r(graph.VerticesCount(), INT_MAX);
    std::vector<int> pathsCount(graph.VerticesCount(), 0);
    std::queue<int> q;
    q.push(from);
    r[from] = 0;
    pi[from] = -1;
    pathsCount[from] = 1;
    int vertices_count = 0;
    while (!q.empty()) {
        int v = q.front();
        vertices_count += 1;
        q.pop();
        for (auto w : graph.GetNextVertices(v)) {
            if (r[w] > r[v] + 1) {
                r[w] = r[v] + 1;
                pi[w] = v;
                pathsCount[w] = pathsCount[v];
                q.push(w);
            } else if (r[w] == r[v] + 1) {
                pathsCount[w] += pathsCount[v];
            }
        }
    }
    return vertices_count;
}

int main() {
    int v;
    std::cin >> v;
    ListGraph lg(v);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, w;
        std::cin >> u >> w;
        lg.AddEdge(u, w);
    }
    if ((bfs(lg, 0, v) == v) && (v - 1 == n)) {
        std::cout << 1;
    } else {
        std::cout << 0;
    }
    return 0;
}

