#include <iostream>
using namespace std;
#define ll long long
#define MAX 998244353
ll nCr(ll n, ll r)
{
    ll ans = 1;
    for (ll i = 1; i <= r; i++)
    {
        ans = (ans * (n - i + 1)%MAX)%MAX;
        ans /= i;
    }
    return ans;
}
ll pow(ll a, ll b)
{
    ll ans = 1;
    for (ll i = 1; i <= b; i++)
    {
        ans = (ans * (a)%MAX)%MAX;
    }
    return ans;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll even = m / 2;
        ll odd = m - even;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += ((ll)(nCr(n, i) * pow(odd, i) * pow(even, n - i) * pow(i, k))) % MAX;
            ans = ans % MAX;
        }
        cout << ans << endl;
    }
}