// MMOpenGL.cpp: 定义应用程序的入口点。
//
#include <stdio.h>
#include <stdlib.h>

// 顺序有要求，GLFW依赖于glad
#include <glad/glad.h>
#include <GLFW/glfw3.h> 

#include "MMOpenGL.h"
#include "MMGL.h"


#define STRINGIZE(x)  #x
#define SHADER(shader) "" STRINGIZE(shader)




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

	//char* shaderStr = (char*)"void main(){}";
	float aa = 0;

	char* vertexShader = SHADER(
		#version 330\n

		uniform float a;

		layout(location = 0) in vec3 pos;
		// layout(location = 1) in vec3 pos2;
		// layout(location = 2) in vec3 pos3;

		out vec3 outPos;

		void main() {
			outPos = pos;
			//double w = 1.0;
			float _a = sin(a);
			gl_Position = vec4(pos.x * _a, pos.y * _a, pos.z * _a, 1.0);
		}
	);

	char* fragmentShader = SHADER(
		#version 330\n

		out vec4 rgbaColor;

		in vec3 outPos;

		void main() {
			rgbaColor = vec4(outPos, 1.0);
		}
	);

	// 顶点坐标
	// float vertex[] = {
	// 	 0.0f,  1.0f, 0.0f,
	// 	-1.0f, -1.0f, 0.0f,
	// 	 1.0f, -1.0f, 0.0f
	// };

	//float vertex[] = {
	//	/* A */ -1.0f,  1.0f, 0.0f,
	//	/* D */ -1.0f, -1.0f, 0.0f,
	//	/* B */  1.0f,  1.0f, 0.0f,

	//	/* B */  1.0f,  1.0f, 0.0f,
	//	/* D */ -1.0f, -1.0f, 0.0f,
	//	/* C */  1.0f, -1.0f, 0.0f

	//};

	float vertex[] = {
		/* A */ -1.0f,  1.0f, 0.0f,
		/* B */  1.0f,  1.0f, 0.0f,
		/* C */  1.0f, -1.0f, 0.0f,
		/* D */ -1.0f, -1.0f, 0.0f

	};

	unsigned int index[] = {
		/* A->D->B */
		0, 3, 1,
		/* B->D->C */
		1, 3, 2
	};

	// MMGLShader * shader = new MMGLShader(shaderStr, MMGLShaderType::MMGL_SHADER_VERTEX);
	
	MMGLProgram* program = new MMGLProgram(vertexShader, fragmentShader);

	MMGLVAO* vao = new MMGLVAO();
	vao->AddVertex3D(vertex, 4, 0);
	vao->Setindex(index, 6);

	while (!glfwWindowShouldClose(window)) {
		//TODO 绘制操作

		// 清空画布中的颜色内容
		glClear(GL_COLOR_BUFFER_BIT);

		// 养成很久之前绑定voa的习惯
		program->UseProgram();

		GLint location = glGetUniformLocation(program->program, "a");

		glUniform1f(location, aa);
		

		//vbo模式(GL_TRIANGLES是三角模式)
		//vao->BindVAO();
		//glDrawArrays(GL_TRIANGLES, 0, 6);

		//ebo模式
		vao->Draw();
		aa += 0.001;


		//TODO 等到双缓冲之后再了解
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	delete vao;

	// delete shader;
	 delete program;

	glfwTerminate();

	printf("Close success!!!\n");
	return 0;
}
