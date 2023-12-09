#include <iostream>
#include <vector>
#include <list>

using namespace std;

int n, m;

const int MAX_N = 100010;

pair<int, int> arr[MAX_N];

void read_input(){
	cin >> n >> m;
    for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		arr[i] = make_pair(u, v);
    }
}

bool bipartite(pair<int, int> arr[], int s){
    int visited[MAX_N];
	int team[MAX_N];
	int index = 0;
    vector<int> adj[MAX_N];

	for (int i = 0 ; i < n ; i++){
        visited[i] = 0;
        team[i] = 0;
    }

    for (int i = 0; i < s; i++){
		adj[arr[i].first].push_back(arr[i].second); 
		adj[arr[i].second].push_back(arr[i].first);
    }
    
    while (index!=n){
        if (visited[index] == 0){
            int t, x;
			list<int> Q;
            Q.push_back(index);
            while(!Q.empty()){
                x = Q.front();
                Q.pop_front();

                if (team[x] == 0){
                    t = 1;
                }
                else{
                    t = 0;
                }

                visited[x] = 1;

                for(int i = 0; i < adj[x].size(); i++){
					int a = adj[x][i];
                    if (visited[a] == 0){
                        Q.push_back(a); 
						visited[a] = 1;
                        team[a] = t;
                    }
                    else{
                        if (t != team[a]){
                            return false;
                        }
                    }
                }
            }
        }
        index++;
    }
    return true;
}

int binarySearch(pair<int, int> arr[], int left, int right){
        if (right > left) {
            int mid = (right + left) / 2;
            if (!bipartite(arr, mid)){
                return binarySearch(arr, left, mid-1);
            } else{
                return binarySearch(arr, mid+1, right);
            }     
        } else{
            if (bipartite(arr, right)){
                return right;
            } else{
                return right-1;
            }
        }
}


int main(){
	read_input();
    cout << binarySearch(arr, 0, m-1) << "\n";

    cout << 13/2;
}

/*
3 3 
1 2 
2 3 
3 1


5 7 
1 2 
2 3 
3 4 
4 1 
4 5 
5 2 
5 1

*/