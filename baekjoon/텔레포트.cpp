#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 1005
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

struct Node {
    int s;
    int x;
    int y;
};

int n, m, t;

vector<Node> node;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dist[SIZE] = {0};

int main() {
    FAST_IO
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int s, x, y;
        cin >> s >> x >> y;
        node.push_back({s, x, y});
    }

    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        for (int i = 0; i < n; i++) {
            dist[i] = INF;
        }

        ll mx = abs(node[s].x - node[e].x) + abs(node[s].y - node[e].y);

        pq.push({0, s});
        while (!pq.empty()) {
            int cur = pq.top().second;
            int curCost = pq.top().first;
            pq.pop();
            if (curCost > dist[cur]) continue;
            for (int i = 0; i < n; i++) {
                if (i == cur) continue;
                int next = i;
                int cost = abs(node[cur].x - node[next].x) + abs(node[cur].y - node[next].y);
                if (node[cur].s == 1 && node[next].s == 1) cost = min(cost, t);
                if (curCost + cost < dist[next]) {
                    dist[next] = curCost + cost;
                    if (dist[next] < mx) pq.push({dist[next], next});
                }
            }
        }

        cout << dist[e] << '\n';
    }
}