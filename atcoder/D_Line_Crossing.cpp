#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 1000006
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

ll cnt[SIZE] = {0};
int n, m;
ll sum = 0;
ll ans = 0;

int main() {
    FAST_IO
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cnt[(a + b) % n]++;
    }
    sum = m;

    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) continue;
        sum -= cnt[i];
        ans += sum * cnt[i];
    }
    cout << ans;
}