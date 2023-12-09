#include <iostream>
#include <string>

#define MAX_N 30
#define MAX_M 30

using namespace std;

char map[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int n,m;
char tmp;
bool pass = false;

void read_input()
{
    cin >> n >> m;
    
    for (int i = 0 ; i < n ; i++){
         for (int j = 0 ; j < m ; j++){
             cin >> tmp;
                map[i][j] = tmp;
         }
     }
    
    /*
    cout << "\n";
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            //cout << map[i][j] << " ";
            if (map[i][j] == '.') { cout << 1 << " "; }
            else { cout << 0 << " "; }
        }
        cout << "\n";
    }
    */
    
}

void init(){
    for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                visited[i][j] = false;
            }
        }
}

bool boxpass(int x, int y){
    //cout << x << " " << y << endl;

    if (!pass){
        if (x >= 0 || y >= 0 || x < n-1 || y < m-1){ //check in map
            if (!visited[x][y]){
                if (map[x][y] == '.' && map[x+1][y] == '.' && map[x][y+1] == '.' && map[x+1][y+1] == '.'){ //check box 2x2
                    //cout << "box can pass\n";
                    visited[x][y] = true;
                    if (x == n-2){
                        //cout << "finish\n";
                        pass = true;
                    } else {
                        //go right
                        //cout << "--- x, y+1 ---\n";
                        boxpass(x, y+1);

                        //go down
                        //cout << "--- x+1, y ---\n";
                        boxpass(x+1, y);

                        //go left
                        //cout << "--- x, y-1 ---\n";
                        boxpass(x, y-1);

                        //go up
                        //cout << "--- x-1, y ---\n";
                        boxpass(x-1, y);
                    }                
                }         
            }
        }
        return false;
    }
    return true;
}

int main(){
    read_input();
    init();

    for (int i = 0 ; i < m ; i++){
        if (boxpass(0, i)) {
            cout << "yes\n"; 
            return 0;
        } 
    }
    cout << "no\n";
}

/*
7 14
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
..........###.
####...######.
...#..##..###.

2 14
##..##...#.#..
##..##...#.#.#

7 14
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
........#####.
####...######.
...#..##..###.
*/