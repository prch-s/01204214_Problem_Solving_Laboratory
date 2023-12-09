#include <iostream>

using namespace std;

const int MAX_N = 100010;
const int INFINITY = 1e6;

int n;
int input[MAX_N];
int solve[MAX_N];

int min(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}

int max(int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> input[i];
    }

    //basecase
    solve[0] = 0;
    solve[1] = INFINITY;
    solve[2] = max(input[0], input[1]) - min(input[0], input[1]);
    
    for (int i = 2 ; i < n ; i++){
        int cost = INFINITY;
        int size = max(0, i - 10 + 1);
        for (int j = i - 1 ; j >= size ; j--){
            int mn = INFINITY;
            int mx = -INFINITY;
            for (int k = j ; k <= i ; k++){
                mn = min(mn, input[k]);
            }
            for (int k = j ; k <= i ; k++){
                mx = max(mx, input[k]);
            }
            cost = min(cost, solve[j] + mx - mn);
        }
        solve[i + 1] = cost;
    }

    cout << solve[n] << "\n";
}


/*
10
9 10 3 5 4 3 4 8 8 9

15
2 1 1 1 1 1 1 1 1 1 1 2 6 6 6

score: 75 [ PP[PP]PPP-[---] ] 
*/