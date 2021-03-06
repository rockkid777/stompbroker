#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>


#define print(...) fprintf(stdout,__VA_ARGS__);
// define or alter log levels here
#define warn(...) fprintf(stderr,__VA_ARGS__);
#define info(...) print(__VA_ARGS__);
#define debug(...) print(__VA_ARGS__);fflush(stdout);
#define trace(...) print(__VA_ARGS__);

#endif