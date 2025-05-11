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
stack<int> s;

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = 1;
    s.push(cur);

    for (int next : edge[cur]) {
        dfs(next);
    }
}

int main() {
    FAST_IO
    cin >> n >> m;
    if (n != m) {
        cout << "No";
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1);

    if (s.size() != n) {
        cout << "No";
        return 0;
    }

    for (int next : edge[s.top()]) {
        if (next == 1) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
}