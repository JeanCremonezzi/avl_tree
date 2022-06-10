#include "header.h"

int main() {
    Tree* tree = initTree();

    if (insertNode(&tree->root, createPessoa(tree->count, "111", "USER 1", "TEST 1"))) {
        tree->count++;
    }

    if (insertNode(&tree->root, createPessoa(tree->count, "222", "USER 2", "TEST 2"))) {
        tree->count++;
    }

    if (insertNode(&tree->root, createPessoa(tree->count, "333", "USER 3", "TEST 3"))) {
        tree->count++;
    }

    printInOrder(tree->root);

    if (insertNode(&tree->root, createPessoa(tree->count, "444", "USER 4", "TEST 4"))) {
        tree->count++;
    }

    if (insertNode(&tree->root, createPessoa(tree->count, "555", "USER 5", "TEST 5"))) {
        tree->count++;
    }
}