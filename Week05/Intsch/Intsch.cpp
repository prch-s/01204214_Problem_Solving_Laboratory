#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool mycomparator(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second; //sort by .second
}

int main()
{
    int n,s,t;
    cin >> n;

    vector<pair<int,int>> jobs;

    for (int i = 0 ; i < n ; i++){
        cin >> s >> t;
        jobs.push_back(make_pair(s,t));

    }

    sort(jobs.begin(), jobs.end(), mycomparator);

    
    cout << "Print pair input\n";
    for (int i = 0 ; i < jobs.size() ; i++){
        cout << "i : " << i << " -> " << jobs[i].first << " " << jobs[i].second << "\n";
    }
    
    
    
    queue<int> sch;
    int last_finished = 0; //start = 0
    for (int i = 0 ; i < n ; i++){
        if (jobs[i].first >= last_finished){
            sch.push(i);
            last_finished = jobs[i].second;
        }
    }

    cout << sch.size() << "\n";

    /*
    while (!sch.empty())    {
        int i = sch.front();
        sch.pop();
        //cout << "(" << jobs[i].first << "," << jobs[i].second << ") ";
    }
    */
}

/*
3
1 2
2 3
1 3

4 
1 2
1 4 
3 4 
2 4

10
2 4
7 9
3 4
8 9
1 3
3 5
4 5
9 10
2 5
6 8
*/