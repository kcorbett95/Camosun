
#include "statistics.h"

//Compute mean
double avg(const double sum, const int count){
    
    double n = 0.0;
    //error handling for #entries
    //if(count<2){
    //    fprintf(stderr,"\nInsufficient Entries for Mean function");
    //    return EXIT_FAILURE;
    //}
    
    n = sum / count;
    
    return (n);
}

//Compute std dev for sample
double ssdev(const double sum, const double sumsq, const int count){
    
}
