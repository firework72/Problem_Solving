#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 1000005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n, k;
string s;
int q;

vector<int> pos[129];
int dp[SIZE] = {0};

vector<int> target_pos(129, 0);

int main() {
    FAST_IO
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) {
        pos[s[i]].push_back(i);
    }
    for (int i = 'a'; i <= 'z'; i++) {
        pos[i].push_back(n);
    }
    for (int i = 0; i < 129; i++) {
        target_pos[i] = n;
    }
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        int mn = INF;
        for (int j = 'a'; j < 'a' + k; j++) {
            mn = min(mn, dp[target_pos[j]]);
        }

        dp[i] = mn + 1;
        target_pos[s[i]] = i;
    }
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int cur = -1;
        for (int i = 0; i < t.size(); i++) {
            int selected = upper_bound(pos[t[i]].begin(), pos[t[i]].end(), cur) - pos[t[i]].begin();
            cur = pos[t[i]][selected];
            if (cur >= n) break;
        }

        cout << dp[cur] << '\n';
    }
}