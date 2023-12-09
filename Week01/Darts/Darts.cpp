#include <iostream>
#include <math.h>

//using namespace std;

int main() {
    double x,y;
    double d;
    int n;
    int score = 0;

    std::cin >> n;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> x;
        std::cin >> y;
        d = sqrt( pow(x, 2) + pow(y, 2) );
        if (d >= 0 && d <= 2) {
            score += 5;
        } else if (d > 2 && d <= 4) {
            score += 4;
        } else if (d > 4 && d <= 6) {
            score += 3;
        } else if (d > 6 && d <= 8) {
            score += 2;
        } else if (d > 8 && d <= 10) {
            score += 1;
        }
    }
    std::cout << score << "\n";
    return 0;
}