#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
string filename = "/home/simon/dashboad.jpg";

Mat img;
Point prevPt(-1, -1);

void onMouse( int event, int x, int y, int flags, void* ) {
    std::cout << "x: "<< x << " y: "<< y<< endl;
}

cv::Rect getSafeRect(cv::Rect rect) {
   int x = rect.x;
   int y = rect.y;
   if(x < 0) {
       x = 0;
   }
   if(y < 0) {
       y = 0;
   }
   return cv::Rect(x, y, rect.width, rect.height);
}

bool verifyDashboardSize(cv::RotatedRect mr) {
      float error = 0.99f;

      // Real dashboard size: 402.0 * 399, aspect 1.00751
      float aspect = 1.00751;

      // Get only patchs that match to a respect ratio.
      float rmin = aspect - aspect * error;
      float rmax = aspect + aspect * error;

      float r = (float) mr.size.width / (float) mr.size.height;
      if (r < 1) r = (float) mr.size.height / (float) mr.size.width;

      cout<< "Width: " << mr.size.width << " Height: " << mr.size.height << endl;
      if (r < rmin || r > rmax || mr.size.width == 719)
        return false;
      else
        return true;
}

void colorFilter(cv::Mat &image) {
    int nl = image.rows;
    int nc = image.cols * image.channels();

    if(image.isContinuous()) {
        nc = nc * nl;
        nl = 1;
    }
    for(int j = 0; j < nl; j++) {
        uchar* data = image.ptr<uchar>(j);
        for(int i = 0; i < nc; i++) {
           data[i] = data[i] * data[i]/255 * 255;
        }
    }
}


int main()
{
    /*
     *                  仪表盘定位
     */
    Mat image = imread(filename, cv::IMREAD_COLOR);
    if( image.empty() )
    {
        cout << "\n Durn, couldn't read image filename " << filename << endl;
        return 1;
    }
    cv::resize(image, image, cv::Size(image.cols/2, image.rows/2));
    imshow("original", image);

    cv::Mat img_blur;
    cv::GaussianBlur(image, img_blur, Size(3, 3), 0, 0, BORDER_DEFAULT);

//    Mat imageEnhance;
//    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, 0, 5, 0, 0, -1, 0);
//    cv::filter2D(image, imageEnhance, CV_8UC3, kernel);
//    imshow("imageEnhance", imageEnhance);

    cv::Mat img_gray;
    cv::cvtColor(img_blur, img_gray, cv::COLOR_BGR2GRAY);
    imshow("gray", img_gray);

//    cv::Mat img_sobel;
//    cv::Sobel(img_gray, img_sobel, CV_16S, 1, 0);
//    imshow("sobel", img_gray);

    cv::Mat img_threshold;
    threshold(img_gray, img_threshold, 0, 255, cv::THRESH_OTSU+cv::THRESH_BINARY);
    imshow("threshold", img_threshold);


    cv::Mat closed;
    cv::Mat element5(9, 9, CV_8U, cv::Scalar(1));
//    cv::morphologyEx(img_threshold, closed, cv::MORPH_CROSS, element5);
    cv::erode(img_threshold, closed, element5);
    cv::dilate(closed, closed, element5);
    cv::dilate(closed, closed, element5);
    cv::dilate(closed, closed, element5);
    cv::dilate(closed, closed, element5);
    cv::dilate(closed, closed, element5);
    cv::dilate(closed, closed, element5);
    imshow("closed", closed);

    cv::Mat dashboard;
    namedWindow( "dashboard", 1 );
    cv::Mat rectangle = image.clone();
    vector< vector< Point> > contours;
    findContours(closed,
             contours, // a vector of contours
             cv::RETR_CCOMP,
             cv::CHAIN_APPROX_SIMPLE); // all pixels of each contours

    for( size_t i = 0; i < contours.size(); i++ ) {
        RotatedRect mr = minAreaRect(contours[i]);
        if (verifyDashboardSize(mr)) {
            dashboard = image(getSafeRect(mr.boundingRect()));
        }
        cv::rectangle(rectangle, getSafeRect(mr.boundingRect()), cv::Scalar(0, 255 ,0), 3);
    }
    cv::resize(dashboard, dashboard, cv::Size(300, 300));
    dashboard.copyTo(img);
    imshow("dashboard", dashboard);
    setMouseCallback("dashboard", onMouse, 0 );
    imshow("rectangle", rectangle);

    waitKey(0);

    /*
     *                  读数分割
     */
    cv::Mat value1 = dashboard(cv::Rect(28, 26, 109, 35));
    imshow("value1", value1);
    cv::Mat unit1 = dashboard(cv::Rect(28, 70, 86, 12));
    imshow("unit1", unit1);

    cv::Mat value2 = dashboard(cv::Rect(28, 97, 253, 35));
    if(!img.empty()) {
       img.release();
    }
    colorFilter(value2);
    cv::Mat value2_threshold;
    cv::cvtColor(value2, value2_threshold, cv::COLOR_RGB2GRAY);
    threshold(value2_threshold, value2_threshold, 0, 255, cv::THRESH_OTSU+cv::THRESH_BINARY);
    imshow("value2", value2_threshold);
    int char_h = 35;
    int char_w = 28;
    int value2_w = value2_threshold.cols;
    for(int i = 0; i <= value2_w - char_w; i+=char_w) {
        imshow("value2_char", value2_threshold(cv::Rect(i, 0, char_w, char_h)));
        cv::waitKey();
    }
    cv::Mat unit2 = dashboard(cv::Rect(175, 145, 110, 12));
    colorReduce(unit2);
    cv::Mat unit2_threshold;
    cv::cvtColor(unit2, unit2_threshold, cv::COLOR_RGB2GRAY);
    threshold(unit2_threshold, unit2_threshold, 0, 255, cv::THRESH_OTSU+cv::THRESH_BINARY);
    imshow("unit2", unit2_threshold);

    return 0;
}
