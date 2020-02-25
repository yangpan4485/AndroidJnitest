#include <iostream>
#include <string>

#include "../src/verify_callback.h"
#include "../src/verify_class.h"
#include "../src/verify_test.h"

int main(void) {
    RegisteCallback([](int val) { std::cout << "val:" << val << std::endl; });
    Start();

    VerifyClass verify_class;

    verify_class.SetValue(1,"hello");
    verify_class.SetValue(2,"world");

    std::cout << verify_class.GetValue(1) << std::endl;
    std::cout << verify_class.GetValue(2) << std::endl;

    std::cout << GetRandValue() << std::endl;
    std::cout << GetStringValue() << std::endl;

    getchar();
    Stop();
    return 0;
}
