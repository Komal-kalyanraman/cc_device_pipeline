// Code Specific Header File(s)
#include "inc/cc_device_img_capture_handler.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <sstream>

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

string ImgCaptureHandler::getValue()
{
    char key = 'r';

    cv::VideoCapture camera(CAMERA_NO);

    cv::Mat src, gray, filename;

    camera.set(3,IMG_WIDTH);	//for setting o/p image resolution
    camera.set(4,IMG_HEIGT);

    camera >> src;

    while(1)
    {
    camera >> src;

    // Check if image is loaded fine
    if(src.empty()){
        printf(" Error opening image\n");
        printf(" Failed to open camera number: %d \n", CAMERA_NO);
        return "false";
    }

    cv::imshow("Detected circles", src);
    key=cv::waitKey(1);

    if(key == 'q')
    break;
    }

    string value = "true";

    return value;
}
