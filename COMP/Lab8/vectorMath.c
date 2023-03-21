/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include "vectorMath.h"

Vector *vectorMath (const Vector v1, const Vector v2, Vector *resPtr, const char op){
    //check for vector size
    if(v1.size != v2.size){
        //fprintf(stderr,"Vectors must be same size\n");
        return NULL;
    }
    //put result vector size
    resPtr->size = v1.size;
    //switch for operator
    for (int i = 0; i < v1.size; i++) {
        switch(op) {
            case '+':
                resPtr->data[i] = v1.data[i] + v2.data[i];
                break;
            case '-':
                resPtr->data[i] = v1.data[i] - v2.data[i];
                break;
            case '*':
                resPtr->data[i] = v1.data[i] * v2.data[i];
                break;
            case '/':
                if (v2.data[i] == 0) {
                    return NULL;
                }
                resPtr->data[i] = v1.data[i] / v2.data[i];
                break;
            default:
                //fprintf(stderr,"Invalid operator\n");
                return NULL;
        }
            
    }
}