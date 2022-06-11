Tree* initTree();
void freeTree(Tree *tree);
Pessoa* createPessoa(int id, char* cpf, char* name, char* lastName);
void freePessoa(Pessoa *pessoa);
Node* createNode(Pessoa *pessoa);
void freeNode(Node *node);
int nodeHeight(Node *node);
int balanceFactor(Node *node);
void leftRotation(Node *node);
void rightRotation(Node *node);
void doubleRightRotation(Node *node);
void doubleLeftRotation(Node *node);
Node* insertNode(Node **root, Pessoa *pessoa);
void printInOrder(Node *node);
void addFriend(Tree *tree, int id, int idToAdd);
void showFriends(Tree *tree, int id);
void showFriendsOfFriends(Tree *tree, int id);
void printPessoa(Pessoa *pessoa);