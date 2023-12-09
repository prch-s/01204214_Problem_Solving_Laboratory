#include <iostream>
#include <vector>
#include <map>

const int MAX_N = 100010;
const int INFINITY = 1000000000; //1000*100000 (W*N)

using namespace std;

vector<int> adj[MAX_N];
vector<int> expressway[MAX_N];
vector<int> length[MAX_N]; //weight
int dist[MAX_N][2];

int n, m;
int result;

int min(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}

void read_input(){
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
        //cout << i << "\n";
        int u, v, w, s;
        cin >> u >> v >> w >> s;

        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);

        expressway[u].push_back(s);
        expressway[v].push_back(s);

        length[u].push_back(w);
        length[v].push_back(w);
    }
}

map <pair<int, int>, int> setds; // (weight,index,express)

void dijkstra(int s){
    
    for (int i = 0 ; i < n ; i++){
        dist[i][0] = INFINITY;
        dist[i][1] = INFINITY;
    }

    dist[s][0] = 0;
    dist[s][1] = 0;

    setds.insert(pair<pair<int, int>, int> (pair<int, int>(dist[s][0], s), 0));

    while (!setds.empty()){
        auto tmp = *(setds.begin());
        setds.erase(setds.begin());

        int best_u = tmp.first.second; //now node
        int now_status = tmp.second; //now express

        int deg = adj[best_u].size();
        // cout << "deg : " << deg << "\n";
        // cout << "Now node : " << best_u << " , Now status : " << now_status << "\n";

        for (int i = 0 ; i < deg ; i++){

            int v = adj[best_u][i]; //node
            int len = length[best_u][i]; //weight
            int status = expressway[best_u][i]; //express

            if (now_status == 1 && status == 1){
				continue;
			}
			if (now_status == 1 && status == 0){
                if (dist[best_u][now_status] + len < dist[v][now_status]){
                    dist[v][now_status] = dist[best_u][now_status] + len;
                    setds.insert(pair<pair<int, int>, int> (pair<int, int>(dist[v][now_status], v), now_status));
                }
            } else if (now_status == 0 && (status == 1 || status == 0)){
				if (dist[best_u][now_status] + len < dist[v][status]){
					dist[v][status] = dist[best_u][now_status] + len;
                    setds.insert(pair<pair<int, int>, int> (pair<int, int>(dist[v][status], v), status));
				}
			}
        }
    }
}

int main(){
    read_input();

    //cout << "dijkstra\n";

    dijkstra(0);

    // cout << "dist[i][0]\n";
    // for (int i = 0 ; i < n ; i++){
    //     cout <<  dist[i][0] << " " <<  dist[i][1] << "\n";
    // }

    result = INFINITY;
    for(int i = 0 ; i <= 1 ; i++){
		result = min(result, dist[n-1][i]);
	}

	if (result == INFINITY){
		cout << "-1" << "\n";
	}else{
		cout << result << "\n";
	}
}

/*
5 6
1 2 10 0 
2 3 10 0 
1 3 5 1 
3 4 10 0 
4 5 10 0 
3 5 4 1

5 4
1 2 10 0 
2 3 10 1 
3 4 10 0 
4 5 10 1
*/