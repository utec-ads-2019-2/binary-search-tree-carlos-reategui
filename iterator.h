#ifndef ITERATOR_H
#define ITERATOR_H

#include <stack>
#include "node.h"

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        std::stack<Node<T>*> nodes;
        std::stack<Node<T>*> descendingNodes;

    public:
        Iterator() : current(nullptr) {}

        Iterator(Node<T> *node, bool isBegin) {
            if (isBegin and node) {
                while (node) {
                    nodes.push(node);
                    node = node->left;
                }
                current = nodes.top();
            } else
                while (node) if (!node->right) current = node->right;
        }

        Iterator<T>& operator=(const Iterator<T> &other) {          
            current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return current != other.current;
        }

        Iterator<T> operator++() {
            if (!nodes.empty() and current) {
                descendingNodes.push(nodes.top());
                if (current->right) {
                    auto currentRight = current->right;
                    nodes.pop();
                    while (currentRight) {
                        nodes.push(currentRight);
                        currentRight = currentRight->left;
                    }
                } else
                    nodes.pop();
            } else
                current = nullptr;
            if (nodes.empty())
                current = nullptr;
            else
                current = nodes.top();
            return *this;
        }

        Iterator<T>& operator--() {
            if (!descendingNodes.empty()) {
                current = descendingNodes.top();
                descendingNodes.pop();
                return *this;
            }
        }

        T operator*() {
            if (current) return current->data;
        }
};

#endif
