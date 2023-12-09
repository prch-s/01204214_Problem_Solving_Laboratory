#include <iostream>
#include <list>

const int MAX_M = 300010;
using namespace std;

list<int> necklace[MAX_M];
int position[MAX_M]; //for keep index necklace[i] bigO = o(n)

void showlist(list<int> l[MAX_M],int n){
    list<int>::iterator itr;
    for (int i=1 ; i <= n ; i++){
        for (itr = l[i].begin() ; itr != l[i].end() ; ++itr) {
            //cout << *itr << "\n";
            cout << *itr << " ";
        }
    }
    cout << "\n";
}

int main() {
    
    int n; // #command
    cin >> n;

    for (int i = 1 ; i <= n ; i++)
    {
        necklace[i].push_back(i);
        position[i] = i;
    }
    //showlist(necklace,n);
    
    for (int j = 0 ; j < n-1 ; j++)
    {
        int x,y;
        cin >> x >> y;

        list<int>::iterator itr_x,itr_y;
        int idX = position[x];
        int idY = position[y];

        for (itr_y = necklace[idY].begin() ; itr_y != necklace[idY].end() ; itr_y++)
        {
            if (*itr_y == y) break;
        }
        advance(itr_y,1);

        //Update position
        for (itr_x = necklace[idX].begin() ; itr_x != necklace[idX].end() ; itr_x++)
        {
            position[*itr_x] = idY;
        }

        necklace[idY].splice(itr_y,necklace[idX]);
        //showlist(necklace,n);

        /*
        for (itr1 = necklace[position[y]].begin() ; itr1 != necklace[position[y]].end() ; itr1++)
        {
            //cout << *itr1 << "\n";
            if (*itr1 == y)
            {   
                //cout << "pos x: " << position[x] << " pos y: "<< position[y] << "\n";
                advance(itr1,1);
                necklace[position[y]].splice(itr1,necklace[position[x]]); 
                
                //Update position
                position[x] = position[y];

                //cout << "pos x: " << position[x] << " pos y: "<< position[y] << "\n";
                //showlist(necklace,n);
                break;
            }
        }
        */

    }
    showlist(necklace,n);

    return 0;
}

/*
8 
7 4
3 5
5 4
8 1
2 8
1 6
4 1
*/