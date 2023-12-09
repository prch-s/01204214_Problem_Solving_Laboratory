#include <iostream>
#include <vector>
#include <set>

const int MAX_N = 100010;
const int INFINITY = 1000000000; //1000*100000 (W*N)
const int MAX_S = 1000;


using namespace std;

vector<int> adj[MAX_N];
vector<int> length[MAX_N]; //weight
long dist[MAX_S][MAX_N];
int stock[MAX_S];
int village[MAX_S];
int n, m, s, t;

void read_input(){
    cin >> n >> m >> s >> t;
    for (int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);

        length[u].push_back(1);
        length[v].push_back(1);
    }
    for (int i = 0 ; i < s ; i++){
        int x;
        cin >> x;
        x--;
        stock[i] = x;
    }
    for (int i = 0 ; i < t ; i++){
        int x;
        cin >> x;
        x--;
        village[i] = x;
    }
    //cout << "finish input\n";
}

set <pair<int, int>> setds; // (weight,index)

void dijkstra(int factory, int s){
    
    dist[factory][s] = 0;

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

            if (dist[factory][best_u] + len < dist[factory][v]){
                dist[factory][v] = dist[factory][best_u] + len;
                setds.insert(make_pair(dist[factory][v], v));
            }
        }
    }
}

int main(){
    read_input();
    //reset
    for (int i = 0 ; i < s ; i++){
        for (int j = 0 ; j < n ; j++){
            dist[i][j] = INFINITY;
        }
    }
    for (int i = 0 ; i < s ; i++){
        //cout << " dijkstra[" << i << "] => stock[" << stock[i] << "]\n";
        dijkstra(i, stock[i]);
    }

    // for (int i = 0 ; i < s ; i++){
    //     cout << " dist[" << i << "] => stock[" << stock[i] << "]\n";
    //     for (int j = 0 ; j < n ; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0 ; i < t ; i++){
        int min = INFINITY;
        for (int j = 0 ; j < s ; j++){
            if (dist[j][village[i]] < min){
                min = dist[j][village[i]];
            }
        }
        cout << min << "\n";
    }
}

/*
8 9 3 5 
1 3
2 3
3 4
4 5
2 5
4 6
5 6
7 5
8 7
1 2 8 
1 6 5 4 7
score: 50 [ PPPPP[x-][-x][-x][-x][-x] ] 
*/