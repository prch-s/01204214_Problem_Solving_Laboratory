#include <iostream>

//using namespace std;

const int MAX_S = 300;

int main() {
    int n,i;
    int size;
    int freq[MAX_S];
    int max = 0;

    std::cin >> n;
    
    for (i = 0 ; i < MAX_S ; i++){
        freq[i] = 0;
    }

    for (i = 0 ; i < n ; i++) {
        std::cin >> size;
        freq[size] += 1;
    }

    for (i = 0 ; i < MAX_S ; i++){
        if (freq[i] > max){
            max = freq[i];
        }
    }

    std::cout << max << "\n";
    return 0;
}