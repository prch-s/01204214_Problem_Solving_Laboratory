#include <iostream>

const int MAX_N = 1050;

using namespace std;

int main(){
    int n, l, a, b, total = 0;
    int getwell[MAX_N];

    cin >> n;

    for (int i = 1 ; i <= MAX_N ; i++){
        getwell[i] = 0;
    }

    for (int i = 1 ; i <= n ; i++){
        //cout << "day : " << i << "\n";
        cin >> l;
        if (l > 0) {
            //cout << "l : " << l << "\n";
            for (int j = 0 ; j < l ; j++){
                cin >> a >> b;
                getwell[i+b] += a;
                total += a;
            }
        }

        // for (int j = 1 ; j <= n ; j++){
        //     cout << "getwell[" << j << "] : " << getwell[j] << "\n";
        // }

        total -= getwell[i];
        cout << total << "\n";
    }
}

/*
8
2 10 2 10 5 
2 5 1 4 3 
0
1 3 10
0
0
0
0
*/