#include <iostream>

using namespace std;

const int MAX_T = 300;
const int INFINITY = 1e6;

int n, m, k;
int table[MAX_T][MAX_T];
int dp[MAX_T][MAX_T][MAX_T];

void read_input(){
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            cin >> table[i][j];
        }
    }
}

int max(int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}

int solve(int x, int y, int k){
    if (x == n + 1 || y == 0 || y == m + 1){
        return 0;
    }
    if (dp[x][y][k] != 0)
        return dp[x][y][k];
    if (k > 0){
        return dp[x][y][k] = max(table[x][y] + solve(x + 1, y - 1, k - 1), max(table[x][y] + solve(x + 1, y, k),table[x][y] + solve(x + 1, y + 1, k - 1)));
    }else{
        return dp[x][y][k] = table[x][y] + solve(x + 1, y, k);
    }    
}

int main(){
    read_input();
    int result = -INFINITY;
    for(int i = 1 ; i <= m ; i++){
        result = max(solve(1, i, k), result);
    }
    cout << result << "\n";
}


/*
4 5 0 
3 6 7 3 1 
7 100 3 2 5 
10 2 1 1 6 
20 3 1 50 3

4 5 1 
3 6 7 3 1 
7 100 3 2 5 
10 2 1 1 6 
20 3 1 50 3

4 5 2  
3 6 7 3 1 
7 100 3 2 5 
10 2 1 1 6 
20 3 1 50 3

4 5 3 
3 6 7 3 1 
7 100 3 2 5 
10 2 1 1 6 
20 3 1 50 3
*/