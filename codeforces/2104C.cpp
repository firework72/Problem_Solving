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
    if (s[0] == s[n-1]) {
        if (s[0] == 'A') {
            cout << "Alice\n";
        }
        else {
            cout << "Bob\n";
        }
    }
    else if (s[0] == 'B') {
        int a_max = -1;
        int b_max = -1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'A') a_max = i;
            else if (s[i] == 'B') b_max = i;
        }

        if (a_max > b_max) {
            cout << "Alice\n";
        }
        else {
            cout << "Bob\n";
        }
    }
    else if (s[n-1] == 'B') {
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            cnt += s[i] == 'B';
        }
        if (cnt == 0) {
            cout << "Alice\n";
        }
        else {
            cout << "Bob\n";
        }
    }
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}