#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

void solve() {
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
        sum += tmp;
    }

    sort(v.begin(), v.end());
    v[n-1]--;

    sort(v.begin(), v.end());
    if (v[n-1] - v[0] > k) {
        cout << "Jerry\n";
    }
    else {
        if (sum % 2 == 0) {
            cout << "Jerry\n";
        }
        else {
            cout << "Tom\n";
        }
    }
}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}