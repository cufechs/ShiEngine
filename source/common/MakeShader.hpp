#pragma once
#include <application.hpp>
#include <iostream>
#include <fstream>
#include <cassert>

namespace NotEngine
{
	class MakeShader: public NotEngine::
	{

		// These unsigned integers represent the way we communicate with the GPU.
		// They act like a name (or, in other words, an ID).
		// These uint are passed to the GL header functions to tell the GL which OpenGL object
		// we are referring to. Also the values are set by the GL functions when passed by reference.
		GLuint program = 0, vertex_array = 0;

		void onInitialize() override 
		{
			program = glCreateProgram();    // We ask GL to create a program for us and return a uint that we will use it by.
											// (act as a pointer to the created program).

			attachShader(program, "assets/shaders/ex02_shader_introduction/triangle.vert", GL_VERTEX_SHADER);   // read the vertex shader and attach it to the program.
			attachShader(program, "assets/shaders/ex02_shader_introduction/red.frag", GL_FRAGMENT_SHADER);      // read the fragment shader and attach it to the program.

			glLinkProgram(program);                     // Link the vertex and fragment shader together.
			checkProgramLinkingErrors(program);         // Check if there is any link errors between the fragment shader and vertex shader.

			glGenVertexArrays(1, &vertex_array);        // Ask GL to create a vertex array to easily create a triangle.

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);       // Set the clear color
		}

		void onDraw(double deltaTime) override 
		{
			glClear(GL_COLOR_BUFFER_BIT);               // Clear the frame buffer (back buffer of the window)
			glUseProgram(program);                      // Ask GL to use this program for the upcoming operations.
														// Every shader and rendering call after glUseProgram will now use this program object (and the shaders).

			glBindVertexArray(vertex_array);            // Binding is like selecting which object to use.
														// Note that we need to bind a vertex array to draw
														// Even if that vertex array does not send any data down the pipeline

			// Sends vertices down the pipeline for drawing
			// Parameters:
			// mode (GLenum): what primitives to draw. GL_TRIANGLES will combine each 3 vertices into a triangle.
			// first (GLint): the index of the first vertex to draw. It is useless here since we are not receiving data through the vertex array.
			// count (GLsizei): How many vertices to send to the pipeline. Since we are sending 3 vertices only, only one triangle will be drawn.
			glDrawArrays(GL_TRIANGLES, 0, 3);

			glBindVertexArray(0);                       // Unbind the buffer.
		}

		void onDestroy() override 
		{
			glDeleteProgram(program);                   // Cleaning up the program we compiled and saved.
			glDeleteVertexArrays(1, &vertex_array);     // Clean up the array we allocated Params: (n: number of vertex array objects, array containing the n addresses of the objects)
		}

	};
}