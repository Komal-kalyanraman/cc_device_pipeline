set(APP_NAME sample_common)

add_library(${APP_NAME} STATIC
	src/sample_config_handler.cpp
	src/cc_device_img_capture_handler.cpp
)
