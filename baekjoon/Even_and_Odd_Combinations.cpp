#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int n, k;
    cin >> n >> k;

    ll val = 0;
    
    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        val |= (1ll << (tmp - 1));
    }

    val ^= 1;

    int bitCnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if ((val & (1ll << i)) != 0) {
            ans.push_back(i+1);
            bitCnt++;
        }
    }

    cout << n << ' ' << ans.size() << '\n';

    for (int i : ans) {
        cout << i << ' ';
    }

    
    cout << '\n';
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}