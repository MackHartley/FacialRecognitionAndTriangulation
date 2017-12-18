cmake_minimum_required(VERSION 3.8)
project(FaceRecC)


if (DLIB_NO_GUI_SUPPORT)
   message("No GUI support, s won't build the demo.")
else()
   find_package(OpenCV QUIET)
   if (OpenCV_FOUND)
      include_directories(${OpenCV_INCLUDE_DIRS})
      include_directories("/usr/local/Cellar/cgal")


      set(SOURCE_FILES main.cpp)
      add_executable(FaceRecC ${SOURCE_FILES})


      target_link_libraries(FaceRecC dlib::dlib ${OpenCV_LIBS} )
   else()
      message("OpenCV not found, so won't build the demo.")
   endif()
endif()

add_subdirectory(dlib dlib_build)




set(CMAKE_CXX_STANDARD 11)










#OLD:
#target_link_libraries(FaceRecC dlib::dlib)