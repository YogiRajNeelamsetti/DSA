#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int x = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s.substr(0, 2) == "++")
        {
            ++x;
        }
        else if (s.substr(0, 2) == "--")
        {
            --x;
        }
        else if (s.substr(1, 2) == "++")
        {
            x++;
        }
        else if (s.substr(1, 2) == "--")
        {
            x--;
        }
    }

    cout << x << endl;

    return 0;
}