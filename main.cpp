#include "inc/cc_device_adas_v1_handler.hpp"
#include "inc/cc_device_big_model_handler.hpp"
#include "inc/cc_device_adas_v2_handler.hpp"
#include "inc/cc_device_img_capture_handler.hpp"
#include "inc/cc_device_data_aggregator_handler.hpp"
#include "inc/cc_device_convert_image_bytestream.hpp"

int main()
{
    bool imageCapture = ImgCaptureHandler::getInstance()->getImage();
    if(!imageCapture){
        cout << "ERROR: Failed to capture image" << endl;
        cout << "Exiting process" << endl << endl;
        return 0;
    }

    bool adasV1Success = adasV1Handler::getInstance()->adasV1_output();
    if(!adasV1Success){
        cout<< "ERROR: adas v1 model failed to process image"<< endl;
        cout << "Exiting process" << endl << endl;
        return 0;
    }

    bool bigModelSuccess = bigModelHandler::getInstance()->bigModel_output();
    if(!bigModelSuccess){
        cout<< "ERROR: big model failed to process image"<< endl;
        cout << "Exiting process" << endl << endl;
        return 0;
    }

    bool dataAggregatorSuccess = dataAggregatorHandler::getInstance()->dataAggregator_output();
    if(!dataAggregatorSuccess){
        cout<< "ERROR: Issue in aggregating data" << endl;
        cout << "Exiting process" << endl << endl;
        return 0;
    }

    string path = IMG_PATH + time_stamp + CAM_IMG;
    image_byteStream = ImageConverter::getInstance()->mat2str(path);
    // cout << image_byteStream << endl;

    return 0;
}
