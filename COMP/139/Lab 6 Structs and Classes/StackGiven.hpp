/*
 * A linked implementation of a TEMPLATE stack that can be used to store objects
 *
 * File:   Stack.hpp
 * Author: dale
 *
 * Created on Oct. 22, 2018
 */

#ifndef STACK_HPP
#define	STACK_HPP

#include <cstdlib>
#include "StackException.hpp"

template <class T> class Stack {
private:
    // The node that will be used for the Stack
    typedef struct stackNode {
	struct stackNode* next;
	T Data;
    } StackNode;

    /** A pointer to the StackNode at the top of the stack */
    StackNode* topOfStack;
    /** The number of items currently on the stack */
    int count;
public:
    /** Constructor initializes the data members */
    inline Stack () : topOfStack(NULL), count(0) {
    }

    /**
     * Push an item onto the stack
     *
     * @param the item to be stored
     */
    void push(T item) {
        if(topOfStack == nullptr){
            topOfStack = new stackNode();
            topOfStack->next = nullptr;
            topOfStack->Data = item;
        }else{
            StackNode* newNode = new stackNode();
            newNode->Data = item;
            newNode->next = topOfStack;
            topOfStack = newNode;
        }
    }



    /**
     * Remove an item from the stack
     *
     * @throw A StackException if the stack is empty
     * @return the Item
     */
    T pop(void)  {
        //return Stack[--count];
    }



    /**
     * Peek at the item at the top of the stack
     *
     * @throw A StackException if the stack is empty
     * @return
     */
    T top(void)  {
        //return Stack[count-1];
    }


    /**
     * The number of items currently on the stack
     * @return That number
     */
    inline int size(void) {
	return count;
    }

    /**
     * Query if the stack is empty
     *
     * @return true if the stack is empty
     */
    inline bool isEmpty(void) {
	return count == 0;
    }
};


#endif	/* STACK_HPP */
