#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INFINITY = 1e6;
const int MAX_N = 50050;


int N, n, m, S, T;
int u, v, w;


long int dijkstra(int S, int T){
    vector<int> adj[MAX_N];
    vector<int> weight[MAX_N]; 
    set <pair<int, int>> setds; // (weight,index)
    long int dist[MAX_N];
    bool visited[MAX_N];
    int flag = 0;

    for (int i = 0 ; i < m ; i++){
            cin >> u >> v >> w;

            adj[u].push_back(v);
            adj[v].push_back(u);

            weight[u].push_back(w);
            weight[v].push_back(w);

            flag = 1;
        }

    //init
    for (int i = 0 ; i < n ; i++){
        dist[i] = INFINITY;
        visited[i] = false;
    }

    dist[S] = 0;

        
    if (flag){
        setds.insert(make_pair(0, S));
    }

    while (!setds.empty()){
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int best_u = tmp.second;

        int deg = adj[best_u].size();
        for (int i = 0 ; i < deg ; i++){

            int v = adj[best_u][i];
            int len = weight[best_u][i];

            if (dist[best_u] + len < dist[v]){
                dist[v] = dist[best_u] + len;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    // cout << "dist\n";
    // for (int i = 0 ; i < n ; i++){
    //     cout << dist[i] << " ";
    // }
    // cout << "\n";
    return dist[T];
}

int main(){

    cin >> N;

    for (int k = 1 ; k <= N ; k++){
    
        cin >> n >> m >> S >> T;
        
        long int answer = dijkstra(S, T);
        
        cout << "Case #" << k << ": ";
        if (answer != INFINITY){
            cout << answer << "\n";
        } else {
            cout << "unreachable\n";
        }
    }
}

/*
3 
2 1 0 1 
0 1 100 
3 3 2 0 
0 1 100 
0 2 200 
1 2 50 
2 0 0 1

*/