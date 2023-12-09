#include <iostream>
#include <map>

const int INFINITY = 1e6;

using namespace std;

int abs(int a){
    if (a > 0){
        return a;
    } else {
        return -a;
    }
}

int main(){
    int n, q;
    int x, c, l;
    int y;

    map<int, pair<int, int>> bread; // first = x, second.first = c , second.second = l
    
    cin >> n >> q;
    
    while(n--){
        cin >> x >> c >> l;
        bread.insert(pair<int ,pair<int, int>> (x, pair<int, int>(c, l)));
    }

    // cout << "\n";
    // for(auto it = bread.begin() ; it != bread.end() ; it++){
    //     cout << (*it).first << " " << (*it).second.first << " " << (*it).second.second << "\n";
    // }
    
    //cout << q << "\n";
    for(int i = 0 ; i < q ; i++){
        //cout << "---" << i << "---\n";
        int price = INFINITY;
        auto pos = bread.begin();
        cin >> y;
        auto lwb = bread.lower_bound(y - 5);
        //cout << (*lwb).first << "\n";
        while ( abs((*lwb).first - y) <= 5){
            if ( (*lwb).second.first < price && (*lwb).second.second > 0){
                price = (*lwb).second.first;
                pos = lwb;
            }
            lwb = next(lwb);
        }
        if(pos != bread.begin()){
            (*pos).second.second--;
        }
        if (price == INFINITY){
            price = 0;
        }
        cout << price << "\n";
        //cout << "---" << i << "---\n";
    }
}

/*
2 6
20 7 2
17 9 30
19
26
14
25
20
20

4 6
20 7 2
20 9 3
17 9 30
20 7 3

4 6
21 7 2
20 9 3
17 9 30
29 7 3
score: 75 [ -P-PPPPP ] 
*/