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
    vector<int> v;
    bool flag = false;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 1; i < n; i++) {
        if (abs(v[i]) > abs(v[0])) {
            cnt++;
        }
    }

    if (cnt >= (n + 1) / 2 - 1) {
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