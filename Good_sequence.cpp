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
    ll n;
    cin >> n;
    vector<int> v = tii(n);
    int N = v.back();
    int sieve[N + 1];
    loop(i, N + 1) sieve[i] = i;
    for (ll i = 2; i * i <= N; ++i)
    {
        if (sieve[i] == i)
        {
            for (ll j = i * i; j <= N; j += i)
            {
                if (sieve[j] == j)
                {
                    sieve[j] = i;
                }
            }
        }
    }

    int seq_len[N + 1];
    memset(seq_len, 0, sizeof(seq_len));
    int ans = 0;
    for (ll i = 0; i < n; ++i)
    {
        ll curr = v[i];
        int count = 0;
        while (curr > 1)
        {
            count = max(count, seq_len[sieve[curr]] + 1);
            curr /= sieve[curr];
        }
        ans = max(ans, count);
        curr = v[i];
        while (curr > 1)
        {
            seq_len[sieve[curr]] = max(seq_len[sieve[curr]], count);
            curr /= sieve[curr];
        }
    }
    cout << max(1, ans) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
