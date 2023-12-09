#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

vector<int> droid;

const int INFINITY = 1e7;

int abs(int a){
    if (a > 0){
        return a;
    } else {
        return -a;
    }
}

int result;
int n, m;
int robot, box;
int busy;

int main(){
    cin >> n >> m;

    for (int i = 0 ; i < n ; i++){
        cin >> robot;
        droid.push_back(robot);
    }

    // for (int i = 0 ; i < n ; i++){
    //     cout << droid[i] << " ";
    // }
    // cout << "\n";

    sort(droid.begin(), droid.end());

    // for (int i = 0 ; i < n ; i++){
    //     cout << droid[i] << " ";
    // }
    // cout << "\n";
    
    busy = INFINITY;

    for (int i = 0 ; i < m ; i++){
        cin >> box;
        int index = upper_bound(droid.begin(), droid.end(), box) - droid.begin();
        int pre_index = index - 1;
        //cout << index << "\n";

        if (pre_index == busy){
            pre_index--;
        }
        if (index == busy){
            index++;
        }

        if (pre_index < 0){
            busy = index;
            result += abs(droid[index] - box);
        }
        else if (index >= n){
            busy = pre_index;
            result += abs(droid[pre_index] - box);
        }
        else if (abs(droid[pre_index] - box) <= abs(droid[index] - box)){
            busy = pre_index;
            result += abs(droid[pre_index] - box);
        }
        else if (abs(droid[index] - box) < abs(droid[pre_index] - box)){
            busy = index;
            result += abs(droid[index] - box);
        }
    }
    cout << result << "\n";
}


/*
5 6
40
10
55
20
80 
15 
29 
100 
90 
91 
40
*/