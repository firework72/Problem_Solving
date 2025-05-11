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
    int mx = -1;
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        mx = max(mx, tmp);
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == mx) cnt++;
    }

    if (cnt == n) {
        cout << "No\n";
        return;
    }

    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == mx) {
            pos = i;
            break;
        }
    }

    cout << "Yes\n";

    for (int i = 0; i < n; i++) {
        if (i == pos) {
            cout << "1 ";
        }
        else {
            cout << "2 ";
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