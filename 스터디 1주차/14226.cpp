#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// {emo, clipBoard, time}
typedef pair<int, pair<int,int>> pii;

int checked[1001][1001];

int BFS(int s){

    queue<pii> q;
    q.push({1,{0,0}});

    while(1){
        pii a = q.front();
        q.pop();

        int emo = a.first;
        int clipBoard = a.second.first;
        int time = a.second.second;
        checked[emo][clipBoard] = 1;

        if(emo == s)
            return time;

        // clipboard에 복사하는 부분
        if(!checked[emo][emo]){
            q.push({emo,{emo, time+1}});
        }
        // 삭제하는 부분
        if(emo > 1 && !checked[emo-1][clipBoard]){
        q.push({emo-1,{clipBoard,time+1}});
        }
        if(clipBoard > 0 && emo+clipBoard < 1001 && !checked[emo+clipBoard][clipBoard])
        q.push({emo+clipBoard,{clipBoard,time+1}});

    }
    return 0;
}

int main(){

    int s;
    cin >> s;

    cout << BFS(s);
    return 0;
}
