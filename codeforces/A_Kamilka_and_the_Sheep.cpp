#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 1e18
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int n;
    cin >> n;
    ll mn = INF, mx = -INF;

    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        mn = min(mn, tmp);
        mx = max(mx, tmp);
    }

    cout << mx - mn << '\n';
}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}