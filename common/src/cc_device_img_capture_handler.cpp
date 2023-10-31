// Code Specific Header File(s)
#include "inc/cc_device_img_capture_handler.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "cc_device_convert_image.cpp"

// https://stackoverflow.com/questions/29772271/c-opencv-convert-mat-to-base64-and-vice-versa

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

    string output_path = IMG_PATH + time_stamp + CAM_IMG;

    // writing the image to a defined location as JPG
    bool check = imwrite(output_path, src);

    ImagemConverter ic;

    string op = ic.mat2str(src);

    cout << op << endl;

    cv::Mat out = ic.str2mat(op);

    string decoded_path = IMG_PATH + time_stamp + ADAS_V1_IMG;

    bool done = imwrite(decoded_path, out);

    // std::vector<uchar> buf;
    // cv::Mat img = cv::imread("/home/komal/workspace/cc_device_pipeline/1.jpg");
    // cv::imencode(".jpg", img, buf);
    // auto *enc_msg = reinterpret_cast<unsigned char*>(buf.data());
    // std::string encoded = ImagemConverter::base64_encode(enc_msg, buf.size());

    // string dec_jpg =  base64_decode(encoded);
    // std::vector<uchar> data(dec_jpg.begin(), dec_jpg.end());
    // cv::Mat img2 = cv::imdecode(cv::Mat(data), 1);
  
    // if the image is not saved 
    if (check == false) { 
        cout << "Mission - Saving the image, FAILED" << endl << endl; 
        return false; 
    } 
  
    cout << "Successfully saved the image. " << endl << endl;

    return true;
}
