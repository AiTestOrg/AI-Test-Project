#include "feature_extractor/feature_extractor.h"
#include "opencv2/core.hpp"
//#ifdef HAVE_OPENCV_XFEATURES2D
#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"












feature_extractor::feature_extractor(cv::Mat& img, int feature_type, int max_features, std::vector<cv::KeyPoint>& kpts):_feature_type(feature_type),_max_features(max_features){
  // 0 is FAST, 1 is ORB, 2 is SURF, 3 is SIFT, 4 is Superpoint
  switch(feature_type) {
      case 0 :
        {
        std::cout << "FAST Feature Type selected" << std::endl;
        cv::Ptr<cv::FastFeatureDetector> detector = cv::FastFeatureDetector::create(_fast_threshold, true); 
        detector->detect(img, kpts);
        std::cout<<"Number of keypoints detected = "<<kpts.size()<<std::endl;
        }
        break;
      case 1 :
        {
        std::cout << "ORB Feature Type selected" << std::endl;
        cv::Ptr<cv::ORB> detector = cv::ORB::create(max_features);
        detector->detect(img, kpts);
        }
        break;
      case 2 :
        {
        std::cout << "SURF Feature Type selected" << std::endl;
        cv::Ptr<cv::Feature2D> detector = cv::xfeatures2d::SURF::create(_surf_hess_threshold);
        detector->detect( img, kpts );
        std::cout<<"Number of keypoints detected = "<<kpts.size()<<std::endl;
        }
        break;
      case 3 :
        {
        std::cout << "SIFT Feature Type selected" << std::endl;
        cv::Ptr<cv::Feature2D> detector = cv::SIFT::create();
        detector->detectAndCompute(img, cv::Mat(), kpts, cv::Mat());
        }
        break;
      case 4 :
        {
        std::cout << "Superpoint Feature Type selected" << std::endl;
        }
        break;  
      
      //default :
      //   std::cout << "Invalid grade" << std::endl;
   }
  
}