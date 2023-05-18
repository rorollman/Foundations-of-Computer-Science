/***********************************
Date: 3 May 2021
Problem Number: 7
Hours spent working on project: 45
Instructor: Komogortsev, TSU
***********************************/
#include "DynQueue.h"
#include <stdio.h>
#include <iostream>
using namespace std;

//constructor
charQueue::charQueue()
{
    front = NULL;
    rear = NULL;
    numItems = 0;
}

//destructor
charQueue::~charQueue()
{
    clear();
}

//adding to the queue
void charQueue::enqueue(char c)
{
    queueNode *newnode;

    newnode = new queueNode;
    newnode->character = c;
    newnode->next= NULL;

    if (isEmpty()) {
        front = newnode;
        rear = newnode;
    }
    else {
    rear->next = newnode;
        rear = newnode;
    }
    numItems++;
}

//removing from the queue
void charQueue::dequeue(char &c)
{
    queueNode *temp;

    if (isEmpty()) {
        cout << "The queue is empty.\n";
        return;
    }
    else {
    c = front->character;
        temp = front;
        front = front->next;
        delete temp;
        numItems--;
    }
}

//check to see if the queue is empty
bool charQueue::isEmpty() const
{
    bool test;

    if (numItems>0) {
        test = false;
    }
    else
        test = true;

    return test;
}

void charQueue::clear()
{
    char c;
    while (!isEmpty()) {
        dequeue(c);
    }
}

//checking the balance of parans and braackets
int checkBalance(charQueue cqueue)
{
    //return 0 if valid
    //return 1 if missing paranthesis
    //return 2 if missing bracket
    //return -1 if nothing else
    int paran=0, bracket=0;

    //dequeues until queue is empty
    while (!cqueue.isEmpty()) {
        char c;
        cqueue.dequeue(c);
        switch (c) {
            case '(':
                paran++;
                break;
            case '[':
                bracket++;
                break;
            case ')':
                paran++;
                break;
            case ']':
                bracket++;
                break;
        }
    }
    //if parans and brackets are even, checks out
    if (paran%2 == 0 && bracket%2 == 0) {
        cout << "valid\n";
        return 0;
    }
    else
    {
        //determines with was odd, that's the missing one
        if (paran%2 != 0) {
            cout << "invalid\n";
            return 1;
        }
        if (bracket%2 != 0) {
            cout << "invalid\n";
            return 2;
        }
    }
    return -1;
}
