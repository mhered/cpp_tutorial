// Cat.h
#ifndef CAT_H_
#define CAT_H_

#include <iostream>
using namespace std;

namespace cat
{
    const string NAME = "CAT";

    class Cat
    {
    public:
        Cat();
        virtual ~Cat();
        void speak();
    };
}
#endif
