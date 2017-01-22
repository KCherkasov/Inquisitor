#infdef BEHAVIORAL_OBJECT_H
#define BEHAVIORAL_OBJECT_H

#include "GameObject.h"

class Approvals {
  public:
    Approvals() {}
    ~Approvals() {}
    ssize_t factions(const size_t& faction) const { return _factions[faction]; }
    std::map<size_t&, ssize_t> factions() const { return _factions; }
    ssize_t classes(const size_t& char_class) const { return _classes[char_class]; }
    std::map<size_t&, ssize_t> classes() const { return _classes; }
    ssize_t origins(const size_t& origin) const { return _origins[origin]; }
    std::map<size_t&, ssize_t> origins() const { return _origins; }
    ssize_t genders(const bool& gender) const { return _genders[gender]; }
    std::map<bool, ssize_t> genders() const { return _genders; }
    ssize_t stats(const size_t& stat) const { return _stats[stat]; }
    std::map<size_t, ssize_t> stats() const { return _stats; }
    size_t clear() { _factions.clear(); _classes.clear(); _origins.clear(); _genders.clear(); _stats.clear(); return RC_OK; }
    
    Approvals& operator = (const Approvals& rhs) {
      _factions.clear();
      _factions = rhs._factions;
      _classes.clear();
      _classes = rhs._classes;
      _origins.clear();
      _origins = rhs._origins;
      _genders.clear();
      _genders = rhs._genders;
      _stats.clear();
      _stats = rhs._stats;
      return *this;
    }
    
    friend std::ifstream& operator >> (std::ifstream& stream, Approvals& data);
    friend std::ofstream& operator << (std::ofstream& stream, const Approvals& data)
    
  private:
    std::map<size_t, ssize_t> _factions;
    std::map<size_t, ssize_t> _classes;
    std::map<size_t, ssize_t> _origins;
    std::map<bool, ssize_t> _genders;
    std::map<size_t, ssize_t> _stats;
};

class BehavioralObject: public GameObject {
  public:
    BehavioralObject(const size_t& id = 0): GameObject(id) {}
    virtual ~BehavioralObject() {}
    ssize_t affections(const size_t& index) const { return _affections[index]; }
    std::vector<ssize_t> affections() const { return _affections; }
    Approvals approvals() { return _approvals; }
    ssize_t stat_modifiers(const size_t& index) const { return _stat_modifiers[index]; }
    std::vector<ssize_t> stat_modifiers() const { return _stat_modifiers; }
    std::string what() const;
    std::string short_what() const;
    size_t update() { return RC_OK; }
    
    friend std::ifstream& operator >> (std::ifstream& stream, BehavioralObject&  data);
    friend std::ofstream& operator << (std::ofstream& stream, const BehavioralObject& data);
    
  protected:
    std::vector<ssize_t> _affections;
    Approvals _approvals;
    std::vector<ssize_t> _stat_modifiers;
};

class BehavioralStorage {
  public:
    BehavioralObject() {}
    ~BehavioralObject() {}
    BehavioralObject& classes(const size_t& index) const { return _classes[index]; }
    std::vector<BehavioralObject> classes() const { return _classes; }
    size_t classes_count() const { return _classes.size(); }
    BehavioralObject& factions(const size_t& index) const { return _factions[index]; }
    std::vector<BehavioralObject> factions() const { return _factions; }
    size_t factions_count() const { return _factions.size(); }
    BehavioralObject& origins(const size_t& index) const { return _origins[index]; }
    std::vector<BehavioralObject> origins() const { return _origins; }
    size_t origins_count() const { return _origins.size(); }
    size_t add_class(const BehavioralObject& new_class) { _classes.push_back(new_class); return RC_OK; }
    size_t add_origin(const BehavioralObject& new_origin) { _origins.push_back(new_origin); return RC_OK; }
    size_t add_faction(const BehavioralObject& new_faction) { _factions.push_back(new_faction); return RC_OK; }
    size_t clear() { _classes.clear(); _origins.clear(); _factions.clear(); return RC_OK; }
  private:
    std::vector<BehavioralObject> _classes;
    std::vector<BehavioralObject> _factions;
    std::vector<BehavioralObject> _origins;
};

#endif