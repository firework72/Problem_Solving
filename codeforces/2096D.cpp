#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 1e18
#define MOD 1000000007
#define FLAG 10000

void solve() {
    map<ll, int> xm;
    map<ll, ll> ym;
    ll ans_x, ans_y = -INF;
    int n;
    cin >> n;
    vector<pair<ll, ll>> pos;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        xm[x]++;
        ym[y]++;
        pos.push_back({x, y});
    }

    if (pos.size() == 1) {
        cout << pos[0].first << ' ' << pos[0].second << '\n';
        return;
    }

    for (auto i : xm) {
        if (i.second % 2 == 1) {
            ans_x = i.first;
        }
    }

    for (int i = 0; i < n; i++) {
        if (pos[i].first == ans_x) {
            ans_y = max(ans_y, pos[i].second);
        }
    }

    if (xm[ans_x - 1] == 0 && xm[ans_x + 1] == 0) {
        for (int i = 0; i < n; i++) {
            if (pos[i].first == ans_x) {
                cout << pos[i].first << ' ' << pos[i].second << '\n';
            }
        }
    }
    else if (xm[ans_x - 1] == 0) {
        for (int i = 0; i < n; i++) {
            if (pos[i].first == ans_x + 1) {
                ans_y = max(ans_y, pos[i].second + 1);
            }
        }
    } 
    else if (xm[ans_x + 1] == 0 ) {
        ll mx = -INF;
        for (int i = 0; i < n; i++) {
            if (pos[i].first == ans_x - 1) {
                ans_y = max(ans_y, pos[i].second - 1);
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (pos[i].first == ans_x + 1) {
                ans_y = max(ans_y, pos[i].second + 1);
            }
        }

        for (int i = 0; i < n; i++) {
            if (pos[i].first == ans_x - 1) {
                ans_y = max(ans_y, pos[i].second - 1);
            }
        }
    }
    

    cout << ans_x << ' ' << ans_y << '\n';
}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}