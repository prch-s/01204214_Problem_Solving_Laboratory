#include <iostream>

using namespace std;

int x, year;
bool event[3000]; //false
bool host = true;  //K

int main(){
    cin >> x;
    while(true){
        cin >> year;
        if (year == 0){
            break;
        }
        event[year-2558] = true;
    }
    for (int i = 1 ; i <= x-2558 ; i++){
        if(!event[i]){
            host = !host;
        }
    }
    if (host) {
        cout << "K\n";
    } else {
        cout << "C\n";
    }
}

/*
2565
2559 2562 0

2560 
0
*/