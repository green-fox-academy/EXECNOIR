#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>



cv::Mat img;
cv::Mat gray;
cv::Mat filter;
cv::Mat filter2;
cv::Mat erosion;
cv::Mat kernel;
cv::Point anchor;
double delta;
int ddepth;
int kernel_size;



int main() {
    img = cv::imread("../smug.jpg", cv::IMREAD_COLOR);




    cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Gray", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Filter", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Erosion", cv::WINDOW_AUTOSIZE);

    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY );
    cv::cvtColor(gray, gray, cv::COLOR_GRAY2BGR );
    cv::putText(gray, "u r faget", cv::Point(gray.cols/4, gray.rows/4), cv::FONT_HERSHEY_PLAIN, 2, cv::Scalar(0, 0, 255), 2, 8, false);
    cv::bilateralFilter(gray, filter, 10, 10, 10, cv::BORDER_DEFAULT );




    anchor = cv::Point( -1, -1 );
    delta = 0;
    ddepth = -1;

    int ind = 0;
    /*for(;;)
    {

        kernel_size = 3 + 2*( ind%5 );
        kernel = cv::Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size); //ezt miert es minek es hogyan

        filter2D(img, filter2, ddepth , kernel, anchor, delta, cv::BORDER_DEFAULT );
        imshow( "Filter2", filter2 );
        char c = (char)cv::waitKey(500);

        if( c == 27 )
        { break; }
        ind++;
    }*/

    kernel = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(11,11));
    cv::erode(gray, erosion, kernel, cv::Point(-1,-1), 1);


    cv::imshow("Original", img);
    cv::imshow("Gray", gray);
    cv::imshow("Filter", filter);
    cv::imshow("Erosion", erosion);
    cv::waitKey();
    return 0;
}

