#include "testfunctions.h"
#include <iostream> // do not include in the header, only in implementation

namespace my_namespace // namespace is recommended to avoid conflicts
{
    void test_function()
    {
        std::cout << "Message from test function" << std::endl;
    }
}
