#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1010;
const int INFINITY = 1000000010; 

int n, m;
vector<int> adj[MAX_N];
vector<int> weight[MAX_N];
int deg[MAX_N];

void read_input(){
    cin >> n >> m;

    for (int i = 0 ; i < n ; i++){
        deg[i] = 0;
    }

    for (int i = 0 ; i < m ; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);

        weight[u].push_back(w);
        weight[v].push_back(w);

        deg[u]++;
        deg[v]++;
    }
}

bool visited[MAX_N];
int min_weight[MAX_N];

int prim(){
    for (int i = 0 ; i < n ; i++){
        visited[i] = false;
        min_weight[i] = INFINITY;
    }
    //start
    min_weight[0] = 0;

    int result = 0;
    int count = 0;

    //use set faster
    while (count < n) {
        int u = -1;
        int wu = INFINITY;
        for (int i = 0 ; i < n ; i++) {
            if ((!visited[i]) && (min_weight[i] < wu)){
                u = i;
                wu = min_weight[i];
            }
        }

        visited[u] = true;
        result += wu;

        //scan all edges adjancent to u
        for (int i = 0 ; i < deg[u] ; i++){
            int v = adj[u][i];

            if (min_weight[v] > weight[u][i]){
                min_weight[v] = weight[u][i];
            }
        }
        count++;
    }
    return result;
}



int main(){
    read_input();
    int result = prim();
    cout << result << "\n";
}

/*
4 5
1 2 10 
1 3 20 
3 4 5 
4 2 7 
2 3 12
*/