#include <iostream>
#include <list>

std::list<int> l;

int main() {
    
    int M; // round
    char cmd[5]; // I or D

    std::cin >> M;

    for (int i = 0 ; i < M ; i++) {
        std::cin >> cmd;
        //insert
        if (cmd[0] == 'I') {
            int x;
            std::cin >> x;
            l.push_front(x);
        } 
        //append
        else if (cmd[0] == 'A') {
            int x;
            std::cin >> x;
            l.push_back(x);
        }
        //delete
        else {
            int k;
            std::cin >> k;
            if (k > l.size()){
                continue;
            } else {
                std::list<int>::iterator itr1 = l.begin();
                advance(itr1,k-1);
                l.erase(itr1);
            }
        }
    }

    for (std::list<int>::iterator itr = l.begin() ; itr != l.end() ; ++itr) {
        std::cout << *itr << "\n";
    }

    return 0;
}

/*
6
A 10 
I 20 
D2 
A 15 
I 30 
D2
*/