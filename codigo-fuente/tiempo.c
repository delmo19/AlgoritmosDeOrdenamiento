#include "tiempo.h"

long diferencia(struct timeval *inicio, struct timeval *final) {
    long micros = final->tv_usec - inicio->tv_usec;
    return micros;
}
