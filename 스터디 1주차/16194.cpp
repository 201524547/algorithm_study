#include <iostream>
#include <algorithm>

using namespace std;

int card_price_array[1001];
int dp[1001];

int main() {

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> card_price_array[i];
        dp[i]= 999999;
    }

    dp[1] = card_price_array[1]
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = min(dp[i],dp[i-j]+card_price_array[j]);
        }
    }

    cout << dp[N];
    return 0;
}
