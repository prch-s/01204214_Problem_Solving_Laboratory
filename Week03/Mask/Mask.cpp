#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_N = 1210; //4*300+10
//const int MAX_L = 10e6;
using namespace std;

int skill[MAX_N];
int n; //#contestant

void showvector(vector<int> under)
{
   for (auto itr = under.begin() ; itr != under.end() ; itr++)
   {
       cout << *itr << " ";
    }
    cout << "\n";
}

/*
void showskill()
{
    for (int i = 1 ; i <= MAX_L ; i++)
    {
        cout << skill[i] << " ";
    }
    cout << "\n";
}
*/

int main(){
    
    cin >> n;

    vector<int> contestant;
    

    //maximum contestant = 4n
    for (int i = 1 ; i <= 4*n ; i++)
    {
        int x;
        cin >> x;
        contestant.push_back(x);
        skill[i] = x;
    }

    //showskill();
    //showvector(contestant);

    sort(contestant.begin(), contestant.begin() + n);
    sort(contestant.begin() + n, contestant.begin() + 2*n);
    sort(contestant.begin() + 2*n, contestant.begin() + 3*n);
    sort(contestant.begin() + 3*n, contestant.begin() + 4*n);
    
    //showvector(contestant);

   int win1 = *(contestant.begin()+ n - 1);
   int win2 = *(contestant.begin()+ 2*n - 1);
   int win3 = *(contestant.begin()+ 3*n - 1);
   int win4 = *(contestant.begin()+ 4*n - 1);

   //cout << win1 << " " << win2 << " " << win3 << " " << win4 << "\n";

   int winA,lostA,winB,lostB;

   if (win1 > win2) 
   {
       winA = win1;
       lostA = win2;
   }
   else
   {
       winA = win2;
       lostA = win1;
   }

   if (win3 > win4) 
   {
       winB = win3;
       lostB = win4;
   }
   else
   {
       winB = win4;
       lostB = win3;
   }

    int first,second;

    if (winA > winB)
    {
        first = winA;
        second = winB;
    }
    else
    {
        first = winB;
        second = winA;
    }

    //cout << first << " " << second << " " << lostA << " " << lostB << "\n";
    
    int idx_first, idx_second, idx_lostA, idx_lostB;

    for (int i = 1 ; i <= 4*n ; i++)
    {
        if(skill[i] == first) {idx_first = i;}
        if(skill[i] == second) {idx_second = i;}
        if(skill[i] == lostA) {idx_lostA = i;}
        if(skill[i] == lostB) {idx_lostB = i;}
    }

    cout << idx_first << " " << idx_second << " " << idx_lostA << " " << idx_lostB << "\n";
}
/*
3
1
2
5
40
25
39
21
29
27
10
20
15
*/