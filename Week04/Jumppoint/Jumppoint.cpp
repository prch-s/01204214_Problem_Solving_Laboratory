#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define MAX_N 1010

int n,r;
vector<int> adj[MAX_N];
int deg[MAX_N];
bool visited[MAX_N];
int level[MAX_N];
pair<int, int> point[MAX_N];

void read_input(){

    cin >> n >> r;

    int x,y;

    point[0] = make_pair(0,0); //start
    point[n+1] = make_pair(100,100); //top

    for (int i = 1 ; i < n+1 ; i++){
        cin >> x >> y;
        point[i] = make_pair(x,y); //tree
    }
}

void init()
{
    for(int i = 0 ; i < n+2 ; i++) { // start(1) + tree(n) + top(1)
        //cout << "node " << i << " : (" << point[i].first << ","<< point[i].second << ")\n";
        visited[i] = false;
        level[i] = -1;
        deg[i] = 0;
    }
}

void makeGraph(){
    for (int i = 0 ; i < n+2 ; i++){
        for (int j = i+1 ; j < n+2 ; j++){
            int distance_x = point[i].first - point[j].first;
            int distance_y = point[i].second - point[j].second;
            int distance = (distance_x*distance_x) + (distance_y*distance_y);
            if (distance <= r*r) {
                adj[i].push_back(j);
                deg[i]++;
                adj[j].push_back(i);
                deg[j]++;
            }
        }
    }
}

void bfs(int s)
{
    list<int> Q;

    Q.push_back(s);
    visited[s] = true;
    level[s] = 0;
  
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        //cout << "node " << u << " level " << level[u] << "\n";
        for(int i = 0 ; i < deg[u]; i++) {
            int v = adj[u][i];
            if(!visited[v]) {
	            Q.push_back(v);
	            visited[v] = true;
	            level[v] = level[u] + 1;
            }
        }
    }
}


void showvector(vector<int> v[MAX_N])
{
   for (int i = 0 ; i < n+2 ; i++){
       cout << "node "<< i << " : ";
        for (auto itr = v[i].begin() ; itr != v[i].end() ; itr++)
        {
           cout << *itr << " ";
        }
        cout << "\n";
   }
}

int main(){
    read_input();
    init();
    makeGraph();
    //showvector(adj);
    bfs(0);

    /*
    for (int i = 0 ; i < n+2 ; i++){
        cout << "node " << i << " level " << level[i] << "\n";
    }
    */

   if (level[n+1] != -1) { //level top
       cout << level[n+1] << "\n";
   } else {
       cout << -1 << "\n";
   }

}

/*
5 60
50 0
100 0
100 50
50 30
70 50
*/