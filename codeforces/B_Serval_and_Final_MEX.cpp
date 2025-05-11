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
    vector<int> v, pos;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        if (tmp == 0) {
            pos.push_back(i);
        }
    }

    if (pos.size() == 0) {
        cout << "1\n";
        cout << "1 " << n << '\n';
    }
    else if (pos.size() == 1) {
        cout << "2\n";
        if (pos[0] == n - 1) {
            cout << n-1 << ' ' << n << '\n';
        }
        else {
            cout << pos[0] + 1 << ' ' << pos[0] + 2 << '\n';
        }
        cout << "1 " << n - 1 << '\n';
    }
    else {
        if (pos[0] == 0 && pos.back() == n - 1) {
            cout << "3\n";
            cout << "1 2\n";
            cout << "2 " << n-1 << '\n';
            cout << "1 2\n";
        }
        else {
            cout << "2\n";
            cout << pos[0] + 1 << ' ' << pos.back() + 1 << '\n';
            cout << "1 " << n - (pos.back() - pos[0]) << '\n';
        }
    }
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}