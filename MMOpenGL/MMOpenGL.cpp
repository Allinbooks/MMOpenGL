// MMOpenGL.cpp: 定义应用程序的入口点。
//
#include <stdio.h>

// 顺序有要求，GLFW依赖于glad
#include <glad/glad.h>
#include <GLFW/glfw3.h> 

#include "MMOpenGL.h"




int main()
{
	glfwInit();
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	printf("Hello MMOpenGL!");
	return 0;
}
