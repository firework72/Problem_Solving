#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;
string s, t;
int ans = 0;

int main() {
    FAST_IO
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) ans++;
    }

    cout << ans;
}