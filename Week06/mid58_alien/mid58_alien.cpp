#include <iostream>

using namespace std;

int main(){

    int n, a, b, r, x, y, cnt = 0;

    cin >> n >> a >> b >> r;

    for (int i = 0 ; i < n ; i++){
        cin >> x >> y;
        int tmp = ((x - a)*(x - a)) + ((y - b)*(y - b));
        if (tmp <= r*r){
            cnt++;
        }
    }
    cout << cnt << "\n";
}

/*
5 0 0 5 
0 0
10 10 
0 5
3 4 
4 4
 */