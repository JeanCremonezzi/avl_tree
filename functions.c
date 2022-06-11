#include "header.h"

Tree* initTree() {
    Tree *ptrTree = malloc(sizeof(Tree));
    ptrTree->count = 0;
    ptrTree->root = NULL;

    memset(ptrTree->friends, 0, sizeof(ptrTree->friends));

    return ptrTree;
}

void freeTree(Tree *tree) {
    freeNode(tree->root);

    free(tree);
    tree = NULL;
}

Pessoa* createPessoa(int id, char* cpf, char* name, char* surname) {
    Pessoa *ptrPessoa = malloc(sizeof(Pessoa));

    ptrPessoa->id = id;
    strcpy(ptrPessoa->CPF, cpf);
    strcpy(ptrPessoa->nome, name);
    strcpy(ptrPessoa->sobrenome, surname);

    return ptrPessoa;
}

void freePessoa(Pessoa *pessoa) {
    if (!pessoa) return;
    free(pessoa);
    pessoa = NULL;
}

Node* createNode(Pessoa *pessoa) {
    Node *ptrNode = malloc(sizeof(Node));

    ptrNode->person = pessoa;
    ptrNode->left = NULL;
    ptrNode->right = NULL;

    return ptrNode;
}

void freeNode(Node *node) {
    if (!node) return;

    freeNode(node->left);
    freeNode(node->right);

    freePessoa(node->person);

    free(node);
    node = NULL;
}

int nodeHeight(Node *node) {
    if (!node) return 0;

    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

int balanceFactor(Node *node) {
    return nodeHeight(node->right) - nodeHeight(node->left);
}

void leftRotation(Node *node) {
    Node A = *node;
    Node B = *node->right;

    node->person = B.person;
    node->left = node->right;
    node->right = B.right;
    
    A.right = B.left;
    *node->left = A;
}

void rightRotation(Node *node) {
    Node A = *node;
    Node B = *node->left;

    node->person = B.person;
    node->right = node->left;
    node->left = B.left;

    A.left = B.right;
    *node->right = A;
}

void doubleRightRotation(Node *node) {
    rightRotation(node->right);
    leftRotation(node);
}

void doubleLeftRotation(Node *node) {
    leftRotation(node->left);
    rightRotation(node);
}

Node* insertNode(Node **root, Pessoa *pessoa) {
    if (!*root) {
        *root = createNode(pessoa);

        return *root;
    }
    
    Node *node = *root;
    Node *newNode;

    if (pessoa->id == node->person->id) return NULL;

    if (pessoa->id > node->person->id) {
        newNode = insertNode(&node->right, pessoa);

        int balance = balanceFactor(node);
        if (balance > 1) {
            if (balanceFactor(node->right) > 0) {
                leftRotation(node);
            } else {
                doubleRightRotation(node);
            }
        }
    }

    if (pessoa->id < node->person->id) {
        newNode = insertNode(&node->left, pessoa);

        int balance = balanceFactor(node);
        if (balance < -1) {
            if (balanceFactor(node->left) < 0) {
                rightRotation(node);
            } else {
                doubleLeftRotation(node);
            }
        }
    }

    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);

    return newNode;
}

void printInOrder(Node *node) {
    if (!node) return;
    printInOrder(node->left);
    printPessoa(node->person);
    printInOrder(node->right);
}

void addFriend(Tree *tree, int id, int idToAdd) {
    if (id == idToAdd) return;

    tree->friends[id][idToAdd] = 1;
    tree->friends[idToAdd][id] = 1;
}

void showFriends(Tree *tree, int id) {
    printf("\n\n--- Friends of ID %i ---", id);
    for (int i = 0; i < MAX_USERS; i++) {
        if (tree->friends[id][i] == 1) printPessoa(searchPessoa(tree->root, i));
    }
}

void showFriendsOfFriends(Tree *tree, int id) {
    printf("\n\n====== Friends of friends ======");
    for (int i = 0; i < MAX_USERS; i++) {
        if (tree->friends[id][i] == 1) showFriends(tree, i);
    }
}

void printPessoa(Pessoa *pessoa) {
    printf("\n%i - %s | %s %s", // ID - CPF | NOME SOBRENOME
        pessoa->id, 
        pessoa->CPF,
        pessoa->nome, 
        pessoa->sobrenome);
}

Pessoa* searchPessoa(Node *node, int id) {
    if (!node) return NULL;

    if (id == node->person->id) return node->person;
    if (id < node->person->id) return searchPessoa(node->left, id);
    if (id > node->person->id) return searchPessoa(node->right, id);
}