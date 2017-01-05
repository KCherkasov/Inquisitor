#ifndef MISC_H
#define MISC_H

#include <vector>
#include <string>
#include <map>
#include <cmath>

enum ResponseCodes { RC_OK, RC_BAD_INPUT, RC_BAD_INDEX, RC_NOT_EMPTY, RC_SIZE };

const bool BOOL_DEFAULT_VALUE = false;
const size_t SIZE_T_DEFAULT_VALUE = 0;
const ssize_t SSIZE_T_DEFAULT_VALUE = 0;

const ssize_t FREE_ID = -1;
const size_t FREE_UID = 0;

const size_t START_LEVEL = 1;

#endif
