#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 25
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

vector<ll> val1[SIZE][SIZE], val2[SIZE][SIZE];
ll field[SIZE][SIZE] = {0};

int n, m;
ll ans = 0;

void dfs1(int r, int c, ll val) {
    if (r + c == n - 1) {
        val1[r][c].push_back(val);
        return;
    }

    dfs1(r + 1, c,(val + field[r+1][c]) % m);
    dfs1(r, c + 1, (val + field[r][c+1]) % m);
}

void dfs2(int sr, int sc, int r, int c, ll val) {
    if (r == n - 1 && c == n - 1) {
        val2[sr][sc].push_back(val);
        return;
    }

    if (r >= n || c >= n) {
        return;
    }

    dfs2(sr, sc, r+1, c, (val + field[r+1][c]) % m);
    dfs2(sr, sc, r, c+1, (val + field[r][c+1]) % m);
}

int main() {
    FAST_IO
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> field[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            field[i][j] %= m;
            for (int k = 0; k < (2 * n - 2 - i - j); k++) {
                field[i][j] *= 10;
                field[i][j] %= m;
            }
        }
    }

    dfs1(0, 0, field[0][0]);
    for (int i = 0; i < n; i++) {
        dfs2(i, n - i - 1, i, n - i - 1, 0);
        sort(val2[i][n-i-1].begin(), val2[i][n-i-1].end());
        for (ll j : val1[i][n-i-1]) {
            int pos = lower_bound(val2[i][n-i-1].begin(), val2[i][n-i-1].end(), m - j) - val2[i][n-i-1].begin();
            pos--;
            if (pos >= 0) {
                ans = max(ans, j + val2[i][n-i-1][pos]);
            }
            else {
                ans = max(ans, (j + val2[i][n-i-1].back()) % m);
            }
        }
    }

    cout << ans;
}