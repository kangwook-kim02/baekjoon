/*
다이나믹 프로그래밍 > 등굣길
Level 3
느낀점: 문해기 시간에 비슷한 문항을 풀어본 느낌이 있었으나
버그가 하나 있었다.
첫번째 행을 1로 채우는 과정과
첫번째 열을 1로 채우는 과정에서
물 웅덩이를 만나면 지나가지 못하기 때문에 break를 했어야했지만
기존에 continue를 해버려서 로직에 문제가 생겼었음
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> minRoute(n, vector<int>(m, 0));
    for (int i = 0; i < puddles.size(); i++) {
        minRoute[puddles[i][1]-1][puddles[i][0]-1] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        if (minRoute[i][0] == -1) break;
        minRoute[i][0] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        if (minRoute[0][i] == -1) break;
        minRoute[0][i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (minRoute[i][j] == -1) continue;
            
            int up = minRoute[i-1][j];
            int left = minRoute[i][j-1];
            
            if (up == -1) {
                up = 0;
            }
            
            if (left == -1) {
                left = 0;
            }
            
            minRoute[i][j] = (up%1000000007)+(left%1000000007);
            
        }
    } 
    
    
    int answer = minRoute[n-1][m-1]%1000000007;
    return answer;
}
