#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100010;

int n, m, k;
int parents[MAX_N];
int ranks[MAX_N];
int result = 0;

vector<pair<pair<int, int>, int>> concrete;
vector<pair<pair<int, int>, int>> marble;
vector<pair<pair<int, int>, int>> solve;


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

int main(){
    cin >> n >> m >> k;

    init_union_find();

    for (int i = 1 ; i <= m ; i++){
        int u, v, s;
        cin >> u >> v >> s;
        if (s == 1){
            concrete.push_back({{u, v}, s});
            union_set(find(u), find(v));
        }else{
            marble.push_back({{u, v}, s});
        }
    }

    for (auto it = marble.begin() ; it != marble.end() ; it++){
        int u = (*it).first.first;
        int v = (*it).first.second;
        int s = (*it).second;
        if (find(u) != find(v)){
            solve.push_back({{u, v}, s});
            union_set(find(u), find(v));
            marble.erase(it);
            result++;
        }
    }

    if (k > m || result > k){
        cout << "no solution\n";
        return 0;
    }

    int p = find(1);
    for (int i = 1; i <= n; i++){
        if (find(i) != p || k > m || result > k){
            cout << "no solution\n";
            return 0;
        }
    }

    init_union_find();

    for (auto it = solve.begin() ; it != solve.end() ; it++){
        int u = (*it).first.first;
        int v = (*it).first.second;
        union_set(find(u), find(v));
    }

    int cnt = 0;
    while (result != k){
        if (cnt == marble.size()){
            cout << "no solution\n";
            return 0;
        }
        int u = marble[cnt].first.first;
        int v = marble[cnt].first.second;
        int s = marble[cnt].second;

        if (find(u) != find(v)){
            solve.push_back({{u, v}, s});
            union_set(find(u), find(v));
            result++;
        }
        cnt++;
    }
    
    cnt = 0;
    while (result != n - 1){
        int u = concrete[cnt].first.first;
        int v = concrete[cnt].first.second;
        int s = concrete[cnt].second;

        if (find(u) != find(v)){
            solve.push_back({{u, v}, s});
            union_set(find(u), find(v));
            result++;
        }
        cnt++;
    }

    for (auto it = solve.begin() ; it != solve.end() ; it++){
        cout << (*it).first.first << " " << (*it).first.second << " " << (*it).second << "\n";
    }
}

/*
5 7 2 
1 3 0
4 5 1  
3 2 0  
5 3 1
4 3 0 
1 2 1 
4 2 1

score: 72 [ xPP-PPP-PPP ] 
*/

