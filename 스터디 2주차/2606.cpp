#include <iostream>
#include <algorithm>

using namespace std;

int computer_graph[101][101];
int checked[101];

int N;

int DFS(int start){

    int result = 1;
    checked[start] = 1;

    for(int i = 1; i <= N; i++){
        if(!checked[i] && computer_graph[start][i]) result += DFS(i);
    }
    return result;
}

int main(){
    int g;
    cin >> N >> g;

    for(int i = 0; i < g; i++){
        int a, b;
        cin >> a >> b;

        computer_graph[a][b] = 1;
        computer_graph[b][a] = 1;
    }

    cout << DFS(1) - 1;

}
