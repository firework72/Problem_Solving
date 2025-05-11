#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int s;

int main() {
    FAST_IO
    cin >> s;
    if (200 <= s && s <= 299) {
        cout << "Success";
    }
    else {
        cout << "Failure";
    }
}