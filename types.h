typedef struct Pessoa {
    int id;
    char CPF[12];
    char nome[200];
    char sobrenome[200];
} Pessoa;

typedef struct Node {
    struct Pessoa *person;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree {
    int count;
    struct Node *root;
    int friends[MAX_USERS][MAX_USERS];
} Tree;