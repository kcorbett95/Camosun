/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include "arraySearch.h"

int linearSearch(const int value, const int numbers[], const int nNum){
    //loop through numbers array and return index when value is found
    int index = -1;
    for(int i = 0; i < nNum; i++){
        if(numbers[i] == value){
            index = i;
            break;
        }
    }
    return(index);
}