#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < 3; j++)
        {
            int ele;
            cin >> ele;
            if (ele == 1)
            {
                flag++;
            }
        }
        if (flag >= 2)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}