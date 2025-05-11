#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 600005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int isNotPrime[SIZE] = {0};
vector<ll> prime;
vector<pair<ll, int>> v;
vector<ll> candidate;

void makePrime() {
    for (int i = 2; i * i < SIZE; i++) {
        if (isNotPrime[i]) continue;
        for (int j = i * 2; j < SIZE; j += i) {
            isNotPrime[j] = 1;
        }
    }

    for (int i = 2; i <= 600000; i++) {
        if (isNotPrime[i] == 0) prime.push_back(i);
    }
}

int main() {
    FAST_IO
    makePrime();
    //cout << prime.size() << '\n';

    for (int i = 0; i < prime.size(); i++) {
        ll cur = 1;
        while (1) {
            cur *= prime[i];
            if (cur > 1000000000000) break;
            cur *= prime[i];
            if (cur > 1000000000000) break;
            v.push_back({cur, prime[i]});
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i].second == v[j].second) continue;
            if (v[i].first * v[j].first > 1000000000000) break;
            candidate.push_back(v[i].first * v[j].first);
        }
    }

    sort(candidate.begin(), candidate.end());

    int q;
    cin >> q;
    while (q--) {
        ll a;
        cin >> a;
        int pos = upper_bound(candidate.begin(), candidate.end(), a) - candidate.begin();
        pos--;
        cout << candidate[pos] << '\n';
    }

}