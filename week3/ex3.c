#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t {
    int nbr;
    struct node_t* next;
};

typedef struct node_t Node;
typedef Node* List;

int size(List list) {   //function return the number of elemnts in the linked list
    List temp = list;
    int i = 0;
    while (temp != NULL) {
        i++;
        temp = temp -> next;
    }
    return i;
}

List allocateNode(int i) {
    List List = (Node*) malloc(sizeof(Node));
    if (List ==  NULL){
        printf("Not enough memory");
        return NULL;
    }
    else {
        List -> nbr = i;
        List -> next = NULL;
        return List;
    }
}

void print_list(List list) {
    List temp = list;
    while (temp != NULL) {
        printf("%d ",temp -> nbr);
        temp = temp -> next;
    }
    printf("\n");
}

void addLast(List* list, int i) { //add element at the end
    if (*list == NULL) {
        *list =  allocateNode(i);
    }
    else {
        List temp = *list;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
    
        temp -> next = allocateNode(i);
    }
}

void addFirst(List* list, int i) {
    if (list == NULL) {
        *list =  allocateNode(i);
    }
    else {
        List temp = allocateNode(i);
        temp -> next = *list;
        *list = temp;
    }
}

//insert a new node with value equal 'value' after some existing element with index 'index'

void insert_node(List* list, int index, int value) {
    
    if ((*list == NULL) || (index >= size(*list)) || (index < 0)) {
        printf("Cannot insert a new element: invalid index\n");
        return;
    }
    else {
        List temp = *list;
        int i = 0;
        while ((temp -> next != NULL) & (i < index)) {
            i++;
            temp = temp -> next;
        }
        
            List next_node = temp -> next;
            List new_node = allocateNode(value);
            temp -> next = new_node;
            new_node -> next = next_node;
    }
}

//delete a node with a given index

void delete_node(List* list, int index) {
    
    if ((*list == NULL) || (index >= size(*list)) || (index < 0)) {
        printf("Cannot delete a new element: invalid index\n");
        return;
    }
    else {
        
        if (index == 0) {
            *list = (*list) -> next;
        }
        else {
            List temp = *list;
            int i = 0;
            while ((temp -> next != NULL) & (i < index - 1)) {
                i++;
                temp = temp -> next;
            }
        
            temp -> next = temp -> next -> next;
        }
    }
}

int main(int argc, char * argv[]) {
    
    List list = NULL;  //create list
    
    addLast(&list, 10);
    addFirst(&list, 1);
    addFirst(&list, 3);
    addLast(&list, 4);
    addLast(&list, 5);
    addFirst(&list, 0);
    
    print_list(list);  //0 3 1 10 4 5
    printf("Size: %d\n\n", size(list));  //5
    
    printf("Inserting a node after index 1 with value 11:\n");
    insert_node(&list, 1, 11);
    print_list(list); //0 3 11 1 10 4 5
    
    printf("\nDeleting a node with index 1:\n");
    delete_node(&list, 1);
    print_list(list); //0 11 1 10 4 5
    
    return 0;
}
