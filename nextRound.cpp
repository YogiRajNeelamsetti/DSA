#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    int num = v[k - 1];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] >= num && v[i] > 0)
            count++;
    }

    cout << count << endl;

    return 0;
}