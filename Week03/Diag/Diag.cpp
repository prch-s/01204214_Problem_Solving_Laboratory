#include <iostream>
#include <algorithm>

const int MAX_N = 100010;

using namespace std;

long mx, my, sumx = 0, sumy = 0;
int n, x[MAX_N], y[MAX_N];

long abs(long x, long y){
    long answer = x - y;
    if (answer > 0){
        return answer;
    } else {
        return -answer;
    }
}

void read_input(){

    cin >> n;

    for (int i = 0 ; i < n ; i++){
        long a, b;
        cin >> a >> b;
        x[i] = a - b;
        y[i] = a + b;
    }

    sort(x, x + n);
    sort(y, y + n);
}

int main(){

    read_input();

    if (n % 2) { //n is Odd
        //cout << "Odd\n";
        mx = x[((n + 1) / 2) - 1 ];
        my = y[((n + 1) / 2) - 1 ];
    } else { //n is Even
        //cout << "Even\n";
        mx = (x[(n / 2) - 1] + x[(n / 2)]) / 2;
        my = (y[(n / 2) - 1] + y[(n / 2)]) / 2;
    }

    //cout << "mx : " << mx << " , my : " << my << "\n";
    for (int i = 0 ; i < n ; i++){
        //cout << x[i] << " " << y[i] << "\n";
        sumx += abs(mx, x[i]);
        sumy += abs(my, y[i]);
    }

    cout << sumx + sumy << "\n";
}

/*
4
1 1
5 5
6 6
3 3

6
1 1
2 3
4 4
5 3
4 1
7 3

5
1 1
2 3
4 4
5 3
4 1
*/

