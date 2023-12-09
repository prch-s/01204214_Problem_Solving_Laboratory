#include <iostream>

using namespace std;

const int MAX = 100;

int main() {
    int x = 0,y = 0;

    char direction[MAX];
    cin >> direction;
    
    for (int i = 0 ; i < MAX ; i++) {
        
        if (direction[i] == 'Z') {
            x = 0;
            y = 0;
        } else if (direction[i] == 'N') {
            y += 1;
        } else if (direction[i] == 'S') {
            y -= 1;
        } else if (direction[i] == 'E') {
            x += 1;
        } else if (direction[i] == 'W') {
            x -= 1;
        } 
    }

    cout << x << " " << y << "\n";
    return 0;
}