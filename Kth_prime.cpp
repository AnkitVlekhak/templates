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

const int N = 90000000;
bool sieve[N + 1];
vector<int> primes;
void generate_sieve()
{
    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = 0;
    for (ll i = 2; i * i <= N; ++i)
    {
        if (sieve[i])
        {
            for (ll j = i * i; j <= N; j += i)
            {
                if (sieve[j])
                {
                    sieve[j] = false;
                }
            }
        }
    }
    for (ll i = 0; i <= N; i++)
    {
        if (sieve[i])
        {
            primes.push_back(i);
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    cout << primes[n - 1] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    generate_sieve();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
