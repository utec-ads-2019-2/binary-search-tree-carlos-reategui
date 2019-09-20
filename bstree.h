#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;
    unsigned int nodes;

    public:
        BSTree() : root(nullptr), nodes(0) {};

        Node<T>* getRoot() {
            return root;
        }

        bool find(T data) {
            auto newNode = new Node<T>();
            newNode->data = data;
            auto currentNode = root;
            while (currentNode) {
                if (data == currentNode->data)
                    return true;
                else
                    if (data <= currentNode->data)
                        currentNode = currentNode->left;
                    else
                        currentNode = currentNode->right;
            }
            return false;
        } 

        void insert(T data) {
            auto newNode = new Node<T>();
            newNode->data = data;
            if (root == nullptr)
                root = newNode;
            else {
                Node<T> * parent = nullptr, * currentNode = root;
                while(currentNode) {
                    parent = currentNode;
                    if (data <= currentNode->data)
                        currentNode = currentNode->left;
                    else
                        currentNode = currentNode->right;
                }
                if (data <= parent->data)
                    parent->left = newNode;
                else
                    parent->right = newNode;
            }
            nodes++;
        }

        bool remove(T data) {
            /*auto newNode = new Node<T>();
            newNode->data = data;
            auto currentNode = root;
            while (currentNode) {
                if (data == currentNode->data)
                    return true;
                else
                if (data <= currentNode->data)
                    currentNode = currentNode->left;
                else
                    currentNode = currentNode->right;
            }*/
        }

        size_t size() {
            return nodes;
        }

        size_t height() {

        }

        void traversePreOrder(Node<T> * Root) {
            if (Root == nullptr) return;
            cout << Root->data << " ";
            traversePreOrder(Root->left);
            traversePreOrder(Root->right);
        }

        void traverseInOrder(Node<T> * Root) {
            if (Root == nullptr) return;
            traverseInOrder(Root->left);
            cout << Root->data << " ";
            traverseInOrder(Root->right);
        }

        void traversePostOrder(Node<T> * Root) {
            if (Root == nullptr) return;
            traversePostOrder(Root->left);
            traversePostOrder(Root->right);
            cout << Root->data << " ";
        }

        Iterator<T> begin() {
            // TODO
        }

        Iterator<T> end() { 
            // TODO
        }

        ~BSTree() {
            // TODO
        }
};
#endif
