#include <iostream>
#include <vector>

const int MAX_N = 1050;

using namespace std;

int n;
int input[MAX_N];

void read_input(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> input[i];
    }
}

void printArray(){
    for (int i = 0 ; i < n ; i++){
        if (i == n-1) {
            cout << input[i] << "\n";
        } else {cout << input[i] << " ";
        }
    }
}

void findLST(int input[]){
    vector<int> LIS[MAX_N];

    LIS[0].push_back(input[0]);

    for (int i = 1 ; i < n ; i++){
        for (int j = 0 ; j < i ; j++){
            if (input[j] < input[i] && LIS[j].size() > LIS[i].size()) {
                LIS[i] = LIS[j];
            }
        }
        LIS[i].push_back(input[i]);
    }

    int j = 0;
    for (int i = 0; i < n; i++){
        if (LIS[j].size() < LIS[i].size()) {
            j = i;
        }
    }
    
    cout << LIS[j].size() << "\n";
    for (int i: LIS[j]) {
        cout << i << " ";
    }
}

int main(){
    read_input();
    //printArray();
    findLST(input);
}

/*
5 1 2 2 3 4

5 1 -1 2 -2 3

5 5 4 3 2 1

5 1 1 1 1 1

ref : https://www.techiedelight.com/longest-increasing-subsequence-using-dynamic-programming/
*/