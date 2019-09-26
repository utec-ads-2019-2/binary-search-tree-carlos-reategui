#ifndef ITERATOR_H
#define ITERATOR_H

#include <stack>
#include "node.h"

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        std::stack<Node<T>*> nodes;

    public:
        Iterator() : current(nullptr) {}

        Iterator(Node<T> *node, bool condition) : current(node){
            if (condition)
                while (node) node = node->right;
            else {
                while (node) {
                    nodes.push(node);
                    node = node->left;
                }
            }
        }

        Iterator<T>& operator=(const Iterator<T> &other) {          
            current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return current != other.current;
        }

        Iterator<T>& operator++() {
            auto topNode = nodes.top();
            nodes.pop();
            if (topNode->right) {
                nodes.push(topNode->right);
                while (nodes.top()->left) nodes.push(nodes.top()->left);
            }
            if (nodes.empty()) current = nullptr;
            else current = nodes.top();
        }

        T operator*() {
            if (current) return current->data;
        }
};

#endif
