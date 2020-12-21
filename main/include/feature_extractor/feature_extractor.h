#include <iostream>
#include "opencv2/core.hpp"
//#ifdef HAVE_OPENCV_XFEATURES2D
#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"


class feature_extractor
{
    int _feature_type = 0;                   // 0 is FAST, 1 is ORB, 2 is SURF, 3 is SIFT
    int _max_features = 400;

    public:
        feature_extractor(int feature_type, int  max_features);


};