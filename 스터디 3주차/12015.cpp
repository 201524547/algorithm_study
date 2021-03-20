#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main(){
    int N;
    cin >> N;

    int a;
    cin >> a;
    arr.push_back(a);

    for(int i = 1; i < N; i++){
        cin >> a;
        if(a > arr.back()){
            arr.push_back(a);
        }else{
            vector<int>::iterator i = lower_bound(arr.begin(),arr.end(),a);
            *i = a;
        }
    }

    cout << arr.size();
}
