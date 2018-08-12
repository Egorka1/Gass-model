#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "DialogStrt.h"
#include "Ball.h"
#include <algorithm>
#include <glut.h>

const unsigned int Nmax = 25;
unsigned int N = 0;
Ball b[Nmax];

DialogStrt::DialogStrt(CWnd* pParent) : CDialog(IDD_DIALOG1, pParent) {}

void MouseClck(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		if (N < Nmax) b[N++] = Ball(double(x - 675) / 675, double(365 - y) / 365, 1);
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		if (N < Nmax) b[N++] = Ball(double(x - 675) / 675, double(365 - y) / 365, 2);
}

void qSort(int size) {
	int i = 0, j = size - 1;
	Ball mid = b[size / 2];
	do {
		while (b[i]._x < mid._x) i++;
		while (b[j]._x > mid._x) j--;
		if (i <= j) {
			Ball tmp = b[i];
			b[i] = b[j];
			b[j] = tmp;
			i++; j--;
		}
	} while (i <= j);
	if (j > 0) qSort(j + 1);
	if (i < size) qSort(size - i);
}

void Scene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(255, 255, 255, 1.0f);
	const double k = 0.5625;
	glColor3d(0, 0, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glEnd();
	glPointSize(5);
	glBegin(GL_POINTS);
	for (unsigned int n = 0; n < N; n++) {
		if(b[n]._t == 1) glColor3d(0, 255, 0);
		else glColor3d(255, 0, 0);
		glVertex2f(b[n]._x, b[n]._y);
	}
	glColor3d(255, 255, 255);
	glEnd();
	glutSwapBuffers();
}

void Timer(int value) {
	qSort(N);
	for (unsigned int n = 0; n < N; n++) {
		b[n].Colscr();
		for (unsigned int i = n + 1; i < N; i++)
			b[n].Collision(b[i]);
		b[n].Move();
	}
	glutPostRedisplay();
	glutTimerFunc(1, Timer, 1);
}

void DialogStrt::Run() {
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1350, 730);
	unsigned int MainWnd = glutCreateWindow("Balls");
	glutMouseFunc(MouseClck);
	glutDisplayFunc(Scene);
	glutTimerFunc(1, Timer, 1);
	glutMainLoop();
}

DialogStrt::~DialogStrt() {}

BEGIN_MESSAGE_MAP(DialogStrt, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, Run)
END_MESSAGE_MAP()