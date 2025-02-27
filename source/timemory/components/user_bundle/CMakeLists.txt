set(NAME user_bundle)

file(GLOB_RECURSE header_files ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

if(TIMEMORY_USE_CUDA AND CMAKE_CUDA_COMPILER)
    set_source_files_properties(${source_files} PROPERTIES # LANGUAGE CUDA
                                                           LINKER_LANGUAGE CUDA)
endif()

build_intermediate_library(
    USE_INTERFACE
    NAME ${NAME}
    TARGET ${NAME}-component
    CATEGORY USER_BUNDLE
    FOLDER components
    HEADERS ${header_files}
    SOURCES ${source_files}
    DEPENDS ${DEPS}
    PROPERTY_DEPENDS GLOBAL COMPONENT)

list(REMOVE_ITEM source_files ${CMAKE_CURRENT_SOURCE_DIR}/extern.cpp)
timemory_install_header_files(${source_files})
