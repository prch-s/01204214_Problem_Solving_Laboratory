#include <iostream>

const int MAX_N = 30;

using namespace std;

int map[MAX_N][MAX_N];
bool jump[MAX_N][MAX_N];
int n,k;
bool flag = false;

void bfs(int x, int y){
    if (!jump[x][y]){
        jump[x][y] = true;
        int curr = map[x][y];
        //finish
        if (x == n-1 && y == n-1){
            flag = true;
        }

        //go down
        if (x+1 < n && map[x+1][y] - curr <= k) { 
            bfs(x+1,y);
        }
        //go right
        if (y+1 < n && map[x][y+1] - curr <= k) {
            bfs(x,y+1);
        }
        //go up
        if (x-1 >= 0 && map[x-1][y] - curr <= k) {
            bfs(x-1,y);
        }
        //go left
        if (y-1 >= 0 && map[x][y-1] - curr <= k) {
            bfs(x,y-1);
        }
    }
}

int main(){
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cin >> map[i][j];
            jump[i][j] = false;
        }
    }

    // for (int i = 0 ; i < n ; i++){
    //     for (int j = 0 ; j < n ; j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    bfs(0,0);

    if (flag){
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

/*
4 30
10 15 45 20
20 6 46 13
50 36 12 72
40 40 24 4

4 20
10 15 45 20
20 6 46 13
50 36 12 72
40 40 24 4
*/