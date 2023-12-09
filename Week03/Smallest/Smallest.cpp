#include <iostream>

const int MAX_N = 200010;
const int MAX_Q = 100010;

using namespace std;

//int height[MAX_N];
int shortest[MAX_N];
int answer[MAX_Q];

void showarray(int x[MAX_N],int n)
{
    for (int i = 1 ; i <= n ; i++)
    {
        cout << x[i] << " ";
    }
    cout << "\n";
}

void showanswer(int x[MAX_Q],int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        cout << x[i] << "\n";
    }
}

int binsearch(int left, int right, int val, int *array)
{
  int mid = (left + right) / 2;
  if (val <= array[mid] && val > array[mid+1]) {
    return mid;
  } else if (val > array[mid]) {
    return binsearch(left, mid-1, val, array);
  } else {
    return binsearch(mid+1, right, val, array);
  }
}

int main(){

    int n,q;
    int h;
    cin >> n >> q;

    

    for (int i = 1 ; i <= n ; i++)
    {
        cin >> h;
        //height[i] = h;
        if (i == 1) 
        {
            shortest[1] = h;
        }
        else
        {
            if (h > shortest[i-1]) {shortest[i] = shortest[i-1];}
            else { shortest[i] = h;}
        }
    }
    
    //showarray(height,n);
    //showarray(shortest,n);

    for (int i = 0 ; i < q ; i++)
    {
        int T,x;
        cin >> T >> x;
        if (T == 1)
        {
            //cout << shortest[x] << "\n";
            answer[i] = shortest[x];
        }
        else if (T == 2)
        {
            //if (x > shortest[1]) { cout << "0\n"; }
            if (x > shortest[1]) { answer[i] = 0; }
            //else if (x < shortest[n]) { cout << n << "\n"; }
            else if (x < shortest[n]) { answer[i] = n; }
            else 
            {
                //cout << (binsearch(1, n, x, shortest)) << "\n";
                answer[i] = binsearch(1, n, x, shortest);
            }
        }
        
    }

    showanswer(answer,q);
}


/*
5 8
100
240
80
90
75
1 1
2 95
1 4
2 80
2 50
1 5
2 120
2 100

*/