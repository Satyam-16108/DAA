#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for(int i = 0; i < graph[curr].size(); i++) {
            int neighbor = graph[curr][i];
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2}};
    bfs(graph, 0);
    return 0;
}
