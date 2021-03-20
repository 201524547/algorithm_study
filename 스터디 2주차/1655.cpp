#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> max_queue;
priority_queue<int, vector<int>,greater<int>> min_queue;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int case_;
    cin >> case_;

    int x;
    cin >> x;
    max_queue.push(x);
    cout << x;

    for(int i = 1; i < case_; i++){
        int x;
        cin >> x;
        if(i % 2 == 0){
            max_queue.push(x);
        }
        if(i % 2 == 1){
            min_queue.push(x);
        }
        if(max_queue.top() > min_queue.top()){
            int a = max_queue.top();
            int b = min_queue.top();

            max_queue.pop();
            min_queue.pop();

            max_queue.push(b);
            min_queue.push(a);
        }
        cout << max_queue.top() << "\n";
    }
}
