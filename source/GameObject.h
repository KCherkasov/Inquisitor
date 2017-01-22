#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Misc.h"
#include "TagManager.h"
#include <fstream>

class GameObject {
  public:
    GameObject(const ssize_t& id = 0): _own_id(id), _manager(NULL) { if (_own_id == 0) {_own_id = _id++; } }
    virtual ~GameObject() {}
    ssize_t id() const { return _own_id; }
    std::string name() const { return _name; }
    std::string description() const { return _description; }
    TagManager* manager() const { return _manager; }
    virtual std::string what() const = 0;
    virtual std::string short_what() const = 0;
    virtual size_t update() { return RC_OK; }
    size_t set_name(const std::string& value);
    size_t set_description(const std::string& value);
    size_t set_manager(TagManager* value) { if (_manager != NULL) { return RC_NOT_EMPTY; } if (manager == NULL) { return RC_BAD_INPUT; } _manager = manager; return RC_OK; }
  protected:
    static ssize_t _id;
    ssize_t _own_id;
    TagManager* _manager;
    std::string _name;
    std::string _description;
};

#endif