#include <iostream>
#include <string.h>

using namespace std;

const int MAX_N = 25;

int main(){
    char temp[MAX_N];
    char a[5000][MAX_N];
    int size;
    int i, j, k = 0;
    int alpha[26];

    for (i = 0 ; i <= 26 ; i++){
        alpha[i] = 0;
    }

    while (cin >> temp){

        if (temp[0] == '#'){
            break;
        }

        size = strlen(temp);

        for (i = 0 ; i < size ; i++){
            a[k][i] = temp[i];
        }

        for (i = 0 ; i < size ; i++){
            cout << a[k][i] << " ";
        }
        cout << "\n";

        while (i != MAX_N){
            //a = 97
            a[k][i++] = 'a';
        }

        
        for (i = 0 ; i < size ; i++){
            cout << a[k][i] << " ";
        }
        cout << "\n";

        k++;
    }

    // for (i = 0 ; i < MAX_N ; i++){
    //     for (j = 0 ; j < k ; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (i = 0 ; i < MAX_N ; i++){
        for (j = 0 ; j < k ; j++){
            //A = 65 Z = 90
            if ( a[j][i] > 64 && a[j][i] < 91){
                alpha[a[j][i] - 65]++;
            }
            if (alpha[a[j][i] - 65] == 1){
                cout << a[j][i];
            }
        }
    }
    cout << "\n";
}

/*
XWY
ZX
ZXY
ZXW
YWWX
#

ref:https://tausiq.wordpress.com/2009/02/11/uva-200-rare-order/
ref:https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%20200%20-%20Rare%20Order/src/UVa%20200%20-%20Rare%20Order.cpp
*/