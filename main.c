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

    if (insertNode(&tree->root, createPessoa(tree->count, "444", "USER 4", "TEST 4"))) {
        tree->count++;
    }

    addFriend(tree, 0, 1);
    addFriend(tree, 0, 2);
    addFriend(tree, 2, 3);

    printInOrder(tree->root);
    showFriends(tree, 0);
    showFriendsOfFriends(tree, 0);
}