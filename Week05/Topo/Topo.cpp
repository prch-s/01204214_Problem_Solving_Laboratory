#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100010;

int m,n;
vector<int> adj[MAX_N];

int deg[MAX_N];
int indeg[MAX_N];

//bool visited[MAX_N];

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
    deg[u]++;
    indeg[v]++;
  }
}

/*
void init()
{
    for(int i = 0; i < n ; i++) {
        visited[i] = false;
    }
}
*/

bool Iscycle(){
    for(int i = 0 ; i < n ; i++){
        if (indeg[i] == 0) {
            return true;
        }
    }
    return false;
}



void topologicalorder(){
    queue<int> q;

    for(int i = 0 ; i < n ; i++){
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()){
        int f = q.front();
        cout << f + 1 << "\n";
        q.pop();

        for(auto itr = adj[f].begin() ; itr != adj[f].end() ; itr++){
                indeg[*itr]--;
                if(indeg[*itr] == 0){
                    q.push(*itr);
                }
            }
    }

}

int main(){
    read_input();
    /*
    cout << "deg[i]\n";
    for(int i = 0 ; i < n ; i++) {
        cout << deg[i] << "\n";
    }

    cout << "indeg[i]\n";
    for(int i = 0 ; i < n ; i++) {
        cout << indeg[i] << "\n";
    }

    cout << "adj[i]\n";
    for(int i = 0 ; i < n ; i++) {
        for (auto itr = adj[i].begin() ; itr != adj[i].end() ; itr++){
            cout << *itr << " ";
        }
        cout << "\n";
    }
    */
    //init();

    //cout << "Check cycle\n\n";
    if (Iscycle()){
        //cout << "No cycle\n";
        //cout << "topologicalorder\n";
        topologicalorder();
    } else {
        //cout << "Detect cycle\n";
        cout << "no\n";
    }
}

/*
3 3
1 2
2 3
3 1

4 4
1 2
1 4
3 4
2 4
*/