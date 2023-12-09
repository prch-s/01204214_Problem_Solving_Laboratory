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

void dfs(int u)
{
    visited[u] = true;
    for(int i=0; i<deg[u]; i++) {
        int v = adj[u][i];
        if(!visited[v]) {
            dfs(v);
    }
  }
}

void bfs(int s)
{
    list<int> Q;
    //parent[s] = -1;

    Q.push_back(s);
    visited[s] = true;
    level[s] = 0;
  
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        cout << "node : " << u+1 << " level : " << level[u] << "\n";
        for(int i = 0 ; i < deg[u]; i++) {
            int v = adj[u][i];
            if(!visited[v]) {
	            Q.push_back(v);
	            visited[v] = true;
	            level[v] = level[u] + 1;
                //parent[v] = u;
            }
        }
    }
}

int main()
{
  read_input();
  init();
  int conn_component = 0;

  for (int i = 0 ; i < n ; i++){
      if (!visited[i]) {
          bfs(i);
          conn_component++;
      }
  }

  cout << conn_component << "\n";
}

/*
3 2
1 2
3 1

5 4
1 2
2 5
1 5
4 3
*/