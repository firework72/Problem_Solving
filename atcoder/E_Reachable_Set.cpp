#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n, m;

int parent[SIZE] = {0};
int depth[SIZE] = {0};
int cnt[SIZE] = {0};
vector<int> edge[SIZE];
set<int> s;

int find(int x) {
    if (x == parent[x]) return x;
    int y = find(parent[x]);
    parent[x] = y;
    return y; 
} 

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    // cout << x << ' ' << y << '\n';

    if (x == y) return;
    
    if (depth[x] > depth[y]) {
        parent[y] = x;
        depth[x] += depth[y];
        cnt[x] += cnt[y];
        cnt[y] = 0;
    }
    else {
        parent[x] = y;
        depth[y] += depth[x];
        cnt[y] += cnt[x];
        cnt[x] = 0;
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        depth[i] = 1;
        cnt[i] = 1;
    }
}

int main() {
    FAST_IO
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (s.find(i) != s.end()) {
            s.erase(i);
        }

        for (int j : edge[i]) {
            if (j < i) merge(i, j);
            if (j > i) s.insert(j);
        }

        if (cnt[find(1)] != i) {
            cout << "-1\n";
        }
        else {
            cout << s.size() << '\n';
        }

        // for (int j = 1; j <= n; j++) {
        //     cout << cnt[j] << ' ';
        // }
        // cout << '\n';
    }
}