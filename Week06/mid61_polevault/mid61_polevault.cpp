#include <iostream>

using namespace std;

const int MAX_N = 1e9;

int main(){
    int n, q, x;
    int pole[MAX_N];
    bool stick[MAX_N];

    cout << "hello\n";
    cin >> n >> q;

    cout << n << q << "\n";

    for (int i = 0 ; i < n ; i++){
        cout << "hello\n";
        cin.ignore(1, ' ') >> x;
        pole[i] = x;
    }
    cout << "hello\n";
    
    for (int i = 0 ; i < MAX_N ; i++){
        stick[i] = false;
    }

    for (int i = 0 ; i < n ; i++){
        x = pole[i];
        stick[i] = true;
        cout << x << "\n";
        for (int j = i ; j < n ; j++){
            x += pole[j];
            stick[i] = true;
            cout << x << "\n";
        }
    }
}

/*
5 4
2 2 1 2 2
2 4 6 2

4 10
1 3 1 4
1 2 3 4 5 6 7 8 9 10
*/