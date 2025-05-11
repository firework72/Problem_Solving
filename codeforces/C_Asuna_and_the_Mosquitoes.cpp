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
    vector<ll> v;
    ll odd = 0, even = 0;
    ll mx_odd = -1;
    int mx_odd_pos = -1;
    vector<ll> odd_list;
    vector<ll> even_list;

    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
        if (tmp % 2 == 0) {
            even += tmp;
            even_list.push_back(tmp);
        }
        else {
            odd += tmp;
            odd_list.push_back(tmp);
            if (mx_odd < tmp) {
                mx_odd = tmp;
                mx_odd_pos = i;
            }
        }
    }

    sort(odd_list.begin(), odd_list.end());
    sort(even_list.begin(), even_list.end());

    ll ans = -1;

    for (int i = 0; i < n; i++) {
        ans = max(ans, v[i]);
    }

    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 1) {
            odd -= v[i];
            if (odd >= even) {
                ans = max(ans, v[i] + 2 * even);
            }
            else {
                ans = max(ans, v[i] + max(2 * odd + 1, even));
            }
            odd += v[i];
        }
        else {
            even -= v[i];
            if (odd <= even) {
                ans = max(ans, v[i] + 2 * odd);
            }
            else {
                ans = max(ans, v[i] + max(2 * even + 1, odd));
            }
            even += v[i];
        }
    }

    cout << ans << '\n';

}


int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
}