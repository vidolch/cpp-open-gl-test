#include "Wall.h"
#include <GL/GLUT.h>
#include "Dot.h"

Wall::Wall()
{
}

Wall::~Wall()
{
}

void Wall::drawWall(float width, float height, float thick, Dot coordinates, float angle)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);

	if (angle > 0.0f) {
		glRotatef(angle, 0, 1, 0);
	}

	//glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	// Define vertices in counter-clockwise (CCW) order with normal pointing out
	// Green
	glColor3f(0.0f, 1.0f, 0.0f);     
	// Top face (y = 1.0f)
	glVertex3f(coordinates.x,			coordinates.y + height, coordinates.z);
	glVertex3f(coordinates.x + width, coordinates.y + height, coordinates.z);
	glVertex3f(coordinates.x + width, coordinates.y + height, coordinates.z + thick);
	glVertex3f(coordinates.x,			coordinates.y + height, coordinates.z + thick);
	
	// Orange
	glColor3f(1.0f, 0.5f, 0.0f);
	// Bottom face (y = -1.0f)
	glVertex3f(coordinates.x,			coordinates.y, coordinates.z);
	glVertex3f(coordinates.x + width,	coordinates.y, coordinates.z);
	glVertex3f(coordinates.x + width,	coordinates.y, coordinates.z + thick);
	glVertex3f(coordinates.x,			coordinates.y, coordinates.z + thick);
	
	// Red
	glColor3f(1.0f, 0.0f, 0.0f);     
	// Front face  (z = 1.0f)
	glVertex3f(coordinates.x,			coordinates.y,			coordinates.z);
	glVertex3f(coordinates.x,			coordinates.y + height, coordinates.z);
	glVertex3f(coordinates.x + width,	coordinates.y + height, coordinates.z);
	glVertex3f(coordinates.x + width,	coordinates.y,			coordinates.z);

	// Yellow
	glColor3f(1.0f, 1.0f, 0.0f);     
	// Back face (z = -1.0f)
	glVertex3f(coordinates.x,			coordinates.y,			coordinates.z + thick);
	glVertex3f(coordinates.x,			coordinates.y + height, coordinates.z + thick);
	glVertex3f(coordinates.x + width,	coordinates.y + height, coordinates.z + thick);
	glVertex3f(coordinates.x + width,	coordinates.y,			coordinates.z + thick);
	
	// Blue
	glColor3f(0.0f, 0.0f, 1.0f);     
	// Left face (x = -1.0f)
	glVertex3f(coordinates.x, coordinates.y,			coordinates.z + thick);
	glVertex3f(coordinates.x, coordinates.y + height,	coordinates.z + thick);
	glVertex3f(coordinates.x, coordinates.y + height,	coordinates.z);
	glVertex3f(coordinates.x, coordinates.y,			coordinates.z);
	
	// Magenta
	glColor3f(1.0f, 0.0f, 1.0f);     
	// Right face (x = 1.0f)
	glVertex3f(coordinates.x + width, coordinates.y,			coordinates.z + thick);
	glVertex3f(coordinates.x + width, coordinates.y + height,	coordinates.z + thick);
	glVertex3f(coordinates.x + width, coordinates.y + height,	coordinates.z);
	glVertex3f(coordinates.x + width, coordinates.y,			coordinates.z);
	glEnd();
	// End of drawing color-cube
	glPopMatrix();
}
