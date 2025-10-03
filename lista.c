#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int getOption(Node *head) {
    int choice;
    system("clear");
    printf("+=============================+\n");
    printf("|==| GERENCIADOR DE LISTAS |==|\n");
    printf("+=============================+\n");
    printf("[ 1] Criar lista\n");             // create()
    if (head != NULL) {
        printf("[ 2] Exibir lista\n");        // show()
        printf("[ 3] Ordenar lista\n");       // order()
        printf("[ 4] Buscar valor\n");        // search()
        printf("[ 5] Adicionar no inicio\n"); // topAdd()
        printf("[ 6] Adicionar no meio\n");   // middleAdd()
        printf("[ 7] Adicionar no fim\n");    // endAdd()
        printf("[ 8] Adicionar por index\n"); // addAnywhere()
        printf("[ 9] Remover do inicio\n");   // topRemove()
        printf("[10] Remover do meio\n");     // middleRemove()
        printf("[11] Remover do fim\n");      // endRemove()
    }
    printf("[12] Encerrar o programa\n");
    printf("\n");
    printf("Digite: ");
    scanf("%d", &choice);
    return choice;
}

void partialFrame() {
    system("clear");
    printf("+=============================+\n");
    printf("|==| GERENCIADOR DE LISTAS |==|\n");
    printf("+=============================+\n");
}

int count(Node *head) {
    int i = 0;
    while (head != NULL){
        i++;
        head = head->next;
    }
    return i;
}

void create(Node **head, int size) {

    Node *node, *tmp;
    int i;

    (*head) = malloc(sizeof (Node *));
    node = *head;

    for (i = 0; i < size; i++) {
        // Insere valor no nó
        printf("Insira o %d* valor: ", i + 1);
        scanf("%d", &node->value);
        
        // Se estiver no final, next recebe null 
        if (size - 1 == i) {
            node->next = NULL;
        } else {
            // Aloca espaco na lista
            tmp = malloc(sizeof (Node *));
            if (tmp == NULL) {
                printf("Erro de alocacao! Tente novamente...");
                return;
            }
            node->next = tmp;
        }

        // Passa para o proximo nó
        node = node->next;
    }
        
}

void show(Node *head) {
    Node *node = head;
    printf("Lista: ");
    while(node != NULL) {
        if (node->next == NULL) {
            printf("%d", node->value);
        } else { 
            printf("%d - ", node->value);
        }
        node = node->next;
    }    
    printf("\nTamanho: %d", count(head));
}

void order(Node *head) {
    Node *node = head;
    Node *tmp = node->next;
    int aux, ctd = 0;
    
    printf("A ordenar...\n");
    while (node->next != NULL) {
        while (tmp != NULL) {
            if (node->value > tmp->value) {
                aux = node->value;
                node->value = tmp->value;
                tmp->value = aux;
            }
            tmp = tmp->next;
            ctd++;
        }
        node = node->next;
        if (node != NULL) {
            tmp = node->next;
        }
    }
    printf("Lista ordenada com sucesso!\n");
    printf("Quantidade de operações: %d", ctd);
}

void search(Node *head, int value) {
    Node *node = head;
    int i = 0;

    printf("Realizando busca...\n");
    printf("Lista: ");
    while (node != NULL) {
        if (node->value == value && node->next == NULL) {
            printf("|%d|", node->value);
            i++;
        } else if (node->value == value) {
            printf("|%d| - ", node->value);
            i++;
        } else {
            if (node->next == NULL) {
                printf("%d", node->value);
            } else { 
                printf("%d - ", node->value);
            }
        }
        node = node->next;
    }

    printf("\n");
    if (i > 0) {
        printf("O numero %d ESTA na lista...\n", value);
        printf("Aparece %d vezes!", i);
    } else {
        printf("O numero %d NAO esta na lista...", value);
    }
}

void topAdd(Node **head){
    Node *node = *head;
    int num;

    (*head) = malloc(sizeof (Node *));
    (*head)->next = node;
    printf("Insira o valor: ");
    scanf("%d", &num);
    (*head)->value = num;
    printf("Numero %d adicionado com sucesso!", num);
}

void middleAdd(Node *head) {
    int i, j, cont, num;
    Node *node = head, *aux, *tmp;

    cont = count(head);
    i = cont / 2;
    if (cont % 2 == 0) { 
        i--;
    }

    for (j = 0; j < i; j++) {
        node = node->next;
    }

    aux = node->next;
    tmp = malloc(sizeof (Node *));
    if (tmp == NULL) {
        printf("Erro de alocacao...");
        return;
    }
    node->next = tmp;
    node = node->next;
    printf("Insira o numero: ");
    scanf("%d", &num);
    node->value = num;
    node->next = aux;
    printf("Numero %d inserido com sucesso!", num);
}

void endAdd(Node *head) {
    Node *node = head, *tmp;
    int num;

    while (node->next != NULL) {
        node = node->next;
    }

    printf("Insira o valor: ");
    scanf("%d", &num);
    printf("Realizando alocacao...\n");
    tmp = malloc(sizeof (Node *));
    if (tmp == NULL) {
        printf("Erro de alocacao...");
        return;
    }
    node->next = tmp;
    node = node->next;
    node->next = NULL;
    node->value = num;
    printf("Numero %d inserido com sucesso!", num);
}

void topRemove(Node **head) {
    Node *node = *head;
    (*head) = (*head)->next;
    printf("Primeiro valor removido da lista...\n");
    free(node);
    node = NULL;
    printf("Espaco liberado na memoria!");
}

void middleRemove(Node *head) {
    int i, j, cont, num;
    Node *node = head, *aux;

    cont = count(head);

    if (cont == 1) {
        printf("Erro...\n");
        printf("Preciso manter a cabeca da lista!");
        return;
    }

    i = cont / 2;
    if (cont % 2 == 0) { 
        i--;
    }

    for (j = 0; j < i; j++) {
        node = node->next;
    }

    aux = node->next;
    node->next = aux->next;
    free(aux);
    aux = NULL;
    printf("Valor removido com sucesso!");
}

void endRemove(Node *head) {
    Node *node = head->next;

    if (count(head) == 1) {
        printf("Erro...\n");
        printf("Nao posso remover a cabeca!");
        return;
    }
    while (node->next != NULL) {
        node = node->next;
        head = head->next;
    }
    free(node);
    node = NULL;
    printf("Numero removido da lista...\n");
    printf("Espaco liberado!");
    head->next = NULL;
}

void add(Node **head, int position) {
    
}