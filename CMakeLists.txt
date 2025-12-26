### TITLE ###
cmake_minimum_required(VERSION 3.20)
PROJECT(Circle_Radius C)



### Adding Source and Include Dir's
add_library(circle circle_dir/src/circle.c)
target_include_directories(circle PUBLIC 
        circle_dir/Include)
target_include_directories(circle PUBLIC
    circle_dir/Include
    thread_struct
)

find_package(SDL3 REQUIRED)



### Creating executable and generating linking operation.
add_executable(app main.c)
target_link_libraries(app PRIVATE circle SDL3::SDL3)
target_link_libraries(circle PUBLIC m)



### cmake -S . -B build -G Ninja     
### cmake --build build
