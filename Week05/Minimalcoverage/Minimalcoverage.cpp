#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool mycomparator(pair<int, int> a, pair<int, int> b)
{
	if(a.first == b.first)
		return a.second > b.second;
	else
		return a.first < b.first;
}


// void showpair(){
//     cout << "Print pair input\n";
//     for (int i = 0 ; i < segment.size() ; i++){
//         cout << "i : " << i << " -> " << segment[i].first << " " << segment[i].second << "\n";
//     }
// }


int main()
{
    
	int n,l,r,m;
	cin >> n;
	while(n--) {
		cin >> m;
		vector<pair<int, int>> segment;
		while(true)
		{
			cin >> l >> r;
			if (l==0 && r==0) {
                break;
            }
			else {
                segment.push_back(make_pair(l,r));
            }
		}
		
        //showpair();
		sort(segment.begin(), segment.end(), mycomparator);
        //showpair();
		cout << "Print pair input\n";
    	for (int i = 0 ; i < segment.size() ; i++){
        	cout << "i : " << i << " -> " << segment[i].first << " " << segment[i].second << "\n";
    	}
		
		int currentL=0, maxR=0;
		vector<pair<int, int>> answer;
		int i = 0;

		while(maxR < m){
			int newL = currentL;
			int index = -1;
			//cout << "size : " << segment.size() << "\n";
			for(; i<segment.size() ; i++){
				//cout << "segment[" << i << "] : " << segment[i].first << " " << segment[i].second << "\n";
				if(segment[i].first > currentL) {
                    break;
                }	
				else if(segment[i].second >= newL){
					newL = segment[i].second;
					index = i;
				}
			}
			if(index==-1) {
                break;
            }
			
			maxR = segment[index].second;
			answer.push_back(segment[index]);
			currentL = segment[index].second;

		}
		if(maxR >= m){
			cout << answer.size() << "\n";
			for(auto p:answer){
				cout << p.first << " " << p.second << "\n";
            }
		}
		else{
			cout << 0 << "\n";
        }
		if(n){
			cout << "\n";
        }
	}
}

/*
2
1
-1 0 
-5 -3 
2 5 
0 0
1 
-1 0 
0 1 
0 0

1
1
-1 0 
0 1 
0 0

1
2
-2 1
-2 6
1 5
1 2
1 3
-7 0
0 0

1
2
-3 1
-1 3
2 3
0 3
-1 1
0 2
0 0
*/