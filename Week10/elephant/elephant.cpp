#include <iostream>

const int MAX_N = 100010;

using namespace std;

int main(){
    int n;
    int banana[MAX_N];
    int maxSum[MAX_N];

    cin >> n;

    for (int i = 0 ; i < n ; i++){
        cin >> banana[i];

        //cant jump (take off 2 position)
        if (i <= 1){
            maxSum[i] = 0;
        }

        //first banana can jump
        if (i == 2){
            maxSum[i] = banana[i];
        }

        // A(i) = max( A(i-1) , P(i) + A(i-3) )
        if (i >= 3){
            //find max
            //case 1 dont pick
            if (maxSum[i-1] > banana[i] + maxSum[i-3]){
                maxSum[i] = maxSum[i-1];
            } 
            //case 2 pick
            else {
                maxSum[i] = banana[i] + maxSum[i-3];
            }
        }
    }

    // landing 1 position
    cout << maxSum[n-1];
}

/*
12
1
2
5
4
3
0
6
1
2
7
2
1
*/