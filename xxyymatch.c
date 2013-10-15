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

float lineDistance(float x1, float y1, float x2, float y2);

/*
 * match与obj的长度相同
 */
void xxyymatch(int *objid, float *objra, float *objdec, float *objx, float *objy, 
        float *objmag, float *objmage, int *refid, float *refra, float *refdec, 
        float *refx, float *refy, float *refmag, float *refmage, int *matchid, 
        float *matchra, float *matchdec, float *matchx, float *matchy, 
        float *matchmag, float *matchmage, float *matchDistance, int objlen, 
        int reflen) {
       
    float distance = 0.0, tmp;
    int matchIndex = 0;

    int i, j;
    for (i = 0; i < objlen; i++) {
        distance = lineDistance(objx[i], objy[i], refx[0], refy[0]);
        matchIndex = 0;
        for (j = 1; j < reflen; j++) {
            tmp = lineDistance(objx[i], objy[i], refx[j], refy[j]);
            if (tmp < distance) {
                distance = tmp;
                matchIndex = j;
            }
        }
        matchid[i] = refid[matchIndex];
        matchra[i] = refra[matchIndex];
        matchdec[i] = refdec[matchIndex];
        matchx[i] = refx[matchIndex];
        matchy[i] = refy[matchIndex];
        matchmag[i] = refmag[matchIndex];
        matchmage[i] = refmage[matchIndex];
        matchDistance[i] = distance;
    }
}

float lineDistance(float x1, float y1, float x2, float y2) {
    float xdiff = (x1 - x2);
    float ydiff = (y1 - y2);
    float dist = sqrt(xdiff * xdiff + ydiff * ydiff);
    return dist;
}
