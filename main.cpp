#include "inc/cc_device_adas_v1_handler.hpp"
#include "inc/cc_device_big_model_handler.hpp"
#include "inc/cc_device_adas_v2_handler.hpp"
#include "inc/cc_device_img_capture_handler.hpp"
#include "inc/cc_device_data_aggregator_handler.hpp"

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
    cout << detection["adas_v1"] << endl << endl;

    bool bigModelSuccess = bigModelHandler::getInstance()->bigModel_output();
    if(!bigModelSuccess){
        cout<< "ERROR: big model failed to process image"<< endl;
        cout << "Exiting process" << endl << endl;
        return 0;
    }
    cout << detection["big_model"] << endl << endl;

    bool adasV2Success = adasV2Handler::getInstance()->adasV2_output();
    if(!adasV2Success){
        cout<< "ERROR: adas v2 model failed to process image"<< endl;
        cout << "Exiting process" << endl << endl;
        return 0;
    }
    cout << detection["adas_v2"] << endl << endl;

    bool dataAggregatorSuccess = dataAggregatorHandler::getInstance()->dataAggregator_output();
    if(!dataAggregatorSuccess){
        cout<< "ERROR: Issue in aggregating data" << endl;
        cout << "Exiting process" << endl << endl;
        return 0;
    }
    
    return 0;
}
