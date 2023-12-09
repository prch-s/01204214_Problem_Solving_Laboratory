#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n,s,t;
    cin >> n;

    vector<pair<int,int>> jobs;

    for (int i = 0 ; i < n ; i++){
        cin >> s >> t;
        jobs.push_back(make_pair(s,t));

    }

    sort(jobs.begin(), jobs.end());

    /* 
    cout << "Print pair input\n";
    for (int i = 0 ; i < jobs.size() ; i++){
        cout << "i : " << i << " -> " << jobs[i].first << " " << jobs[i].second << "\n";
    }
    */
    
    int daycnt = 0;
    int maxlate = 0;

    for (int i = 0 ; i < n ; i++){
        daycnt += jobs[i].second;
        if (daycnt > jobs[i].first + 10){
            if (daycnt - (jobs[i].first + 10) > maxlate){
                maxlate = daycnt - (jobs[i].first + 10);
            }
        }
    }

    cout << maxlate * 1000 << "\n";
}

/*
3
50 10
20 20
10 30

3
50 10
20 10
10 20
*/