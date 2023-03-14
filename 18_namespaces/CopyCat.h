// Cat.h
#ifndef COPY_CAT_H_
#define COPY_CAT_H_

#include <iostream>
using namespace std;

namespace copycat
{

    const string NAME = "COPYCAT";

    class Cat
    {
    public:
        Cat();
        virtual ~Cat();
        void speak();
    };

}
#endif
