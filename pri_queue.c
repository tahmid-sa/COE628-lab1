#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author Tahmid Sajin, Section 2 COE 628, 500 830 210
 */
void PQ_insert(int priority, char * data) {
 //FIX THIS
    /*Create a Node_new of type Node_ptr_t and assign priority and data to it*/
    Node_ptr_t Node_new = malloc(sizeof(Node_t));
    Node_new->priority = priority;
    Node_new->data = data;
    
    /*If the Node_new has a priority greater than the head, then it will become the new head.*/
    if(head == NULL || Node_new->priority > head->priority){
        Node_new->next = head;
        head = Node_new;
    } else {
        /*If the Node_new has a lower priority than the head, then the algorithm will traverse the linked list to find an appropriate position to place
         the Node_new. This position will be such that Node_new->next->priority is larger than the Node_new priority, but if not, then the loop is ended.*/
        Node_ptr_t Node_start = head;
        
        while(Node_start->next != NULL && Node_start->next->priority > Node_new->priority){
            Node_start = Node_start->next;
        }
        
        Node_new->next = Node_start->next;
        Node_start->next = Node_new;
    }
}
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
  //FIX THIS
    /*If the linked list has a size of 0 nodes, then it will return NULL*/
    if (PQ_get_size() == 0) {
        return NULL;
    } else {
        /*If the linked list has 1 or more nodes, then the head of the list will be assigned to Node_start, and thus Node_start will be removed. A new head
         will be assigned to the next node with the highest priority.*/
        Node_ptr_t Node_start = head;
        head = head->next;
        free(Node_start);
        return Node_start;
    }
    
    return NULL;
}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
    return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++)
        ;
    return size;
}

