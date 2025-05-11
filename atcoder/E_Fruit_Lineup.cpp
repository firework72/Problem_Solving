#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 3000006
#define INF 987654321
#define MOD 998244353
#define FLAG 10000

ll a, b, g, o;
ll fact[SIZE] = {0};
ll ans = 0;

ll fast_pow(ll x, ll y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 0) {
        ll tmp = fast_pow(x, y/2);
        return (tmp * tmp) % MOD;
    }
    else {
        ll tmp = fast_pow(x, y-1);
        return (tmp * x) % MOD;
    }
}

ll comb(ll x, ll y) {
    ll ret = 1;
    //cout << x << ' ' << y << '\n';
    if (x < y) return 1;
    ret = fact[x] * fast_pow((fact[x - y] * fact[y]) % MOD, MOD - 2) % MOD;
    //cout << ret << '\n';
    return ret;
}


int main() {
    FAST_IO
    cin >> a >> o >> b >> g;
    fact[0] = 1;
    for (int i = 1; i < SIZE; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }

    for (int i = 1; i <= a + b + 1; i++) {
        ll tmp = 1;
        tmp *= comb(o - 1 + i - 1, o - 1);
        //cout << tmp << '\n';
        tmp %= MOD;
        tmp *= comb(g + min(b + 1, a + b - i + 2) - 1, g);
        tmp %= MOD;
        //cout << tmp << '\n';
        ans += tmp;
        ans %= MOD;
        //cout << ans << '\n';
    }

    cout << ans;
}