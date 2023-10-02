#ifndef TREENODE_H
#define TREENODE_H

template<class T> class TreeNode {
    protected:
        TreeNode *_lchild;
        TreeNode *_rchild;
        T val;
    public:
        TreeNode(T);
        virtual ~TreeNode(void);
        friend class SearchTree<T>;
        friend class BraidedSearchTree<T>;
};
template<class T> TreeNode<T>::TreeNode(T v) : val(v), _lchild(NULL), _rchild(NULL){

}
template<class T> TreeNode<T>::~TreeNode(void){
    if (_lchild)
        delete _lchild;
    if (_rchild)
        delete _rchild;
}
#endif