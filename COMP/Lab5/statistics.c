
#include "statistics.h"

//Compute mean
double avg(const double sum, const int count){
    
    double m = 0.0;
    //error handling for #entries
    if(count<2){
        fprintf(stderr,"\nInsufficient Entries for Mean function");
        return EXIT_FAILURE;
    }
    
    m = sum / count;
    
    return (m);
}

//Compute std dev for sample
double ssdev(const double sum, const double sumsq, const int count){
    
    double sdv = 0.0;
    //error handling for #entries
    if(count<2){
        fprintf(stderr,"\nInsufficient Entries for Sdv function");
        return EXIT_FAILURE;
    }
    
    sdv = sqrt(((count*sumsq)-(sum*sum))/(count*(count - 1)));
    
    return(sdv);
}
