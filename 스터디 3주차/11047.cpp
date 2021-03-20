#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int coin[11];

int main(){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> coin[i];
    }
    sort(coin, coin + N, greater<int>());

    int min_coin = 0;
    for(int i = 0; i < N; i++){
        if(K >= coin[i]){
            min_coin += K / coin[i];
            K = K % coin[i];
        }
    }
    cout << min_coin;
    return 0;
}
