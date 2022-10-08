#include <bits/time.h>
#include <err.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#include "utils.h"


pid_t *pids;

int main(int argc, char *argv[]) {
    int ret = EXIT_FAILURE;

    if (argc < 4) {
        fprintf(stderr,
            "Usage: %s <nproc> <total [ms]> <resolution [ms]>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int nproc = strtol(argv[1], NULL, 10);
    int total = strtol(argv[2], NULL, 10);
    int resol = strtol(argv[3], NULL, 10);
    
    if (nproc < 1) {
        fprintf(stderr, "<nproc>(%d) should be >=1\n", nproc);
        exit(EXIT_FAILURE);
    }

    if (total < 1) {
        fprintf(stderr, "<total>(%d) should be >=1\n", total);
        exit(EXIT_FAILURE);
    }

    if (resol < 1) {
        fprintf(stderr, "<resol>(%d) should be >=1\n", resol);
        exit(EXIT_FAILURE);
    }

    if (total % resol) {
        fprintf(stderr, "<total>(%d) should be multiple of <resolution>(%d)=1\n",
            total, resol);
        exit(EXIT_FAILURE);
    }

    int nrecord = total / resol;

    struct timespec *logbuf = malloc(sizeof(struct timespec) * nrecord);
    if (!logbuf)
        err(EXIT_FAILURE, "malloc (logbuf) failed");

    puts("Estimating workload which takes just on millisecond");
    unsigned long nloop_per_resol = loops_per_msec() * resol;
    puts("Finished estimation");
    fflush(stdout);

    pids = malloc(sizeof(pid_t) * nproc);
    if (pids == NULL) {
        warn("malloc(pids) failed");
        goto free_logbuf;
    }

    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);

    int i, ncreated;
    for (i = 0, ncreated = 0; i < nproc; i++, ncreated ++) {
        pids[i] = fork();

        if (pids[i] < 0) {
            goto wait_children;
        } else if (pids[i] == 0) {
            child_fn(i, logbuf, nrecord, nloop_per_resol, start);
        }
    }
    ret = EXIT_SUCCESS;

wait_children:
    if (ret == EXIT_FAILURE) {
        for (i = 0; i < ncreated; i++) {
            if (kill(pids[i], SIGINT) < 0) {
                warn("kill(%d) failed", pids[i]);
            }
        }
    }

    for (i = 0; i < ncreated; i++) {
        if (wait(NULL) < 0) {
            warn("wait() failed");
        }
    }

free_pids:
    free(pids);

free_logbuf:
    free(logbuf);
    exit(ret);
}