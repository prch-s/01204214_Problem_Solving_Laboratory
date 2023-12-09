#include <iostream>

//using namespace std;

int main() {
    int number;
    int answer = 0;
    
    for (int i = 0 ; i < 4 ; i++) {
        std::cin >> number;
        answer += number;
    }

    std::cout << answer << "\n";
    return 0;
}