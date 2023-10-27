#include "inc/cc_device_adas_v1_handler.hpp"
#include "inc/cc_device_img_capture_handler.hpp"

int main()
{
    bool imageCapture = ImgCaptureHandler::getInstance()->getImage();

    if(!imageCapture){
        cout << "ERROR: Failed to capture image" << endl;
        cout << "Exiting process" << endl;
        return 0;
    }

    string adasV1Response = adasV1Handler::getInstance()->adasV1_output();
    cout<< adasV1Response <<endl;

    return 0;
}
