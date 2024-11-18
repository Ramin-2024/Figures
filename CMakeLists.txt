cmake_minimum_required(VERSION 3.10)

project(Shapes VERSION 0.0.1)

# Укажите путь к заголовочным файлам
set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/src/include")
# Укажите путь к библиотеке (необходимо указать сам файл)
set(SDL2_LIBRARY "${CMAKE_SOURCE_DIR}/src/lib/libSDL2.a")

# Указываем директории с заголовочными файлами
include_directories(${SDL2_INCLUDE_DIR} Include)

# Указываем источники
set(SOURCES
    main.cpp
    CPP/Circle.cpp
    CPP/Rectangle.cpp
    CPP/Square.cpp
    CPP/Triangle.cpp
    CPP/Figure.cpp
)

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES})

# Линковка с библиотеками
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})