#include <bits/stdc++.h>
using namespace std;

int towerOfHanoi(int s, int d, int h, int n)
{
    if (n == 1)
    {
        return 1;
    }
    int moves = towerOfHanoi(s, h, d, n - 1) + 1;
    moves += towerOfHanoi(h, d, s, n - 1);
    return moves;
}

void printTowerOfHanoiMoves(int s, int d, int h, int n)
{
    if (n == 1)
    {
        cout << s << " " << d << endl;
        return;
    }
    printTowerOfHanoiMoves(s, h, d, n - 1);
    cout << s << " " << d << endl;
    printTowerOfHanoiMoves(h, d, s, n - 1);
}

int main()
{
    int n;
    cin >> n;

    cout << towerOfHanoi(1, 3, 2, n) << endl;
    printTowerOfHanoiMoves(1, 3, 2, n);

    return 0;
}
