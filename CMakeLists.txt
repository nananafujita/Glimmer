cmake_minimum_required(VERSION 3.16)

project(Glimmer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick OpenGL OpenGLWidgets)

qt_standard_project_setup()

qt_add_executable(appGlimmer
    main.cpp
    shaders.qrc
)

qt_add_qml_module(appGlimmer
    URI Glimmer
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES glimmerwindow.h glimmerwindow.cpp
        SOURCES
        RESOURCES vertshader.vert
        RESOURCES
        RESOURCES fragshader.frag
        RESOURCES
        SOURCES openglwindow.h openglwindow.cpp
        RESOURCES shaders.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appGlimmer PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appGlimmer
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appGlimmer
    PRIVATE Qt6::Quick
)


set(shaders_resource_files
    "fragshader.frag"
    "vertshader.vert"
)

qt6_add_resources(appGlimmer "shaders"
    PREFIX
        "/"
    FILES
        ${shaders_resource_files}
)

include(GNUInstallDirs)
install(TARGETS appGlimmer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
