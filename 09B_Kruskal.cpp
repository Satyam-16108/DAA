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

int find(vector<int>& parent, int node) {
    if(parent[node] == node) {
        return node;
    }
    parent[node] = find(parent, parent[node]);
    return parent[node];
}

void kruskal(vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> parent(n);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;
    for(int i = 0; i < n; i++) {
        for(auto neighbor : graph[i]) {
            pq.push({i, neighbor.first, neighbor.second});
        }
    }
    int mst_weight = 0;
    vector<Edge> mst;
    while(!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();
        int parent1 = find(parent, curr.from);
        int parent2 = find(parent, curr.to);
        if(parent1 != parent2) {
            mst_weight += curr.weight;
            mst.push_back(curr);
            parent[parent1] = parent2;
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
    kruskal(graph);
    return 0;
}
