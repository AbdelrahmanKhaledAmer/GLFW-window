/*
* This is some test code
*/

// Include Libraries
#include <Windows.h>
#include <iostream>				/* For basic input/output operations when debugging */
#include <string>				/* For basic string manipulation */
#include <GL\glew.h>			/* Extension for OpenGL libraries and for portability to different devices
                                   with different drivers by getting function locations at runtime */
#include <GLFW\glfw3.h>			/* For window creation and input listening */

// Use namespace
using namespace std;

// Constants
const GLint scale = 50;			/* How large the page should be keeping a 16*9 aspect ratio */
const GLint width = 16 * scale;
const GLint height = 9 * scale;

// Main code starts here
int main(int argc, char** argv)
{
	// ============================================= Initialize GLFW ======================================== //
	glfwInit();
	// Try to set OpenGL to version 3.3 (Higher is fine, lower is too old | My version is 4.4)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Don't use OpenGL features that are deprecated
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// make window size static (not resizable)
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	// Create window object
	GLFWwindow* window = glfwCreateWindow(width, height, "Hello world", nullptr, nullptr);
	// Check if window failed
	if (window == nullptr)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	// Make window main context on current thred 
	glfwMakeContextCurrent(window);
	// ======================================== End of GLFW initialization ================================== //

	// ============================================= Initialize GLEW ======================================== //
	// Manage OpenGL functionalities
	glewExperimental = GL_TRUE;
	// Initialize GLEW and check if it failed
	if (glewInit() != GLEW_OK)
	{
		cout << "Failed to initialize GLEW" << endl;
		return -1;
	}
	// ======================================== End of GLEW initialization ================================== //

	// Set OpenGL rendering area (Can be different from window width and height
	int GLWidth;
	int GLHeight;
	glfwGetFramebufferSize(window, &GLWidth, &GLHeight);
	// Start from bottom left corner to GLWidth and GLHeight
	glViewport(0, 0, GLWidth, GLHeight);

	// "Game loop" to keep GLFW running
	while (!glfwWindowShouldClose(window))	/* This function always returns false unless window was instructed to close*/
	{
		glfwPollEvents();					/* For listening to events (keyboard and mouse) */
		glfwSwapBuffers(window);			/* Shows prvious itteration's color buffer */
	}

	// Terminate window and all resources allocated to it
	glfwTerminate();

	return 0;
}