// Cat.h

// header file contains function prototypes
//  #ifndef - #endif precompilar instruciton to prevent including twice

#ifndef CAT_H_
#define CAT_H_
class Cat //Cat class prototype
{
private:
    bool happy; //private state variable (encapsulated so it cannot be accessed from outside)
public: // public data and methods
    void make_happy();
    void make_sad();
    void speak(); //public method prototype
    void jump(); //public method prototype
};

#endif
