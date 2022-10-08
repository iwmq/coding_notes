#ifndef UTILS_H_
#define UTILS_H_

#include <time.h>

#define NLOOPS_FOR_ESTIMATION 1000000000UL
#define NSECS_PER_MSEC 1000000UL
#define NSECS_PER_SEC 1000000000UL

long diff_nsec(struct timespec, struct timespec);

unsigned long loops_per_msec();

void load(unsigned long loops);

void child_fn(int, struct timespec *, int, unsigned long, struct timespec);

void parent_fn(int);

#endif