#include <iostream>
#include <algorithm>

using namespace std;

int positive_number[10001];
int negative_number[10001];

int main(){
    int N;
    cin >> N;

    int pi=0, ni=0;
    int one = 0;
    for(int i = 0; i < N; i++){
        int a = 0;
        cin >> a;
        if(a == 1) one++;
        else if(a > 0) positive_number[pi++] = a;
        else negative_number[ni++] = a;
    }
    sort(positive_number, positive_number + pi, greater<int>());
    sort(negative_number, negative_number + ni);

    int total = 0;
    for(int i = 0; i < pi / 2; i++){
        total += positive_number[2*i] * positive_number[2*i+1];
    }
    if( pi % 2 ) total += positive_number[pi-1];
    for(int i = 0; i < ni / 2; i++){
        total += negative_number[2*i] * negative_number[2*i+1];
    }
    if( ni % 2 ) total += negative_number[ni-1];

    cout << total+one;
}
