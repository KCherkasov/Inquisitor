#include "BehavioralObject.h"

std::ifstream& operator >> (std::ifstream& stream, Approvals& data) {
  if (stream.is_open()) {
    size_t counter = SIZE_T_DEFAULT_VALUE;
    stream >> counter;
    if (counter > FREE_UID) {
      size_t key = SIZE_T_DEFAULT_VALUE;
      ssize_t value = SSIZE_T_DEFAULT_VALUE;
      for (size_t i = 0; i < counter; ++i) {
        stream >> key >> value;
        data._factions[key] = value;
      }
    }
    stream >> counter;
    if (counter > FREE_UID) {
      size_t key = SIZE_T_DEFAULT_VALUE;
      ssize_t value = SSIZE_T_DEFAULT_VALUE;
      for (size_t i = 0; i < counter; ++i) {
        stream >> key >> value;
        data._classes[key] = value;
      }
    }
    stream >> counter;
    if (counter > FREE_UID) {
      size_t key = SIZE_T_DEFAULT_VALUE;
      ssize_t value = SSIZE_T_DEFAULT_VALUE;
      for (size_t i = 0; i < counter; ++i) {
        stream >> key >> value;
        data._origins[key] = value;
      }
    }
    stream >> counter;
    if (counter > FREE_UID) {
      bool key = BOOL_DEFAULT_VALUE;
      ssize_t value = SSIZE_T_DEFAULT_VALUE;
      for (size_t i = 0; i < counter; ++i) {
        stream >> key >> value;
        data._genders[key] = value;
      }
    }
    stream >> counter;
    if (counter > FREE_UID) {
      size_t key = SIZE_T_DEFAULT_VALUE;
      ssize_t value = SSIZE_T_DEFAULT_VALUE;
      for (size_t i = 0; i < counter; ++i) {
        stream >> key >> value;
        data._stats[key] = value;
      }
    }
  }
  return stream;
}

std::ofstream& operator << (std::ofstream& stream, const Approvals& data) {
  if (stream.is_open()) {
    size_t counter = data._factions.size();
    stream << counter;
    for (std::map<size_t, ssize_t>::iterator elem = data._factions.begin(); elem != data._factions.end(); ++elem) {
      stream << elem->first << elem->second;
    }
    counter = data._classes.size();
    stream << counter;
    for (std::map<size_t, ssize_t>::iterator elem = data._classes.begin(); elem != data._classes.end(); ++elem) {
      stream << elem->first << elem->second;
    }
    counter = data._origins.size();
    stream << counter;
    for (std::map<size_t, ssize_t>::iterator elem = data._origins.begin(); elem != data._origins.end(); ++elem) {
      stream << elem->first << elem->second;
    }
    counter = data._genders.size();
    stream << counter;
    for (std::map<bool, ssize_t>::iterator elem = data._genders.begin(); elem != data._genders.end(); ++elem) {
      stream << elem->first << elem->second;
    }
    counter = data._stats.size();
    stream << counter;
    for (std::map<size_t, ssize_t>::iterator elem = data._stats.begin(); elem != data._stats.end(); ++elem) {
      stream << elem->first << elem->second;
    }
  }
  return stream;
}
