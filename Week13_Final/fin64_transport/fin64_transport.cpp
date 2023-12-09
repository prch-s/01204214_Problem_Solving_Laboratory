#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>
#include <cstdio>

using namespace std;

const int MAX_N = 550;
const int MAX_M = 250010; //500*500

int n, x, y;
pair<int, int> point[MAX_N]; // x, y
pair<double, int> witems[MAX_M];
vector<int> adj[MAX_N];
int deg[MAX_N];
int edges[MAX_M][2];
double weight[MAX_N][MAX_N];
int parents[MAX_N];
int ranks[MAX_N];
int cnt;

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

double kruskal(){
    double result = 0;
    double max = -1;

    init_union_find();

    //sort
    sort(witems, witems + cnt);

    for (int i = 0 ; i < cnt ; i++){
        double w = witems[i].first; //weight
        int e = witems[i].second; //edges

        int u = edges[e][0];
        int v = edges[e][1];

        int pu = find(u);
        int pv = find(v);

        if (pu != pv){
            //use edge e in the MST
            union_set(pu, pv);
            result += w;
            if(w > max){
                max = w;
            }
        }
    }
    // << max << "\n";
    return result - max;
}

int main(){

    cin >> n;

    for (int i = 0 ; i < n ; i++){
        cin >> point[i].first >> point[i].second;
        //point[i].make_pair(x,y);
    }

    cnt = 0;
    for (int u = 0 ; u < n ; u++){
        for (int v = 0 ; v < n ; v++){

            adj[u].push_back(v);
            adj[v].push_back(u);

            deg[u]++;
            deg[v]++;

            edges[cnt][0] = u;
            edges[cnt][1] = v;

            double w = sqrt( pow((point[u].first - point[v].first), 2) + pow((point[u].second - point[v].second), 2));
            witems[cnt].first = w;
            witems[cnt].second = cnt;

            cnt++; 
        }
    }

    double answer = kruskal();

    printf("%.5f", answer);

}

/*
7 
2 2 
8 2 
9 3 
4 3 
10 1 
3 5 
4 4
*/
