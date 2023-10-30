
#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include <map>

using namespace std;

const int CAMERA_NO = 0;
const int IMG_WIDTH = 640;
const int IMG_HEIGT = 480;

inline string time_stamp;

const string IMG_PATH = "../data/image/";

const string CAM_IMG       = " cam_img.jpg";
const string ADAS_V1_IMG   = " adas_v1_img.jpg";
const string BIG_MODEL_IMG = " big_model_img.jpg";
const string ADAS_V2_IMG   = " adas_v2_img.jpg";

inline map<string, string> detection;

#define NULL_PTR 0

#endif // End of _COMMON_H_
