/*
동적계획법 > 정수 삼각형
Level 3
느낀점: 어렵진 않았으나, 벡터 접근할 때 코드가 조금 헷갈림
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle.size());
    dp[0].push_back(triangle[0][0]);
    dp[1].push_back(dp[0][0]+triangle[1][0]);
    dp[1].push_back(dp[0][0]+triangle[1][1]);
    for (int i = 2; i < dp.size(); i++) {
        for (int j = 0; j < dp[i-1].size(); j++) {
            if (j == 0) {
                dp[i].push_back(dp[i-1][j] + triangle[i][j]);
                continue;
            }
            dp[i].push_back(max(dp[i-1][j]+triangle[i][j], dp[i-1][j-1]+triangle[i][j]));
        }
        dp[i].push_back(dp[i-1][dp[i-1].size()-1]+triangle[i][triangle[i].size()-1]);
    }
    int answer = 0;
    
    for (int j = 0; j < dp[dp.size()-1].size(); j++) {
        cout << dp[dp.size()-1][j] << " ";
        answer = max(answer, dp[dp.size()-1][j]);
    }
    
    return answer;
}
