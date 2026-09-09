/*
깊이/너비 우선 탐색(DFS/BFS)
Level 3
느낀점: 앞으로 코딩 테스트 준비를 매일 해야한다. 10월에 코딩 테스트가 몰려있을 예정이기 때문에.
알고리즘 고득점 킷을 얼른 끝내고 기업 코딩 테스트 기출 문제를 제한 시간을 갖고 풀어야한다.
*/

#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &computers, vector<bool>& visit, int idx) {
    visit[idx] = true;
    
    for (int j = 0; j < computers[idx].size(); j++) {
        if (j == idx) continue;
        
        if (computers[idx][j] == 1 && !visit[j]) {
            dfs(computers, visit, j);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            dfs(computers, visit, i);
            answer++;
        }
    }
    
    return answer;
}
