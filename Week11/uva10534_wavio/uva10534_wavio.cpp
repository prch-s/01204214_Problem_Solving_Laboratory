#include <iostream>
#include <vector>

const int MAX_N = 10010;

using namespace std;

int min(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}

int max(int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}

int main(){
    int n;

    int input[MAX_N], LIS[MAX_N], LDS[MAX_N];
    vector<int> wavio;

    while (cin >> n && n != EOF){
        int count, temp;

        //cin >> n;

        for (int i = 0 ; i < n ; i++){
            cin >> input[i];
        }

        //LIS
        wavio.clear();

        count = 1;
        wavio.push_back(input[0]);
        LIS[0] = 1;

        for (int i = 0 ; i < n ; i++){
            if (input[i] > wavio.back()){
                wavio.push_back(input[i]);
                count++;
                LIS[i] = count;
            } else {
                temp = lower_bound(wavio.begin(), wavio.end(), input[i]) - wavio.begin();
                wavio[temp] = input[i];
                LIS[i] = temp + 1;
            }
        }

        //LDS
        wavio.clear();

        count = 1;
        wavio.push_back(input[n - 1]);
        LDS[n - 1] = 1;

        for (int i = n - 2 ; i >= 0 ; i--){
            if (input[i] > wavio.back()){
                wavio.push_back(input[i]);
                count++;
                LDS[i] = count;
            } else {
                temp = lower_bound(wavio.begin(), wavio.end(), input[i]) - wavio.begin();
                wavio[temp] = input[i];
                LDS[i] = temp + 1;
            }
        }

        // cout << "\nLIS\n";
        // for (int i = 0 ; i < n ; i++){
        //     cout << LIS[i] << " ";
        // }
        // cout << "\nLDS\n";
        // for (int i = 0 ; i < n ; i++){
        //     cout << LDS[i] << " ";
        // }
        // cout << "\n";

        temp = 0;
        for (int i = 0 ; i < n ; i++){
            temp = max(temp, min(LIS[i], LDS[i]));
        }

        cout << temp * 2 - 1 << "\n";

    }
    
}

/*
10
1 2 3 4 5 4 3 2 1 10
19 
1 2 3 2 1 2 3 4 3 2 1 5 4 1 2 3 2 2 1 
5
1 2 3 4 5

ref:http://naivered.github.io/2016/08/26/Problem_Solving/UVa/UVa-10534-Wavio-Sequence/#Solution
*/

