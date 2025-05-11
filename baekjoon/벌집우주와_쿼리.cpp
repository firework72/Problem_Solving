#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int q;

int main() {
    FAST_IO
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x >= 0 && y == 0) {
            cout << "0";
        }
        else if (x == y || x >= 0 || (x < 0 && y == 0) || x > y) {
            cout << "1";
        }
        else {
            cout << "2";
        }
        cout << '\n';
    }
}