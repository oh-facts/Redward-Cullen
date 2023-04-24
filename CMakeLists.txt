cmake_minimum_required(VERSION 3.21)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/warnings.cmake)

project(BSE2 VERSION 0.1.0)

include_directories("include")
add_executable(${PROJECT_NAME} "sandbox/main.cpp" "src/BSE.cpp" "src/Scene.cpp" 
                               "src/Input.cpp" "src/Entity.cpp" "src/Window.cpp"
                               "src/Sprite.cpp")
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
set_project_warnings(${PROJECT_NAME})

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-system sfml-network sfml-graphics sfml-window
)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/res
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/res
)