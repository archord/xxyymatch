/* 
 * File:   xxyymatch.c
 * Author: xy
 *
 * Created on October 12, 2013, 3:12 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "xxyymatch.h"

float lineDistance(struct STAR star1, struct STAR star2) ;

/*
 * 
 */
void xxyymatch(struct STAR *obj, struct STAR *ref, struct STAR *match, int length) {
    
    float distance = 0.0, tmp;
    int matchIndex = 0;

    int i, j;
    for (i = 0; i < length; i++) {
        distance = lineDistance(obj[i], ref[0]);
        matchIndex = 0;
        for (j = 1; j < length; j++) {
            tmp = lineDistance(obj[i], ref[j]);
            if (tmp < distance) {
                distance = tmp;
                matchIndex = j;
            }
        }
        match[i].id = ref[matchIndex].id;
        match[i].ra = ref[matchIndex].ra;
        match[i].dec = ref[matchIndex].dec;
        match[i].x = ref[matchIndex].x;
        match[i].y = ref[matchIndex].y;
        match[i].mag = ref[matchIndex].mag;
        match[i].mage = ref[matchIndex].mage;
        match[i].distance = distance;
    }
}

float lineDistance(struct STAR star1, struct STAR star2) {
    float xdiff = (star1.x - star2.x);
    float ydiff = (star1.y - star2.y);
    float dist = sqrt(xdiff * xdiff + ydiff * ydiff);
    return dist;
}
