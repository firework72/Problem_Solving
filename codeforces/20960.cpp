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
    int l = 1, r = 2;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<') r++;
    }
    l = r - 1;
    cout << l << ' ';
    l--;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '>') {
            cout << r << ' ';
            r++;
        }
        else {
            cout << l << ' ';
            l--;
        }
    }

    cout << '\n';
}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}