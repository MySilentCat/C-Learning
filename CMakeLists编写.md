# CMakeLists编写

## 1. 单个源文件编译

### 1.1 一个基本的CMakeLists

```cmake
# 设置cmake的最低版本，FATAL_ERROR表示低于该版本编译报错
cmake_minium_required(VERSION 3.8 FATAL_ERROR)

# project声明该项目的名称，并使用LANGUAGES标识该项目支持的编程语言，CXX表示C++
# cmake中，c++是默认的编程语言，但还是建议显示声明
project(hello-world LANGUAGES C)

# 指示CMake创建一个新目标：可执行文件hello-world
# 这个可执行文件是通过编译和链接源文件hello-world.c生成的
add_excutable(hello-world hello-world.c)
```

2. CmakeLists和hello-world.c放在同一级目录下，然后创建build文件夹进行cmake构建

### 1.2 切换生成器

1. 在命令行显示的使用-G切换生成器

   ```shell
   $ mkdir -p build
   $ cd build
   $ cmake -G Ninja ..
   -- The CXX compiler identification is GNU 8.1.0
   -- Check for working CXX compiler: /usr/bin/c++
   -- Check for working CXX compiler: /usr/bin/c++ -- works
   -- Detecting CXX compiler ABI info
   -- Detecting CXX compiler ABI info - done
   -- Detecting CXX compile features
   -- Detecting CXX compile features - done
   -- Configuring done
   -- Generating done
   -- Build files have been written to: /home/user/cmake-cookbook/chapter-01/recipe-02/cxx-exampl
   ```

2. 每个生成器会生成自己的特有的文件集

### 1.3 构建和链接静态库与动态库

1. 创建静态库，使用```add_library()```函数进行静态库创建

   ```cmake
   add_library(message
   	STATIC
   		Message.c
   		Message.h
   )
   ```

   其中第一个参数是静态库的名称，```STATIC```指明了是一个静态库

2. 使用静态库

   ```cmake
   add_executable(hello-world hello-world.c)
   
   # 在创建可执行文件后，将静态库链接到可执行目标
   target_link_libraries(hello-world message)
   ```

3. 生成的静态库默认是lib开头，后接自定义的静态库名称，生成库的后缀是```.a```。

4. 动态链接库通过将``STATIC``修改为``SHARED``，生成的库后缀为.dll

5. 其他CMake接受的生成对象

   ```
   STATIC：用于创建静态库，即编译文件的打包存档，以便在链接其他目标时使用，例如：可执行文件。
   SHARED：用于创建动态库，即可以动态链接，并在运行时加载的库。可以在CMakeLists.txt中使用add_library(message SHARED Message.hpp Message.cpp)从静态库切换到动态共享对象(DSO)。
   OBJECT：可将给定add_library的列表中的源码编译到目标文件，不将它们归档到静态库中，也不能将它们链接到共享对象中。如果需要一次性创建静态库和动态库，那么使用对象库尤其有用。我们将在本示例中演示。
   MODULE：又为DSO组。与SHARED库不同，它们不链接到项目中的任何目标，不过可以进行动态加载。该参数可以用于构建运行时插件。
   ```

6. ``OBJECT``的使用

   ```cmake
   cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
   project(recipe-03 LANGUAGES CXX)
   add_library(message-objs
       OBJECT
           Message.hpp
           Message.cpp
       )
   # 构建OBJECT目标时，需要保证编译的目标文件与生成位置无关
   # 通过设置POSITION_INDEPENDENT_CODE属性来实现
   set_target_properties(message-objs
       PROPERTIES
           POSITION_INDEPENDENT_CODE 1
       )
   add_library(message-shared
       SHARED
       	# 这是生成器表达式语法
           $<TARGET_OBJECTS:message-objs> 
       )
   add_library(message-static
       STATIC
           $<TARGET_OBJECTS:message-objs>
       )
   add_executable(hello-world hello-world.cpp)
   target_link_libraries(hello-world message-static)
   ```

### 1.4 使用条件句控制编译

1. 使用示例

   ```cmake
   cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
   project(recipe-04 LANGUAGES CXX)
   
   # 引入了一个新变量USE_LIBRARY，这是一个逻辑变量，值为OFF
   set(USE_LIBRARY OFF)
   # 打印了它的值
   message(STATUS "Compile sources into a library? ${USE_LIBRARY}")
   
   # CMake中定义BUILD_SHARED_LIBS全局变量，并设置为OFF
   set(BUILD_SHARED_LIBS OFF)
   
   # 引入变量_sources
   list(APPEND _sources Message.hpp Message.cpp)
   
   # 使用条件控制语句if(), else()和endif()
   if(USE_LIBRARY)
       # add_library第二个参数缺省的话，会寻找CMake中定义的BUILD_SHARED_LIBS变量值
       # 在上面将BUILD_SHARED_LIBS设置为了OFF，此时将会创建一个静态库
       add_library(message ${_sources})
       add_executable(hello-world hello-world.cpp)
       target_link_libraries(hello-world message)
   else()
       add_executable(hello-world hello-world.cpp ${_sources})
   endif()
   ```

2. CMake中的逻辑变量

   - `true`：如果将逻辑变量设置为以下任意一种：`1`、`ON`、`YES`、`true`、`Y`或非零数
   - `false`：如果将逻辑变量设置为以下任意一种：`0`、`OFF`、`NO`、`false`、`N`、`IGNORE、NOTFOUND`、空字符串，或者以`-NOTFOUND`为后缀

3. 

   ```cmake
   include(CMakeDependentOption)
   # second option depends on the value of the first
   cmake_dependent_option(
       MAKE_STATIC_LIBRARY "Compile sources into a static library" OFF
       "USE_LIBRARY" ON
       )
   # third option depends on the value of the first
   cmake_dependent_option(
       MAKE_SHARED_LIBRARY "Compile sources into a shared library" ON
       "USE_LIBRARY" ON
       )
   ```
   
   

