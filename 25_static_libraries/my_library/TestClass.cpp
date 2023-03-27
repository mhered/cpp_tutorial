#include "TestClass.h"
#include <iostream> // do not include in the header, only in implementation

namespace my_namespace // namespace is recommended to avoid conflicts
{

    TestClass::TestClass()
    {
    }

    void TestClass::msg()
    {
        std::cout << "Message from test class" << std::endl;
    }

    TestClass::~TestClass()
    {
    }
}