# CMakeList.txt : CMake project for SolarSystemQt, include source and define
# project specific logic here.
cmake_minimum_required(VERSION 3.20)
project(SolarSystemQt)

# Путь к Qt через vcpkg (поменяй путь, если нужно)
set(CMAKE_PREFIX_PATH "C:/Users/sf/vcpkg/installed/x64-windows/share/Qt6")

# Qt компоненты
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Подключаем файлы проекта
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)

# После SOURCES
set(RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources.qrc)
qt_add_resources(QT_RESOURCES
    ${RESOURCES}
)

add_executable(SolarSystemQt
    ${SOURCES}
    ${QT_RESOURCES}
)

target_include_directories(SolarSystemQt PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(SolarSystemQt PRIVATE
    Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick Qt6::QuickControls2
)
