#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define MAX_N 30
#define MAX_M 30

char map[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int deg[MAX_N][MAX_M];
int n,m;
char tmp;
vector<pair<int,int>> adj[MAX_N][MAX_N];
bool forest = false, mineral = false;
int cnt = 0, quality_s = 0, quality_m = 0;

void read_input()
{
    cin >> n >> m;
    
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            cin >> tmp;
            map[i][j] = tmp;
        }
    }
}

void init(){
    for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                visited[i][j] = false;
                deg[i][j] = 0;
            }
        }
}

//make graph and count edge
void makeGraph(){
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cout << "(" << i << "," << j << ") : " << map[i][j] << "\n";
            if(map[i][j] != '#'){
                //go down
                if (i+1 < n && map[i+1][j] != '#') { 
                    adj[i][j].push_back(make_pair(i+1,j));
                    deg[i][j]++;
                }
                //go right
                if (j+1 < m && map[i][j+1] != '#') {
                    adj[i][j].push_back(make_pair(i,j+1));
                    deg[i][j]++;
                }
                //go up
                if(i-1 >= 0 && map[i-1][j] != '#') {
                    adj[i][j].push_back(make_pair(i-1,j));
                    deg[i][j]++;
                }
                //go left
                if (j-1 >= 0 && map[i][j-1] != '#') {
                    adj[i][j].push_back(make_pair(i,j-1));
                    deg[i][j]++;
                }
                
            }
        }
    }
}

void dfs(int x, int y){
    //cout << "x : " << x << " y : " << y << "\n";
    visited[x][y] = true;
    
    //find $ * # .
    if (map[x][y] != '#'){
        cnt++;
        //cout << cnt << "\n";
    }
    if (map[x][y] == '$') {
        //cout << "mineral\n";
        mineral = true;
    }
    if (map[x][y] == '*') {
        //cout << "forest\n";
        forest = true;
    }

    for(int i = 0 ; i < deg[x][y] ; i++){
        //cout << "--------------------" << "\n";
        pair<int, int> p = adj[x][y][i];
        if (!visited[p.first][p.second]){
            //cout << "/////////////////////" << "\n";
            dfs(p.first,p.second);
        }
    }
}

void showvector(vector<pair<int,int>> adj[MAX_N][MAX_N])
{
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cout << "node "<< i << " "<< j << "\n";
            for (auto itr = adj[i][j].begin() ; itr != adj[i][j].end() ; itr++){
                cout << (*itr).first << " " << (*itr).second << "\n";
            }
        }
        cout << "\n";
    }
}

int main(){
    read_input();
    init();
    makeGraph();

    /*
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << deg[i][j] << " ";
        }
        cout << "\n";
    }

    showvector(adj);
    */

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!visited[i][j]){
                //cout << "---main---\n";
                dfs(i,j);
            }
            if (mineral && forest){
                quality_s += cnt;
            }
            else if (mineral || forest){
                quality_m += cnt;
            }
            //cout << quality_s << " " << quality_m << "\n";
            cnt = 0;
            mineral = false;
            forest = false;
        }
    }
    cout << quality_s << " " << quality_m << "\n";
}

/*
7 8
.*..#...
....#...
.$.#..*#
..#..##.
.#.##...
#....###
..$.....
*/