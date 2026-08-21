/*
탐욕법 > 섬연결하기
level 3
알고리즘 자체는 Prim의 알고리즘을 사용해서 최소 비용의 엣지로만 연결을 하고
방문한 노드는 true로 변경
다익스트라 알고리즘이랑 굉장히 비슷하기 때문에 어렵지 않았으나 오랜만에 작성을 하기도 하여
priority_queue 초기화 방법을 까먹고 있었음.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

void mst(vector<vector<pair<int,int>>> &graph, vector<bool> &visit, int &answer) {
    visit[0] = true;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int i = 0; i < graph[0].size(); i++) {
        pq.push({graph[0][i].second, graph[0][i].first});
    }
    
    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (visit[node]) continue;
        
        answer += cost;
        visit[node] = true;
        for (int i = 0; i < graph[node].size(); i++) {
            pq.push({graph[node][i].second, graph[node][i].first});
        }
    }
}

int solution(int n, vector<vector<int>> costs) {
    vector<vector<pair<int,int>>> graph(n);
    vector<bool> visit(n, false);
    for (int i = 0; i < costs.size(); i++) {
        graph[costs[i][0]].push_back({costs[i][1], costs[i][2]});
        graph[costs[i][1]].push_back({costs[i][0], costs[i][2]});
    }
    int answer = 0;
    mst(graph, visit, answer);
    
    return answer;
}
