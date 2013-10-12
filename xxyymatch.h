/* 
 * File:   xxyymatch.h
 * Author: xy
 *
 * Created on October 12, 2013, 3:12 PM
 */

#ifndef XXYYMATCH_H
#define	XXYYMATCH_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct STAR{
        int id;
        float ra;
        float dec;
        float x;
        float y;
        float mag;
        float mage;
        float distance;
    };
    struct STAR_MATCH{
        int id1;
        float ra1;
        float dec1;
        float x1;
        float y1;
        float mag1;
        float mage1;
        int id2;
        float ra2;
        float dec2;
        float x2;
        float y2;
        float mag2;
        float mage2;
        float distance;
    };

    void xxyymatch(struct STAR *obj, struct STAR *ref, struct STAR *match, int length);

#ifdef	__cplusplus
}
#endif

#endif	/* XXYYMATCH_H */

