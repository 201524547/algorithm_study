#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

multiset<long long> bag;
pair<long long,long long> gem[300001];

bool comp(pair<long long,long long> a, pair<long long,long long> b){
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int main(){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        long long a,b;
        cin >> a >> b;
        gem[i] = {a,b};
    }
    for(int i = 0; i < K; i++){
        long long a;
        cin >> a;
        bag.insert(a);
    }
    sort(gem, gem+N,comp);
    int index = 0;
    long long ans = 0;
    while(!bag.empty()){
        int weight = gem[index].first;
        int value = gem[index++].second;

       multiset<long long>::iterator i = bag.lower_bound(weight);

       if(i != bag.end()){
            ans += value;
            bag.erase(i);
       }
    }
    cout << ans;
}
