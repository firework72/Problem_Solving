#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 2005
#define INF 1000000007
#define MOD 987654321
#define FLAG 500000

int n, q;
char field[SIZE][SIZE] = {0};
ll prefix_sum[SIZE][SIZE] = {0};

ll getArea(int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return 0;
    return prefix_sum[r2][c2] - prefix_sum[r1 - 1][c2] - prefix_sum[r2][c1 - 1] + prefix_sum[r1 - 1][c1 - 1];
}

int main() {
    FAST_IO
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            field[i][j] = s[j-1];
            field[i+n][j] = field[i][j+n] = field[i+n][j+n] = field[i][j];
        }
    }

    for (int i = 1; i <= n*2; i++) {
        for (int j = 1; j <= n*2; j++) {
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + (field[i][j] == 'B');
        }
    }

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        ll ans = 0;
        ll tmp = 0;

        ll square = getArea(a%n+1, b%n+1, a%n+n, b%n+n);

        tmp = square * ((c - a) / n);
        tmp += getArea(a%n+1, b%n+1, a%n+1 + (c - a) % n, b%n+n);
        tmp *= (d - b) / n;
        ans += tmp;

        tmp = 0;

        square = getArea(a%n+1, b%n+1, a%n+n, b%n+1 + (d - b) % n);

        tmp = square * ((c - a) / n);
        tmp += getArea(a%n+1, b%n+1, a%n+1 + (c - a) % n, b%n+1 + (d - b) % n);

        ans += tmp;

        cout << ans << '\n';
    }
}

