#include <iostream>

//GLEW
#define GLEW_STATIC
#include <GL/glew.h>
//GLFW
#include <GLFW/glfw3.h>
//other libs
//image loader
#include "stb_image.h"
//GLM_Mathematics
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
//other includes
#include "shader.h"

//function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

//window dimension
const GLuint WIDTH = 800, HEIGHT = 600;

//The MAIN function
int main() {
	//Init GLFW
	glfwInit();
	//Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//Create a GLFWwindow object
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "изучение OpenGl", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	//Set the required callback functions
	glfwSetKeyCallback(window, key_callback);

	// set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// initialize GLEW to setup the OpenGL function pointers
	glewInit();
	//Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// for loading viewer object as realy object
	glEnable(GL_DEPTH_TEST);
	//Building and compile our shader program
	Shader ourShader("shader.vs","shader.frag");
	
	//Set up vertex data
	GLfloat vertices[] = {
		0.5f, 0.5f, 0.5f, //vertice #0
		0.5f, 0.5f, 0.5f, //vertice #1
		0.5f, 0.5f, 0.5f, //vertice #2
		0.5f, 0.5f, 0.5f, //vertice #3
		0.5f, 0.5f, 0.5f, //vertice #4
		0.5f, 0.5f, 0.5f, //vertice #5
		0.5f, 0.5f, 0.5f, //vertice #6
		0.5f, 0.5f, 0.5f  //vertice #7
	};
	GLuint indices[] = {
		0, 1, 2,
		2, 3, 0, // ближний фронтальный квадрат
		1, 0, 5,
		5, 6, 1, // правый квадрат
		1, 6, 7,
		7, 2, 1, // низ
		3, 2, 7,
		7, 4, 3, // левый
		4, 7, 6,
		6, 5, 4, // тыловой
		5, 0, 3,
		3, 4, 5 //верх
	};
	GLfloat vCoord[] = {
		1.0f, 1.0f, //vertice texture #0
		1.0f, 0.0f, //vertice texture #1
		0.0f, 0.0f, //vertice texture #2
		0.0f, 1.0f, //vertice texture #3
		0.0f, 1.0f, //vertice texture #4
		1.0f, 1.0f, //vertice texture #5
		0.0f, 0.0f, //vertice texture #6
		0.0f, 0.0f  //vertice texture #7
	}; 

	while (!glfwWindowShouldClose(window)) {
		//check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		glfwSwapBuffers(window);
	}

	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}