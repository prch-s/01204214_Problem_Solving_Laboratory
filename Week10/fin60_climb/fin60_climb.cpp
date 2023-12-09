#include <iostream>

using namespace std;

const int MAX_M = 40;
const int INFINITY = 1e7;

char plan[MAX_M][MAX_M];
int dist[MAX_M][MAX_M];
int h, w;

void read_input(){
    cin >> h >> w;
    for (int i = 1 ; i <= h ; i++){
        for (int j = 1 ; j <= w ; j++){
            cin >> plan[i][j];
        }
    }
}

void init(){
    for (int i = 1 ; i <= h ; i++){
        for (int j = 1 ; j <= w ; j++){
            dist[i][j] = INFINITY;
        }
    }
}

void walk(int x, int y, int total){
    if (dist[x][y] < total)
        return;
    
    // left
    if (plan[x][y - 1] != 'X' && dist[x][y - 1] > total + 1){
        dist[x][y - 1] = min(dist[x][y - 1], total + 1);
        walk(x, y - 1, total + 1);
    }
    // right
    if (plan[x][y + 1] != 'X' && dist[x][y + 1] > total + 1){
        dist[x][y + 1] = min(dist[x][y + 1], total + 1);
        walk(x, y + 1, total + 1);
    }
    // up
    if (plan[x - 1][y] != 'X' && dist[x - 1][y] > total + 5){
        dist[x - 1][y] = min(dist[x - 1][y], total + 5);
        walk(x - 1, y, total + 5);
    }
    // down
    if (plan[x + 1][y] != 'X' && dist[x + 1][y] > total){
        dist[x + 1][y] = min(dist[x + 1][y], total);
        walk(x + 1, y, total);
    }
}

int main(){
    
    read_input();
    init();

    int result = INFINITY;
    walk(h, 1, 0);
    result = dist[1][w];

    if (result != INFINITY){
        cout << result << "\n";
    } else {
        cout << -1 << "\n";
    }
}

/*
4 5 
...X. 
...X. 
...X. 
.X...

6 4 
.... 
.... 
.... 
.... 
.... 
....

4 5 
...X. 
...X. 
...XX 
.X...

6 7 
...XXX. 
.X.X... 
.X...XX 
..X.... 
...XXX. 
.X.....
*/
