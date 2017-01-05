#include "GameObject.h"

size_t GameObject::_id = 0;

size_t GameObject::set_name(const std::string& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _name.clear();
  _name = value;
  return RC_OK;
}

size_t GameObject::set_description(const std::string& value) {
  if (value.empty()) {
    return RC_BAD_INPUT;
  }
  _description.clear();
  _description = value;
  return RC_OK;
}