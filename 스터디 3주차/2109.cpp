#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

multiset<pair<int,int>> speach;
int checked[10001];

int main(){

    int n;
    cin >> n;
    int max_day = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        max_day = max(b, max_day);

        speach.insert({a,b});
    }
    int cnt = 0;
    int total_price = 0;

    while(max_day){
        if(cnt == n) break;
        int max_price = 0;
        multiset<pair<int,int>>::iterator it = speach.end();
        for(auto i = speach.begin(); i != speach.end(); i++){
            int price = i->first;
            int day = i->second;
            if(day >= max_day && price > max_price){
                it = i;
            }
        }
        if(it != speach.end()){
            total_price += it->first;
            speach.erase(it);
            cnt++;
        }
        max_day--;
    }
    cout << total_price;
}
