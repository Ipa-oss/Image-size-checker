cmake_minimum_required(VERSION 3.19)
project(Image-size-checker LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Image-size-checker
    WIN32 MACOSX_BUNDLE
    main.cpp
    imagesizechecker.cpp
    imagesizechecker.h
    imagesizechecker.ui
)

target_link_libraries(Image-size-checker
    PRIVATE
        Qt::Core
        Qt::Widgets
        libexif.a
)

install(TARGETS Image-size-checker
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Image-size-checker
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
