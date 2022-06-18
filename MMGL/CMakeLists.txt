include_directories(../3rdpart/glfw/include/)
include_directories(../3rdpart/glad/include/)
include_directories(../3rdpart/glad/src/)

link_directories(../3rdpart/glfw/lib/)

# 将源代码添加到此项目的可执行文件。
add_library (
	MMGL 
	../3rdpart/glad/src/glad.c
    MMGL.h
    MMGLShader.cpp
	MMGLProgram.cpp
	MMGLVAO.cpp
)
