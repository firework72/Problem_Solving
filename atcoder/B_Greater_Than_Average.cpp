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
    vector<ll> v;
    ll sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
        sum += tmp;
    }

    sort(v.begin(), v.end());

    ll mean = sum / n;
    
    int pos = upper_bound(v.begin(), v.end(), mean) - v.begin();

    ans = max(ans, n - pos);

    for (int i = n - 1; i >= 1; i--) {
        sum -= v[i];
        mean = sum / i;
        v.pop_back();
        pos = upper_bound(v.begin(), v.end(), mean) - v.begin();
        ans = max(ans, i - pos);
    }

    cout << ans << '\n';
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}