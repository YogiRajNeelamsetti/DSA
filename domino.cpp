#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int nCount = 0, mCount = 0;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            n -= 2;
            nCount++;
        }
        else
        {
            n -= 1;
            nCount++;
        }
    }

    while (m > 0)
    {
        if (m % 2 == 0)
        {
            m -= 2;
            mCount++;
        }
        else
        {
            m -= 1;
            mCount++;
        }
    }

    cout << nCount * mCount << endl;
}