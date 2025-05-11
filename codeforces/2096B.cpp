#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

bool comp(pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.first > p2.first;
}

void solve() {
    vector<pair<ll, ll>> v;
    vector<ll> a, b;
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        v.push_back({min(a[i], b[i]), max(a[i], b[i])});
    }

    for (int i = 0; i < n; i++) {
        ans += v[i].second;
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < k - 1; i++) {
        ans += v[i].first;
    }

    cout << ans + 1 << '\n';
}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}