#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> meetings[100001];

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        meetings[i] = {a,b};
    }
    sort(meetings, meetings+N,compare);
    int meeting = 0;
    int end_time = 0;
    for(int i = 0; i < N; i++){
        int _start = meetings[i].first;
        int _end = meetings[i].second;
        if(_start >= end_time){
                end_time = _end;
                meeting++;
        }

    }
    cout << meeting;
};
