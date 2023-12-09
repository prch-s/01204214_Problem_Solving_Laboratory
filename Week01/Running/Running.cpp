#include <iostream>
//#include <fstream>

//using namespace std;

const int MAX_N = 100010;

int main() {
    int n,k,i;
    int spr; //second per round
    int athlete[MAX_N];
    long long int min = 10e9;
    int count = 0;
    
    std::cin >> n;
    std::cin >> k;

    for (i = 1 ; i <= n ; i++){
        std::cin >> spr;
        athlete[i] = spr;
        if (spr < min){
            min = spr;
        }
    }
    //cout << min << endl;
    
    //cout << max << endl;

    for (i = 1 ; i <= n ; i++){
        if (athlete[i] <= (min*k)/(k-1)){
            count += 1;
        }
    }
    
    std::cout << count << "\n";

    return 0;
}

/*
int main() {
    int n,k,i;
    int spr; //second per round
    int athlete[MAX_N];
    long long int min = 10e9;
    int count = 0;
    
    ifstream input_data;
    input_data.open("test_8.txt");
    input_data >> n >> k;

    for (i = 1 ; i <= n ; i++){
        input_data >> spr;
        athlete[i] = spr;
        if (spr < min){
            min = spr;
        }
    }
    cout << min << endl;
    

    for (i = 1 ; i <= n ; i++){
        if (athlete[i] <= (min*k)/(k-1)){
            count += 1;
        }
    }
    
    cout << count << endl;

    return 0;
}
*/