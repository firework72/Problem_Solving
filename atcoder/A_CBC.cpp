#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

string s;

int main() {
    FAST_IO
    cin >> s;
    for (int i = 0 ; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') cout << s[i];
    }
}