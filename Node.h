//
// Created by yuval on 10/08/2019.
// A node library for setting up other data structs
//
#include <stdlib.h>

#ifndef VECTOR_TASK_NODE_H
#define VECTOR_TASK_NODE_H

typedef struct node Node;

Node* new_Node(void* value);

void delete_Node(Node *this);
void delete_all_Nodes(Node *this);

void set_next(Node *this,Node *next);
Node* get_next(Node *this);

void set_value(Node *this, void *value);
void* get_value(Node *this);

Node* get_last_node(Node *this);

#endif //VECTOR_TASK_NODE_H

