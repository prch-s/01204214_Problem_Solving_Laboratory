#include <iostream>

using namespace std;

const int MAX_MW = 35;

int main(){
    int T;
    cin >> T;
    for (int i = 0 ; i < T ; i++){
        int N, P, W, G, MW;
        int SuperSale[MAX_MW];
        int result = 0;

        cin >> N;

        //reset
        for (int j = 1 ; j <= 30 ; j++){
            SuperSale[j] = 0;
        }

        for (int j = 0 ; j < N ; j++){
            cin >> P >> W;
            for (int k = 30 ; k >= W ; k--){
                if(SuperSale[k] < SuperSale[k - W] + P){
                    SuperSale[k] = SuperSale[k - W] + P;
                }
            }
        }

        // cout << "\n";
        // for (int j = 1 ; j <= 30 ; j++){
        //     cout << SuperSale[j] << " ";
        // }
        // cout << "\n";

        cin >> G;
        for (int j = 0 ; j < G ; j++){
            cin >> MW;
            result += SuperSale[MW];
        }

        cout << result << "\n";
    }
}

/*
2

3
72 17
44 23
31 24
1
26

6
64 26
85 22
52 4
99 18
39 13
54 9
4
23
20
20
26

ref:https://shareablecode.com/snippets/c-solution-for-uva-problem-supersale-10130-cpp-pq7T-eHWz
ref:https://github.com/morris821028/UVa/blob/master/volume101/10130%20-%20SuperSale.cpp

*/