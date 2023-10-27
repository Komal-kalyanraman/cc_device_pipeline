// Code Specific Header File(s)
#include "inc/cc_device_img_capture_handler.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <sstream>
#include <iostream>

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
        cout<<"Failed to open camera number: "<< CAMERA_NO <<endl;
        return false;
    }

    // writing the image to a defined location as JPG
    bool check = imwrite(IMG_PATH, src);
  
    // if the image is not saved 
    if (check == false) { 
        cout << "Mission - Saving the image, FAILED" << endl; 
        return false; 
    } 
  
    cout << "Successfully saved the image. " << endl; 

    return true;
}
