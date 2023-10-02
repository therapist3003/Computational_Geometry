#ifndef RANDOMIZEDNODE_H
#define RANDOMIZEDNODE_H

template<class T>
class RandomizedNode : public BraidedNode<T> {
    protected:
        RandomizedNode *_parent;
        double _priority;
        void rotateRight(void);
        void rotateLeft(void);
        void bubbleUp(void);
        void bubbleDown(void);
    public:
        RandomizedNode(T v, int seed = -1);
        RandomizedNode *lchild(void);
        RandomizedNode *rchild(void);
        RandomizedNode *next(void);
        RandomizedNode *prev(void);
        RandomizedNode *parent(void);
        double priority(void);
        friend class RandomizedSearchTree<T>;
};

#endif