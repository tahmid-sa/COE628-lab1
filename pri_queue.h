/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pri_queue.h
 * Author: Tahmid Sajin, Section 2 COE 628, 500 830 210
 *
 * Created on January 19, 2021, 8:27 AM
 */

#ifndef PRI_QUEUE_H
#define PRI_QUEUE_H
typedef struct node {
    int priority;
    char * data;
    struct node * next;
} Node_t, * Node_ptr_t;
extern void PQ_insert( int, char *);
extern Node_ptr_t PQ_delete();
extern Node_ptr_t PQ_get_head();
extern int PQ_get_size();
#endif /* PRI_QUEUE_H */


