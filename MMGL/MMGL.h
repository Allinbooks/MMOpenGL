#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h> 
#include <vector>

enum MMGLShaderType {
	MMGL_SHADER_VERTEX = 1,
	MMGL_SHADER_FRAGMENT = 2
};

class MMGLShader {
public:
	MMGLShader(char* shaderStr, MMGLShaderType type);
	~MMGLShader();

//private:
	GLuint shader = 0;
};

class MMGLProgram
{
public:
	MMGLProgram(char* vertexShaderStr, char* fragmentShaderSrc);
	~MMGLProgram();

	int UseProgram();

public:
	GLuint program = 0;

};

class MMGLVAO
{
public:
	MMGLVAO();
	~MMGLVAO();
	
	int AddVertex3D(float* data, int vertexCount, int layout);

	int Setindex(unsigned int* indexData, int indexCount);

	int Draw();

	int BindVAO();
private:
	GLuint vao = 0;
	GLuint ebo = 0;

	int drawTime = 0;

	std::vector<GLuint> vboList;
};


