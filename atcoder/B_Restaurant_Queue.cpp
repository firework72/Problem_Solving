#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;
queue<int> q;

int main() {
    FAST_IO
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            q.push(x);
        }
        else {
            cout << q.front() << '\n';
            q.pop();
        }
    }
}