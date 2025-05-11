#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int r, x;

int main() {
    FAST_IO
    cin >> r >> x;
    if (x == 1) {
        if (1600 <= r && r <= 2999) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
    }
    else {
        if (1200 <= r && r <= 2399) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
    }
}