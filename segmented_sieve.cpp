#include <bits/stdc++.h>
#define startt                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
typedef long long ll;
using namespace std;
#define vec(t) vector<t>
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
    ll n, m;
    cin >> m >> n;
    vec(bool) v(sqrt(n) + 1, true);
    v[1] = 0;
    for (ll i = 2; i * i <= sqrt(n); i++)
    {
        if (v[i])
        {
            for (ll j = i * i; j <= sqrt(n); j += i)
            {
                v[j] = 0;
            }
        }
    }
    vec(ll) prime;
    for (ll i = 2; i < v.size(); ++i)
    {
        if (v[i])
        {
            prime.push_back(i);
        }
    }
    v.clear();
    v.resize(n - m + 1, true);
    for (auto x : prime)
    {
        ll i = (m % x == 0) ? m : m + (x - (m % x));
        i = max(x * x, i);
        i -= m;
        for (ll j = i; j < v.size(); j += x)
        {
            v[j] = 0;
        }
    }
    for (ll i = 0; i < v.size(); ++i)
    {
        if (v[i] && m + i > 1)
        {
            cout << m + i << endl;
        }
    }
    cout << endl;
}
int32_t main()
{
    startt
        ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
