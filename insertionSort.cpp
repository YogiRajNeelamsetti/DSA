#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (auto &ele : arr)
    {
        cin >> ele;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        {
            swap(arr[j], arr[j - 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}