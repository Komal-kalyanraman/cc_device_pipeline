// Code Specific Header File(s)
#include "inc/cc_device_big_model_handler.hpp"

using namespace std;

bigModelHandler* bigModelHandler::m_pInstance = NULL_PTR;

bigModelHandler* bigModelHandler::getInstance()
{
    if (NULL_PTR == m_pInstance) {
        m_pInstance = new bigModelHandler;
    }
    return m_pInstance;
}

bool bigModelHandler::bigModel_output()
{
    string output_path = IMG_PATH + time_stamp + BIG_MODEL_IMG;
    
    detection["big_model"] = "{ Big model JSON response here }";
    return true;
}
