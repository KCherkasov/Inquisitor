#include "BehavioralObject.h"

std::ifstream& operator >> (std::ifstream& stream, Approvals& data) {
  if (stream.is_open()) {
    stream >> data._factions;
    stream >> data._classes;
    stream >> data._origins;
    stream >> data._genders;
    stream >> data._stats;
  }
  return stream;
}

std::ofstream& operator << (std::ofstream& stream, const Approvals& data) {
  if (stream.is_open()) {
    stream << data._factions;
    stream << data._classes;
    stream << data._origins;
    stream << data._genders;
    stream << data._stats;
  }
  return stream;
}