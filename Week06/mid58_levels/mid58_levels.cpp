#include <iostream>

using namespace std;

const int MAX_N = 1010;

int n, m, level = 1;
int condition[MAX_N][3];
bool pass[3];
int play[3];

bool isPass(){
    for (int i = 0 ; i < 3 ; i++){
        if (!pass[i]){
            return false;
        }
    }
    return true;
}

void resetPass(){
    for (int i = 0 ; i < 3 ; i++){
        pass[i] = false;
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0 ; i < n - 1 ; i++){
        cin >> condition[i][0] >> condition[i][1] >> condition[i][2];
    }

    for (int i = 0 ; i < m ; i++){
        //level max
        if (level == n){
            break;
        }
        //play
        for (int j = 0 ; j < 3 ; j++){
            cin >> play[j];
            if (play[j] >= condition[level - 1][j]){
                pass[j] = true;
            }
        }
        //check
        if (isPass()){
            resetPass();
            level++;
        }
    }

    if (level > n){
        cout << n << "\n";
    } else {
        cout << level << "\n";
    }
}

/*
4 5
1000 10 0
0 0 0
0 5 10
1230 5 15
10 9 100
5 11 0
1 1 1
0 4 15
*/