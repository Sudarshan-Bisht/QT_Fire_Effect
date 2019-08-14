cmake_minimum_required(VERSION 3.15.2)

project(Fire_Demo)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(OpenCV_DIR "C:\\opencv\\build")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set (CMAKE_PREFIX_PATH "C:\\Qt\\5.12.4\\msvc2017_64\\lib\\cmake\\Qt5")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(project_ui
	mainwindow.ui)

set(project_headers
	mainwindow.h
	color.h
	intensity.h
	openCV.h)

set(project_sources 
	main.cpp
	mainwindow.cpp
	color.cpp
	intensity.cpp
	openCV.cpp)

qt5_wrap_ui(project_headers_wrapper ${project_ui})

qt5_wrap_cpp(project_sources_moc ${project_headers})

add_executable(${PROJECT_NAME} main.cpp ${project_sources} ${project_headers} ${project_headers_wrapper} ${project_sources_moc} )

target_link_libraries(${PROJECT_NAME}
	PUBLIC
	Qt5::Core
	Qt5::Gui
	Qt5::Widgets
	${OpenCV_LIBS})
