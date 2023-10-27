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

string adasV2Handler::adasV2_output()
{
    cout << "Output from adas v2 model" << endl;
    return "{ adas v2 JSON response here }";
}
