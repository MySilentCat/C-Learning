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