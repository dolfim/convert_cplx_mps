cmake_minimum_required(VERSION 3.3)

find_package(ALPS REQUIRED HINTS "${HOME}/opt/alps-clang")
#set(ALPS_MPS_DIR "/Users/dolfim/opt/alps-clang/share/alps")
find_package(ALPS_MPS REQUIRED)

# this will account for c++11 and stdlib
set(CMAKE_CXX_FLAGS "${ALPS_CMAKE_CXX_FLAGS}")

include_directories(${ALPS_MPS_INCLUDE_DIRS} ${ALPS_INCLUDE_DIRS})
link_directories(${ALPS_MPS_LIBRARY_DIRS} ${ALPS_LIBRARY_DIRS})
add_definitions(${ALPS_MPS_DEFINITIONS})

add_executable(convert_cplx_mps main.cpp)
target_link_libraries(convert_cplx_mps ${ALPS_MPS_LIBRARIES} ${ALPS_LIBRARIES})
set_target_properties(convert_cplx_mps PROPERTIES LINK_FLAGS "${ALPS_MPS_LINKER_FLAGS}")
