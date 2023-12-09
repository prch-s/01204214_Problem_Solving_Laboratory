#include <iostream>

using namespace std;

const int MAX_N = 100100;
const int MAX_K = 110;
const int INFINITY = 1e7;

int min(int a, int b){
    if (a > b){
        return b;
    } else {
        return a;
    }
}


int c, n, k;
int score[MAX_N][2*MAX_K];
int result;
int taro, tora;

int main(){
    cin >> c;
    for (int a = 0 ; a < c ; a++){
        
        cin >> n >> k;

        int start = MAX_K - k;
        int end = MAX_K + k;

        //reset
        for (int i = 0 ; i <= n ; i++){
            for (int j = start - 1 ; j <= end + 1 ; j++){
                score[i][j] = INFINITY;
            }
        }

        score[0][MAX_K] = 0;

        for(int i = 1 ; i <= n ; i++){
            cin >> taro >> tora;
            for(int j = start ; j <= end ; j++){
                score[i][j] = min(score[i-1][j+1] + taro, score[i-1][j-1] + tora);
            }
        }

        result = INFINITY;
        for(int i = start ; i <= end ; i++){
            result = min(result, score[n][i]);
        }
        cout << result << "\n";
    }
}

/*
2 
4 2 

1 2
1 2
1 2 
1 2 

4 2 

5 2 
2 5 
5 2 
2 5

----

1
1 4
2 3
3 2
4 1

*/