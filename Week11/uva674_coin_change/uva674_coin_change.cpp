#include <iostream>

using namespace std;

const int MAX_C = 7500;

int answer[MAX_C];
int coins[4] = {5, 10, 25, 50};
int n;

int main(){
    for(int i = 0 ; i < 5 ; i++){
        answer[i] = 1;
    }
    for(int i = 5 ; i < MAX_C ; i++){
        answer[i] = answer[i - 1];
    }
    for(int i = 0 ; i < 4 ; i++){
        for(int j = coins[i] ; j < MAX_C ; j++){
            answer[j] += answer[j - coins[i]];
        }
    }

    while(cin >> n && n != EOF){
        cout << answer[n] << "\n";
    }
}

/*
11

26

ref:https://quickgrid.wordpress.com/2015/03/27/uva-problem-674-coin-change-solution/
*/