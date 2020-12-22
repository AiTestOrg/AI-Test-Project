cmake_minimum_required(VERSION 3.10.2)
find_package(OpenCV REQUIRED)

include_directories(include)



add_executable(object_detector src/object_detector/object_detector.cpp)
add_executable(feature_extractor src/feature_extractor/feature_extractor.cpp)
add_executable(feature_classifier src/feature_classifier/feature_classifier.cpp)

target_link_libraries( feature_extractor ${OpenCV_LIBS} )



