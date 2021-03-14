#include <iostream>
#include <algorithm>

using namespace std;

class node{
private:
    node* root;
    int depth;
public:
    node(){
        root=this;
        depth = 1;
    }
    node* node_find(){
        if(root != this){
            return root->node_find();
        }
        return this;
    }
    int get_depth(){
        return depth;
    }
    void setRoot(node* root){
        this->root = root;
        root->depth += this->depth;
    }
};

class disjoint_set{
private:
    node* nodes;
    int size_;
public:
    disjoint_set(int size_ = 1){
        nodes = new node[size_+1];
        this -> size_ = size_;
    }
    void ds_union(int a, int b){
        node* a_node = nodes[a].node_find();
        node* b_node = nodes[b].node_find();

        if(a_node == b_node){
            return;
        }
        if(a_node->get_depth() > b_node->get_depth()){
            b_node->setRoot(a_node);
            nodes[b].setRoot(a_node);
        }else{
            a_node->setRoot(b_node);
            nodes[a].setRoot(b_node);
        }
    }
    int ds_find(int a, int b){
        node* a_node = nodes[a].node_find();
        node* b_node = nodes[b].node_find();
        if(a_node == b_node){
            return 1;
        }
        else{
            return 0;
        }
    };
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_node;
    int case_;
    cin >> num_node >> case_;
    disjoint_set ds(num_node);
    while(case_--){
        int Oper,a,b;
        cin >>   Oper >> a >> b;
        if(Oper){
            if(ds.ds_find(a,b))
                cout << "yes" << "\n";
            else
                cout << "no" << "\n";
        }
        else{
            ds.ds_union(a,b);
        }
    }

};
