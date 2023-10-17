#include <deque>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void CrossingMakeBlack(int u, int v,
                       std::unordered_map<int, std::vector<int>>& graph,
                       std::unordered_set<int>& black_v,
                       std::unordered_map<int, bool>& color) {
  color[u] = color[v] = true;
  black_v.insert(u);
  black_v.insert(v);
  for (int x : graph[u]) {
    for (int y : graph[v]) {
      if (x == y) {
        color[x] = true;
        black_v.insert(x);
        break;
      }
    }
  }
}

int Crossing(int u, int v, std::unordered_map<int, std::vector<int>> graph) {
  if (u == v) {
    return 0;
  }

  int i = 0;
  
  for (int x : graph[u]) {
    for (int y : graph[v]) {
      if (x == y) {
        ++i;
        break;
      }
    }
  }
  return i;
}

int main() {
  int M;
  std::unordered_map<int, std::vector<int>> graph;
  std::unordered_set<int> vertex, black_vertex;
  std::unordered_map<int, bool> color;
  std::deque<int> que;
  std::unordered_set<int> ans;
  std::cin >> M;

  int u, v;

  for (int i = 0; i < M; ++i) {
    std::cin >> u >> v;
    color[u] = color[v] = false;
    graph[u].push_back(v);
    graph[v].push_back(u);
    vertex.insert(u);
    vertex.insert(v);
  }

  while (black_vertex.size() < vertex.size()) {
    int max_cross = 0;
    int x, y;
    if (que.empty()) {
      for (int u : vertex) {
        for (int v : vertex) {
          int m = 0;
          if ((m = Crossing(u, v, graph)) > max_cross && !color[u] &&
              !color[v]) {
            max_cross = m;
            x = u, y = v;
          }
        }
      }
      ans.insert(x);
      ans.insert(y);
      que.push_back(x);
      que.push_back(y);
    } else {
      u = que.front();
      for (auto v : vertex) {
        if (u != v && color[v]) {
          CrossingMakeBlack(u, v, graph, black_vertex, color);
        }
      }

      que.pop_front();
      for (int v : vertex) {
        int m = 0;
        if ((m = Crossing(u, v, graph)) > max_cross && !color[v]) {
          max_cross = m;
          x = u, y = v;
        }
      }
      if (max_cross != 0) ans.insert(y);
    }
    if (max_cross != 0) CrossingMakeBlack(x, y, graph, black_vertex, color);
    if (max_cross == 0 && que.empty()) {
      for (auto x : vertex) {
        if (!color[x]) {
          ans.insert(x);
          black_vertex.insert(x);
        }
      }
      break;
    }
  }

  std::cout << ans.size() << std::endl;

  for (auto x : ans) {
    std::cout << x << " ";
  }

}