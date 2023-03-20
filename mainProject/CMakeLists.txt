
#include_directories(${PROJECT_SOURCE_DIR}/mainProject/include)

add_library(${PROJECT_NAME} src/TemperatureController.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)