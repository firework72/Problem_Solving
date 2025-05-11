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
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(n+3, vector<int>(4, 0));
    vector<vector<int>> field(n+3, vector<int>(2, 0));

    for (int i = 1; i <= n; i++) {
        if (s[i-1] == 'A') field[i][0] = 1;
        if (t[i-1] == 'A') field[i][1] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {
            dp[i+2][2] = max(dp[i+2][2], dp[i][3] + (field[i+1][0] + field[i+1][1] + field[i+2][1] >= 2));
            dp[i+2][1] = max(dp[i+2][1], dp[i][3] + (field[i+1][0] + field[i+1][1] + field[i+2][0] >= 2));
            dp[i+3][3] = max(dp[i+3][3], dp[i][3] + (field[i+1][0] + field[i+2][0] + field[i+3][0] >= 2) + (field[i+1][1] + field[i+2][1] + field[i+3][1] >= 2));
        }
        else if (i % 3 == 2) {
            dp[i+1][3] = max(dp[i+1][3], dp[i][2] + (field[i][0] + field[i+1][0] + field[i+1][1] >= 2));
            dp[i+1][3] = max(dp[i+1][3], dp[i][1] + (field[i][1] + field[i+1][0] + field[i+1][1] >= 2));

        
            dp[i+3][2] = max(dp[i+3][3], dp[i][2] + (field[i][0] + field[i+1][0] + field[i+2][0] >= 2) + (field[i+1][1] + field[i+2][1] + field[i+3][1] >= 2));
            dp[i+3][1] = max(dp[i+3][3], dp[i][1] + (field[i][1] + field[i+1][1] + field[i+2][1] >= 2) + (field[i+1][0] + field[i+2][0] + field[i+3][0] >= 2));
        }
    }

    cout << dp[n][3] << '\n';
}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();   
}