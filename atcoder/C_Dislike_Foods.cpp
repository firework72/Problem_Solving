#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 300005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

vector<int> v[SIZE];
int cnt[SIZE] = {0};
int ans = 0;
int n, m;

int main() {
    FAST_IO
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        cnt[i] = k;
        while (k--) {
            int x;
            cin >> x;
            v[x].push_back(i);
        }
    }

    for (int i = 1; i <= m; i++) {
        if (cnt[i] == 0) ans++;
    }

    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        for (int j : v[b]) {
            cnt[j]--;
            if (cnt[j] == 0) ans++;
        }
        cout << ans <<'\n';
    }
}