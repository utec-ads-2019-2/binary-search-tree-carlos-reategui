#include <iostream>
#include "tester/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    //Tester::execute();
    auto tree = new BSTree<int>();
    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->traversePreOrder(tree->getRoot()); cout << endl;
    tree->traverseInOrder(tree->getRoot()); cout << endl;
    tree->traversePostOrder(tree->getRoot()); cout << endl;
    cout << tree->depth(tree->getRoot());
    return EXIT_SUCCESS;
}
