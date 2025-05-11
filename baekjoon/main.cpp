#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int penalty[129] = {0};
int accepted = 0;
int p = 0;

int main() {
    FAST_IO
    while (1) {
        int a;
        char b;
        string c;
        cin >> a;
        if (a == -1) break;
        cin >> b >> c;
        if (c == "right") {
            accepted++;
            p += a + penalty[b];
        }
        else {
            penalty[b] += 20;
        }
    }

    cout << accepted << ' ' << p;
}