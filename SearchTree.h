#ifndef SEARCHTREE_H
#define SEARCHTREE_H

template<class T> class SearchTree
{
private:
    TreeNode<T> *root;
    int (*)(T,T) cmp;
    TreeNode<T> *_findMin(TreeNode<T>*);
    void _remove(T, TreeNode<T>* &);
    void _inorder(TreeNode<T>*, void (*)(T));
public:
    SearchTree(int (*)(T,T));
    ~SearchTree(void);
    int isEmpty(void);
    T find(T);
    T findMin(void);
    void inorder(void(*)(T));
    void insert(T);
    void remove(T);
    T removeMin(void);
};

template<class T> SearchTree<T>::SearchTree(int(*c)(T,T)):cmp(c),root(NULL)
{
}

template<class T> int SearchTree<T>::isEmpty(void)
{
    return (root == NULL);
}

template<class T> SearchTree<T>::~SearchTree(void)
{
    if(root)
        delete root;
}

template<class T> T SearchTree<T>::find(T val){
    TreeNode<T> *n = root;
    while(n) {
        int result = (*cmp)(val, n->val);
        if (result < 0)
            n = n->_lchild;
        else if (result > 0)
            n = n->_rchild;
        else
            return n->val;
    }
    return NULL;
}

template<class T> T SearchTree<T>::findMin(void){
    TreeNode<T> *n = _findMin(root);
    return (n ? n->val : NULL);
}

//Error in the following block
//Source pg.43 of Laszlo
template<class T> 
TreeNode<T> *SearchTree<T>::_findMin(TreeNode<T> *n){
    if (n==NULL)
        return NULL;
    while (n->_lchild)
        n = n->_lchild;
    return n;
}

#endif