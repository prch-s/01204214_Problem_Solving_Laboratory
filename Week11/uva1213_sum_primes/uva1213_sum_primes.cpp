#include <iostream>

using namespace std;

const int MAX_N = 1200;
const int MAX_K = 20;

int cnt;
bool isPrime[MAX_N];
int prime[MAX_N];
int answer[MAX_N][MAX_K];

void init(){

    //reset
    for (int i = 0 ; i < MAX_N ; i++){
        isPrime[i] = true;
    }

    cnt = 0;
	isPrime[0] = false;
    isPrime[1] = false;

	for (int i = 2 ; i < MAX_N ; i++) {
		if (isPrime[i]) {
			prime[cnt++] = i;
            //cout << "i : " << i << " prime[" << cnt << "] :" << prime[cnt] << "\n ---------------- \n";
			for (int j = 2 ; i * j < MAX_N ; j++){
                isPrime[i*j] = false;
            }
		}
	}
}

void solve() {
    answer[0][0] = 1;
    for(int i = 0 ; i < cnt ; i++){
        for(int j = 1120 ; j >= prime[i] ; j--){
            for(int k = 14 ; k >= 1 ; k--){
                answer[j][k] += answer[j - prime[i]][k-1];
            }
        }
    }
}

int main() {
    init();

    // for (int i = 1 ; i <= 1120 ; i++){
    //     cout << prime[i] << "\n";
    // }

    solve();

    // for (int i = 1 ; i <= 1120 ; i++){
    //     for (int j = 1 ; j <= 14 ; j++){
    //         cout << answer[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    //cout << "answer\n";

    int x, y;
    while(true){
        cin >> x >> y;
        if(x == 0 && y == 0){
            break;
        }
        cout << answer[x][y] << "\n";
    }
    return 0;
}

/*
24 3
24 2 
2 1
1 1
4 2
18 3
17 1
17 3
17 4 
100 5 
1000 10 
1120 14 
0 0

2
3
1
0
0
2
1
0
1
55
200102899
2079324314

ref:https://github.com/morris821028/UVa/blob/master/volume012/1213%20-%20Sum%20of%20Different%20Primes.c
ref:https://blog.karatos.in/a?ID=01300-977a85ae-7405-4fcb-9e1d-f67f8290f5be
*/