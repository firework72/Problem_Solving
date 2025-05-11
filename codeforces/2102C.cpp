#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int n;
    cin >> n;
    int cur = 0;
    vector<vector<int>> ans(n*2+4, vector<int> (n*2+4, -1));

    int l = n, r = n;

    for (int i = 0; i < n; i++) {
        

        if (i % 2 == 0) {
            for (int j = l + 1; j <= r; j++) {
                ans[l][j] = cur++;
            }

            for (int j = l + 1; j <= r; j++) {
                ans[j][l] = cur++;
            }
            ans[l][l] = cur++;
            r++;
        }
        else {
            for (int j = l; j < r; j++) {
                ans[r][j] = cur++;
            }

            for (int j = l; j < r; j++) {
                ans[j][r] = cur++;
            }
            ans[r][r] = cur++;
            l--;
        }
    }

    for (int i = 0; i < 2*n+4; i++) {
        bool flag = false;
        for (int j = 0; j < 2*n+4; j++) {
            if (ans[i][j] == -1) continue;
            flag = true;
            cout << ans[i][j] << ' ';
        }
        if (flag) cout << '\n';
    }
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}