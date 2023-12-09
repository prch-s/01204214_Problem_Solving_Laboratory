#include <iostream>

const int MAX_N = 1500;
const int MAX_K = 500;

int k, n;
int c[MAX_K], p[MAX_K], w[MAX_K];
int box[MAX_N];
int price[MAX_K];
int max_box = 0;
int cnt = 1;


using namespace std;

int main(){
    cin >> k >> n;

    for (int i = 1 ; i <= k ; i++){
        cin >> c[i] >> p[i] >> w[i];
    }

    for (int i = 1 ; i <= n ; i++){
        cin >> box[i];
        if (box[i] > max_box){
            max_box = box[i];
        }
    }

    for (int i = 1 ; i <= k ; i++){
        int weight = w[i];
        if (max_box > weight){
            continue;
        }
        for (int j = 1 ; j <= n ; j++){
            if (weight - box[j] >= 0){
                weight = weight - box[j];
            } else {
                weight = w[i] - box[j];
                cnt++;
            }
        }
        price[i] = c[i] + p[i]*cnt;
        cnt = 1;
    }

    int sale = 1e6;
    for (int i = 1 ; i <= k ; i++){
        if (price[i] < sale && price[i] != 0){
            sale = price[i];
        }
    }
    cout << sale << "\n";
}

/*
4 6
50 100 20 
100 10 10 
0 1000 1000 
10 10 5 
5 4 3 3 3 7
*/