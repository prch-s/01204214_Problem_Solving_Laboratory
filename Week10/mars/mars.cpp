#include <iostream>
#include <string>

using namespace std;

const int INFINITY = 1e7;

string text;
int cost[1000][26][26];
int t;

int min(int a, int b){
    if (a < b){
        return a;
    } else {
        return b;
    }
}

int abs(int a){
    if (a > 0){
        return a;
    } else {
        return -a;
    }
}

int distance(int a, int b){
    int wheel1 = abs(a - b);
    int wheel2 = 26 - abs(a - b);
    return min(wheel1, wheel2);
}

int main(){
    cin >> t;
    //for (int i = 0 ; i < t ; i++){
    while (t--){
        cin >> text;
        int size = text.length();

        //init
        for (int i = 0 ; i < size ; i++){
            for (int j = 0 ; j < 26 ; j++){
                for (int k = 0 ; k < 26 ; k++){
                    cost[i][j][k] = INFINITY;
                }
            }
        }

        //basecase
        cost[0][text[0] - 'A']['A' - 'A'] = distance(0, text[0] - 'A');
        cost[0]['A' - 'A'][text[0] - 'A'] = distance(0, text[0] - 'A');

        //recurrence : cost[i][x][[i]] = min(cost[i-1][x][y]+dis(s[i],y))  for y in A to Z
        for (int i = 1 ; i < size ; i++){
            for (int j = 0 ; j < 26 ; j++){
                for (int k = 0 ; k < 26 ; k++){
                    cost[i][text[i] - 'A'][k] = min(cost[i][text[i] - 'A'][k], cost[i - 1][j][k] + distance(text[i] - 'A', j));
                    cost[i][j][text[i] - 'A'] = min(cost[i][j][text[i] - 'A'], cost[i - 1][j][k] + distance(text[i] - 'A', k));
                }
            }
        }

        int result = INFINITY;
        
        for (int j = 0 ; j < 26 ; j++){
            for (int k = 0 ; k < 26 ; k++){
                result = min(cost[size - 1][j][k], result);
            }
        }

        cout << result << "\n";
    }
}



/*
3
BYEBYE
YOUBELONGWITHME
HELLOWORLD
*/
