#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

const int alpha_slider_max = 100;
const int alpha_slider_max2 = 100;
int alpha_slider;
int alpha_slider2;
int beta_slider;
const int beta_slider_max = 100;
double alpha;
double alpha2;
double beta;
double beta2;
cv::Mat image;
cv::Mat image2;
cv::Mat image3;
cv::Mat WillItBlend;
cv::Mat bright_image = cv::Mat::zeros (image3.size(), image3.type());

static void on_trackbar(int, void*)
{
    alpha = (double)alpha_slider/alpha_slider_max;
    beta = (1.0 - alpha);
    cv::addWeighted(image, alpha, image2, beta, 0.0, WillItBlend );
    cv::imshow("smug blend", WillItBlend);
}

static void on_trackbar2(int, void*)
{
    alpha2 = (double)alpha_slider2/alpha_slider_max2*3;
    WillItBlend.convertTo(bright_image, -1, alpha2, beta2);
    cv::imshow("smug blend", bright_image);
}

static void on_trackbar3(int, void*)
{
    beta2 = (double)beta_slider/beta_slider_max*100;
    WillItBlend.convertTo(bright_image, -1, alpha2, beta2);
    cv::imshow("smug blend", bright_image);
}



int main()
{

    image = imread("../smug.jpg", cv::IMREAD_COLOR);
    image2 = imread("../smug2.jpg", cv::IMREAD_COLOR);
    image3 = imread("../bright.jpg", cv::IMREAD_COLOR);
    if( image.empty() )
    {
        std::cout << "nem nyilik a szar" << std::endl ;
        return -1;
    }
    if(image2.empty())
    {
        std::cout << "nem nyilik a masik szar" << std::endl;
        return -1;
    }
    if(image3.empty())
    {
        std::cout << "a harmadik szar nem nyilik" << std::endl;
        return -1;
    }



    alpha_slider = 0;
    alpha_slider2 = 0;
    beta_slider = 0;



    alpha2 = 1.0;
    beta2 = 0;

    cv::namedWindow( "smug blend", cv::WINDOW_AUTOSIZE);
    //cv::namedWindow( "brightness", cv::WINDOW_AUTOSIZE);
    char TrackbarName[50];
    char TrackbarName2[50];
    char TrackbarName3[50];
    sprintf(TrackbarName, "Alpha x %d", alpha_slider_max);
    sprintf(TrackbarName2, "Brightness %d", alpha_slider_max2);
    sprintf(TrackbarName3, "Contrast %d", beta_slider_max);
    cv::createTrackbar(TrackbarName, "smug blend", &alpha_slider, alpha_slider_max, on_trackbar);
    cv::createTrackbar(TrackbarName2, "smug blend", &alpha_slider2, alpha_slider_max2, on_trackbar2);
    cv::createTrackbar(TrackbarName3, "smug blend", &beta_slider, beta_slider_max, on_trackbar3);

    cv::waitKey(0);
    return 0;
}