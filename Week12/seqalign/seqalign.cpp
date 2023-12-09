#include <iostream>
#include <string>
#include <algorithm> 
 
using namespace std;

const int MAX_N = 1000;

void read_input(){
    
}
 
void SequenceAlignment(string x, string y, int pm, int pgap){
     
    int m = x.length();
    int n = y.length();

    int dp[MAX_N][MAX_N];

    //make matrix
    for (int i = 0 ; i <= m ; i++){
        for (int j = 0 ; j <= n ; j++){
            dp[i][j] = 0;
        }
    }
    
    //make boundary
    for (int i = 0; i <= n+m ; i++){
        dp[i][0] = i * pgap;
        dp[0][i] = i * pgap;
    }   

    for (int i = 1 ; i <= m ; i++){
        for (int j = 1 ; j <= n ; j++){
            if (x[i - 1] == y[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = min({dp[i - 1][j - 1] + pm, dp[i - 1][j] + pgap, dp[i][j - 1] + pgap});
            }
        }
    }

    cout << dp[m][n] << "\n";
    return;
}
 
int main(){

    string text1, text2;
    cin >> text1 >> text2;

    int missmatch = 1;
    int gap = 1;
 
    SequenceAlignment(text1, text2, missmatch, gap);
    
    return 0;
}

/*
AAABBBCCC
ZBBCCD

ABCDEFGH
AABEEGHFI

ref:https://www.geeksforgeeks.org/sequence-alignment-problem/
*/