#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int n, r;
    cin >> n >> r;
    vector<int> v;
    int one = 0, two = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        two += v[i] / 2;
        one += v[i] % 2;
    }

    r -= two;

    cout << two * 2 + min(one, r * 2 - one) << '\n';
}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}