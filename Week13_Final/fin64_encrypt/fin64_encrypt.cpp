#include <iostream>

using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    int input[20];
    for (int i = 0 ; i < n ; i++){
        cin >> input[i];
    }

    // for (int i = 0 ; i < n ; i++){
    //     cout << input[i] << " ";
    // }
    // cout << "\n";

    int num = 1;
    for (int i = n ; i < 20 ; i++){
        input[i] = num;
        num++;
    }

    // for (int i = 0 ; i < 20 ; i++){
    //     cout << input[i] << " ";
    // }
    // cout << "\n";

    int result[20];

    for(int i = 0 ; i < 20 ; i++){
        int pos = (20-s+i);
        if (pos >= 20){
            pos -= 20;
        }
        result[i] = input[pos];
    }

    // for (int i = 0 ; i < 20 ; i++){
    //     cout << result[i] << " ";
    // }
    // cout << "\n";

    for (int i = 5 ; i >= 1 ; i--){
        for (int j = 1 ; j <= 4 ; j++){
            int pos = j * 5 - i;
            cout << result[pos]<< " ";
        }
    }

}

/*
15 7
11 12 13 10 20 30 100 200 300 15 16 17 50 60 70
*/