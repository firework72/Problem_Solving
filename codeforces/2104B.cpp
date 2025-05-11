#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int n;
    cin >> n;
    vector<ll> ans(n+3, 0);
    vector<ll> v(n+3, 0);
    vector<ll> suffix_sum(n+3, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = n; i >= 1; i--) {
        suffix_sum[i] = suffix_sum[i+1] + v[i];
    }

    ll mx = -1;
    
    for (int i = 1; i <= n; i++) {
        ll sum = suffix_sum[i];
        if (i == 1) {
            ans[i] = sum;
        }
        else {
            if (v[i] < mx) {
                sum += mx - v[i];
            }
            ans[i] = sum;
        }

        mx = max(mx, v[i]);
    }

    for (int i = n; i >= 1; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}