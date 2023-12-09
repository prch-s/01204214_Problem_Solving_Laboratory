#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 100010;

int m,n;
vector<int> adj[MAX_N];
int deg[MAX_N];
bool visited[MAX_N];
int level[MAX_N];

void read_input()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++) {
    deg[i] = 0;
    adj[i].clear();
  }
  for(int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v; 
    u--; v--; // start 0

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

bool bipartite_bfs(int s)
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

int main()
{

    int k;
    cin >> k;

    for (int i = 0 ; i < k ; i++){

        bool answer = true;
        read_input();
        init();

        for (int j = 0 ; j < n ; j++){
            if (visited[j]) { continue; }
            // bipartite_bfs = false
            if (!bipartite_bfs(j)) { 
                answer = false;
                break;
            }
        }

        if (answer) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }
    
}

/*
2
3 3
1 2
2 3
3 1
4 3
1 2
1 3
4 1
*/