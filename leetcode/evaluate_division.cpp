#include <map>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries) {
    int current_idx = 0;
    map<string, int> name_to_idx;
    for (int i = 0; i < equations.size(); i++) {
      string name1 = equations[i].first;
      string name2 = equations[i].second;
      if (name_to_idx.find(name1) == name_to_idx.end()) {
        name_to_idx[name1] = current_idx;
        current_idx++;
      }
      if (name_to_idx.find(name2) == name_to_idx.end()) {
        name_to_idx[name2] = current_idx;
        current_idx++;
      }
    }
    int n = current_idx; // nodes
    vector<vector<double> > graph(n);
    for (int i = 0; i < n; i++) {
      graph[i].resize(n);
      graph[i][i] = 1;
    }

    for (int i = 0; i < values.size(); i++) {
      string name1 = equations[i].first;
      string name2 = equations[i].second;
      int node1 = name_to_idx[name1];
      int node2 = name_to_idx[name2];
      graph[node1][node2] = values[i];
      graph[node2][node1] = 1 / values[i];
    }

    vector<double> result(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      string name1 = queries[i].first;
      string name2 = queries[i].second;
      // check
      if(name_to_idx.find(name1) == name_to_idx.end() || name_to_idx.find(name2) == name_to_idx.end()) {
        result[i] = -1;
        continue;
      }
      int node1 = name_to_idx[name1];
      int node2 = name_to_idx[name2];

      vector<bool> vis(n, false);
      queue<pair<int, double> > q;
      vis[node1] = true;
      q.push(pair<int, double>(node1, 1));

      while (!q.empty()) {
        pair<int, double> tmp = q.front();
        int node = tmp.first;
        double val = tmp.second;
        for (int j = 0; j < n; j++) {
          if (!vis[j] && graph[node][j] != 0) {
            graph[node1][j] = val * graph[node][j];
            vis[j] = true;
            q.push(pair<int, double>(j, graph[node1][j]));
          }
        }
        q.pop();
        if (graph[node1][node2] != 0) break;
      }
      if (graph[node1][node2] == 0) {
        result[i] = -1;
      }
      else {
        result[i] = graph[node1][node2];
      }
    }

    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  return 0;
}
