// Code Specific Header File(s)
#include "inc/cc_device_adas_v1_handler.hpp"

using namespace std;

adasV1Handler* adasV1Handler::m_pInstance = NULL_PTR;

adasV1Handler* adasV1Handler::getInstance()
{
    if (NULL_PTR == m_pInstance) {
        m_pInstance = new adasV1Handler;
    }
    return m_pInstance;
}

string adasV1Handler::adasV1_output()
{
    cout << "Output from adas v1 model" << endl;
    return "{adas v1 JSON response here}";
}
