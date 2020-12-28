#include "feature_extractor/feature_extractor.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"




int main(){

  std::string image_path = cv::samples::findFile("../../data/test_img1.jpeg");
  cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);        
  cv::Mat img_kp;
  std::vector<cv::KeyPoint> keypoints_1, keypoints_2;
  feature_extractor feat_ext(img, 2, 400, keypoints_1);
  cv::drawKeypoints(img,keypoints_1,img_kp);
  cv::imshow("Fast Keypoints", img_kp);
  cv::waitKey(0);
  return 0;
}


