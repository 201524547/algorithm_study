#include <iostream>
#include <algorithm>

using namespace std;

double Arr[10001];
double SumArr[10001];

int main()
{
    int N;
    double tmp = 0;

    cin >> N;

    for(int i = 0; i < N; i++){

        cin >> Arr[i];

    }

    SumArr[0] = Arr[0];
    tmp = Arr[0];

    for(int i = 1; i < N; i++){
            SumArr[i] = max(SumArr[i-1]*Arr[i],Arr[i]);
            tmp = max(SumArr[i], tmp);
    }
    cout << fixed;
    cout.precision(3);
    cout << tmp ;

    return 0;

}
