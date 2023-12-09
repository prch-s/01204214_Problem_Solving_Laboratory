#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long int> bip;
int n;
int a;
int b;

void showvector(vector<long long int> under)
{
   for (auto itr = under.begin() ; itr != under.end() ; itr++)
   {
       cout << *itr << " ";
    }
    cout << "\n";
}

int binsearch(int left, int right, int val)
{
  if (right < left) {
    return -1;
  }
  int mid = (left + right) / 2;
  if (bip[mid] == val) {
    return mid;
  } else if (bip[mid] < val) {
    return binsearch(mid+1, right, val);
  } else {
    return binsearch(left, mid-1, val);
  }
}

int main(){
    long long answer = 0;
    cin >> n >> a >> b;

    for (int i = 0 ; i < n ; i++)
    {
        long long int price;
        cin >> price;
        bip.push_back(price);
    }

    //showvector(bip);
    sort(bip.begin(), bip.end());
    //showvector(bip);

    for (int i = 0 ; i < n ; i++)
    {
        //cout << "------------------------------------\n";
        //cout << bip[i] << "\n";

        if (bip[i] >= b) {break;}

        int min = a - bip[i];
        int max = b - bip[i];

        //cout << "min: " << min << " max: " << max << "\n";

        auto low = lower_bound(bip.begin() + i, bip.end(), min);
        auto up = upper_bound(bip.begin() + i, bip.end(), max);

        int lower = low - bip.begin();
        int upper = up - bip.begin();

        //cout << "Before\nLower_bound >> value: " << *low << " index: " << lower << "\n";
        //cout << "Upper_bound >> value: " << *up << " index: " << upper << "\n";

        if (lower <= n && bip[lower] == bip[i]) {lower++; low++;}
        if (upper >= 0 && bip[upper] != max) {upper--; up--;}

        //cout << "After\nLower_bound >> value: " << *low << " index: " << lower << "\n";
        //cout << "Upper_bound >> value: " << *up << " index: " << upper << "\n";

        if (upper >= lower) {answer += upper-lower+1;}

        //cout << upper-lower+1 << " " << answer << "\n";
        
    }

    cout << answer << "\n";
}

/*
4 10 20 
5
7
10
15

6 60 100
10
20
30
60 
40 
60
*/