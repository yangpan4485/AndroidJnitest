#pragma once

#include <cstdint>
#include <functional>

using Callback = std::function<void(int)>;

void RegisteCallback(Callback callback);

void Start();

void Stop();
