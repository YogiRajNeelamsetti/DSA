#include <bits/stdc++.h>
using namespace std;

int main()
{

    double n, m, a;
    cin >> n >> m >> a;

    if (n < 1 || m < 1 || a <= 0)
        return 0;

    double len = ceil(n / a);
    double width = ceil(m / a);
    cout << len * width << endl;

    return 0;
}