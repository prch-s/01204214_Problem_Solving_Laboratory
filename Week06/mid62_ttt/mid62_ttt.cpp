#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_M = 3010;

int n, m;
int skip_u, skip_v;
bool flag;

vector<int> adj[MAX_M];
int deg[MAX_M];
bool visited[MAX_M];
int level[MAX_M];

int pairs[MAX_M][2];

void read_input(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        deg[i] = 0;
        adj[i].clear();
    }
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v; 
        u--; v--; // start 0
        pairs[i][0] = u;
        pairs[i][1] = v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}

void init()
{
    for(int i = 0; i < n ; i++) {
        visited[i] = false;
        level[i] = -1;
    }
}

bool bfs(int s)
{
    list<int> Q;
    Q.push_back(s);
    visited[s] = true;
    level[s] = 0;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();

        //cout << "-------------------------------\n";
        //cout << "node : " << u+1 << " level : " << level[u] << "\n";

        for(int i = 0 ; i < deg[u]; i++) { 

            int v = adj[u][i];
            if((u == skip_u && v == skip_v) || (v == skip_u && u == skip_v)){
                continue;
            }
            if(!visited[v]) {
	            Q.push_back(v);
	            visited[v] = true;
	            level[v] = level[u] + 1;
            } else {
                if (level[u] == level[v]){
                    //cout << "Red(" << u+1 << ") : " << level[u] << "  "<< "Blue(" << v+1 << ") : " << level[v] << "\n";
                    return false;
                }
            }
        }
    }
    //cout << "-------------------------------\n"; 
    return true;
}


int main() {
    read_input();
    init();
    for (int i = 0 ; i < m ; i++){
        flag = true;
        skip_u = pairs[i][0];
        skip_v = pairs[i][1];
        
        //cout << "su : " << skip_u+1 << " sv : " << skip_v+1 << "\n";
        
        for (int j = 0 ; j < n ; j++){
            if (visited[j]) { continue; }
            // bfs = false bipartite
            //cout << "i : " << i << " j : " << j << "\n";
            if (!bfs(j)) { 
                flag = false;
                break;
            }
        }
        if (flag){
            cout << skip_u + 1 << " " << skip_v + 1 << "\n";
            break;
        }
        init(); //reset
    }

}

/*
5 5
2 3
1 2
3 1
1 4
2 4

3 3
1 2
2 3
1 3
*/