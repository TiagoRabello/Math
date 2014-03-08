## Prerequisites

* A C++11 compliant compiler and standard library.
* CMake

## Adding Math to your Project

1. Clone this repository into a subfolder of your project.

    ```
    git clone git://github.com/TiagoRabello/Math.git
    ```
2. Add the repository as a subfolder on CMake.

    ```
    ADD_SUBDIRECTORY( Math )
    ```
3. Set Math include and library directories

    ```
    INCLUDE_DIRECTORIES( ${MATH_INCLUDE_DIRS} )
    LINK_DIRECTORIES   ( ${MATH_LIBRARY_DIRS} )
    ```
4. Link with Math

    ```
    TARGET_LINK_LIBRARIES( MyProject ${MATH_LIBRARY} )
    ```
5. Use it!
    ```c++
    #include <Math/Point3D.h>
    #include <Math/Vector3D.h>

    struct Particle
    {
      Math::Point3D  position;
      Math::Vector3D velocity;
    };
    ```
