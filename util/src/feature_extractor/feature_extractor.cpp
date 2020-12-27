#include "feature_extractor.h"
#include "opencv2/core.hpp"
//#ifdef HAVE_OPENCV_XFEATURES2D
#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"



feature_extractor::feature_extractor(int feature_type, int max_features):_feature_type(feature_type),_max_features(max_features){
  // 0 is FAST, 1 is ORB, 2 is SURF, 3 is SIFT, 4 is Superpoint
  switch(feature_type) {
      case FAST :
        {
        std::cout << "FAST Feature Type selected" << std::endl;
        cv::Ptr<cv::FastFeatureDetector> detector = cv::FastFeatureDetector::create(max_features); 

        }
        break;
      case ORB :
        {
        std::cout << "ORB Feature Type selected" << std::endl;
        cv::Ptr<cv::ORB> detector = cv::ORB::create(max_features);
        }
        break;
      case SURF :
        {
        std::cout << "SURF Feature Type selected" << std::endl;
        cv::Ptr<cv::Feature2D> detector = cv::xfeatures2d::SURF::create(max_features);
        }
        break;
      case SIFT :
        {
        std::cout << "SIFT Feature Type selected" << std::endl;
        cv::Ptr<cv::Feature2D> detector = cv::SIFT::create();
        }
        break;
      case SUPERPOINT :
        {
        std::cout << "Superpoint Feature Type selected" << std::endl;
        }
        break;  
      
      //default :
      //   std::cout << "Invalid grade" << std::endl;
   }
  
}
