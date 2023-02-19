# C++ Tutorial for Complete Beginners

Udemy Free Tutorial: https://www.udemy.com/course/free-learn-c-tutorial-beginners/

Repo: https://github.com/caveofprogramming/cplusplus-beginners

W3 C++ reference: https://www.w3schools.com/cpp/default.asp

## Pros/Cons(#1)

* Challenging to learn

* Often time-consuming to write

* Low level: 

  * Powerful: Very fast execution / Allows to access hardware. Good for real time, device drivers
  * Does not protect you from yourself -> Easy to introduce terrible bugs

  * Issues instructions directly to the computer, i.e. no virtual machine: Not truly platform-independent

## 1_hello_world (lessons #3-4)

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

## 2_outputting_text (lessons #5-6)

## 3_strings (lesson #7)

## 4_input (lesson #8)

## 5_types (lessons #9-12)

* Integer types: `int`, `short`, `long` , `unsigned`: There are limits to the values that can be stored in different types, cfr: https://www.tutorialspoint.com/c_standard_library/limits_h.htm Overflowing values don't automatically raise error messages!
* Floating types: `float`, `double`, `long double`
* `bool`: true(1) or false(0)
* `char`: 1 byte, `wchar_t` for unicode are 4 bytes

## 6_if_else (lessons #14-17)

```c++
if(condition1){
	// code block1
} else if(condition2){
    // code block2
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

