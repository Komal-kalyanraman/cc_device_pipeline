#include "inc/sample_init_handler.hpp"

using namespace std;

sampleInitHandler* sampleInitHandler::m_pInstance = NULL_PTR;

sampleInitHandler* sampleInitHandler::getInstance()
{
    if (NULL_PTR == m_pInstance) {
        m_pInstance = new sampleInitHandler;
    }
    return m_pInstance;
}

bool sampleInitHandler::sample_init()
{
    cout << "InitHandler: Initing for CRM" << endl;
    return true;
}

