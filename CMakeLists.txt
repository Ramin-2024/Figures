cmake_minimum_required(VERSION 3.10)
project(MySDLProject)

# Укажите путь к папке с заголовочными файлами SDL2
include_directories(C:/Users/ramag/Desktop/SDL2-2.30.8/x86_64-w64-mingw32/include)

# Укажите путь к вашим заголовочным файлам
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Include)

# Укажите путь к библиотекам SDL2
link_directories(C:/Users/ramag/Desktop/SDL2-2.30.8/x86_64-w64-mingw32/lib)

# Укажите все ваши cpp файлы
set(SOURCES
    main.cpp
    CPP/Circle.cpp
    CPP/CustomForm.cpp
    CPP/Figure.cpp
    CPP/Rectangle.cpp
    CPP/Square.cpp
    CPP/Triangle.cpp
)

# Создание исполняемого файла
add_executable(MySDLProject ${SOURCES})

# Линковка с библиотеками SDL2 и SDL2main
target_link_libraries(MySDLProject SDL2 SDL2main)
