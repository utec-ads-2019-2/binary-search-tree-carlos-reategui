#include <iostream>
#include "tester/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tester::execute();
    /*auto tree = new BSTree<int>();
    int data[] = {1, 2, 3, 4, 5, 6};
    for (int i : data) tree->insert(i);
    for (int i : data) cout << i << (tree->find(i) ? " True" : " False") << endl;
    tree->traversePreOrder();
    tree->traverseInOrder();
    tree->traversePostOrder();
    cout << "Height " <<(tree->height()) << endl;
    cout << "Size " << tree->size() << endl;
    //for (int i : data) tree->remove(i);
    tree->remove(1);
    tree->remove(2);
    tree->remove(3);
    tree->remove(4);
    tree->remove(5);
    tree->remove(6);
    tree->traversePreOrder();
    tree->traverseInOrder();
    tree->traversePostOrder();
    cout << "Height " <<(tree->height()) << endl;
    cout << "Size " << tree->size() << endl;
    auto it = tree->begin();*/
    return EXIT_SUCCESS;
}
