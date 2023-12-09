#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_N = 100100;

int n, m;
set<pair<int, pair<int, int>>> adj;

int parents[MAX_N];
int ranks[MAX_N];

void init_union_find(){
  for (int i = 1 ; i <= n ; i++) {
    parents[i] = i;
    ranks[i] = 0;
  }
}

int find(int u){
    if (parents[u] == u){
        return u;
    }
    return parents[u] = find(parents[u]);
}

void union_set(int pu, int pv){
    if (pu == pv){
        return;
    }
  if (ranks[pu] < ranks[pv]) {
    parents[pu] = pv;
  } else if (ranks[pv] < ranks[pu]) {
    parents[pv] = pu;
  } else {
    parents[pv] = pu;
    ranks[pv]++;
  }
}

void kruskal(){
    int result = 0;
    init_union_find();
    for (auto it = adj.begin() ; it != adj.end() ; it++){
        int w = (*it).first;
        int pu = find((*it).second.first);
		int pv = find((*it).second.second);

        if (pu != pv){
            union_set(pu, pv);
            result += w;
        }
    }
    for (int k = 2 ; k <= n ; k++){
		if (find(1) != find(k)){
			result = -1;
			break;
		}
	}
    cout << result << "\n";
}

int main(){
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj.insert({w, {u, v}});
        kruskal();
    }
}

/*
4 6
1 2 10
1 3 8
3 2 3
1 4 3
1 3 6
2 1 8
*/