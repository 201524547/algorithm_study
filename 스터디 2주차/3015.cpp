#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<pair<int,int>> s;
int audiance[500001];

int main(){
    int N;
    cin >> N;
    long long ans = 0;
    for(int i = 0; i < N; i++){
        cin >> audiance[i];
    }

    for(int i = 0; i < N; i++){
        int dup = 1;
        while(!s.empty() && s.top().first <= audiance[i]){
            ans += s.top().second;
            if(s.top().first == audiance[i]){
                dup = s.top().second + 1;
            }
            else{
                dup = 1;
            }
            s.pop();
        }
        if(!s.empty())ans++;
        s.push({audiance[i],dup});
    }
    cout << ans;
}
