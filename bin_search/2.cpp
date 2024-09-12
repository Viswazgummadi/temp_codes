// C++ file 1.cpp
#include <bits/stdc++.h>

using namespace std;

int n ,k;
int arr[100100];

int check(int x)
{
    int need = 0;
    for (int i = 1; i < n;i++)
    {
        int diff = arr[i] - arr[i - 1];
        need += (diff + x - 1) / x - 1;
    }
    return need <= k;
}

void solve()
{

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "]:" << endl;
        cin >> arr[i];
    }

    int low = 1;
    int high = 1e9;
    int ans = 1e9;

    cout << endl;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (check(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "\n"
         << ans << endl;
}

signed
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
