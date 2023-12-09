#include <iostream>
#include <map>

using namespace std;

map<int, int> buy; //P A
map<int, int> sell; //Q B

int n, p, a, q, b;
int total = 0;

int main(){
    cin >> n;
    int type, bpg, g;

    for (int i = 0 ; i < n ; i++) {
        cin >> type >> bpg >> g;
        //buy
        if (type == 1) {
            for (auto it = sell.begin() ; it != sell.end() ; it++){
                if (g > 0 && (*it).first <= bpg){    
                    if ((*it).second > g){
                        total += bpg * g;
                        (*it).second -= g;
                        g = 0;
                        break;
                    } else {
                        total += bpg * (*it).second;
                        g -= (*it).second;
                        (*it).second = 0;
                    }
                }
            }
            if (g > 0){
                if (!buy.count(bpg)) {
                    buy[bpg] = 0;
                }
                buy[bpg] += g;
            }
        } 
        //sell
        else if (type == 2) {
            for (auto it = buy.begin() ; it != buy.end() ; it++){
                if (g > 0 && (*it).first >= bpg){
                    if ((*it).second > g){
                        total += bpg * g;
                        (*it).second -= g;
                        g = 0;
                        break;
                    } else {
                        total += bpg * (*it).second;
                        g -= (*it).second;
                        (*it).second = 0;
                    }
                }
            }
            if (g > 0){
                if (!sell.count(bpg)){
                    sell[bpg] = 0;
                }
                sell[bpg] += g;
            }
        }
    }
    cout << total << "\n";
}

/*
8
2 10 5
1 5 10
1 15 3
2 4 30
1 10 21
2 10 5
1 15 4
1 14 10

2
1 10 5 
2 7 5

2 
2 7 5 
1 10 5

score: 8 [ -P---------- ] 
*/