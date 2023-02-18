# C++ Tutorial for Complete Beginners

Udemy Free Tutorial: https://www.udemy.com/course/free-learn-c-tutorial-beginners/

Repo: https://github.com/caveofprogramming/cplusplus-beginners

## Pros/Cons

* Challenging to learn

* Often time-consuming to write

* Low level: 

  * Powerful: Very fast execution / Allows to access hardware. Good for real time, device drivers
  * Does not protect you from yourself -> Easy to introduce terrible bugs

  * Issues instructions directly to the computer, i.e. no virtual machine: Not truly platform-independent

## Hello World

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

* Install an IDE: he uses Eclipse CDT, I will use Visual Studio Code

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

