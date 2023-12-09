#include <iostream>
#include <vector>
#include <set>

const int MAX_N = 100010;
const int INFINITY = 1000000000; //1000*100000 (W*N)

using namespace std;

vector<int> adj_black[MAX_N];
vector<int> adj_red[MAX_N];

vector<int> length_black[MAX_N];
vector<int> length_red[MAX_N];

int dist_black[MAX_N];
int dist_red[MAX_N];

int n, m, s, t;

void read_input(){
    cin >> n >> m >> s >> t;
    s--;
    t--;
    for (int i = 0 ; i < m ; i++){
        int u, v, c;
        cin >> u >> v >> c;

        u--;
        v--;
        

        if (c == 0){
            adj_black[u].push_back(v);
            adj_black[v].push_back(u);
            adj_red[u].push_back(v);
            adj_red[v].push_back(u);
            length_black[u].push_back(1);
            length_black[v].push_back(1);
            length_red[u].push_back(1);
            length_red[v].push_back(1);
        } else if (c == 1){
            adj_red[u].push_back(v);
            adj_red[v].push_back(u);
            length_red[u].push_back(1);
            length_red[v].push_back(1);
        } else if (c == 2){
            adj_black[u].push_back(v);
            adj_black[v].push_back(u);
            length_black[u].push_back(1);
            length_black[v].push_back(1);
        } 
    }
}

set <pair<int, int>> setds_black;
set <pair<int, int>> setds_red;

void dijkstra_black(int s){
    
    for (int i = 0 ; i < n ; i++){
        dist_black[i] = INFINITY;
    }

    dist_black[s] = 0;

    setds_black.insert(make_pair(0, s));

    while (!setds_black.empty()){
        pair<int, int> tmp = *(setds_black.begin());
        setds_black.erase(setds_black.begin());
        int best_u = tmp.second;

        int deg = adj_black[best_u].size();
        for (int i = 0 ; i < deg ; i++){

            int v = adj_black[best_u][i];
            int len = length_black[best_u][i];

            if (dist_black[best_u] + len < dist_black[v]){
                dist_black[v] = dist_black[best_u] + len;
                setds_black.insert(make_pair(dist_black[v], v));
            }
        }
    }
}

void dijkstra_red(int s){
    
    for (int i = 0 ; i < n ; i++){
        dist_red[i] = INFINITY;
    }

    dist_red[s] = 0;

    setds_red.insert(make_pair(0, s));

    while (!setds_red.empty()){
        pair<int, int> tmp = *(setds_red.begin());
        setds_red.erase(setds_red.begin());
        int best_u = tmp.second;

        int deg = adj_red[best_u].size();
        for (int i = 0 ; i < deg ; i++){

            int v = adj_red[best_u][i];
            int len = length_red[best_u][i];

            if (dist_red[best_u] + len < dist_red[v]){
                dist_red[v] = dist_red[best_u] + len;
                setds_red.insert(make_pair(dist_red[v], v));
            }
        }
    }
}

int main(){
    read_input();

    dijkstra_black(s);
    dijkstra_red(s);

    if (dist_black[t] == INFINITY && dist_red[t] == INFINITY){
        cout << -1 << "\n";
    } else if(dist_red[t] < dist_black[t]){
        cout << dist_red[t] << "\n";
    } else {
        cout << dist_black[t] << "\n";
    }
}

/*
6 7 2 4 
2 5 0 
3 4 2 
6 5 0 
3 6 0 
1 4 1 
2 1 2 
1 3 0

3 2 1 3 
1 2 1 
2 3 2
*/