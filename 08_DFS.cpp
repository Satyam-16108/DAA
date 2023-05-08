#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr) {
    visited[curr] = true;
    cout << curr << " ";
    for(int i = 0; i < graph[curr].size(); i++) {
        int neighbor = graph[curr][i];
        if(!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

void dfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    dfs(graph, visited, start);
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2}};
    dfs(graph, 0);
    return 0;
}
