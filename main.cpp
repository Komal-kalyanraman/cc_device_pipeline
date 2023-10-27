#include "inc/sample_init_handler.hpp"

int main()
{
    bool sampleInitStatus = sampleInitHandler::getInstance()->sample_init();

    if (sampleInitStatus) {
        cout<< "Sample Init Handle is SUCCESSFUL"<<endl;

        /* Perform update for the remaining */
        if ("true" == ImgCaptureHandler::getInstance()->getValue()) {
            cout<<"Img Handle Initialization"<<endl;
        }
    }
    else {
        cout << "Sample init failed" << endl;
    }

    cout << "Sample exiting..." << endl;
    return 0;
}
