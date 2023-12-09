#include <iostream>

using namespace std;

int min(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}

int main(){
    int n;
    cin >> n;

    int yesterday = 0;
    int today;
    int energy = 0;

    for (int i = 0 ; i < n ; i++){
        cin >> today;
        if (yesterday - today > 10){
            energy += min(700, (yesterday - today) * 10 );
        }
        yesterday = today;
    }
    
    cout << energy << "\n";
}

/*
9
10
30
15
17
10
20
8
100
4
*/