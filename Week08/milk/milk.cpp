#include <iostream>
 
const int MAX_N = 100010;
 
int parents[MAX_N];
int ranks[MAX_N];
int n, m, x, y;
char order;

using namespace std;
 
void init()
{
  for (int i = 1 ; i <= n ; i++) {
    parents[i] = i;
  }
}

int find(int u)
{
  if (parents[u] != u) {
    parents[u] = find(parents[u]);
  }
  return parents[u];
  //  while(parents[u] != u) {
  //   u = parents[u];
  // }
  // return u;
}

void union_set(int pu, int pv)
{
  // int parent_pu = find(pu);
  // int parent_pv = find(pv);
  parents[pu] = pv;

  //by rank run time log n
  // if (ranks[pu] < ranks[pv]) {
  //   parents[pu] = pv;
  // } else if (ranks[pu] > ranks[pv]) {
  //   parents[pv] = pu;
  // } else {
  //   parents[pu] = pv;
  //   ranks[pv]++;
  // }
}

int main(){
    cin >> n >> m;

    init();

    // cout << "parents\n";
    // for (int i = 1 ; i <= n ; i++) {
    //     cout << parents[i] << " ";
    // }
    // cout << "\nranks\n";
    //     for (int i = 1 ; i <= n ; i++) {
    //         cout << ranks[i] << " ";
    //     }
    // cout << "\n";

    for (int i = 0 ; i < m ; i++){
      
        cin >> order >> x >> y;
        int parent_x = find(x);
        int parent_y = find(y);
        //cout << parent_x << " " << parent_y << "\n";

        if (order == 'c'){
            if (parent_x != parent_y){
              union_set(parent_x, parent_y);
            } else {
              continue;
            }
        } else if (order == 'q'){
            if (parent_x == parent_y){
                cout << "yes\n"; 
            } else {
                cout << "no\n";
            }
        }

        // cout << "parents\n";
        // for (int i = 1 ; i <= n ; i++) {
        //     cout << parents[i] << " ";
        // }
        // cout << "\nranks\n";
        // for (int i = 1 ; i <= n ; i++) {
        //     cout << ranks[i] << " ";
        // }
        // cout << "\n";
    }
}

/*
5 10 
q 1 2 
c 1 3 
q 3 2 
c 3 2 
q 1 2 
q 4 5 
c 4 2 
q 4 1 
c 1 4 
q 5 1

5 10
c 1 3
c 3 2
c 4 2
c 1 4
*/