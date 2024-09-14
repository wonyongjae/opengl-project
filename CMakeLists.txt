cmake_minimum_required(VERSION 3.10)
project(opengl_project)

# vcpkg 툴체인 파일 설정
set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")

# 필요한 라이브러리 찾기
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLAD REQUIRED)

# 실행 파일 설정
add_executable(OpenGLApp main.cpp)

# 라이브러리 링크
target_link_libraries(OpenGLApp PRIVATE OpenGL::GL GLFW glm::glm GLEW::GLEW)