#include <iostream>

const int INFINITE = 1e6;
const int MAX_L = 1005;

using namespace std;
int d[MAX_L][MAX_L], a[MAX_L], n;


int main(void){
    int len;
    while(cin >> len && len){
        cin >> n;

        for(int i = 0 ; i <= len ; i++){
            for(int j = 0 ; j <= len ; j++){
                d[i][j] = INFINITE;
            }
        }

        for(int i = 1 ; i <= n ; i++){
            cin >> a[i];
        }

        a[0] = 0;
        a[n+1] = len;

        for(int i = 1 ; i <= n + 1 ; i++){
            d[a[i-1]][a[i]] = 0;
        }

        //OPT(i, j) = min (Cj - Ci) + OPT(i, k) + OPT (k, j)
        for(int l = 2 ; l <= n + 1 ; l++){
            for(int i = 0 ; i+l <= n + 1 ; i++){
                int j = i + l;
                for(int k = i+1 ; k<j ; k++){
                    if(d[a[i]][a[j]] > d[a[i]][a[k]] + d[a[k]][a[j]] + a[j] - a[i]){
                        d[a[i]][a[j]] = d[a[i]][a[k]] + d[a[k]][a[j]] + a[j] - a[i];
                    }
                }
            }
        }
        cout << "The minimum cutting is " << d[0][len] << ".\n";
    }
}

/*
100
3
25 50 75
10
4
4 5 7 8
0

*/