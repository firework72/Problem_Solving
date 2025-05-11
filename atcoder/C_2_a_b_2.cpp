#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

ll n;
ll ans = 0;

int main() {
    FAST_IO
    cin >> n;
    
    ll target = n / 2;

    ll start = 0;
    ll end = 1e9+9;

    while (start <= end) {
        ll mid = (start + end) / 2;
        if (mid * mid <= target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    ans += end;

    target = n / 4;
    start = 0;
    end = 1e9+9;
    while (start <= end) {
        ll mid = (start + end) / 2;
        if (mid * mid <= target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    ans += end;

    cout << ans;
}