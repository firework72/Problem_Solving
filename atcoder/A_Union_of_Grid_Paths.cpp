#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int h, w;
    cin >> h >> w;
    int d = h-1, r = w-1;
    string s;
    cin >> s;
    for (int i = 0; i < h + w - 2; i++) {
        if (s[i] == 'D') d--;
        if (s[i] == 'R') r--;
    }

    vector<int> mn(w+2, INF), mx(w+2, -1);

    int a = 0, b = 0;
    mn[b] = a, mx[b] = a;

    for (int i = 0; i < h + w - 2; i++) {
        if (s[i] == 'D') {
            a++;
        }
        else if (s[i] == 'R') {
            b++;
        }
        else {
            if (d > 0) {
                a++;
                d--;
            }
            else {
                b++;
                r--;
            }
        }

        mn[b] = min(mn[b], a);
        mx[b] = max(mx[b], a);
    }

    d = h-1, r = w-1;
    for (int i = 0; i < h + w - 2; i++) {
        if (s[i] == 'D') d--;
        if (s[i] == 'R') r--;
    }
    a = 0, b = 0;

    for (int i = 0; i < h + w - 2; i++) {
        if (s[i] == 'D') {
            a++;
        }
        else if (s[i] == 'R') {
            b++;
        }
        else {
            if (r > 0) {
                b++;
                r--;
            }
            else {
                a++;
                d--;
            }
        }

        mn[b] = min(mn[b], a);
        mx[b] = max(mx[b], a);
    }

    ll ans = 0;
    for (int i = 0; i < w; i++) {
        ans += mx[i] - mn[i] + 1;
    }
    cout << ans << '\n';
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}