#include <iostream>

const int MAX_N = 1010;
using namespace std;

int n,m,a,b;
int parent[MAX_N];

void showparent(int n)
{
    for (int i = 1 ; i <= n ; i++)
    {
        cout << parent[i] << " ";
    }
    cout << "\n";
}

int main(){
    
    cin >> n >> m;

    for (int i = 1 ; i <= n ; i++)
    {
        if (i == 1) {parent[i] = 1;}
        else {cin >> parent[i];}
    }
    
    //showparent(n);

    for (int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        if (a == 1 || b == 1) { cout << "1\n"; }
        else if (parent[a] == b) { cout << b << "\n"; }
        else if (parent[b] == a) { cout << a << "\n"; }
        else
        {
            
            bool check = false;

            //check b
            int x = parent[b];
            while (x != 1 && !check)
            {
                if (x == a)
                {
                    check = true;
                    cout << x << "\n";
                }
                else
                {
                    //swap
                    int tmp = x;
                    x = parent[tmp];
                }
            }
            
            //check a
            if (!check)
            {
                x = parent[a];
                while (x != 1 && !check)
                {
                    if (x == b)
                    {
                        check = true;
                        cout << x << "\n";
                    }
                    else
                    {
                        int tmp = x;
                        x = parent[tmp];
                    }
                }
            }
            //finally
            if (!check) { cout << "-1\n"; }
        }
    }
}

/*
4 3
1
4
1
4 1
3 2
4 3

10 6
1
9
9
9
4
1
7
1
7
6 4
4 9
9 1
5 8
4 7
10 7

*/