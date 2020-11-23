cmake_minimum_required(VERSION 3.10.2)
find_package(OpenCV REQUIRED)

add_executable(object_detector object_detector/object_detector.cpp)
add_executable(feature_extractor feature_extractor/feature_extractor.cpp)
add_executable(feature_classifier feature_classifier/feature_classifier.cpp)



