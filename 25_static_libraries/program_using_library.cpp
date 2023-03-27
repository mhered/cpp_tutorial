// program_using_library.cpp

#include <iostream>
#include "lib/TestClass.h"
#include "lib/testfunctions.h"

int main()
{
    my_namespace::test_function();

    my_namespace::TestClass test;
    test.msg();
    return 0;
}
