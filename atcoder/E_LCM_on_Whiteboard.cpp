#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;
map<int, int> mx_m;
map<int, int> target_m;
vector<pair<int, int>> v[SIZE];
set<int> s;

int main() {
    FAST_IO
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int p, e;
            cin >> p >> e;
            v[i].push_back({p, e});
            mx_m[p] = max(mx_m[p], e);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            int p = v[i][j].first;
            int e = v[i][j].second;

            if (e == mx_m[p]) {
                if (target_m[p] == 0) {
                    target_m[p] = i;
                }
                else {
                    target_m[p] = INF;
                }
            }
        }
    }

    for (auto i : target_m) {
        if (i.second == INF) continue;
        s.insert(i.second);
    }

    cout << min(n, (int)s.size() + 1);
}