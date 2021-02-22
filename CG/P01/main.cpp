#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

void changeSize(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you can�t make a window with zero width).
	if (h == 0)
		h = 1;
	// compute window's aspect ratio
	float ratio = w * 1.0f / h;
	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load the identity matrix
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	// Set the perspective
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

float angle = 0.0f;

float lx = 0.0f, lz = -0.1f;

float x = 0.0f, z = 5.0f;

void renderScene(void)
{
	float fraction = 0.05f;
	int time = glutGet(GLUT_ELAPSED_TIME);

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// set camera
	glLoadIdentity();
	gluLookAt(x, 0.0f, z,
			  x+lx, 0.0f, z+lz,
		      0.0f, 1.0f, 0.0f);

	glRotatef(angle, 1.0f, 0.0f, 0.0f);

		
	// put drawing instructions here
	glutWireTeapot(1.0f);
	
	if (!((time/1000) & 1)) {
		x += lx * fraction;
		z += lz * fraction;
	}
	else {
		x -= lx * fraction;
		z -= lz * fraction;
	}
	
	// End of frame
	glutSwapBuffers();
}


void printInfo() {

	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));
}


int main(int argc, char** argv)
{
	// put GLUT init here
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("CG@DI");
    
	// put callback registry here

	glutDisplayFunc( renderScene ); //--> função para desenhar a janela

	glutReshapeFunc( changeSize ); //--> função para responder à criação da janela ou resize da janela

	glutIdleFunc( renderScene ); //--> função para qd o event queue está vazio
	
	// some OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	// enter GLUT�s main cycle
	glutMainLoop();
	
	return 1;
}