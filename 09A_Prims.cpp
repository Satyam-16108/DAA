#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

struct CompareEdge {
    bool operator() (const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

void prim(vector<vector<pair<int, int>>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    visited[start] = true;
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;
    for(auto neighbor : graph[start]) {
        pq.push({start, neighbor.first, neighbor.second});
    }
    int mst_weight = 0;
    vector<Edge> mst;
    while(!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();
        if(!visited[curr.to]) {
            mst_weight += curr.weight;
            mst.push_back(curr);
            visited[curr.to] = true;
            for(auto neighbor : graph[curr.to]) {
                if(!visited[neighbor.first]) {
                    pq.push({curr.to, neighbor.first, neighbor.second});
                }
            }
        }
    }
    cout << "Minimum Spanning Tree:" << endl;
    for(auto edge : mst) {
        cout << edge.from << " " << edge.to << " " << edge.weight << endl;
    }
    cout << "Total Weight: " << mst_weight << endl;
}

int main() {
    vector<vector<pair<int, int>>> graph = {{{1, 5}, {2, 1}}, {{0, 5}, {2, 2}, {3, 4}}, {{0, 1}, {1, 2}, {3, 3}}, {{1, 4}, {2, 3}}};
    prim(graph, 0);
    return 0;
}
