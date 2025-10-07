#include <stdio.h>
#include "lista.h"

int main() {
    Node *head = NULL;
    int leave = 0, num, size, value, index;

    while (leave == 0) {
        switch (getOption(head)) {
        case 1:
            partialFrame();
            printf("Digite o tamanho da lista: ");
            scanf("%d", &size);
            create(&head, size);
            break;
        case 2:
            partialFrame();
            show(head);
            break;
        case 3:
            partialFrame();
            order(head);
            break;
        case 4:
            partialFrame();
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &value);
            search(head, value);
            break;
        case 5:
            partialFrame();
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &value);
            topAdd(&head, value);
            break;
        case 6:
            partialFrame();
            middleAdd(head);
            break;
        case 7:
            partialFrame();
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &value);
            endAdd(head, value);
            break;
        case 8:
            partialFrame();
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &value);
            printf("Digite o index: ");
            scanf("%d", &index);
            add(&head, value, index);
            break;
        case 9:
            partialFrame();
            topRemove(&head);
            break;
        case 10:
            partialFrame();
            middleRemove(head);
            break;
        case 11:
            partialFrame();
            endRemove(head);
            break;
        case 12:
            partialFrame();
            printf("Digite o index: ");
            scanf("%d", &index);
            removeAny(&head, index);
            break;    
        default:
            leave = 1;
            break;
        }

        printf("\nContinuar >>> [Enter]");
        getchar();
        getchar();
    }

    return 0;
}