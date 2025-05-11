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
    string s;
    cin >> s;
    vector<int> cnt(129, 0);

    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }

    vector<int> ans;

    for (int i = 0; i < 2 * n + 2; i++) {
        if (cnt['L'] == cnt['I'] && cnt['I'] == cnt['T']) break;
        vector<pair<int, int>> v;
        v.push_back({cnt['L'], 'L'});
        v.push_back({cnt['I'], 'I'});
        v.push_back({cnt['T'], 'T'});
        sort(v.begin(), v.end());

        for (int j = 0; j < 3; j++) {
            bool flag = false;
            for (int k = 0; k < n - 1; k++) {
                if (s[k] != s[k+1] && s[k] != v[j].second && s[k+1] != v[j].second) {
                    s.insert(s.begin() + k + 1, v[j].second);
                    ans.push_back(k+1);
                    cnt[v[j].second]++;
                    //cout << s << '\n';
                    flag = true;
                    break;
                }
            }

            if (flag) break;
        }
    }

    if (cnt['L'] == cnt['I'] && cnt['I'] == cnt['T'] && ans.size() <= 2 * n) {
        cout << ans.size() << '\n';
        for (int i : ans) {
            cout << i << '\n';
        }
    }
    else {
        cout << "-1\n";
    }
}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}