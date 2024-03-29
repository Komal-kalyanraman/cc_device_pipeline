cmake_minimum_required(VERSION 3.10)
project(cc_device VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Warning flags
SET(WARNING_FLAG OFF)     # On for showing the warning
if(WARNING_FLAG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wformat-security")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsign-conversion")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wduplicated-cond")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfloat-equal")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wlogical-not-parentheses")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnull-dereference")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wdouble-promotion")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pie")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIE")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FORTIFY_SOURCE=2")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--exclude-libs,ALL")
endif()

find_package(OpenCV REQUIRED)
find_package(nlohmann_json 3.7.3 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories("${PROJECT_SOURCE_DIR}/bl")
include_directories("${PROJECT_SOURCE_DIR}/cv")
include_directories("${PROJECT_SOURCE_DIR}/common")

add_subdirectory(bl)
add_subdirectory(cv)
add_subdirectory(common)

####### GTests ########
SET(GTEST OFF)     # On for build the unitest, off for not
if(GTEST)
  add_subdirectory(unitTests/lib/googletest)
  add_subdirectory(unitTests)
endif()

add_executable(CC_DEVICE
  main.cpp
)

target_link_libraries(CC_DEVICE
  ${OpenCV_LIBS}
  cc_device_bl
  cc_device_cv
  cc_device_common
)

# Set the path to the directory where all project artifacts should be installed, based on config option from cmake
if(NOT DEFINED VAL_INSTALL_DIR)
	set(VAL_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/cc_device)
endif()

add_compile_definitions(VAL_INSTALL_DIR="${VAL_INSTALL_DIR}")

# Install targets
install(TARGETS CC_DEVICE
  RUNTIME DESTINATION ${VAL_INSTALL_DIR}
)
