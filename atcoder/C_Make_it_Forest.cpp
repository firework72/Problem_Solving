#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n, m;
vector<int> edge[SIZE];
int visited[SIZE] = {0};

int v = 0, e = 0;
int ans = 0;

void dfs(int cur) {
    e++;
    if (visited[cur]) return;

    visited[cur] = 1;
    v++;

    for (int next : edge[cur]) {
        dfs(next);
    }
}

int main() {
    FAST_IO
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i);
        e--;
        e /= 2;
        ans += max(0, e - v + 1);

        v = 0, e = 0;
    }

    cout << ans;
}