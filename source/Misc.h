#ifndef MISC_H
#define MISC_H

//-- include block --//

#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <cstdlib>

//-- include block end --//

//-- enumerations declaration --//

// subroutines and method return values enumeration
enum ResponseCodes { RC_OK, RC_BAD_INPUT, RC_BAD_INDEX, RC_NOT_EMPTY, RC_SIZE };

//-- enumerations declaration end --//

//-- global constants declaration --//

// different types default values for variables and class fields initialization
const bool BOOL_DEFAULT_VALUE = false;
const size_t SIZE_T_DEFAULT_VALUE = 0;
const ssize_t SSIZE_T_DEFAULT_VALUE = 0;

// consts for designated an empty id (when instance id is used instead of reference/pointer to instance)
const ssize_t FREE_ID = -1;
const size_t FREE_UID = 0;

// levelable objects min and max level value
const size_t START_LEVEL = 1;
const size_t MAX_LEVEL = 100;

//-- global constants declaration end --//

#endif
