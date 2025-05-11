#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n, m;

ll ans[SIZE] = {0};
ll cur_ans = 0;
vector<pair<int, int>> edge;

int parent[SIZE] = {0};
int depth[SIZE] = {0};

int find(int x) {
    if (x == parent[x]) return x;
    int y = find(parent[x]);
    parent[x] = y;
    return y;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (x > y) {
        cur_ans += (ll) depth[y] * (depth[y] - 1) / 2;
        cur_ans += (ll) depth[x] * (depth[x] - 1) / 2;
        parent[y] = x;
        depth[x] += depth[y];
        cur_ans -= (ll) depth[x] * (depth[x] - 1) / 2;
    }
    else {
        cur_ans += (ll) depth[y] * (depth[y] - 1) / 2;
        cur_ans += (ll) depth[x] * (depth[x] - 1) / 2;
        parent[x] = y;
        depth[y] += depth[x];
        cur_ans -= (ll) depth[y] * (depth[y] - 1) / 2;
    }
}

int main() {
    FAST_IO
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge.push_back({a, b});
    }

    cur_ans = (ll)n * (n - 1) / 2;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        depth[i] = 1;
    }

    for (int i = m - 1; i >= 1; i--) {
        merge(edge[i].first, edge[i].second);
        ans[i] = cur_ans;
    }

    for (int i = 1; i < m; i++) {
        cout << ans[i] << '\n';
    }

    cout << (ll)n * (n - 1) / 2 << '\n';
}