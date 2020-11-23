cmake_minimum_required(VERSION 3.10.2)
find_package(OpenCV REQUIRED)

project (feature_extractor)
add_executable(feature_extractor feature_extractor/feature_extractor.cpp)
target_link_libraries(feature_extractor ${OpenCV_LIBS})

project (object_detector)
add_executable(object_detector object_detector/object_detector.cpp)
target_link_libraries(object_detector ${OpenCV_LIBS})

