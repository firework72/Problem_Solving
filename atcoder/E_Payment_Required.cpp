#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 5005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n, x;
long double prob[10][SIZE] = {0};
long double dp[1000][SIZE] = {0};

int main() {
    FAST_IO
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int s, c, p;
        cin >> s >> c >> p;
        long double cur_prob = 1.0;
        for (int j = 0; j <= x; j++) {
            if (j > 0 && j % c == 0) {
                cur_prob *= (long double) (100 - p) / 100;
            }
            cout << cur_prob << '\n';
            prob[i][j] = s * (1 - cur_prob);
        }
    }

    for (int i = 0; i <= x; i++) {
        dp[0][i] = 1.0;
    }

    for (int i = 1; i <= (1 << n); i++) {
        int mx = 0;
        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) mx = max(mx, 1 << j);
        }

        int p = i - mx;
        for (int j = 0; j <= x; j++) {
            dp[i][j] = 
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = max({dp[i][j], dp[i-1][j-k] + prob[i][k]});
            }
        }
    }

    cout << fixed;
    cout.precision(25);
    cout << dp[n][x];
}