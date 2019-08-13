//
// Created by yuval on 11/08/2019.
//
#include <stdio.h>
#include "Node.h"
#include "Vector.h"
#include "myLib.h"

typedef struct vector{
    Node *first;
    Node *last;
    int size;
}Vector;

Vector* new_Vector(){
    Vector *vec = (Vector*)malloc(sizeof(Vector));
    vec->size = 0;
    vec->first = vec->last = NULL;
    return vec;
}

void addElement(Vector* this , void* element){
    Node *addable_element;
    addable_element = new_Node(element);
    if(this->first == NULL){
        this->first = this->last = addable_element;
    } else{
        set_next(get_last_node(this->first), addable_element);
    }

    this->size++;
}

void* get(Vector* this, int index){
    int i = 0;
    Node *chain = this->first;
    void *value_reference;
    while(chain != NULL){
        if(i == index){
            value_reference = get_value(chain);
            return value_reference;
        }
        chain = get_next(chain);
        i++;
    }
    return NULL;
}

void clear(Vector* this){
    delete_all_Nodes(this->first);
    this->first = this->last = NULL;
    this->size = 0;
}

int size(Vector* this){
    int count = 0;
    Node* head = this->first;
    while(head != NULL){
        count++;
        head = get_next(head);
    }
    return count;
}

boolean contains(Vector* this, void* element){
    for(int i = 0; i < size(this); i++){
        if(get(this, i) == element) return true;
    }
    return false;
}

void copyInto(Vector* this, void** array){
    for (int i = 0;i<size(this);i++){
        array[i] = get(this, i);
    }
}

void* elementAt(Vector* this, int index){
    return get(this, index);
}

void* firstElement(Vector* this){
    return get(this, 0);
}

boolean equals(Vector* this, Vector* other){
    if(size(this) != size(other)) return false;
    for(int i = 0;i<size(this);i++){
        if(get(this, i) != get(other, i)) return false;
    }
    return true;
}

int indexOf(Vector* this, void* element){
    int i = 0;
    for(;i<size(this);i++){
        if(get(this,i) == element) return i;
    }

    return -1;
}

boolean isEmpty(Vector* this){
    if(this->first == NULL && this->last == NULL && this->size == 0) return true;

    return  false;
}

void* lastElement(Vector* this){
    return get(this, size(this)-1);
}

int lastIndexOf(Vector* this, void* element){
    for(int i = size(this)-1; i>=0;i--){
        if(get(this, i)==element) return  i;
    }
    return -1;
}

void* removeElement(Vector* this, int index){
    Node *prev = this->first, *chain = this->first;
    if(index == 0){
        if(this->first != NULL){
            void* ret_val = get_value(this->first);
            Node* del_node = this->first;
            this->first = get_next(this->first);
            delete_Node(del_node);
            this->size--;

            return ret_val;
        } else return  NULL;
    }
    else{
        int i = 0;
        while(get_next(chain)!= NULL){
            i++;
            chain = get_next(chain);
            if(i == index){
                Node *for_delete = chain;
                void* returnable;
                chain = get_next(chain);
                set_next(prev, chain);
                returnable = get_value(for_delete);
                delete_Node(for_delete);
                this->size--;
                return returnable;
            }
            prev = chain;
        }
    }
    return NULL;
}

boolean removeElementByReference(Vector* this, void* element){
    Node *prev = this->first, *chain = this->first;
    if(indexOf(this, element) == 0){
        if(this->first != NULL){
            void* ret_val = get_value(this->first);
            Node* del_node = this->first;
            this->first = get_next(this->first);
            delete_Node(del_node);
            this->size--;

            return true;
        } else return false;
    }
    else{
        int i = 0;
        while(get_next(chain)!= NULL){
            i++;
            chain = get_next(chain);
            if(get(this,i) == element){
                Node *for_delete = chain;
                chain = get_next(chain);
                set_next(prev, chain);

                delete_Node(for_delete);
                this->size--;
                return true;
            }
            prev = chain;
        }
    }
    return false;
}

void** to_array(Vector* this){
    void **arr = malloc(sizeof(void*)*size(this)) ;
    copyInto(this, arr);
    return arr;
}

void set(Vector* this, void* element, int index){
    int i = 0;
    Node *prev = this->first, *chain = this->first;
    Node* node_element = new_Node(element);
    if(index == 0){
        set_next(node_element, this->first);
        this->first = node_element;
    }
    while(chain != NULL){
        i++;
        chain = get_next(chain);
        if(i == index){
            set_next(prev, node_element);
            set_next(node_element, chain);
            return;
        }

        prev = get_next(prev);
    }

}

void print_integers_nodes(Node *this){
    if(this != NULL) {
        Node *chain;
        chain = this;
        while (chain != NULL) {
            if (chain != this)
                printf(",");
            printf("%d", *(int *) get_value(chain));

            chain = get_next(chain);
        }
        printf("\n");
    }
}

void print_integers_vector(Vector* this){
    print_integers_nodes(this->first);
}
