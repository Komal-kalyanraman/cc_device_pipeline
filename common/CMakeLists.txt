set(APP_NAME cc_device_common)

add_library(${APP_NAME} STATIC
	src/cc_device_img_capture_handler.cpp
	src/cc_device_convert_image_bytestream.cpp
)
