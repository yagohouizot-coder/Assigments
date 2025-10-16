cmake_minimum_required(VERSION 3.10)
project(ecs-demo VERSION 1.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED True
	COMPILE_WARNING_AS_ERROR True
	EXPORT_COMPILE_COMMANDS True
)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
