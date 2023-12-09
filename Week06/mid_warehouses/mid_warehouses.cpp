#include <iostream>
#include <vector>
#include <list>

const int MAX_N = 100010;

using namespace std;
int n, m, k, a, b, s, t, i;

vector<int> adj[MAX_N];
int deg[MAX_N];
bool visited[MAX_N];
int level[MAX_N];

int team[MAX_N];

void init() {
    for(int i = 0; i < n ; i++) {
        visited[i] = false;
        level[i] = -1;
    }
}

void bfs(int s)
{
    list<int> Q;
    //parent[s] = -1;

    Q.push_back(s);
    visited[s] = true;
    team[s] += s;
  
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for(int i = 0 ; i < deg[u]; i++) {
            int v = adj[u][i];
            if(!visited[v]) {
	            Q.push_back(v);
	            visited[v] = true;
	            team[v] += s;
            }
        }
    }
}

int main(){
    cin >> n >> m >> k;

    for(int i = 0 ; i < n ; i++) {
        deg[i] = 0;
        team[s] = 0;
    }

    for (int i = 0 ; i < m ; i++){
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    init();

    for (int i = 0 ; i < n ; i++){
        cout << "i : " << i << "\n";
        if (!visited[i]) {
            cout << "bfs i : " << i << "\n";
        
          bfs(i);
        }
    }

    
    for (int i = 0 ; i < n ; i++){
        cout << team[i] << " ";
    }
    

    for (int i = 0 ; i < k ; i++){
        cin >> s >> t;
        s--;
        t--;
        if (team[s] == team[t]){
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

}

/*
6 5 3 
1 2 
1 3 
3 1 
4 5 
3 6 
1 6 
6 4 
5 4
*/