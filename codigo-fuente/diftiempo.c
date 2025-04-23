#include "diftiempo.h"

long diferencia(struct timeval *inicio, struct timeval *final) {
    long secs  = final->tv_sec  - inicio->tv_sec;
    long usecs = final->tv_usec - inicio->tv_usec;
    return secs * 1000000L + usecs;
}
