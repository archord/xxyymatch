/* 
 * File:   main.c
 * Author: xy
 *
 * Created on October 12, 2013, 3:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "xxyymatch.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    int length = 10;
    
    struct STAR *ref = (struct STAR*)malloc(length*sizeof(struct STAR));
    struct STAR *obj = (struct STAR*)malloc(length*sizeof(struct STAR));
    struct STAR *match = (struct STAR*)malloc(length*sizeof(struct STAR));
    
    int i;
    for(i=0; i<length; i++){
        ref[i].x = i+0.1;
        ref[i].y = i+0.1;
        obj[i].x = i+0.2;
        obj[i].y = i+0.2;
    }
    xxyymatch(obj, ref, match, length);
    
    for(i=0; i<length; i++){
        printf("%3d%f %f%3d%f %f %f\n", 
                obj[i].id, obj[i].x, obj[i].y,
                match[i].id, match[i].x, match[i].y, match[i].distance);
    }

    return (EXIT_SUCCESS);
}

