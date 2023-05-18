/***********************************
Date: 3 May 2021
Problem Number: 7
Hours spent working on project: 45
Instructor: Komogortsev, TSU
***********************************/

#ifndef DynQueue_h
#define DynQueue_h

class charQueue
{
private:
    struct queueNode
    {
         char character;
        queueNode *next;
    };
    queueNode *front;
    queueNode *rear;
    int numItems;

public:
    charQueue();
    ~charQueue();
    void enqueue (char);
    void dequeue (char &);
    bool isEmpty () const;
    void clear();
};
int checkBalance(charQueue cqueue);
#endif
