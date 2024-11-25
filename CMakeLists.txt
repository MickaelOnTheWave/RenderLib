cmake_minimum_required(VERSION 3.20)

cmake_policy(SET CMP0040 NEW)
cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

project(RenderLib)

include_directories(src/)

###
### Options
###
# Unsed previous parameters from cache for the sake of dynamism
unset(KITGL_SUPPORT_GLFW CACHE)
unset(KITGL_SUPPORT_GLAD CACHE)

# Enable desired libs
option(KITGL_SUPPORT_GLFW "Set ON/OFF to enable/disable GLFW support." ON)
option(KITGL_SUPPORT_GLAD "Set ON/OFF to enable/disable GLAD support." ON)


###
### Initialization
###
# Project parameters
set(PROJ_LINK_LIBS)
set(PROJ_SRC)

# Add all files/folders under src folder automatically to the project
file(GLOB_RECURSE PROJ_SRC src/*.h src/*.cpp)
file(GLOB_RECURSE PROJ_SRC_OBJS src/objects/*.h src/objects/*.cpp)
file(GLOB_RECURSE PROJ_SRC_CAMS src/cameras/*.h src/cameras/*.cpp)
file(GLOB_RECURSE PROJ_SRC_MATH src/math/*.h src/MATH/*.cpp)
file(GLOB_RECURSE PROJ_SHADERS src/shaders/*)


###
### Compiler settings
###
add_definitions(
    -fPIC -fcommon
    )


###
### GLFW
###
if(KITGL_SUPPORT_GLFW)
    # Disable internal builds
    unset(GLFW_BUILD_EXAMPLES CACHE)
    unset(GLFW_BUILD_TESTS CACHE)
    unset(GLFW_BUILD_DOCS CACHE)
    option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
    option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
    option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
    add_subdirectory(libs/glfw)
    include_directories(libs/glfw/include)
    include_directories(libs/glfw/deps)
    list(APPEND PROJ_LINK_LIBS glfw)
endif(KITGL_SUPPORT_GLFW)


###
### GLAD
###
if(KITGL_SUPPORT_GLAD)
    include_directories(libs/glfw/deps)
    list(APPEND PROJ_SRC
        libs/glfw/deps/glad_gl.c
        )
endif(KITGL_SUPPORT_GLAD)



###
### Generating the project files
###
add_library(${PROJECT_NAME} ${PROJ_SRC} ${PROJ_SRC_OBJS} ${PROJ_SRC_CAMS} ${PROJ_SRC_MATH} ${PROJ_SHADERS})

target_include_directories(RenderLib PUBLIC src/ libs/glfw/deps)


###
### Linking to the project
###
target_link_libraries(${PROJECT_NAME} ${PROJ_LINK_LIBS})

file(GLOB shaderFiles "${CMAKE_CURRENT_SOURCE_DIR}/src/shaders/*")
file(COPY ${shaderFiles} DESTINATION "${CMAKE_BINARY_DIR}/data")
