set(APP_NAME sample_threadHandler)

add_library(${APP_NAME} STATIC
	src/sample_threadHandler.cpp
)

target_link_libraries(${APP_NAME} sample_common)