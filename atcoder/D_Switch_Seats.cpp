#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int d[2] = {-1, 1};

void solve() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<int> v;
    vector<pair<int, int>> pos(n+2, {-1, -1});

    for (int i = 0; i < 2 * n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        
        if (pos[tmp].first != -1) {
            pos[tmp].second = i;
        }
        else {
            pos[tmp].first = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (abs(pos[i].first - pos[i].second) == 1) continue;
        vector<pair<int, int>> tmp;
        set<pair<int, int>> s;
        if (pos[i].first - 1 >= 0) s.insert({v[pos[i].first - 1], pos[i].first - 1});
        if (pos[i].first + 1 < 2 * n) s.insert({v[pos[i].first + 1], pos[i].first + 1});
        if (pos[i].second - 1 >= 0) s.insert({v[pos[i].second - 1], pos[i].second - 1});
        if (pos[i].second + 1 < 2 * n) s.insert({v[pos[i].second + 1], pos[i].second + 1});

        for (auto j : s) {
            tmp.push_back(j);
        }

        for (int a = 0; a < tmp.size(); a++) {
            for (int b = a + 1; b < tmp.size(); b++) {
                if (tmp[a].first == tmp[b].first && abs(tmp[a].second - tmp[b].second) > 1) {
                    
                    vector<int> pos_tmp;

                    pos_tmp.push_back(pos[i].first);
                    pos_tmp.push_back(pos[i].second);
                    pos_tmp.push_back(tmp[a].second);
                    pos_tmp.push_back(tmp[b].second);

                    sort(pos_tmp.begin(), pos_tmp.end());

                    if (pos_tmp[1] - pos_tmp[0] == 1 && pos_tmp[3] - pos_tmp[2] == 1) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans / 2 << '\n';
}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}