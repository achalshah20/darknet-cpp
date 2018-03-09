cmake_minimum_required(VERSION 3.9)

project(darknet_cpp)

file(GLOB YOLO_SOURCE_FILES src/*.cpp)
file(GLOB CUDA_SOURCE_FILES src/*.cu)
file(GLOB DARKNET_INCS include/*.h)

set(PROJECT_SRCS
${YOLO_SOURCE_FILES}
${CUDA_SOURCE_FILES}
)

set(PROJECT_INCS
${DARKNET_INCS}
)

find_package( OpenCV REQUIRED )
find_package( CUDA REQUIRED )

add_library(${PROJECT_NAME} SHARED ${PROJECT_SRCS} ${PROJECT_INCS})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

target_include_directories(${PROJECT_NAME} PUBLIC
                          $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                          $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>)

target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC
                          ${OpenCV_INCLUDE_DIRS}
                          ${CUDA_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}
                      ${OpenCV_LIBS}
                      ${CUDA_CUBLAS_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
        EXPORT ${CMAKE_PROJECT_NAME}Targets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(FILES ${DARKNET_INCS}
        DESTINATION include/Darknet/)

export(TARGETS ${PROJECT_NAME}
      APPEND FILE ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Targets.cmake)

file(APPEND ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
    "find_dependency(OpenCV REQUIRED)\n"
    "find_dependency(CUDA REQUIRED)\n")
