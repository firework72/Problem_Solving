#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;
vector<int> v1, v2;

int main() {
    FAST_IO
    cin >> n;

    for (int i = 0; i < (n + 1) / 2; i++) {
        v1.push_back(i+1);
    }

    for (int i = (n + 1) / 2; i < n; i++) {
        v2.push_back(i+1);
    }

    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << v1[i / 2] << ' ';
        }
        else {
            cout << v2[i / 2] << ' ';
        }
    }
}