#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;
ll sum = 0;
ll ans = 0;
vector<ll> v;

int main() {
    FAST_IO
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        sum -= v[i];
        ans += v[i] * sum;
    }
    
    cout << ans;
}