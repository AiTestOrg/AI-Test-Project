cmake_minimum_required(VERSION 3.10.2)
find_package(OpenCV REQUIRED)

project (object_detector)
add_executable(object_detector object_detector/object_detector.cpp)

project (feature_extractor)
add_executable(feature_extractor feature_extractor/feature_extractor.cpp)

project (feature_classifier)
add_executable(feature_classifier feature_classifier/feature_classifier.cpp)



