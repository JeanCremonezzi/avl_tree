#include "header.h"

int main() {
    Tree* tree = initTree();

    int option = -1;
    while(1) {
        menu();

        printf("\n\n--> Option: ");
        scanf("%d", &option);

        switch (option) {
            
            case 0:
                exit(1);
                break;

            case 1: { 
                printf("\n====== Create new user ======");

                char cpf[12];
                char nome[200];
                char sobrenome[200];

                printf("\n-> CPF: ");
                fflush(stdin);
                scanf("%s", &cpf);

                printf("\n-> Nome: ");
                fflush(stdin);
                scanf("%s", &nome);

                printf("\n-> Sobrenome: ");
                fflush(stdin);
                scanf("%s", &sobrenome);

                Pessoa *pessoa = createPessoa(tree->count, cpf, nome, sobrenome);

                if (insertNode(&tree->root, pessoa)) tree->count++;

                break;
            }

            case 2:
                printf("\n====== Users in order ======");

                printInOrder(tree->root);
                break;

            case 3: {
                printf("\n====== Add friend ======");
                
                int id, idToAdd;
                printf("\n-> Your ID: ");
                scanf("%d", &id);

                printf("\n-> Friend ID to add: ");
                scanf("%d", &idToAdd);

                addFriend(tree, id, idToAdd);
                break;
            }
           
            case 4: {
                printf("\n====== Show friends ======");

                int id;
                printf("\n-> ID to show friends: ");
                scanf("%d", &id);

                showFriends(tree, id);
                break;
            }

            case 5: {
                printf("\n====== Show friends of friends ======");

                int id;
                printf("\n-> ID to show friends of friends: ");
                scanf("%d", &id);

                showFriendsOfFriends(tree, id);
                break;
            }

            default:
                printf("\n\n====== Invalid option ======\n");
                break;
        }
    }
}

void menu() {
    printf("\n\n====== Menu ======");
    printf("\n1. New user");
    printf("\n2. Print users in ID order");
    printf("\n3. Add friend");
    printf("\n4. Show friends");
    printf("\n5. Show friends of friends");
    printf("\n0. Exit");
}