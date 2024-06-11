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
    string sandwich;
    cin >> sandwich;
    // BSC
    int avail[3], prices[3];
    loop(i, 3) cin >> avail[i];
    loop(i, 3) cin >> prices[i];
    ll money;
    cin >> money;
    int items_for_one[3] = {0};
    loop(i, sandwich.length())
    {
        if (sandwich[i] == 'B')
            items_for_one[0]++;
        else if (sandwich[i] == 'S')
            items_for_one[1]++;
        else if (sandwich[i] == 'C')
            items_for_one[2]++;
    }

    ll left = 0, right = money + 100, ans = 0;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        // processing
        ll required_items[3], items_to_purchase[3], cost = 0;
        loop(i, 3) required_items[i] = mid * items_for_one[i];
        loop(i, 3) items_to_purchase[i] = max(0LL, required_items[i] - avail[i]);
        loop(i, 3) cost += items_to_purchase[i] * prices[i];
        // testing
        if (cost <= money)
        {
            left = mid + 1;
            ans = mid;
        }
        if (cost >= money)
        {
            right = mid - 1;
        }
    }
    cout << ans << endl;
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
