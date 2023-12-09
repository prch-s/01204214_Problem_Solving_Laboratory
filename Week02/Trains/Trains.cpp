#include <iostream>
#include <list>
const int MAX_M = 100010;
using namespace std;

list<int> l[MAX_M];

void showlist(list<int> l[MAX_M]){
    list<int>::iterator itr;
    for (int i=0 ; i < MAX_M ; i++){
        for (itr = l[i].begin() ; itr != l[i].end() ; ++itr) {
            cout << *itr << "\n";
            //cout << *itr << " ";
        }
    }
    //cout << "\n";
}

int main() {
    
    int n; // #command
    cin >> n;

    char cmd[5]; // N or M

    for (int k = 0 ; k < n ; k++){
        cin >> cmd;
        if (cmd[0] == 'N') {
            int x; //trian
            int i; //platform
            cin >> x >> i;
            l[i].push_back(x);
            //showlist(l);
        }
        else if (cmd[0] == 'M') {
            int i; //from platform i
            int j; //to platform j
            cin >> i >> j;
            // target_list.splice(position in target_list, add list)
            l[j].splice(l[j].end(),l[i]); 
            //showlist(l);
        }
    }

    showlist(l);

    return 0;
}

/*
7 
N 1 1 
N 2 1 
N 3 2 
M 1 2 
N 4 1 
N 5 3 
M 3 1
*/