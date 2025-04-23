#ifndef TIEMPO_H
#define TIEMPO_H

#include <sys/time.h>

long diferencia(struct timeval *inicio, struct timeval *final);

#endif
