#include <iostream>

using namespace std;

long long int binsearch(int left, int right, long long int val, long long int *array)
{
  int mid = (left + right) / 2;
  if (val >= array[mid] && val < array[mid+1]) {
    return mid;
  } else if (val < array[mid]) {
    return binsearch(left, mid-1, val, array);
  } else {
    return binsearch(mid+1, right, val, array);
  }
}

int main(){

    int n,q;
    long long int x,y;

    cin >> n >> q;

    long long int price[n];
    long long int answer[q];

    for (int i = 1 ; i <= n ; i++)
    {
        int p;
        cin >> p;
        price[i] = p;
    }
    
    //showarray(price,n);

    for (int i = 0 ; i < q ; i++)
    {
        cin >> x >> y;
        
        long long int total = price[x] + y;
        //cout << total << "\n";
        
        if (total < price[1]) { answer[i] = 0; }
        else if (x > price[n]) { answer[i] = n; }
        else 
        {
            //cout << binsearch(1, n, total, price) << "\n";  
            answer[i] = binsearch(1, n, total, price);
        }
    }

    for (int i = 0 ; i < q ; i++)
    {
        cout << answer[i] << "\n";
    }
}


/*

6 3
10 30 50 55 100 130 
1 40
3 49
5 10

*/