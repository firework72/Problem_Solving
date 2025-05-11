#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 1e18+9
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> field(n+2, vector<ll>(n+1, -1));
    vector<vector<ll>> dp1(n+2, vector<ll>(2, INF));
    vector<vector<ll>> dp2(n+2, vector<ll>(2, INF));
    vector<ll> a(n+2, 0), b(n+2, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> field[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            dp1[1][0] = 0;
            dp1[1][1] = a[1];
        }
        else {
            bool flag0 = true, flag1 = true;
            for (int j = 1; j <= n; j++) {
                if (field[i-1][j]  == field[i][j]) flag0 = false;
                if (field[i-1][j] + 1 == field[i][j]) flag1 = false;
            }

            if (flag0) {
                dp1[i][0] = min(dp1[i][0], dp1[i-1][0]);
            }
            if (flag1) {
                dp1[i][0] = min(dp1[i][0], dp1[i-1][1]);
            }

            flag0 = true, flag1 = true;
            for (int j = 1; j <= n; j++) {
                if (field[i-1][j]  == field[i][j] + 1) flag0 = false;
                if (field[i-1][j] + 1 == field[i][j] + 1) flag1 = false;
            }

            if (flag0) {
                dp1[i][1] = min(dp1[i][1], dp1[i-1][0] + a[i]);
            }
            if (flag1) {
                dp1[i][1] = min(dp1[i][1], dp1[i-1][1] + a[i]);
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        if (j == 1) {
            dp2[1][0] = 0;
            dp2[1][1] = b[1];
        }
        else {
            bool flag0 = true, flag1 = true;
            for (int i = 1; i <= n; i++) {
                if (field[i][j-1]  == field[i][j]) flag0 = false;
                if (field[i][j-1] + 1 == field[i][j]) flag1 = false;
            }

            if (flag0) {
                dp2[j][0] = min(dp2[j][0], dp2[j-1][0]);
            }
            if (flag1) {
                dp2[j][0] = min(dp2[j][0], dp2[j-1][1]);
            }

            flag0 = true, flag1 = true;
            for (int i = 1; i <= n; i++) {
                if (field[i][j-1]  == field[i][j] + 1) flag0 = false;
                if (field[i][j-1] + 1 == field[i][j] + 1) flag1 = false;
            }

            if (flag0) {
                dp2[j][1] = min(dp2[j][1], dp2[j-1][0] + b[j]);
            }
            if (flag1) {
                dp2[j][1] = min(dp2[j][1], dp2[j-1][1] + b[j]);
            }
        }
    }

    if (min(dp1[n][0], dp1[n][1]) + min(dp2[n][0], dp2[n][1]) >= INF) {
        cout << "-1\n";
    }
    else {
        cout << min(dp1[n][0], dp1[n][1]) + min(dp2[n][0], dp2[n][1]) << '\n';
    }
}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}