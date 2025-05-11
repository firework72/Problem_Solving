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

    int tmp1 = 0, tmp2 = 0;

    for (int i = 0; i < n; i++) {
        char c;
        if (i % 2 == 0) {
            c = s[i];
        }
        else {
            c = t[i];
        }

        if (c == '1') tmp1++;
    }

    for (int i = 0; i < n; i++) {
        char c;
        if (i % 2 == 0) {
            c = t[i];
        }
        else {
            c = s[i];
        }

        if (c == '1') tmp2++;
    }

    if (tmp1 > n / 2 || tmp2 > (n + 1) / 2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}