#include <iostream>

using namespace std;

const int MAX_N = 200010;

int main(){
    int l, r, cnt = 0;

    cin >> l >> r;

    bool table[MAX_N];

    for (int i = 0 ; i < MAX_N ; i++){
        table[i] = true;
    }

    table[0] = false;
    table[1] = false;

    //prime start 2
    for (int i = 2 ; i <= r ; i++){
        //cout << "i : " << i << "\n";
        if (table[i]){
            if ((i-2) >= l && i <= r && table[i-2]){ //check i-2 is prime
                cnt++;
                //cout << "cnt : " << cnt << "\n";
            }
            //product of i
            for (int j = 2 ; i*j < MAX_N ; j++){
                //cout << "i*j : " << i*j << "\n";
                table[i*j] = false;
            }
        }
    }
    cout << cnt << "\n";
}