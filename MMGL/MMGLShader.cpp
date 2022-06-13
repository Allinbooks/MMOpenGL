#include"MMGL.h"

#include <stdlib.h>
#include <stdio.h>

MMGLShader::MMGLShader(char* shaderStr, MMGLShaderType type) {
	
	if (type == MMGLShaderType::MMGL_SHADER_VERTEX) {
		shader = glCreateShader(GL_VERTEX_SHADER);
	}
	else if(type == MMGLShaderType::MMGL_SHADER_FRAGMENT) {
		shader = glCreateShader(GL_FRAGMENT_SHADER);
	}
	else {
		// 这行代码完全出于礼貌
		shader = glCreateShader(GL_VERTEX_SHADER);
	}
	glShaderSource(shader, 1, &shaderStr, NULL);

	// 编译shader
	glCompileShader(shader);

	//typedef void (APIENTRYP PFNGLGETSHADERIVPROC)
	//              (GLuint shader, GLenum pname, GLint *params);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	GLint logLength = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);


	//typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC)
	//              (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	if (logLength > 0) {
		char* log = (char*)malloc(logLength);
		glGetShaderInfoLog(shader, logLength, NULL, log);

		printf("Shader Log:\n");
		printf("%s\n", log);
		free(log);
	}

}

MMGLShader::~MMGLShader() {
	if (shader != 0) {
		glDeleteShader(shader);
		shader = 0;
	}
}