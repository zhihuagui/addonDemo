cmake_minimum_required(VERSION 3.20.0)

project(myAddon)

#set(PROJECT_NAME myAddon)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-D_GLIBCXX_USE_CXX11_ABI=0")

FILE(GLOB_RECURSE SOURCE_FILES "./src/*.cpp") 
FILE(GLOB_RECURSE HEADER_FILES "./src/*.h") 

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${CMAKE_JS_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE  
    ${CMAKE_SOURCE_DIR}/node_modules/node-addon-api 
    ${CMAKE_SOURCE_DIR}/node_modules/node-addon-api/src
    ${CMAKE_JS_INC})

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_JS_LIB})

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

