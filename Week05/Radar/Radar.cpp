#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

    double x, y, d;
    int flag, Case = 0;
    int n, i;
    pair<double, double> island[1010];

    while(true){

        cin >> n >> d;
        if (n == 0 && d == 0){
            break;
        }

        flag = 0;

        for (i = 0 ; i < n ; i++){
            cin >> x >> y;
            if (y > d) {
                flag = 1;
            } else {
                island[i].first = x - sqrt(d*d - y*y);
                island[i].second = x + sqrt(d*d - y*y);
            }
        }
        

        int cnt = 0;
        Case++;
        
        if (!flag) {
            /*
             cout << "Before\n";
            for(int i = 0; i < n; i++){
                cout << island[i].first << " " << island[i].second << "\n";     
            }
            */
    
            sort(island, island+n);

            /*
            cout << "After\n";
            for(int i = 0; i < n; i++){
                cout << island[i].first << " " << island[i].second << "\n";
            }
            */
        
            double r = -1e9;

            i = 0;


            while(i < n) {
                //cout << "i : " << i << " r : " << r << " island[i].first : " << island[i].first << " island[i].second : " << island[i].second << "\n";
                //cout << "cnt : " << cnt << "\n";
                while(i < n && island[i].first <= r) {
                    //cout << "r : " << r << "\n";
                    if (r >= island[i].second) {
                        r = island[i].second;
                    }
                    i++;
                }
                cnt++;
                r = island[i].second;
            }
            cnt--;
    
        } else {
            cnt = -1;
        }

        cout << "Case " << Case << ": " << cnt << "\n";
    }
}

/*
3 2 
1 2 
-3 1 
2 1

1 2 
0 2

0 0
*/