#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    int n = s1.length();
    int diff = 0;

    for (int i = 0; i < n; i++)
    {
        diff += (s1[i] - s2[i]);
    }

    if (diff < 0)
        cout << -1;
    else if (diff > 0)
        cout << 1;
    else
        cout << 0;
}