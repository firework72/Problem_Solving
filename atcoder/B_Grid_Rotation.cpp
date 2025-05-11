#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 105
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

string s[SIZE];
string t[SIZE];

int n;
int tmp = 0;
int ans = INF;

int main() {
    FAST_IO
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != t[i][j]) tmp++;
        }
    }

    ans = min(ans, tmp);
    tmp = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != t[n - 1 - j][i]) tmp++;
        }
    }

    ans = min(ans, tmp + 3);
    tmp = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != t[n - 1 - i][n - 1 - j]) tmp++;
        }
    }

    ans = min(ans, tmp + 2);
    tmp = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != t[j][n - 1 - i]) tmp++;
        }
    }

    ans = min(ans, tmp + 1);
    tmp = 0;

    cout << ans;
}