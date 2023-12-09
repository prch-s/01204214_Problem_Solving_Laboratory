#include <iostream>
#include <queue>
using namespace std;

queue<int> deck;

int main() {
	int n; // #cards
    int to_btm; // top card after discard

    while (1) 
    {
        cin >> n;
        if (n <= 0)
        {
            break;
        }
        else 
        {
            //creat deck
            for (int i = 1 ; i <= n ; i++)
            {
                deck.push(i);
            }
            cout << "Discarded cards:";
            while (deck.size() >= 2) //at least two cards in the deck
            {
                cout << " " << deck.front();
                deck.pop(); //discard top
                //the top of the deck to the bottom of the deck.
                to_btm = deck.front();
                deck.pop();
                if (deck.size() != 0)
                {
                    cout << ",";
                }
                deck.push(to_btm);
            }
            cout << "\nRemaining card: " << deck.front() << "\n";
            deck.pop();
        }
    }
    return 0;
}