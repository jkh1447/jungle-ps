#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int cost;
    int alp;
    int cop;
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) {
        return a.cost > b.cost;
    }
};

int dist[151][151];

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    for(int i=0; i<151; i++)
        fill(dist[i], dist[i]+151, 1e9);
    int max_alp = 0, max_cop = 0;
    for (auto& p : problems) {
        max_alp = max(max_alp, p[0]);
        max_cop = max(max_cop, p[1]);
    }
    
    priority_queue<Node, vector<Node>, CompareNode> pq;
    
    pq.push({0, alp, cop});
    dist[alp][cop] = 0;
    
    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();

        if (cur.alp >= max_alp && cur.cop >= max_cop) {
            answer = cur.cost;
            break;
        }

        if (dist[cur.alp][cur.cop] != cur.cost) continue;

        int nxt_alp = min(cur.alp + 1, max_alp);
        int nxt_cop = min(cur.cop + 1, max_cop);

        if (dist[nxt_alp][cur.cop] > cur.cost + 1) {
            dist[nxt_alp][cur.cop] = cur.cost + 1;
            pq.push({ cur.cost + 1, nxt_alp, cur.cop });
        }
        if (dist[cur.alp][nxt_cop] > cur.cost + 1) {
            dist[cur.alp][nxt_cop] = cur.cost + 1;
            pq.push({ cur.cost + 1, cur.alp, nxt_cop });
        }

        for (auto& p : problems) {
            if (p[0] <= cur.alp && p[1] <= cur.cop) {

                int n_alp = min(cur.alp + p[2], max_alp);
                int n_cop = min(cur.cop + p[3], max_cop);

                if (dist[n_alp][n_cop] > cur.cost + p[4]) {
                    dist[n_alp][n_cop] = cur.cost + p[4];
                    pq.push({ cur.cost + p[4], n_alp, n_cop });

                }
            }
        }
    }
    
    return answer;
}