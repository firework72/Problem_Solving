#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n, k;
int ans = 0;
int z[SIZE] = {0};
string s;

int main() {
    FAST_IO
    cin >> n >> k;
    cin >> s;

    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (r < i) {
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                r = i + z[i];
                l = i;
                z[i]++;
            }
        }
        else {
            if (z[i - l] <= r - i) {
                z[i] = z[i - l];
            }
            else {
                z[i] = r - i;
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                    r = i + z[i];
                    l = i;
                    z[i]++;
                }
            }
        }
    }

    z[0] = n;

    for (int i = 1; i <= n; i++) {
        bool fail = false;
        for (int j = 0; j < n; j += i) {
            if (z[j] < min(i, n - j)) {
                fail = true;
            }
        }

        if (!fail) {
            int flag = n / i * i;
            if (n % i != 0) flag += i;
            flag = max(flag, i * 2);
            if (n + k >= flag) {
                ans = max(ans, i);
            }
        }
    }

    cout << ans;
}