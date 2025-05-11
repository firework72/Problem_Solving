#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    ll x, y, a;
    cin >> x >> y >> a;
    a %= (x + y);

    if (x < a + 0.5) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}