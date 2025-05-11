#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;
int id = 0;

vector<int> edge[SIZE];
vector<pair<int, int>> edge_inline;
int visited[SIZE] = {0};
int s[SIZE] = {0};
int e[SIZE] = {0};
int no[SIZE] = {0};
ll ans[SIZE] = {0};
ll ans_converted[SIZE] = {0};

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = 1;

    id++;
    s[cur] = id;
    no[id] = cur;
    for (int next : edge[cur]) {
        dfs(next);
    }
    e[cur] = id;
}

int main() {
    FAST_IO
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge_inline.push_back({a, b});
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1);

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, x;
            cin >> a >> x;
            a--;
            if (s[edge_inline[a].first] < s[edge_inline[a].second]) {
                // b[e]의 서브트리를 포함하지 않음
                ans[1] += x;
                ans[s[edge_inline[a].second]] -= x;
                ans[e[edge_inline[a].second] + 1] += x;
                ans[n+1] -= x;
            }
            else {
                // a[e]의 서브트리만을 포함함
                ans[s[edge_inline[a].first]] += x;
                ans[e[edge_inline[a].first] + 1] -= x;
            }
        }
        else if (t == 2) {
            int a, x;
            cin >> a >> x;
            a--;
            if (s[edge_inline[a].first] < s[edge_inline[a].second]) {
                ans[s[edge_inline[a].second]] += x;
                ans[e[edge_inline[a].second] + 1] -= x;
            }
            else {
                ans[1] += x;
                ans[s[edge_inline[a].first]] -= x;
                ans[e[edge_inline[a].first] + 1] += x;
                ans[n+1] -= x;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i-1];
    }

    for (int i = 1; i <= n; i++) {
        ans_converted[no[i]] = ans[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << ans_converted[i] << '\n';
    }
}