#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n, m;
int visited[SIZE] = {0};
int ans[SIZE] = {0};
vector<pair<int, int>> edge[SIZE];

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = -1;
    }
}

void bfs(int start, int flag) {
    vector<int> cnt(2, 0);
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    vector<int> node; // 방문한 노드들
    node.push_back(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int j = 0; j < edge[cur].size(); j++) {
            int next = edge[cur][j].first;
            int val = edge[cur][j].second;
            int res = 0;
            // 같으면 0, 다르면 1
            if ((val & flag) == 0) {
                res = visited[cur];
            }
            else {
                res = !visited[cur];
            }

            if (visited[next] != -1 && visited[next] != res) {
                cout << "-1";
                exit(0);
            }

            if (visited[next] == -1) {
                visited[next] = res;
                cnt[res]++;
                q.push(next);
                node.push_back(next);
            }
        }
    }

    int target = 0;
    if (cnt[0] < cnt[1]) {
        target = 0;
    }
    else {
        target = 1;
    }

    for (int j : node) {
        if (visited[j] == target) ans[j] |= flag;
    }
}

int main() {
    FAST_IO
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        ll z;

        cin >> x >> y >> z;

        if (x == y) {
            if (z != 0) {
                cout << "-1";
                return 0;
            }
        }
        else {
            edge[x].push_back({y, z});
            edge[y].push_back({x, z});
        }

    }

    for (int i = 0; i < 30; i++) {
        init();
        int flag = 1 << i;

        for (int j = 1; j <= n; j++) {
            if (visited[j] == -1) {
                bfs(j, flag);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}
