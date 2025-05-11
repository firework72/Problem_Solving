#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FAST_IO std::cin.tie(NULL); std::cout.tie(NULL); std::ios_base::sync_with_stdio(false);
#define SIZE 605
#define INF 987654321
#define MOD 1000000007
#define FLAG 10000

int n;
vector<pair<int, int>> s(SIZE, {0, 0}), e(SIZE, {0, 0});
struct Node {
    int s;
    int e;
    long double dist;
};

vector<Node> node;

bool comp(Node n1, Node n2) {
    return n1.dist < n2.dist;
}

int capacity[SIZE][SIZE] = {0};
int flow[SIZE][SIZE] = {0};
int lv[SIZE] = {0};
int flag[SIZE] = {0};
int totalFlow = 0;
vector<int> edge[SIZE];

bool bfs() {
    for (int i = 0; i <= n * 2 + 2; i++ ) {
        lv[i] = INF;
    }

    lv[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : edge[cur]) {
            if (capacity[cur][next] - flow[cur][next] > 0 && lv[cur] + 1 < lv[next]) {
                lv[next] = lv[cur] + 1;
                q.push(next);
            }
        }
    }

    return lv[n * 2 + 1] != INF;
}


int dfs(int cur, int curFlow) {
    if (cur == n * 2 + 1) {
        return curFlow;
    }

    for (int i = flag[cur]; i < edge[cur].size(); i++) {
        int next = edge[cur][i];
        if (capacity[cur][next] - flow[cur][next] > 0 && lv[cur] + 1 == lv[next]) {
            int tmp = dfs(next, min(curFlow, capacity[cur][next] - flow[cur][next]));
            if (tmp > 0) {
                return tmp;
            }
        }
        flag[cur]++;
    }

    return 0;
}

int main() {
    FAST_IO
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        s[i] = {a, b};
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        int a, b;
        cin >> a >> b;
        s[i] = {a, b};
    }

    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            node.push_back({i, j, sqrt(abs(s[i].first - s[j].first) * abs(s[i].first - s[j].first) + abs(s[i].second - s[j].second) * abs(s[i].second - s[j].second))});
        }
    }

    sort(node.begin(), node.end());

    for (int i = 1; i <= n; i++) {
        edge[0].push_back(i);
        edge[i].push_back(0);
        capacity[0][i] = 1;
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        edge[i].push_back(2 * n + 1);
        edge[2 * n + 1].push_back(i);
        capacity[i][2 * n + 1] = 1;
    }

    for (int i = 0; i < node.size(); i++) {
        edge[node[i].s].push_back(node[i].e);
        edge[node[i].e].push_back(node[i].s);
        capacity[node[i].s][node[i].e] = 1;

        while (bfs()) {
            for (int i = 0; i <= 2 * n + 1; i++) {
                flag[i] = 0;
            }

            while (1) {
                int curFlow = dfs(0, INF);
                if (curFlow == 0) break;
                totalFlow += curFlow;
                if (totalFlow == n) {
                    cout << node[i].dist;
                    return 0;
                }
            }
        }
    }
}