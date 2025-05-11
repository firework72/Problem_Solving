#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int n; ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> v(n+3, 0);
    vector<ll> filled(n+3, 0);
    vector<pair<int, int>> area;
    vector<ll> prefix_max(n+3, 0);

    int zeroCnt = 0, oneCnt = 0;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (s[i-1] == '1') {
            filled[i] = 1;
            oneCnt++;
        }
        else {
            zeroCnt++;
        }
    }

    int l = 0, r = 0;

    area.push_back({0, 0});

    for (int i = 1; i <= n; i++) {
        if (filled[i] == 1) {
            if (l == 0) {
                l = i;
            }
            r = i;
        }
        else if (l != 0) {
            if (l == 1) area.pop_back();
            area.push_back({l, r});
            l = 0, r = 0;
        }
    }

    if (l != 0) {
        if (l == 1) area.pop_back();
        area.push_back({l, r});
        l = 0, r = 0;
    }

    area.push_back({n+1, n+1});
    for (int i = 0; i < area.size(); i++) {
        l = area[i].first; r = area[i].second;
        ll mx = 0;
        ll tmp = 0;
        for (int j = l; j <= r; j++) {
            prefix_max[j] = max({0ll, tmp + v[j]});
            tmp = prefix_max[j];
            mx = max(mx, prefix_max[j]);
        }

        if (mx > k) {
            cout << "No\n";
            return;
        }
    }

    if (oneCnt == n) {
        ll mx = -1e18 - 9;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, prefix_max[i]);
        }
        if (mx == k) {
            cout << "Yes\n";
            for (int i = 1; i <= n; i++) {
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
        else {
            cout << "No\n";
        }
    }
    else {

        ll v1 = prefix_max[area[0].second];
        ll v2 = 0;
        ll tmp = 0;
        for (int i = area[1].first; i <= area[1].second; i++) {
            tmp += v[i];
            v2 = max(v2, tmp);
        }

        v[area[0].second + 1] = k - v1 - v2;
        
        for (int i = area[0].second + 1; i < area[1].first; i++) {
            filled[i] = 1;
        }

        cout << "Yes\n";

        for (int i = 1; i <= n; i++) {
            if (filled[i] == 1) {
                cout << v[i] << ' ';
            }
            else {
                cout << "-1000000000000000000" << ' ';
            }
        }
        cout << '\n';
    }

    
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}