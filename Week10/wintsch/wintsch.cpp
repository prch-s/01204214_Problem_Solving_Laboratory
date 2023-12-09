#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_N = 1050;

using namespace std;

int n;


pair<pair<int, int>, int> Jobs[MAX_N];

void init(){
    cin >> n;

    for (int i = 0 ; i < n ; i++){
        int s, t, w;
        cin >> s >> t >> w;

        //Jobs[i] = make_pair(make_pair(s, t), w);
        Jobs[i].first.first = s;
        Jobs[i].first.second = t;
        Jobs[i].second = w;
    }
}

bool myComparator(pair<pair<int, int>, int> s1, pair<pair<int, int>, int> s2){
    return (s1.first.second < s2.first.second);
}

void printPair(){
    cout << "---print----\n";
    for (int i = 0 ; i < n ; i++){
        cout << "s : " << Jobs[i].first.first << " , t : " << Jobs[i].first.second << " , w : " << Jobs[i].second << "\n";
    }
    cout << "------------\n";
}

//use binary search 
int findIndex(int n){

    // cout << "j : " << j << " start : " << start << " finish : " << finish << "\n" ;

    int left = 0;
    int right = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (Jobs[mid].first.second <= Jobs[n].first.first)
        {
            if (Jobs[mid + 1].first.second <= Jobs[n].first.first) {
                left = mid + 1;
            }
            else {
                //cout << "last finish : " << Jobs[mid + 1].first.second << "new start : " << Jobs[n].first.first << "\n";
                return mid;
            }
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    
    init();

    //printPair();

    //order by finish time
    sort(Jobs, Jobs + n, myComparator);

    //printPair();

    // Dynamic Programming bottom-up
    // opj(j) = max ( opt(j-1) , v(j) + opt(p(j)) )
    
    vector<int> tasks[n];
    int maxSum[n];

    tasks[0].push_back(0);
    maxSum[0] = Jobs[0].second;


    for (int i = 1 ; i < n ; i++){

        int index = findIndex(i);

        //cout << "i : " << i << " , index : " << index << " => " << index + i << "\n";

        int CurWeight = Jobs[i].second;
        // index = -1 is overlap
        if (index != -1) {
            CurWeight += maxSum[index];
        }

        // cout << "maxSum[i-1] : " << maxSum[i-1] << "\n";
        // cout << "Currweight : " << CurWeight << "\n";

        //case 1 pick
        if (maxSum[i-1] < CurWeight){
            //cout << "pick\n";
            maxSum[i] = CurWeight;
            if (index != -1) {
                tasks[i] = tasks[index];
            }
            tasks[i].push_back(i);
        }
        //case 2 dont pick
        else {
            //cout << "dont pick\n";
            maxSum[i] = maxSum[i-1];
            tasks[i] = tasks[i-1];
        }
        //cout << "\n";
    }

    cout << maxSum[n-1] << "\n";
    int cntAns = tasks[n-1].size();
    cout << cntAns << "\n";
    for (int i: tasks[n-1]){
        cout << i+1 << " ";
    }
}

/*
3 
3 5 2
1 3 2 
2 4 3 

3 
1 3 2 
2 4 10 
3 5 2

ref : https://www.techiedelight.com/weighted-interval-scheduling-problem/
*/