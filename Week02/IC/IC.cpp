#include <iostream>
#include <list>
//const int MAX_M = 1010;
using namespace std;

list<int> ci;


void showlist(list<int> l){
    list<int>::iterator itr;
    
    for (itr = l.begin() ; itr != l.end() ; ++itr) {
        cout << *itr << "\n";
        //cout << *itr << " ";
    }
    
    //cout << "\n";
}


int main() {
    
    int n; // #command
    cin >> n;

    char cmd[5]; // li or ri or lr or rr
    int x;
    list<int>::iterator itr;

    for (int k = 0 ; k < n ; k++)
    {
        cin >> cmd;
        if (cmd[0] == 'l' && cmd[1] == 'i') 
        {
            cin >> x;
            ci.push_front(x);
            //showlist(ci);
        }
        else if (cmd[0] == 'r' && cmd[1] == 'i') 
        {
            cin >> x;
            ci.push_back(x);
            //showlist(ci);
        }
        else if (cmd[0] == 'l' && cmd[1] == 'r')
        {
            if (ci.size() == 0) continue;
            itr = ci.begin();
            x = *itr;
            //cout << x << " " << *itr << "\n";
            ci.pop_front();
            ci.push_back(x);
            //showlist(ci);
        } 
        else if (cmd[0] == 'r' && cmd[1] == 'r')
        {
            if (ci.size() == 0) continue;
            itr = ci.end();
            advance(itr,-1);
            x = *itr;
            //cout << x << " " << *itr << "\n";
            ci.pop_back();
            ci.push_front(x);
            //showlist(ci);
        } 

    }

    showlist(ci);

    return 0;
}

/*
8
ri 1
ri 2
ri 3
li 20
ri 100
lr
ri 1000
rr

1000
1
2
3
100
20
*/