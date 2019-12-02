// Author : FangY
// Date   :
/*******************************************************************************

*******************************************************************************/
#include<iostream>
using namespace std;
template<typename T>
struct BinaryTreeNode(const T& data){
    T data;
    BinaryTreeNode<T>* lchild;
    BinaryTreeNode<T>* rchild;
};
template<typename T>
class BinaryTree{
    typedef BinaryTree<T>* pNode;
    typedef BinaryTree<T> Node;
public:
    BinaryTree();
    void create_preorder();
    vector<T> preorder_recursion(BinaryTreeNode<T>* head);
    vector<T> inorder_recursion(BinaryTreeNode<T>* head);
    vector<T> postorder_recursion(BinaryTreeNode<T>* head);
    vector<T> sequenceorder(BinaryTreeNode<T>* head);
    vector<T> preorder_iteration(BinaryTreeNode<T>* head);
    vector<T> inorder_iteration(BinaryTreeNode<T>* head);
    vector<T> postorder_iteration(BinaryTreeNode<T>* head);
    ~BinaryTree();
private:
    BinaryTreeNode<T>* head;
};
BinaryTree::BinaryTree(){
    head=NULL;
}
BinaryTree::~BinaryTree(){

}
template<typename T>
void create_preorder(){

}
template<typename T>
vector<T> preorder_recursion(BinaryTreeNode<T>* head){

}
int main()
{

}

