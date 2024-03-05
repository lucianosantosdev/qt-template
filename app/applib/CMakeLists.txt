cmake_minimum_required(VERSION 3.16)

project(qtTemplate VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME app-lib)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

file(GLOB_RECURSE SRC_SOURCES "src/*.cpp")
file(GLOB_RECURSE SRC_HEADERS "src/*.h")

file(GLOB_RECURSE SRC_QML "ui/*.qml")
get_filename_component(CMAKE_CURRENT_LIST_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)
foreach(qml_file ${SRC_QML})
    file(RELATIVE_PATH relative_qml_file "${CMAKE_CURRENT_LIST_DIR}" "${qml_file}")
    list(REMOVE_ITEM SRC_QML "${qml_file}")
    list(APPEND SRC_QML "${relative_qml_file}")
endforeach()

message(PROJECT_SOURCE_DIR="${SRC_QML}")
qt_add_library(
    ${PROJECT_NAME} STATIC
    ${SRC_SOURCES}
    ${SRC_HEADERS}
)

qt_add_qml_module(${PROJECT_NAME}
    URI app
    VERSION 1.0
    QML_FILES ${SRC_QML}
    SOURCES ${SRC_SOURCES} ${SRC_HEADERS}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
