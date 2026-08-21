/*
탐욕법 > 단속카메라
Level 3

로직 자체는틀리지 않았으나
 if (pq.top().first <= t) {
            while (!pq.empty()) {
                pq.pop();
            }
            cout << "==카메라 설치 시점==\n";
            cout << t << "\n";
            answer++;
        }

조건을 검사하는 부분에서
!pq.empty() && 이걸 생각하지 못했다.
따라서 이 조건 하나 때문에 테스트 케이스에 실패했었다.
프로그래머스는 성공/실패만 알려주기 때문에 실제로 에러가 발생한 건지, 로직이 문제인건지 모른다.
로직의 문제점만 찾으려다 보니 시간을 낭비하게 되었다.
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), comp);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    int t = routes[0][0];
    pq.push({routes[0][1], routes[0][0]});
    int idx = 1;
    while (t <= 30000 && idx < routes.size()) {
        while (idx < routes.size() && routes[idx][0] <= t) {
            pq.push({routes[idx][1],routes[idx][0]});
            idx++;
        }
        
        if (!pq.empty() && pq.top().first <= t) {
            while (!pq.empty()) {
                pq.pop();
            }
            cout << "==카메라 설치 시점==\n";
            cout << t << "\n";
            answer++;
        }
        
        
        t++;
    }
    
    if (!pq.empty()) answer++;
    return answer;
}
