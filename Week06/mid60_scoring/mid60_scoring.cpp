#include <iostream>

using namespace std;

const int MAX_N = 150;

int main(){
    int n, m, no, score, sum = 0; 
    int cnt[MAX_N], preScore[MAX_N];

    cin >> n >> m;

    for (int i = 1 ; i <= n ; i++){
        cnt[i] = 0;
        preScore[i] = 0;
    }

    for (int i = 1 ; i <= m ; i++){
        cin >> no >> score;
        cnt[no]++;
        if (cnt[no] > 5){
            preScore[no] = 0;
        } else {
            if (score > preScore[no]){
                preScore[no] = score;
            }
        }
    }

    for (int i = 1 ; i <= n ; i++){
        sum += preScore[i];
    }

    cout << sum << "\n";
}
/*
3 10 
1 9 
2 8 
1 3 
1 4 
3 8 
3 7 
1 1 
1 9 
1 10 
2 9

5 6 
1 1 
2 2 
3 3 
4 10 
4 5 
3 5
*/