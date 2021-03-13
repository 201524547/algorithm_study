#include <iostream>
#include <set>

using namespace std;

set<int> s;
int main(){

    s.insert(1);
    s.insert(2);
    s.insert(3);


    auto i = s.begin();
    cout << i+1;

}
