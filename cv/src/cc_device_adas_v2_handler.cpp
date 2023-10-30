// Code Specific Header File(s)
#include "inc/cc_device_adas_v2_handler.hpp"

using namespace std;

adasV2Handler* adasV2Handler::m_pInstance = NULL_PTR;

adasV2Handler* adasV2Handler::getInstance()
{
    if (NULL_PTR == m_pInstance) {
        m_pInstance = new adasV2Handler;
    }
    return m_pInstance;
}

bool adasV2Handler::adasV2_output()
{
    string output_path = IMG_PATH + time_stamp + ADAS_V2_IMG;
    
    detection["adas_v2"] = "{ adas v2 JSON response here }";
    return true;
}
