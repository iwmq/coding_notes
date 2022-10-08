#include <err.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <time.h>

#include "utils.h"

inline long diff_nsec(struct timespec before, struct timespec after) {
    return ((after.tv_sec*NSECS_PER_SEC + after.tv_nsec)
        - (before.tv_sec*NSECS_PER_SEC + before.tv_nsec));
}


unsigned long loops_per_msec() {
    struct timespec before, after;
    clock_gettime(CLOCK_MONOTONIC, &before);

    unsigned long i;
    for (i = 0; i < NLOOPS_FOR_ESTIMATION; i++)
        ;

    clock_gettime(CLOCK_MONOTONIC, &after);
    return NLOOPS_FOR_ESTIMATION * NSECS_PER_MSEC / diff_nsec(before, after);
}


inline void load(unsigned long loops) {
    unsigned long i;
    for (i = 0; i < loops; i++)
        ;
}


void child_fn(int id, struct timespec *buf, int nrecord,
    unsigned long nloop_per_resol, struct timespec start) {
    int i;
    for (i = 0; i < nrecord; i++) {
        struct timespec ts;

        load(nloop_per_resol);
        clock_gettime(CLOCK_MONOTONIC, &ts);
        buf[i] = ts;
    }

    for (i = 0; i < nrecord; i++) {
        printf("%d\t%ld\t%d\n", id, diff_nsec(start, buf[i]) / NSECS_PER_MSEC,
            (i+1) * 100 / nrecord);
    }

    exit(EXIT_SUCCESS);
}


void parent_fn(int nproc) {
    int i;
    for (i = 0; i < nproc; i++)
        wait(NULL);
}