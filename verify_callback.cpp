#include "verify_callback.h"

#include <iostream>

#include <thread>

class ValueCallback {
public:
    static ValueCallback& GetInstance() {
        static ValueCallback instance;
        return instance;
    }

    void Start() {
        if (running_) { return; }
        running_ = true;
        work_thread_ = std::thread(&ValueCallback::WorkFunc, this);
    }

    void Stop() {
        if (!running_) { return; }
        running_ = false;
        work_thread_.join();
    }

    void RegisteCallback(Callback callback) { callback_ = callback; }

private:
    ValueCallback() {}
    ValueCallback(const ValueCallback&) = delete;
    ValueCallback& operator=(const ValueCallback&) = delete;
    ~ValueCallback() {}

    void WorkFunc() {
        while (running_) {
            int value = rand() % 9999;
            if (value > 5555 && value < 5600) {
                std::cout << "callback" << std::endl;
                callback_(value);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

private:
    bool running_ = false;
    std::thread work_thread_;
    Callback callback_;
};

void RegisteCallback(Callback callback) {
    ValueCallback::GetInstance().RegisteCallback(callback);
}

void Start() { ValueCallback::GetInstance().Start(); }

void Stop() { ValueCallback::GetInstance().Stop(); }
