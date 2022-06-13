#include "MMGL.h"
#include <stdio.h>
#include <corecrt_malloc.h>

MMGLProgram::MMGLProgram(char* vertexShaderStr, char* fragmentShaderSrc)
{
	program = glCreateProgram();

	MMGLShader vertexShader(vertexShaderStr, MMGLShaderType::MMGL_SHADER_VERTEX);
	MMGLShader fragmentShader(fragmentShaderSrc, MMGLShaderType::MMGL_SHADER_FRAGMENT);

	glAttachShader(program, vertexShader.shader);
	glAttachShader(program, fragmentShader.shader);

	glLinkProgram(program);

	GLint logLength = 0;
	//typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC)
		//              (GLuint program, GLenum pname, GLint *params);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);


	if (logLength > 0) {
		char* log = (char*)malloc(logLength);
		glGetProgramInfoLog(program, logLength, NULL, log);
		printf("Program Log:\n");
		printf("%s\n",log);
		free(log);
	}

	
}

MMGLProgram::~MMGLProgram()
{
	if (program != 0) {
		glDeleteProgram(program);
		program = 0;
	}
}