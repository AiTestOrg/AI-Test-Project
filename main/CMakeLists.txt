cmake_minimum_required(VERSION 3.10.2)
find_package(OpenCV REQUIRED)
#message( ${OpenCV_LIBS})

include_directories(../util/include)

ADD_LIBRARY(LibsModule 
    ../util/src/feature_extractor/feature_extractor.cpp
)

add_executable(app_demo src/app_demo/app_demo.cpp )
target_link_libraries( LibsModule ${OpenCV_LIBS} )
target_link_libraries(app_demo LibsModule)


