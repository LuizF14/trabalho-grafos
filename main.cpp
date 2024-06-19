#include <bits/stdc++.h>
#include "Adj_List.hpp"

using namespace std;

int main() {
    Adj_List<int, int> graph(5);

    cin >> graph;
    cout << graph;

    graph.dfs(0);
    graph.bfs(0);

    graph.dijkstra(0);
    graph.printPredecessors();

    return 0;
}