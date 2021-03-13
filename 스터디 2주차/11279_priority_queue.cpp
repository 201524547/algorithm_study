#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while(N--){
        int x;
        cin >> x;
        if(x){
            pq.push(x);
        }else{
            if(pq.empty()) cout << 0 << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
    return 0;
}
