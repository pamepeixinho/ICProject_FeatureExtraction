cmake_minimum_required(VERSION 2.4)
FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5OpenGL REQUIRED)
FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Sql REQUIRED)
FIND_PACKAGE(Qt5WebKitWidgets REQUIRED)
FIND_PACKAGE(VTK REQUIRED)
FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE(${VTK_USE_FILE})

#INCLUDE_DIRECTORIES(".")

FILE(GLOB_RECURSE Source_Files  *.cpp *.h)
#ADD_EXECUTABLE(AnaliseGrafo ${Source_Files})
ADD_LIBRARY(AnaliseGrafo ${Source_Files})
TARGET_LINK_LIBRARIES(AnaliseGrafo FeatureExtractors Utilities Qt5::Core Qt5::Widgets Qt5::OpenGL  ${OpenCV_LIBS}  ${VTK_LIBRARIES})

#Copy header files to root include dir - Analise Grafo
FILE(GLOB_RECURSE header_files ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
add_custom_command(
    TARGET AnaliseGrafo 
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INCLUDE_OUTPUT_DIRECTORY}/AnaliseGrafo  
    COMMAND cp -f ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_INCLUDE_OUTPUT_DIRECTORY}/AnaliseGrafo/
)