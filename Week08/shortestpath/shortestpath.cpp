#include <iostream>
#include <vector>
#include <set>

const int MAX_N = 100010;
const int INFINITY = 1000000000; //1000*100000 (W*N)

using namespace std;

vector<int> adj[MAX_N];
vector<int> length[MAX_N]; //weight
int dist[MAX_N];

int n, m;

void read_input(){
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
        int u, v, w;
        cin >> u >> v >> w;

        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);

        length[u].push_back(w);
        length[v].push_back(w);
    }
}

set <pair<int, int>> setds; // (weight,index)

void dijkstra(int s){
    
    for (int i = 0 ; i < n ; i++){
        dist[i] = INFINITY;
    }

    dist[s] = 0;

    setds.insert(make_pair(0, s));

    while (!setds.empty()){
        //auto tmp = setds.begin();
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int best_u = tmp.second;

        int deg = adj[best_u].size();
        for (int i = 0 ; i < deg ; i++){

            int v = adj[best_u][i];
            int len = length[best_u][i];

            if (dist[best_u] + len < dist[v]){
                dist[v] = dist[best_u] + len;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
}

int main(){
    read_input();
    dijkstra(0);
    cout << dist[n-1] << "\n";
}

/*
4 5
1 2 10 
1 3 20 
3 4 5 
4 2 7 
2 3 12

ref:https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/
*/