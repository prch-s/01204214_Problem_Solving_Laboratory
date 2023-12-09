#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> under;

void showvector(vector<int> under)
{
   for (auto itr = under.begin() ; itr != under.end() ; itr++)
   {
       cout << *itr << " ";
    }
    cout << "\n";
}

int main(){
    int l; 
    int n; //#bridge
    int a; //start
    int b; //end

    cin >> l >> n;

    under.assign(l,0);

    //showvector(under);

    for (int i = 0 ; i < n ; i++)
    {
        cin >> a >> b;
        for (int j = a ; j < b ; j++)
        {
            under[j]++;
        }
        //showvector(under);
    }

    sort(under.begin(),under.end());
    //showvector(under);

    cout << *(under.end()-1) << "\n";
}

/*
20 5
1 6
1 8
6 12
7 14
15 20

20 5
1 6
1 8
6 12
8 14
15 20

100 5
0 20
20 40
40 60
60 80
80 100
*/