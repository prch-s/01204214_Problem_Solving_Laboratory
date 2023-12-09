#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100010;
const int MAX_M = 200010;

int n, m;
vector<int> adj[MAX_N];
int deg[MAX_N];

int edges[MAX_M][2];
int weight[MAX_M];
pair<int, int> witems[MAX_M];

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

        deg[u]++;
        deg[v]++;

        edges[i][0] = u;
        edges[i][1] = v;
        weight[i] = w;

        witems[i].first = w;
        witems[i].second = i; 
    }
}

int parents[MAX_N];
int ranks[MAX_N];

void init_union_find()
{
  for (int i = 0 ; i < n ; i++) {
    parents[i] = i;
    ranks[i] = 0;
  }
}

int find(int u)
{
  while(parents[u] != u) {
    u = parents[u];
  }
  return u;
}

void union_set(int pu, int pv)
{
  if (ranks[pu] < ranks[pv]) {
    parents[pu] = pv;
  } else if (ranks[pv] < ranks[pu]) {
    parents[pv] = pu;
  } else {
    parents[pu] = pv;
    ranks[pv]++;
  }
}

int kruskal(){
    int result = 0;

    init_union_find();

    //sort
    sort(witems, witems + m);

    for (int i = 0 ; i < m ; i++){
        int w = witems[i].first; //weight
        int e = witems[i].second; //edges

        int u = edges[e][0];
        int v = edges[e][1];

        int pu = find(u);
        int pv = find(v);

        if (pu != pv){
            //use edge e in the MST
            union_set(pu, pv);
            result += w;
        }
    }
    return result;
}

int main(){
    read_input();
    int result = kruskal();
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