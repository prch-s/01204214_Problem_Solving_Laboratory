#include <iostream>

using namespace std;

int ladder[1010];
int n, m, x, pos = 0;

int main(){
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        cin >> x;
        ladder[i] = x;
    }
    for (int i = 0 ; i < m ; i++){
        cin >> x;
        pos = pos + x + ladder[pos+x];
        if (pos < 1){
            pos = 0;
        }
        if (pos >= n){
            pos = n;
            break;
        }
    }
    cout << pos << "\n";
}

/*
5 3 
0 0 0 0 0 
3 3 2

5 2 
2 0 0 0 0 
1 1
*/