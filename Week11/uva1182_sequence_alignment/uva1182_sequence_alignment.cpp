#include <iostream>
#include <string>
#include <algorithm> 
 
using namespace std;

const int MAX_N = 1000;
const int INFINITE = 1e6;

//reverse
void reverse_String(string& text, int n,int i){
    if (n <= i){
            return;
    }
    swap(text[i], text[n]);
    reverse_String(text, n-1, i+1);
}

int SA[MAX_N][MAX_N][2][2];

void SequenceAlignment(string x, string y){
     
    int m = x.length();
    int n = y.length();

    // cout << x << "\n";
    // cout << y << "\n";

    //reverse
    reverse_String(x, m-1, 0);
    reverse_String(y, n-1, 0);

    // cout << x << "\n";
    // cout << y << "\n";

    //make matrix
    for (int i = 0 ; i <= m ; i++){
        for (int j = 0 ; j <= n ; j++){
            SA[i][j][0][0] = -INFINITE;
            SA[i][j][0][1] = -INFINITE;
            SA[i][j][1][0] = -INFINITE;
            SA[i][j][1][1] = -INFINITE;
        }
    }
    
    //make boundary
    SA[0][0][0][1] = 0;
	SA[0][0][1][1] = 0;

    int a = -INFINITE;
    int gap = -1;
    int match = 2;

    for (int i = 0 ; i <= m ; i++){
        for (int j = 0 ; j <= n ; j++){
            int v = max({SA[i][j][0][0], SA[i][j][0][1], SA[i][j][1][0], SA[i][j][1][1]});
            
            SA[i+1][j+1][0][1] = max(SA[i+1][j+1][0][1], v);
			SA[i+1][j+1][1][1] = max(SA[i+1][j+1][1][1], v);

			if (x[i] == y[j]) {
				SA[i+1][j+1][0][1] = max(SA[i+1][j+1][0][1], v + match);
				SA[i+1][j+1][1][1] = max(SA[i+1][j+1][1][1], v + match);
			}

			SA[i+1][j][0][0] = max({SA[i+1][j][0][0], SA[i][j][0][0], SA[i][j][1][0] + gap, SA[i][j][0][1] + gap, SA[i][j][1][1] + gap});
			SA[i][j+1][1][0] = max({SA[i][j+1][1][0], SA[i][j][1][0], SA[i][j][0][0] + gap, SA[i][j][0][1] + gap, SA[i][j][1][1] + gap});

            if (j == n || i == m) {
			    a = max({a, SA[i][j][0][0], SA[i][j][0][1], SA[i][j][1][0], SA[i][j][1][1]});
            }
        }
    }
    cout << a << "\n";
    return;
}
 
int main(){

    int n;
    cin >> n;

    while(n--){
        string text1, text2;
        cin >> text1 >> text2;
        SequenceAlignment(text1, text2);
    }
    return 0;
}


/*
2
AADDEFGGHC
ADCDEGH
ERTTHCBYNQC
BEARTBCHQYN

ref: https://github.com/morris821028/UVa/blob/master/volume011/1182%20-%20Sequence%20Alignment.cpp

*/