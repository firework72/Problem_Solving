#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    c -= b - a;
    a = b;
    if (c - b >= 0 && (c - b) % 3 == 0) {
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