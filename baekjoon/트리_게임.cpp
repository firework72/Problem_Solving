#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n, s, e;
int visited[SIZE] = {0};
vector<int> edge[SIZE];
vector<int> stk, path;

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = 1;

    stk.push_back(cur);

    if (cur == e) {
        path = stk;
    }

    for (int next : edge[cur]) {
        dfs(next);
    }
    stk.pop_back();
}

int main() {
    FAST_IO
    cin >> n >> s >> e;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(s);

    for (int i = 1; i < (int)path.size() - 1; i += 2) {
        if (edge[path[i]].size() > 2) {
            cout << "Second";
            return 0;
        }
    }

    cout << "First";
}