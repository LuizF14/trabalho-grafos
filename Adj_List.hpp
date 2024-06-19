#ifndef ADJ_LIST
#define ADJ_LIST

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

template <typename t, typename w>
class Adj_List {
    private: 
        vector< pair<t, w> > *adj;
        int numberOfNodes;
        int *visited, *predecessors, *distance;

        void dfs_rec(int);
    public: 
        Adj_List(int = 1);
        ~Adj_List();

        void dfs(int);
        void bfs(int);
        void dijkstra(int);

        void printPredecessors() {
            for(int i = 0; i < numberOfNodes; i++) {
                cout << predecessors[i] << " ";
            }
            cout << endl;
        }

        template <typename t1, typename w1>
        friend ostream& operator<<(ostream&, Adj_List<t1, w1>&);

        template <typename t1, typename w1>
        friend istream& operator>>(istream&, Adj_List<t1, w1>&);
};

template <typename t, typename w>
Adj_List<t, w>::Adj_List(int numberOfNodes) {
    this->numberOfNodes = numberOfNodes;
    adj = new vector< pair<t, w> >[numberOfNodes];
    visited = new int[numberOfNodes];
    predecessors = new int[numberOfNodes];
    distance = new int[numberOfNodes];
}

template <typename t, typename w>
Adj_List<t, w>::~Adj_List() {
    delete[] adj;
    delete[] visited;
    delete[] distance;
    delete[] predecessors;
}

template <typename t, typename w>
void Adj_List<t, w>::dfs(int start) {
    memset(visited, 0, sizeof(t) * numberOfNodes);
    dfs_rec(start);
    cout << endl;
}

template <typename t, typename w>
void Adj_List<t, w>::dfs_rec(int u) {
    if (!visited[u]) {
        visited[u] = 1;
        cout << u << " ";
        for (auto i : adj[u]) {
            dfs_rec(i.first);
        }
    }
}

template <typename t, typename w>
void Adj_List<t, w>::bfs(int start) {
    memset(visited, 0, sizeof(t) * numberOfNodes);
    queue<t> bfs_queue;
    int u;

    bfs_queue.push(start);
    visited[start] = 1;

    while(!bfs_queue.empty()) {
        u = bfs_queue.front();
        bfs_queue.pop();
        cout << u << " ";
        for (auto i : adj[u]) {
            if (visited[i.first]) continue;
            visited[i.first] = 1;
            bfs_queue.push(i.first);
        }
    }
    cout << endl;
}

template <typename t, typename weight>
void Adj_List<t, weight>::dijkstra(int start) {
    memset(visited, 0, sizeof(t) * numberOfNodes);
    memset(predecessors, -1, sizeof(t) * numberOfNodes);
    memset(distance, INF, sizeof(t) * numberOfNodes);
    priority_queue<pair<int, int>> q;

    distance[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        int a = q.top().second;
        q.pop();

        if (visited[a]) continue;
        visited[a] = 1;

        for (auto u : adj[a]) {
            int b = u.first;
            int w = u.second;

            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                predecessors[b] = a;
                q.push({-distance[b], b});
            }
        }
    }
}

template <typename t, typename w>
ostream& operator<<(ostream& out, Adj_List<t, w>& graph) {
    for (int i = 0; i < graph.numberOfNodes; i++) {
        cout << i << " = ";
        for (int j = 0; j < graph.adj[i].size(); j++) {
            out << "(" << graph.adj[i][j].first << "," << graph.adj[i][j].second << ") ";
        }
        out << endl;
    }
    return out;
}

template <typename t, typename w>
istream& operator>>(istream& in, Adj_List<t, w>& graph) {
    // for (int i = 0; i < graph.numberOfNodes; i++) {
    //     int c;
    //     string line;
    //     getline(in, line);
    //     istringstream iss(line);
    //     while (iss >> c) {
    //         graph.adj[i].push_back(c);
    //     }
    // }
    int a, b, weight;
    cin >> a >> b >> weight;
    while (a != -1) {
        graph.adj[a].push_back({b, weight});
        cin >> a >> b >> weight;
    }
    return in;
}

#endif