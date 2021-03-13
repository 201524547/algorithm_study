#include <iostream>
#include <algorithm>

using namespace std;

int heap_array[100001];

class my_heap {
private:
    int heap_size;
    int heap_top;
public:
    my_heap(int _size=100001){
        heap_size=_size;
        heap_top = 0;
    }
    bool is_empty();
    bool is_full();
    void push(int item);
    void print();
    int pop();
};

bool my_heap::is_empty(){
    return heap_top == 0;
}
bool my_heap::is_full(){
    return heap_top == heap_size;
}
void my_heap::push(int item){
    heap_array[++heap_top] = item;
    int location = heap_top;

    while(1){
        int parent,child;
        parent = location / 2;
        child = location;
        if(parent == 0){
            break;
        }
        if(heap_array[parent] > heap_array[child]){
            break;
        }
        else{
            int tmp = heap_array[parent];
            heap_array[parent] = heap_array[child];
            heap_array[child] = tmp;
        }
        location = parent;

    }
}

void my_heap::print(){
    for(int i = 1; i <= heap_top;i++){
        cout << heap_array[i] << " ";
    }
}

int my_heap::pop(){
    int result = heap_array[1];
    heap_array[1] = heap_array[heap_top--];

    int parent = 1;
    while(1){
        if(2*parent > heap_top){
            break;
        }
        int child;
        if(heap_array[2*parent] > heap_array[2*parent+1])
            child = 2*parent;
        else{
            child = 2*parent+1;
        }

        if(heap_array[parent] > heap_array[child]){
            break;
        }
        else{
            int tmp;
            tmp = heap_array[child];
            heap_array[child] = heap_array[parent];
            heap_array[parent] = tmp;
            parent = child;
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int case_;
    cin >> case_;

    my_heap h;

    while(case_--){
        int calculate;
        cin >> calculate;

        if(calculate){
            h.push(calculate);
        }
        else{
            if(h.is_empty()){
                cout << 0 << "\n";
            }
            else{
                cout << h.pop() << "\n";
            }
        }
    }

    return 0;
}
