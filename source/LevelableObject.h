#ifndef LEVELABLE_OBJECT_H
#define LEVELABLE_OBJECT_H

#include "GameObject.h"

class LevelableObject: public GameObject {
  public:
    LevelableObject(const ssize_t& id = 0, const size_t& level = START_LEVEL): GameObject(id), _level(level) {}
    virtual ~LevelableObject() {}
    size_t level() const { return _level; }
    virtual size_t level_up() { if (_level < MAX_LEVEL) { ++_level; } return RC_OK; }
  protected:
    size_t _level;
};

#endif