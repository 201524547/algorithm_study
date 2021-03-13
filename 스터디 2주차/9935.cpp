#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string target, bomb;
vector<char> ans_vector;
vector<char> bomb_vector;
vector<char> target_vector;

void bomb_sentence(){
    for(int i = 0; i < target_vector.size(); i++){
            ans_vector.push_back(target_vector[i]);

            if(ans_vector.back() == bomb_vector.back()){
                vector<char> tmp_vector;
                vector<char> tmp_bomb(bomb_vector);
                while(!tmp_bomb.empty()){
                    if(ans_vector.back() != tmp_bomb.back()){
                        while(!tmp_vector.empty()){
                            ans_vector.push_back(tmp_vector.back());
                            tmp_vector.pop_back();
                        }
                        break;
                    }
                    tmp_vector.push_back(ans_vector.back());

                    ans_vector.pop_back();
                    tmp_bomb.pop_back();
                }
            }
    }
}

int main(){

    char ch;
    while(scanf("%c",&ch) && ch != 10){
        target_vector.push_back(ch);
    }
    while(scanf("%c",&ch) && ch != 10){
        bomb_vector.push_back(ch);
    }
    bomb_sentence();
    if(ans_vector.empty()){
        cout <<"FRULA";
    }
    for(int i = 0; i < ans_vector.size(); i++){
        cout << ans_vector[i];
    }

}
