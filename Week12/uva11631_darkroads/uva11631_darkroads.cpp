#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_M = 200010;

int n, m, x, y, z;
vector<int> adj[MAX_M];
int deg[MAX_M];

int edges[MAX_M][2];
int weight[MAX_M];
pair<int, int> witems[MAX_M];

int sum;

//mst2

void read_input(){

    //reset
    for (int i = 0 ; i < n ; i++){
        deg[i] = 0;
    }
    
    sum = 0;
    for (int i = 0 ; i < m ; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(v);
        adj[v].push_back(u);

        deg[u]++;
        deg[v]++;

        edges[i][0] = u;
        edges[i][1] = v;
        weight[i] = w;

        witems[i].first = w;
        witems[i].second = i; 

        sum += w;
    }
}

int parents[MAX_M];
int ranks[MAX_M];

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

    while((cin >> n >> m) && (n != 0 || m!= 0)){
        read_input();
        int min = kruskal();
        cout << sum - min << "\n";
    }
}

/*
7 11 
0 1 7 
0 3 5 
1 2 8 
1 3 9 
1 4 7 
2 4 5 
3 4 15 
3 5 6 
4 5 8 
4 6 9 
5 6 11

4 5
0 1 10
0 2 20
2 3 5
3 1 7
1 2 12

0 0
*/

/*
51
32
*/