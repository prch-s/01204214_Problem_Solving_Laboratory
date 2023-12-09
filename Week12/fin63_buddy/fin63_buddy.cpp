#include <iostream>

using namespace std;

const int MAX_N = 100010;

int input[MAX_N];
bool visited[MAX_N];
int n;

int main(){
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> input[i];
    }
    int result = 0;
    for (int i = 1 ; i <= n ; i++){
        if (visited[i]) {
            continue;
        }
        result++;
        int index = i;
        while (!visited[index]){
            visited[index] = true;
            index = input[index];
        }
    }
    cout << result << "\n";
}

/*
8
2 4 6 8 1 3 5 7

8
1 3 5 7 2 4 6 8

8
8 7 6 5 4 3 2 1

5
2 3 4 5 1
*/