#include <iostream>

const int MAX_N = 200010;

using namespace std;

int food[MAX_N];
int round[MAX_N];
int n;
int cnt[MAX_N];
int maxcnt = 0;

int main(){
    cin >> n;

    
    for (int i = 1 ; i <= n ; i++){
        cin >> food[i];
        round[i] = 0;
        cnt[i] = 0;
    }
    for (int i = 1 ; i <= n ; i++){
        int tmp = food[i] - i;
        if (tmp < 0){
            round[i] = round[i] + tmp + n;
        } else {
            round[i] += tmp; 
        }
    }

    //  for (int i = 1 ; i <= n ; i++){
    //      cout << round[i] << " ";
    //  }

    // cout << "\n";

    for (int i = 1 ; i <= n ; i++){
        cnt[round[i]]++;
    }

    // for (int i = 1 ; i <= n ; i++){
    //      cout << cnt[i] << " ";
    // }

    for (int i = 1 ; i <= n ; i++){
         if (cnt[i] > maxcnt){
             maxcnt = cnt[i];
         }
    }
    
    //cout << "\n";
    cout << maxcnt << "\n";

}

/*
5 
4 5 2 3 1

10
3 4 5 6 7 8 9 10 1 2

10
3 7 8 5 4 9 6 10 1 2
*/