#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n, k;
int cnt = 0;
int cur = 0;
string s, ans;
vector<pair<int, int>> area;

int main() {
    FAST_IO
    cin >> n >> k;
    cin >> s;
    ans = s;
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && s[i-1] == 'o') ans[i] = '.';
        if (i + 1 < n && s[i+1] == 'o') ans[i] = '.';

        if (s[i] == 'o') cnt++;
    }

    // ?를 모두 .으로 채워야 한다.
    if (cnt == k) {
        for (int i = 0; i < n; i++) {
            if (ans[i] == '?') ans[i] = '.';
        }
        cout << ans;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == '?') {
            cur++;
        }
        else {
            if (cur >= 1) {
                cnt += (cur + 1) / 2;
                area.push_back({i - cur, i - 1});
                cur = 0;
            }
        }
    }

    if (cur >= 1) {
        cnt += (cur + 1) / 2;
        area.push_back({n - cur, n - 1});
        cur = 0;
    }

    if (cnt == k) {
        for (auto i : area) {
            if ((i.second - i.first + 1) % 2 == 1) {
                for (int j = 0; j < i.second - i.first + 1; j++) {
                    if (j % 2 == 0) {
                        ans[i.first + j] = 'o';
                    }
                    else {
                        ans[i.first + j] = '.';
                    }
                }
            }
        }
    }
    cout << ans;
}