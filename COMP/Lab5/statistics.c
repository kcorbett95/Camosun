
#include "statistics.h"

//Compute mean
double avg(const double sum, const int count){
    
    double m = 0.0;
    
    m = sum / count;
    
    return (m);
}

//Compute std dev for sample
double ssdev(const double sum, const double sumsq, const int count){
    
    double sdv = 0.0;
    
    //compute standard deviation
    sdv = sqrt(((count*sumsq)-(sum*sum))/(count*(count - 1)));
    
    return(sdv);
}
