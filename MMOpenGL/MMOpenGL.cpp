// MMOpenGL.cpp: 定义应用程序的入口点。
//
#include <stdio.h>
#include <stdlib.h>

// 顺序有要求，GLFW依赖于glad
#include <glad/glad.h>
#include <GLFW/glfw3.h> 

#include "MMOpenGL.h"
#include "MMGL.h"




int main()
{
	// glfwInit();
	// gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	printf("Hello MMOpenGL!\n");
	glfwInit();

	// 设置版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// TODO Core Profile.什么是CORE_PROFILE？
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	int windowWidth = 1280;
	int windowHeight = 720;
	char* windowTitle = "MMOpenGL";
	GLFWwindow*  window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);

	/* OpenGL的运行模式 -（必须）- 单线程模式
	 * 多个线程同时调用不被允许
	 * 将当前线程和OpenGL Context做一个绑定
	 * 如果出现多线程并行需要对资源上锁，这样的多线程并没有提升性能，因此不建议
	 */
	glfwMakeContextCurrent(window);

	// 制作GLAD
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	// GLAD初始化完成
	//GLuint shader = glCreateShader(GL_VERTEX_SHADER);
	//GLuint shader = glCreateShader(GL_FRAGMENT_SHADER);

	char* shaderStr = (char*)"xiaoming";

	// MMGLShader * shader = new MMGLShader(shaderStr, MMGLShaderType::MMGL_SHADER_VERTEX);
	
	MMGLProgram* program = new MMGLProgram(shaderStr, shaderStr);


	while (!glfwWindowShouldClose(window)) {
		//TODO 绘制操作

		//TODO 等到双缓冲之后再了解
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// delete shader;
	 delete program;

	
	glfwTerminate();

	printf("Close success!!!\n");
	return 0;
}
