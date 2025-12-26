### TITLE ###
cmake_minimum_required(VERSION 3.20)
PROJECT(Circle_Radius C)



### Adding Source and Include Dir's
add_library(circle circle_dir/src/circle.c)
target_include_directories(circle PUBLIC 
        circle_dir/Include
        C:/SDL3/include)


### Creating executable and generating linking operation.
add_executable(app main.c)
target_link_libraries(app PRIVATE circle C:/SDL3/lib/libSDL3.dll.a)



### cmake -S . -B build -G Ninja     
### cmake --build build
