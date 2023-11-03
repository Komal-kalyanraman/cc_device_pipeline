set(APP_NAME cc_device_cv)                                     

add_library(${APP_NAME} STATIC   
	src/cc_device_adas_v1_handler.cpp
	src/cc_device_big_model_handler.cpp
	src/cc_device_adas_v2_handler.cpp
)                                         
