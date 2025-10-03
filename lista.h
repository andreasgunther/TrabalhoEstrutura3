#pragma once

// Definicao do Struct Node (No)
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Declaracao
int getOption(Node *head);
void partialFrame();
int count(Node *head);
void create(Node **head, int size);
void show(Node *head);
void order(Node *head);
void search(Node *head, int value);
void topAdd(Node **head);
void middleAdd(Node *head); 
void endAdd(Node *head);
void topRemove(Node **head);
void middleRemove(Node *head);
void endRemove(Node *head);
void add(Node **head, int position);
