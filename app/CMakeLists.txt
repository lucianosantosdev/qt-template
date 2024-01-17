cmake_minimum_required(VERSION 3.16)

project(qtTemplate VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

file(GLOB SRC_SOURCES "${CMAKE_SOURCE_DIR}/src/**/*.cpp")
file(GLOB SRC_HEADERS "${CMAKE_SOURCE_DIR}/src/**/*.h")
qt_add_executable(appqtTemplate src/main.cpp)


file(GLOB SRC_QML "${CMAKE_SOURCE_DIR}/src/*.qml")
qt_add_qml_module(appqtTemplate
    URI qtTemplate
    VERSION 1.0
    QML_FILES ${SRC_QML}
    SOURCES src/Base.h src/Base.cpp
    SOURCES src/Derived.h src/Derived.cpp
    SOURCES src/Foo.h src/Foo.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appqtTemplate PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appqtTemplate
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appqtTemplate
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appqtTemplate
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)