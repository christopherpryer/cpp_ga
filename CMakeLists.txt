cmake_minimum_required(VERSION 3.4)
project(test-project
	VERSION 0.0.0
	LANGUAGES
		CXX
)
file(GLOB SOURCES "./src/*.cpp")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
add_executable(test ${SOURCES})