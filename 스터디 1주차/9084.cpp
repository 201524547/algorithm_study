#include <iostream>
#include <algorithm>

using namespace std;

int coin[21];
int money[10001];

int main(){
    int case_;
    cin >> case_;

    int N, M;

    while(case_--){
        cin >> N;
        for(int i = 0; i < N;i++){
            cin >> coin[i];
        }
        cin >> M;

        money[0] = 1;
        for(int i = 1; i <= M; i++){
            for(int j = 0; j < N; j++){
                if(i - coin[j] >= 0)
                    money[i] += money[i - coin[j]];
            }
        }

        cout << money[M] << endl;

    }

}
