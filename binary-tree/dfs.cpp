#include <iostream>
#include <stack>

using namespace std; 

class Node {
public:

    char value;
    Node* left;
    Node* right;

    Node(int _value){
        value = _value;
    }

    Node(){
        value = 0;
    }
};

void depthFirstSearch(Node* root){
    Node* current = root;
    stack<Node*> s;
    while(true){
        if(current->left && current->right){
            cout<< current->value<< " ";
            s.push(current->right);
            current = current->left;
        }else if(current->left){
            cout<< current->value<<" ";
            current = current->left;
        }else if(current->right){
            cout<< current->value<<" ";
            current = current->right;
        }else{
            if(s.empty()){
                cout<< current->value << endl;
                return;
            }
            cout << current->value<< " ";
            current = s.top();
            s.pop();
        }
    }

}


int main(){
    Node a('a');
    Node b('b');
    Node c('c');
    Node d('d');
    Node e('e');
    Node f('f');

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;

    /* binary tree created with root node a 
                a
               / \
              b   c
             / \   \
            d   e   f                     */

    depthFirstSearch(&a);

    return 0;
}