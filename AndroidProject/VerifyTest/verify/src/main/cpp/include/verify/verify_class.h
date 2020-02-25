#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

class VerifyClass {
public:
    VerifyClass();

    ~VerifyClass();

    void SetValue(uint32_t id, const std::string& value);

    std::string GetValue(uint32_t id);

private:
    std::unordered_map<uint32_t, std::string> value_map_;
};
