#ifndef DIFTIEMPO_H
#define DIFTIEMPO_H

#include <sys/time.h>

// Calcula el tiempo medido en microsegundos.
long diferencia(struct timeval *inicio, struct timeval *final);

#endif
