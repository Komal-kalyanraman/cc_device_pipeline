#include "inc/sample_init_handler.hpp"
#include "inc/cc_device_img_capture_handler.hpp"

int main()
{
    bool sampleInitStatus = sampleInitHandler::getInstance()->sample_init();

    if (sampleInitStatus) {
        cout<< "Sample Init Handle is SUCCESSFUL"<<endl;

        /* Perform update for the remaining */
        if (ImgCaptureHandler::getInstance()->getImage()) {
            cout<<"Img Handle Initialization"<<endl;
        }
    }
    else {
        cout << "Sample init failed" << endl;
    }

    cout << "Sample exiting..." << endl;
    return 0;
}
