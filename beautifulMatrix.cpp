#include <bits/stdc++.h>
using namespace std;

int main()
{

    int iIndex, jIndex;

    vector<vector<int>> a(6, vector<int>(6));

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                iIndex = i;
                jIndex = j;
            }
        }
    }

    cout << abs(3 - iIndex) + abs(3 - jIndex) << endl;
}