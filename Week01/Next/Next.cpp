#include <iostream>

//using namespace std;

const int MAX_N = 100010;

int main() {
    int n,i;
    int next,tmp,visited;
    int order[MAX_N];
    int max = 0;

    std::cin >> n;

    for (i = 1 ; i <= n ; i++){
        std::cin >> next;
        order[i] = next;
    }
    
    for (i = 1 ; i <= n ; i++){
        if (order[i] == 0){
            continue;
        } else {
            //out << "i : " << i << endl;
            int count = 1;
            tmp = order[i];
            while (true) {
                //cout << "tmp : " << tmp << endl;
                count += 1;
                visited = tmp;
                if (order[tmp] == i){
                    order[visited] = 0;
                    break;
                } else {
                    tmp = order[visited];
                    order[visited] = 0;
                }
                
            }
            if (count > max){
                max = count;
            }
        }
    }
    std::cout << max << "\n";
    return 0;
}

/*
#include <iostream>

using namespace std;

const int MAX_N = 100010;

int main() {
    int n,i;
    int next,tmp;
    int order[MAX_N];
    int max = 0;

    cin >> n;

    for (i = 1 ; i <= n ; i++){
        cin >> next;
        order[i] = next;
    }
    
    for (i = 1 ; i <= n/2 ; i++){
        if (order[i] == 0){
            continue;
        } else {
            int count = 1;
            tmp = order[i];
            while (true) {
                count += 1;
                if (order[tmp] == i){
                    break;
                } else {
                    order[tmp] == 0;
                }
                tmp = order[tmp];
            }
            if (count > max){
                max = count;
            }
        }
    }
    cout << max << endl;
    return 0;
}
*/