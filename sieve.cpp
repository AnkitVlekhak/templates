//sieve
const int N = 1000005;
int sieve[N + 1];
void generate_sieve()
{
    memset(sieve, -1, sizeof(sieve));
    sieve[0] = sieve[1] = 0;
    for (ll i = 2; i * i <= N; ++i)
    {
        if (sieve[i] == -1)
        {
            for (ll j = i * i; j <= N; j += i)
            {
                if (sieve[j] == -1)
                {
                    sieve[j] = i;
                }
            }
        }
    }
}
