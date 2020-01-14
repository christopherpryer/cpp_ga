cmake_minimum_required(VERSION 3.4)
project(test-project
	VERSION 0.0.0
	LANGUAGES
		CXX
)
file(GLOB SOURCES "../src/*.cpp")
add_executable(test ${SOURCES})