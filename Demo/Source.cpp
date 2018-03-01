#define _USE_MATH_DEFINES
#include <gl/GLUT.h>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
#include <sstream>
#include <stdlib.h>
#include "Vector.h"
#include "Wall.h"
#include "Dot.h"

int middleX = 160;
int middleY = 160;
// angle of rotation for the camera direction
float angley = 0.0;
float anglex = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f, ly = 1.3f;
// XZ position of the camera
float x = 0.0f, z = 5.0f, y = 1.0f;
Wall wall = Wall();

using namespace std;


void draw(void) {
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
									// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, y, z,
		x + lx, ly, z + lz,
		0.0f, 1.0f, 0.0f);

	// Draw ground
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();
	
	wall.drawWall(20, 40, 0.2, Dot(-10, 0, -10), 0);
	wall.drawWall(20, 3, 0.2, Dot(-10, 0, -10), 90);
	wall.drawWall(20, 3, 0.2, Dot(-10, 0, 10), 0);
	wall.drawWall(20, 3, 0.2, Dot(-10, 0, 10), 90);

	glutSwapBuffers();
}

/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
											   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
								  // Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void processNormalKeys(unsigned char key, int x, int y)
{
	float fraction = 0.8f;
	float angleforce = 0.1f;
	switch (key)
	{
			// 119 - w
		case 119:
			x += lx * fraction;
			z += lz * fraction;
			break;
			// 115 - s
		case 115:
			x -= lx * fraction;
			z -= lz * fraction;
			break;
			// 100 - d
		case 100: 
			
			break;
			// 97 - a
		case 97: 
			
			break;
			// 113 - q
		case 113:
			anglex -= angleforce;
			lx = sin(anglex);
			lz = -cos(anglex);
			break;
			// 101 - e
		case 101:
			anglex += angleforce;
			lx = sin(anglex);
			lz = -cos(anglex);
			break;
			// 122 - z
		case 122:
			if (ly == 0.0f) break;
			ly -= angleforce;
			break;
			// 120 - x
		case 120:
			if (ly == 2.0f) break;
			ly += angleforce;
			break;
			// esc - 27
		case 27:
			exit(0);
			break;
	}
}

void idle() {
	//POINT cursor;
	//GetCursorPos(&cursor);

	//int deltaX = cursor.x - middleX;
	//int deltaY = cursor.y - middleY;

	//glutWarpPointer(middleX, middleY); // could also use SetCursorPos() if you're only going to use Windows

	//lx = sin(deltaX / 50);
	//lz = -cos(deltaY / 50);
	draw();
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	// init GLUT and create window

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

														// register callbacks
	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutKeyboardFunc(processNormalKeys);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();
	return 0;
}