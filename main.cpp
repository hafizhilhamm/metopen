#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <chrono>
#include <thread>

int main() {
// std::string path("/home/hafizh/Documents/kucingputih.jpg");
// std::string path("/home/hafizh/Documents/kucingoyen.jpsg");
std::string path("/home/hafizh/Documents/kucing.jpeg");
cv::Mat img= cv::imread(path);
   
cv::Mat hsv;
cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);
//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

cv::Scalar lower_orange(13, 110 , 249 );
cv::Scalar upper_orange(255 , 255 , 255);
    
// cv::inRange(hsv, lower_orange, upper_orange, thresh);
cv::Mat orange;
cv::inRange(hsv, lower_orange, upper_orange, orange);

std::vector<std::vector<cv::Point>> contours_orange;
std::vector<cv::Vec4i> hierarchy_orange;

    cv::findContours(orange, contours_orange, hierarchy_orange, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        double maxArea_orange = 0;
        size_t maxAreaIdx_orange = 0;

        for (size_t i = 0; i < contours_orange.size(); i++) {
            double area_orange = cv::contourArea(contours_orange[i]);
            if (area_orange > maxArea_orange) {
                maxArea_orange = area_orange;
                maxAreaIdx_orange = i;
            }
                cv::Rect boundingRect_orange = cv::boundingRect(contours_orange[maxAreaIdx_orange]);
                cv::rectangle(img, boundingRect_orange, cv::Scalar(0, 0, 0), 10);
                cv::putText(img, "orange cat", cv::Point(boundingRect_orange.x, boundingRect_orange.y), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 0, 0), 5);
            

cv::Scalar lower_white(25 , 0 , 215);
cv::Scalar upper_white(88 , 59 , 255);
    
// cv::inRange(hsv, lower_orange, upper_orange, thresh);
cv::Mat white;
cv::inRange(hsv, lower_white, upper_white, white);

std::vector<std::vector<cv::Point>> contours_white;
std::vector<cv::Vec4i> hierarchy_white;

cv::findContours(white, contours_white, hierarchy_white, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        double maxArea_white = 0;
        size_t maxAreaIdx_white = 0;

        for (size_t i = 0; i < contours_white.size(); i++) {
            double area_white = cv::contourArea(contours_white[i]);
            if (area_white > maxArea_white) {
                maxArea_white = area_white;
                maxAreaIdx_white = i;
            }
            if (area_white > 200 && contours_white.size() > 0) {
                cv::Rect boundingRect_white = cv::boundingRect(contours_white[maxAreaIdx_white]);
                // cv::rectangle(img, boundingRect_white, cv::Scalar(0, 0, 0), 2);
                cv::putText(img, "white cat", cv::Point(boundingRect_white.x, boundingRect_white.y), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0,0,0), 5);
            }
        }
    
cv::Scalar lower_brown(9 , 65 , 215);
cv::Scalar upper_brown(37 , 96 , 235);

// cv::inRange(hsv, lower_orange, upper_orange, thresh);
cv::Mat brown;
cv::inRange(hsv, lower_brown, upper_brown, brown);

std::vector<std::vector<cv::Point>> contours_brown;
std::vector<cv::Vec4i> hierarchy_brown;

cv::findContours(brown, contours_brown, hierarchy_brown, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    double maxArea_brown = 0;
    size_t maxAreaIdx_brown = 0;

    for (size_t i = 0; i < contours_brown.size(); i++) {
        double area_brown = cv::contourArea(contours_brown[i]);
        if (area_brown > maxArea_brown) {
            maxArea_brown = area_brown;
            maxAreaIdx_brown = i;
        }
        if (area_brown > 180 && contours_brown.size() > 0) {
            cv::Rect boundingRect_brown = cv::boundingRect(contours_brown[maxAreaIdx_brown]);
            // cv::rectangle(img, boundingRect_brown, cv::Scalar(0, 0, 0), 2);
            cv::putText(img, "brown cat", cv::Point(boundingRect_brown.x, boundingRect_brown.y), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0,0,0), 5);
        }
    }

cv::Scalar lower_grey(10 , 35 , 37);
cv::Scalar upper_grey(24 , 84 , 224);

// cv::inRange(hsv, lower_orange, upper_orange, thresh);
cv::Mat grey;
cv::inRange(hsv, lower_grey, upper_grey, grey);

std::vector<std::vector<cv::Point>> contours_grey;
std::vector<cv::Vec4i> hierarchy_grey;

cv::findContours(grey, contours_grey, hierarchy_grey, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    double maxArea_grey = 0;
    size_t maxAreaIdx_grey = 0;

    for (size_t i = 0; i < contours_grey.size(); i++) {
        double area_grey = cv::contourArea(contours_grey[i]);
        if (area_grey > maxArea_grey) {
            maxArea_grey = area_grey;
            maxAreaIdx_grey = i;
        }
        if (area_grey > 2000 && contours_grey.size() > 0) {
            cv::Rect boundingRect_grey = cv::boundingRect(contours_grey[maxAreaIdx_grey]);
            // cv::rectangle(img, boundingRect_grey, cv::Scalar(0, 0, 0), 2);
            cv::putText(img, "grey cat", cv::Point(boundingRect_grey.x, boundingRect_grey.y), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0,0,0), 5);
        }
    }

    cv::imshow("img",img);
    cv::imshow("orange",orange);
    cv::imshow("white",grey);
    cv::waitKey(0);
    
}
    }   

