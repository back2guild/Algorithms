#ifndef _COMMON_H_
#define _COMMON_H_ 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>
#include <time.h>

void bit_pattern(int);
void get_sys_info(void);
void create_random_list(unsigned long long *input, unsigned long lower, unsigned long long upper, unsigned long long size);
void* create_list(void);

#endif