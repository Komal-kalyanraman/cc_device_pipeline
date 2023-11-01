// Code Specific Header File(s)
#include "inc/cc_device_img_capture_handler.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "cc_device_convert_image_bytestream.cpp"

// https://github.com/RonnyldoSilva/OpenCV_Mat_to_Base64

using namespace std;

ImgCaptureHandler* ImgCaptureHandler::m_pInstance = NULL_PTR;

ImgCaptureHandler::ImgCaptureHandler()
{

}

ImgCaptureHandler::~ImgCaptureHandler()
{

}

ImgCaptureHandler* ImgCaptureHandler::getInstance()
{
    if (NULL_PTR == m_pInstance) {
        m_pInstance = new ImgCaptureHandler;
    }
    return m_pInstance;
}

bool ImgCaptureHandler::getImage()
{
    cv::VideoCapture camera(CAMERA_NO);

    cv::Mat src;

    camera.set(3,IMG_WIDTH);	// For setting o/p image resolution
    camera.set(4,IMG_HEIGT);

    camera >> src;

    if(src.empty()){
        cout<<"Failed to open camera number: "<< CAMERA_NO << endl << endl;
        return false;
    }

    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    
    std::stringstream datetime;
    datetime << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");

    time_stamp = datetime.str();
    std::replace(time_stamp.begin(), time_stamp.end(), ' ', '|');
    time_stamp = "[" + time_stamp + "]";

    string output_path = IMG_PATH + time_stamp + CAM_IMG;

    // writing the image to a defined location as JPG
    bool check = imwrite(output_path, src);

    if (check == false) { 
        cout << "Mission - Saving the image, FAILED" << endl << endl; 
        return false; 
    } 
  
    cout << "Successfully saved the image. " << endl << endl;

    return true;
}
