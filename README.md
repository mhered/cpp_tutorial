# C++ Tutorial for Complete Beginners

Udemy Free Tutorial: https://www.udemy.com/course/free-learn-c-tutorial-beginners/

Repo: https://github.com/caveofprogramming/cplusplus-beginners

W3 C++ reference: https://www.w3schools.com/cpp/default.asp

## Pros/Cons of C++ (lesson #1)

* Challenging to learn

* Often time-consuming to write

* Low level: 

  * Powerful: Very fast execution / Allows to access hardware. Good for real time, device drivers
  * Does not protect you from yourself -> Easy to introduce terrible bugs

  * Issues instructions directly to the computer, i.e. no virtual machine: Not truly platform-independent

## 01_hello_world (lessons #3-4)

Shopping list:

* Install a compiler: `gcc` / `g++`is industry standard

  cfr: https://linuxize.com/post/how-to-install-gcc-on-ubuntu-20-04/?utm_content=cmp-true

  Normally already available as part of Ubuntu 20.04 distro, check with:

  ```bash
  $ g++ --version
  g++ (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
  Copyright (C) 2019 Free Software Foundation, Inc.
  This is free software; see the source for copying conditions.  There is NO
  warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  ```

* Create a file `hello_cpp.cpp`

  ```c++
  // hello_cpp.cpp
  
  #include <iostream>
  using namespace std;
  
  int main() {
  	cout << "Hello World!" << endl;
  	return 0;
  }
  ```

* Compile it (with`g++` because`std::cout` won't be accessible to `gcc`):

```bash
$ g++ hello_cpp.cpp -o hello_cpp
```

* Execute it:

```bash
$ ./hello_cpp
Hello World!
```

## C++ in Visual Studio Code

Install and configure an IDE: he uses Eclipse CDT, I will use Visual Studio Code

Refer to: 

* [GCC on Linux](https://code.visualstudio.com/docs/cpp/config-linux)

Modify `tasks.json` to change the behavior of the build, e.g. to place compiled binaries in a `bin/` subfolder, i.e.:

```bash
$ g++ -g code.cpp -o ./bin/code
```

Edit `tasks.json` as follows:

```json
...
"tasks": [
    {
    	...
    	"args": [
    	    "-g", 
    	    "${file}", 
    	    "-o", 
    	    "${fileDirname}/bin/${fileBasenameNoExtension}"
    	],
    	...
  
```

F5: build and debug

F9: toggle breakpoint 

CTRL+SHIFT + i: autoformat 

CTRL+SHIFT + p: command window 

- [CMake Tools on Linux](https://code.visualstudio.com/docs/cpp/cmake-linux)

* [C++ section](https://code.visualstudio.com/docs/cpp) of the VS Code website, with topics on:

  - [Debugging](https://code.visualstudio.com/docs/cpp/cpp-debug)

  - [Editing](https://code.visualstudio.com/docs/cpp/cpp-ide)

  - [Settings](https://code.visualstudio.com/docs/cpp/customize-default-settings-cpp)

  - [FAQ](https://code.visualstudio.com/docs/cpp/faq-cpp)

## 02_outputting_text (lessons #5-6)

## 03_strings (lesson #7)

## 04_input (lesson #8)

## 05_variables (lessons #9-12)

* Integer types: `int`, `short`, `long` , `unsigned`: There are limits to the values that can be stored in different types, cfr: https://www.tutorialspoint.com/c_standard_library/limits_h.htm Overflowing values don't automatically raise error messages!
* Floating types: `float`, `double`, `long double`
* `bool`: true(1) or false(0)
* `char`: 1 byte, `wchar_t` for unicode are 4 bytes
* `const`: constant , yields compiler error if I try to reassign it again
* scope of variables are the brackets where they are declared

## 06_if_else (lessons #14-17)

```c++
if(condition1){
	// code block 1
} else if(condition2){
    // code block 2
} else {
    // final code block
}  
```

Logical operators: `&&` and, `||` or, `!` not

Multiple conditionals evaluate left to right but for better readability (1) use parentheses and (2) store partial conditions in `bool` variables. E.g. instead of: 

```c++
if (value2 !=8 && value1 == 10 || value1<10) {...}
```

It is better:

```c++
bool condition1 = (value2 !=8) && (value1 == 10);
bool condition2 = value1 < 10;
if (condition1 || condition2) {...}
```

## 07_loops (lessons #18-21)

`while(){}`: loop executes while condition is true

```c++
while(condition){
	// code block 1
}
```

`do{}while()`: always executes code block at least once

```c++
do{
	// code block 1
} while(condition)
```

`for(){}` loop:

* initialization statement: executed once, before the execution of the code block. Used to init counter. Note exceptionally the counter will be available inside the code block.
* exit condition: code block executes while this condition is true, exits when false.
* update statement: executed (every time) after the code block.

```c++
for (initialization statement; exit condition; update statement;) {
  // code block
}
```

`continue`: skip to next iteration

`break`: stop iteration

## 08_arrays (lessons #22-25)

Notes:

* if not initialized there will be garbage
* nothing prevents you from accesing an index out of the array and this yields garbage!
* string object stores a pointer, fixed size 8 bytes 
* use loops to initialize and process
* use sizeof to make size independent

Example of 2D array below:

```c++
// multidimensional array, sizeof
    string animals[2][3] = {
        {"fox", "dog", "mouse"},
        {"cat", "squirrel", "parrot"}};

    int rows = sizeof(animals)/sizeof(animals[0]);
    int cols = sizeof(animals[0])/sizeof(string); // sizeof(string) = 8, its a pointer!

    cout << rows << " x " << cols <<endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << animals[i][j] << " " << flush;
        }
        cout << endl;
    };
```

## 09_switch (lesson #26)

```c++
switch(int or char){
    case 1:
        // code block 1
        break;
    ...
    case N:
        // code block N
        break;      
    default:
        // default code
}
```

## 10_functions (lessons #27-30)

Notes:

*  `#include` precompiler instructions paste in the contents of other files
* `#ifndef -#define - #endif` structure prevents duplicated inclusion
* header files contain function prototypes so it is not needed to declare functions before calling them
* C++ is typed: need to declare types of function arguments
* typical structure: define functions in a `utils.cpp` file, declare their prototypes in a `utils.h` file, include the header in a `main.cpp`file to make the functions available
* In VS code, to build all cpp files in a folder modify the following line in `tasks.json`:

```json
            "args": [
				...
                "-g",
                "${fileDirname}/**.cpp",
                ...
```

cfr. https://stackoverflow.com/questions/47665886/vs-code-will-not-build-c-programs-with-multiple-ccp-source-files

## 11_classes (lessons #31-38)

- creating classes is analogous to creating your own variable types
- classes bundle methods and data representing state
- encapsulation: variables are `private:` , public methods are defined to manipulate them, e.g. setters and getters (which are actually not recommended)
- constructor is the place to initialize instance variables
- destructor runs when instance is destroyed (natural scope ends in next closing curly bracket `}`)
- overloading methods: defining methods with the same name and different parameters (cannot differ only in return type). Typical with constructors, but not exclusive
- short methods can be implemented inline in the Class definition
- in constructor and setters use the same names for parameters as for the corresponding instance variables and use the `this->` pointer to distinguish them 
- in constructors it is recommended instead (and faster) to use initialization lists to initialize the variables, either in the header if short or in the .cpp if longer. It is possible to pass parameters or to initialize with fixed values. You can also initialize some parameters in the initialization list and others inside the curly brackets `{}` as needed.
- Good practice to declare as `const` methods that should not change state variables of the class 

## 12_pointers_and_references (lessons #39, #45, #46)

* functions that take pointers can receive &var as parameter and make persistent changes

```c++
// example function takes pointer as parameter and modifies its content
void manipulate(int* pointer) {*pointer*=2}

int var;
manipulate(&var) // if called with &var, it makes persistent changes in var
```

* `&`has two uses: 'address of' and 'reference to' (to make an alias). How to distinguish?

```c++
double var1 =1.0;
double *pointer = &var1; //create a pointer to the address of an existing variable
double &var2 = var1; // create an alias (instead of a copy) of var1
```

* two ways to modify a pointer: modify memory location where it points or modify what is stored in the memory location read from right to left: `const double *const pt_4` is a "constant pointer to a double that is constant"

## 13_arithmetics (lesson #40)

* careful with integer division
* casting into different types
* use brackets for more readable precedences

## 14_array_pointers (lessons #41-42)

* loop trough array using array elements syntax, with for loop incrementing pointers or in a while loop comparing pointers to break
* careful when subtracting pointers: cast the result to `long` and do not use as a pointer but as an offset!!

## 15_char_arrays (lessons #43-44)

* null termination character added at the end. Need to consider when calculating length `LEN = sizeof()-1`!
* two methods of reversing a string

## 16_more_classes (lessons #47-49)

* copy constructor receives a reference to a `const` object, i.e. inside we can only call `const` methods of the object being copied (we do not want to modify the original!)
* if we don't define it explicitly C++ makes an implicit copy constructor and does not call the normal constructor
* `new` allocates memory. Need to call `delete` explicitly, C++ will not call destructor at end of scope!
* special syntax `pt_object->member` is equivalent to `(*pt_object).member`
* typical source of bugs, e.g. not deleting object pointers causing memory leaks, deleting a pointer not created with new, deleting a `NULL` pointer, etc.
* two types of memory: **stack** and **heap**. **Stack** is a small LIFO, keeps addresses of functions and local variables. stack overflow if you call function iteratively. With `new` you allocate memory in the **heap** which is larger.
* we can use new and [] to allocate memory for an array of objects without instantiating them. Remember to delete all after using  them. Works also with primitive types.

```c++
Animal *pt_animal = new Animal()[10];
...
delete [] pt_animal; //no need to specify the size
```



## What next (lesson #77)

- Exceptions
- File handling
- Standard Template Library (STL)
