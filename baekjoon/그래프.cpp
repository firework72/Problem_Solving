#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 55
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;
int m = 0;
set<int> group;
char edge[SIZE][SIZE] = {0};

int parent[SIZE] = {0};
int depth[SIZE] = {0};

void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        depth[i] = 1;
    }
}

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
    if (depth[x] > depth[y]) {
        parent[y] = x;
        depth[x] += depth[y];
    }
    else {
        parent[x] = y;
        depth[y] += depth[x];
    }
}


int main() {
    FAST_IO
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            edge[i][j] = s[j-1];
        }
    }

    if (n == 1) {
        cout << "0";
        return 0;
    }

    init();

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (edge[i][j] == 'Y') {
                m++;
                merge(i, j);
            }
        }
    }

    if (m < n - 1) {
        cout << "-1";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        int root = find(i);
        if (depth[root] < 2) {
            cout << "-1";
            return 0;
        }
        group.insert(root);
    }

    cout << group.size() - 1;
}