#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    int coaches[1010];
    
    while (1) 
    {
        cin >> n;
        if (n == 0) break;

        while (1)
        {
            //first coaches
            cin >> coaches[0];
            if (coaches[0] == 0)
            {
                cout << "\n";
                break;
            }
            //other coaches
            for (int i = 1; i < n; i++)
            {
                cin >> coaches[i];
            }

            //check
            int currentCoach = 1; // 1,2,3,...,n
            int indexCoaches = 0; //check coaches

            stack<int> station;

            while (currentCoach <= n)
            {
                station.push(currentCoach);
                
                while ( station.empty() == 0 && coaches[indexCoaches] == station.top())
                {
                    indexCoaches++;
                    station.pop();
                    if (indexCoaches >= n) break;
                }
                
                currentCoach++;
            }

            // Y or N
            if (station.empty() == 1)
            {
                cout << "Yes" << "\n";
            } 
            else
            {
                cout << "No" << "\n";
            }
            
        }
        
    }
    return 0;
}
