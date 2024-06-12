#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define loop(x, n) for (ll x = 0; x < n; ++x)
#define tll takein<ll>
#define tii takein<int>
#define gcd(x, y) __gcd(x, y)
template <typename T>
vector<T> takein(int n)
{
    vector<T> A;
    for (int i = 0; i < n; i++)
    {
        T x;
        cin >> x;
        A.push_back(x);
    }
    return A;
}

void solve()
{
    ll m, n = -1;
    cin >> m;
    ll left = 0, right = 1e16, ans = 0;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        ll sum = 0;
        for (ll i = 2; i * i * i <= mid; i++)
        {
            sum += (mid / (i * i * i));
        }
        if (sum < m)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            n = sum == m ? mid : n;
        }
    }
    cout << n << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}
