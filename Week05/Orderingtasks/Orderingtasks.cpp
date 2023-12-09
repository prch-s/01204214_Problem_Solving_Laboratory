#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 110;

int main(){
    while(true){
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0){
            break;
        }

        int indeg[MAX_N];
        for (int i = 0 ; i < n ; i++){
            indeg[i] = 0;
        }

        vector<int> adj[MAX_N];
        int u, v;
        for (int i = 0 ; i < m ; i++){
            cin >> u >> v;
            u--; v--; // start 0
            adj[u].push_back(v);
            indeg[v]++;
        }

        //topo
        queue<int> q;

        for(int i = 0 ; i < n ; i++){
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()){
            int f = q.front();
            cout << f +1 << " ";
            q.pop();

            for(auto itr = adj[f].begin() ; itr != adj[f].end() ; itr++){
                indeg[*itr]--;
                if(indeg[*itr] == 0){
                    q.push(*itr);
                }
            }
        }
        cout << "\n";
    }
}

/*
5 4
1 2
2 3
1 3
1 5
*/