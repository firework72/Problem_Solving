#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 200005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

string s;
int cnt[SIZE] = {0};

int main() {
    FAST_IO
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i]]++;
    }

    for (int i = 'a'; i <= 'z'; i++) {
        if (cnt[i] == 0) {
            cout << (char)i;
            return 0;
        }
    }
}