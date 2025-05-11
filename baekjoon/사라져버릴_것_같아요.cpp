#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

ll n, a, b, c;
ll k;
ll len;
ll ans = 1;

ll fact[SIZE] = {0};

ll fast_pow(ll x, ll y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 0) {
        ll tmp = fast_pow(x, y / 2);
        return (tmp * tmp) % MOD;
    }
    else {
        ll tmp = fast_pow(x, y - 1);
        return (tmp * x) % MOD;
    }
}

ll comb(ll x, ll y) {
    ll ret = 1;

    ret *= fact[x] * fast_pow(fact[x - y], MOD - 2) % MOD;

    ret = ret * fast_pow(fact[y], MOD - 2) % MOD;
    return ret;
}

int main() {
    FAST_IO
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= 200000; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    int t;
    cin >> t;
    while (t--) {
        ans = 1;
        cin >> n >> a >> b >> c;
        if (b % 2 != 0) {
            cout << "0";
            return 0;
        }

        k = a + b / 2;
        len = a + b + c + k - 1;

        if (len > n) {
            cout << "0";
            return 0;
        }

        ans *= (comb(k, a) * fact[a]) % MOD * fact[b / 2] % MOD;
        ans %= MOD;
        ans *= comb(c + b / 2 - 1, b / 2) % MOD;
        ans %= MOD;
        ans *= comb(n - (k - 1) - (c + b / 2), k) % MOD;
        ans %= MOD;
        ans *= fact[a] * fact[b] % MOD * fact[c] % MOD;
        ans %= MOD;
        cout << ans << '\n';
    }
    
}