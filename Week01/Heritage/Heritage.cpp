#include <iostream>

//using namespace std;

int main() {
    int number;
    int answer = 0;
    int n;

    std::cin >> n;

    for (int i = 0 ; i < n ; i++) {
        std::cin >> number;
        if (number >= 0) {
            answer += number;
        }
    }

    std::cout << answer << "\n";
    return 0;
}