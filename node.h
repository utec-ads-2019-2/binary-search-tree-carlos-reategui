#ifndef NODE_H
#define NODE_H

template <typename T>
class BSTree; 

template <typename T>
class Iterator; 

template <typename T>
class Node {
    T data;
    Node<T> *left;
    Node<T> *right;

public:
    explicit Node(T data) : left(nullptr), right(nullptr), data(data) {}

    void killSelf() {
        if (this) {
            this->right->killSelf();
            this->left->killSelf();
            delete this;
        }
    }

private:

    template<class>
    friend class BSTree; 

    template<class>
    friend class Iterator;
};

#endif