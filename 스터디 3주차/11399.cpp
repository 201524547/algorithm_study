#include <iostream>
#include <algorithm>

using namespace std;

int P[1001];

int main(){

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }
    sort(P,P+N,less<int>());
    int _time = 0;
    for(int i = 0; i < N; i++){
        _time += (N-i) * P[i];
    }
    cout << _time;

}
