/*---------------------------------------------------------------------------
 * 
 * insert_srt.c 
 *
 *     02/17/2018 - 
 *
 *     <pi@>
 *
 *     All rights reserved.
 *
 *---------------------------------------------------------------------------
 */
#include<stdio.h>
#include"data.h"

void main() {
    int i, j, key;

    for (j=1;j<n;j++) {
        key = a[j];
        i = j-1;
        while (i>=0 && a[i]>key) {
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] = key;
    }
    for ( i=0 ;i<n ;i++ ) {
        printf("%d ", a[i]);
    }
}


