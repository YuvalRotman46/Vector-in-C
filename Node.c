//
// Created by yuval on 10/08/2019.
//

#include "Node.h"

typedef struct node{
    void *value;
    struct node *next;

}Node;

Node* new_Node(void* value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return  new_node;
}

void delete_Node(Node *this){
    free(this);
}

void delete_all_Nodes(Node *this){
    Node *chain, *current;
    chain = this;
    current = this;

    while(chain->next != NULL){
        current = chain;
        chain = chain->next;

        //free(current->value);
        free(current);
    }
    //free(chain->value);
    free(chain);
}

void deep_delete_node(Node* this){
    free(this->value);
    free(this);
}

void deep_delete_all_nodes(Node* this){
    Node *curr = this, *chain = this;
    while(chain->next != NULL){
        curr = chain;
        chain = chain->next;
        free(curr->value);
        free(curr);
    }
    free(chain->value);
    free(chain);
}

void set_next(Node *this,Node *next){
    this->next = next;
}

Node* get_next(Node *this){
    return (this->next);
}

void set_value(Node *this, void *value){
    this->value = value;
}

void* get_value(Node *this){
    return this->value;
}

Node* get_last_node(Node *this){
    Node *chain;
    chain = this;
    if(chain != NULL){
        while(chain->next != NULL){
            chain = chain->next;
        }
        return chain;
    } else return NULL;
}

