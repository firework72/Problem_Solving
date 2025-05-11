#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int login = 0;
int n;
int ans = 0;

int main() {
    FAST_IO
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "login") login = 1;
        if (s == "logout") login = 0;
        if (s == "private" && login == 0) ans++; 
    }

    cout << ans;
}