#include "verify_class.h"
// std::unordered_map<uint32_t, std::string> value_map_;
VerifyClass::VerifyClass() {}

VerifyClass::~VerifyClass() {}

void VerifyClass::SetValue(uint32_t id, const std::string& value) {
    value_map_[id] = value;
}

std::string VerifyClass::GetValue(uint32_t id) {
    if (value_map_.find(id) == value_map_.end()) { return ""; }
    return value_map_[id];
}
