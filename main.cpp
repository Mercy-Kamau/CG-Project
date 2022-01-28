#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int isIdle = 0, ww, wh, s;
int in_about = 1;
int in_guide = 1;
int fontType;
void* font;

int f1, f2, g1, g2, k1, k2, l1, l2, ply1, ply2, h1, h2, h3, h4, s1, s2, u, v, r1, op, w, dice1, enter;

int i, ch1, ch, p1, p2, ra1, z, z1, za1;

float a[100][100] = { {-0.4,-0.325},{-0.1375,-0.7275},{-0.1375,-0.61},{-0.1375,-0.4925},{-0.1375,-0.375},{-0.1375,-0.2575},{-0.2575,-0.14},{-0.375,-0.14},{-0.495,-0.14},{-0.6110,-0.14},{-0.7275,-0.14},{-0.84,-0.14},{-0.84,0.005},{-0.84,0.1375},{-0.7275,0.1375},{-0.6110,0.1375},{-.495,.1375},{-0.375,0.1375},{-0.2575,0.1375},{-0.1375,0.2575},{-0.1375,0.375},{-0.1375,0.4925},{-0.1375,0.61},{-0.1375,0.7275},{-0.1375,0.845},{0,0.845},{0.1375,0.845},{0.1375,0.7275},{0.1375,0.61},{0.1375,0.4925},{0.1375,0.375},{0.1375,0.2575},{0.2575,0.1375},{0.375,0.1375},{.495,0.14},{0.6110,0.1375},{0.7275,0.1375},{0.84,0.1375},{0.84,0.005},{0.84,-0.14},{0.7275,-0.14},{0.6110,-0.14},{.495,-0.14},{0.375,-0.14},{0.2575,-0.14},{0.1375,-0.2575},{0.1375,-0.375},{0.1375,-0.4925},{0.1375,-0.61},{0.1375,-0.7275},{0.1375,-0.845},{0,-0.845},{0,-0.7275},{0,-0.61},{0,-0.4925},{0,-0.375},{0,-0.2575} };
float b[100][100] = { {-0.4,-0.325},{0.1375,0.7275},{0.1375,0.61},{0.1375,0.4925},{0.1375,0.375},{0.1375,0.2575},{0.2575,0.1375},{0.375,0.1375},{0.495,0.14},{0.6110,0.1375},{0.7275,0.1375},{0.84,0.1375},{0.84,0.005},{0.84,-0.14},{0.7275,-0.14},{0.6110,-0.14},{.495,-.14},{0.375,-0.14},{0.2575,-0.14},{0.1375,-0.2575},{0.1375,-0.375},{0.1375,-0.4925},{0.1375,-0.61},{0.1375,-0.7275},{0.1375,-0.845},{0,-0.845},{-0.1375,-0.845},{-0.1375,-0.7275},{-0.1375,-0.61},{-0.1375,-0.4925},{-0.1375,-0.375},{-0.1375,-0.2575},{-0.2575,-0.14},{-0.375,-0.14},{-.495,-0.14},{-0.6110,-0.14},{-0.7275,-0.14},{-0.84,-0.14},{-0.84,0.005},{-0.84,0.1375},{-0.7275,0.1375},{-0.6110,0.1375},{-.495,0.1375},{-0.375,0.1375},{-0.2575,0.1375},{-0.1375,0.2575},{-0.1375,0.375},{-0.1375,0.4925},{-0.1375,0.61},{-0.1375,0.7275},{-0.1375,0.845},{0,0.845},{0,0.7275},{0,0.61},{0,0.4925},{0,0.375},{0,0.2575} };
float c[10][10] = { {-0.5,-0.7},{-0.7,-0.5} };
float d[10][10] = { {0.5,0.7},{0.7,0.5} };
int A[100][100] = { {430,527},{630,608},{626,567},{628,528},{626,485},{629,441},{585,397},{544,398},{502,400},{463,397},{420,395},{381,397},{380,350},{377,304},{421,303},{460,304},{501,301},{541,302},{585,300},{627,260},{627,221},{627,177},{627,138},{627,97},{627,58},{676,56},{723,54},{723,96},{725,138},{724,176},{725,216},{723,258},{764,300},{809,303},{850,304},{890,304},{931,303},{972,303},{971,352},{973,398},{932,396},{890,396},{851,395},{811,395},{768,396},{724,441},{725,484},{724,523},{725,562},{725,606},{728,645},{677,645},{677,608},{677,565},{677,522},{677,485},{677,442} };
int B[100][100] = { {853,104},{723,96},{725,138},{724,176},{725,216},{723,258},{764,300},{809,303},{850,304},{890,304},{931,303},{972,303},{971,352},{973,398},{932,396},{890,396},{851,395},{811,395},{768,396},{724,441},{725,484},{724,523},{725,562},{725,606},{728,645},{677,645},{629,650},{630,608},{626,567},{628,528},{626,485},{629,441},{585,397},{544,398},{502,400},{463,397},{420,395},{381,397},{380,350},{377,304},{421,303},{460,304},{501,301},{541,302},{585,300},{627,260},{627,221},{627,177},{627,138},{627,97},{627,58},{676,56},{677,97},{677,137},{677,177},{677,219},{677,261} };

void display_inter_guide();
void arrow();
void display_enter1();
void init()
{
	glClearColor(1, 0.8, 0.5, 1);
	glEnable(GL_DEPTH_TEST);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1360, 703);
	glutCreateWindow("LUDO GAME");
}

//int width and height
void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-1.0, 1.0, -1.0 * (GLfloat)h / (GLfloat)w,
			2.0 * (GLfloat)h / (GLfloat)w, -20.0, 20.0);
	else
		glOrtho(-1.0 * (GLfloat)w / (GLfloat)h,
			1.0 * (GLfloat)w / (GLfloat)h, -1.0, 1.0, -20.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void dice(int y)
{
	glPointSize(5);
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(-0.82, 0.25);
	glVertex2f(-0.82, 0.38);
	glVertex2f(-0.69, 0.38);
	glVertex2f(-0.69, 0.25);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(-0.82, 0.38);
	glVertex2f(-0.69, 0.38);
	glVertex2f(-0.67, 0.4);
	glVertex2f(-0.79, 0.4);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(-0.69, 0.38);
	glVertex2f(-0.67, 0.4);
	glVertex2f(-0.67, 0.27);
	glVertex2f(-0.69, 0.25);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.82, 0.38);
	glVertex2f(-0.69, 0.38);
	glVertex2f(-0.67, 0.4);
	glVertex2f(-0.79, 0.4);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.69, 0.38);
	glVertex2f(-0.67, 0.4);
	glVertex2f(-0.67, 0.27);
	glVertex2f(-0.69, 0.25);
	glEnd();

	glColor3f(0, 0, 0);
	switch (y)
	{
	case 0:
	case 1:
		glBegin(GL_POINTS);
		glVertex2f(-0.75, 0.31);
		glEnd();
		break;
	case 2:glBegin(GL_POINTS);
		glVertex2f(-0.73, 0.31);
		glVertex2f(-0.77, 0.31);
		glEnd();
		break;
	case 3:glBegin(GL_POINTS);
		glVertex2f(-0.72, 0.31);
		glVertex2f(-0.755, 0.31);
		glVertex2f(-0.79, 0.31);
		glEnd();
		break;
	case 4:glBegin(GL_POINTS);
		glVertex2f(-0.72, 0.285);
		glVertex2f(-0.72, 0.345);
		glVertex2f(-0.78, 0.285);
		glVertex2f(-0.78, 0.345);
		glEnd();
		break;
	case 5:glBegin(GL_POINTS);
		glVertex2f(-0.72, 0.285);
		glVertex2f(-0.72, 0.345);
		glVertex2f(-0.75, 0.31);
		glVertex2f(-0.78, 0.285);
		glVertex2f(-0.78, 0.345);
		glEnd();
		break;
	case 6:glBegin(GL_POINTS);
		glVertex2f(-0.72, 0.29);
		glVertex2f(-0.755, 0.29);
		glVertex2f(-0.79, 0.29);
		glVertex2f(-0.72, 0.34);
		glVertex2f(-0.755, 0.34);
		glVertex2f(-0.79, 0.34);
		glEnd();
		break;

	}
	glPointSize(25);
	glFlush();
}

void player1(int ch);

void player2(int ch1);

void call(int w);

void myMouse(int btn, int state, int x, int y)
{
	int C[10][10];
	GLint rand();
	int D[10][10];
	C[0][0] = A[k2][0]; 
	C[0][1] = A[k2][1];
	C[1][0] = A[k1][0]; 
	C[1][1] = A[k1][1];
	D[0][0] = B[l2][0]; 
	D[0][1] = B[l2][1];
	D[1][0] = B[l1][0];
	D[1][1] = B[l1][1];
	if (ra1 + k1 > 57 || ra1 + k2 > 57 || ra1 + l1 > 57 || ra1 + l2 > 57)
	{
		z = 1;
	}
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (ply1 == 1 && ply2 == 0)
		{
			if (k1 == 0 && x > 483 && x < 517 && y < 615 && y>580)
			{

				if (ra1 == 6 || ra1 == 1)
					player1(1);
				else
					player1(2);
			}
			else if (k2 == 0 && x > 412 && x < 447 && y < 545 && y>510)
			{
				if (ra1 == 6 || ra1 == 1)
					player1(2);
				else
					player1(1);

			}
			else if (x > (C[0][0] - 20) && x<(C[0][0] + 20) && y>(C[0][1] - 20) && y < (C[0][1] + 20) && z1 == 1 && k2>0)
				player1(2);
			else if (x > (C[1][0] - 20) && x<(C[1][0] + 20) && y>(C[1][1] - 20) && y < (C[1][1] + 20) && z1 == 1 && k1>0)
				player1(1);
			if (z == 1 && dice1 == 1)
			{
				z = 0;
				z1 = 1;
				ra1 = rand() % 2 + rand() % 3 + rand() % 2 + rand() % 3;

				if (ra1 == 0)
					ra1 = 1;
				dice(ra1);
			}
		}
		else
		{
			if (l1 == 0 && x > 833 && x < 873 && y>84 && y < 124)
			{
				if (ra1 == 6 || ra1 == 1)
					player2(1);
				else
					player2(2);

			}

			else if (l2 == 0 && x > 906 && x < 940 && y < 190 && y>158)
			{

				if (ra1 == 6 || ra1 == 1)
					player2(2);
				else
					player2(1);

			}
			else if (x > (D[0][0] - 20) && x<(D[0][0] + 20) && y>(D[0][1] - 20) && y < (D[0][1] + 20) && z1 == 1 && l2>0)
				player2(2);
			else if (x > (D[1][0] - 20) && x<(D[1][0] + 20) && y>(D[1][1] - 20) && y < (D[1][1] + 20) && z1 == 1 && l1>0)
				player2(1);

			if (z == 1 && dice1 == 1)
			{
				z = 0;
				z1 = 1;
				ra1 = rand() % 2 + rand() % 3 + rand() % 2 + rand() % 3;

				if (ra1 == 0)
					ra1 = 1;
				dice(ra1);
			}
		}


	}


}

void display2();
void wait(void);
void call(int w);
void display1(void);

void key(unsigned char key, int x, int y)
{

	if (key == 'q' || key == 'Q')
		call(2);

	if (key == 13 && enter == 1)
	{

		call(1);
		wait();
		display_enter1();
		display1();
	}
}


void call(int w)
{
	switch (w)
	{
	case 1:glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glFlush();
		f1 = 0; f2 = 0; g1 = 0; g2 = 0; k1 = 0; k2 = 0; l1 = 0; l2 = 0; ply1 = 1; ply2 = 0; h1 = 0; h2 = 0; h3 = 0; h4 = 0, s1 = 0, s2 = 0;
		c[0][0] = -0.5; c[0][1] = -0.7; c[1][0] = -0.7; c[1][1] = -0.5;
		d[0][0] = 0.5; d[0][1] = 0.7; d[1][0] = 0.7; d[1][1] = 0.5;
		wait();
		break;
	case 2:exit(0);
		break;
	}
}

void about(void)
{
	const char* about = "\t\t\tMATCH IS DRAWN !\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nQ = QUIT   ENTER = RESTART";
	void* en = GLUT_BITMAP_TIMES_ROMAN_24;
	int i;
	float x = -0.4, y = 0.3, z = 0;

	in_about = 1;

	glPushMatrix();
	glLoadIdentity();

	glColor3f(0.9, 0.7, 0.6);
	glRasterPos3f(x, y, z);

	for (i = 0; about[i] != '\0'; i++)
	{
		if (about[i] == '\n')
		{
			y -= 0.08;
			glRasterPos3f(x, y, z);
		}
		if (about[i] == '\t')
		{
			x -= 0.03;
		}
		else
		{
			wait();
			glutBitmapCharacter(en, about[i]);
		}
	}
	glPopMatrix();
	glFlush();
	enter = 1;
}

void about1(void)
{
	const char* about = "\t\t\tCONGRATULATIONS  !\n\n\nPLAYER  1  WON  THE  GAME.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nQ = QUIT   ENTER = RESTART";
	void* en = GLUT_BITMAP_TIMES_ROMAN_24;
	int i;
	float x = -0.4, y = 0.6, z = 0;

	in_about = 1;

	glPushMatrix();
	glLoadIdentity();

	glColor3f(0.9, 0.7, 0.6);
	glRasterPos3f(x, y, z);

	for (i = 0; about[i] != '\0'; i++)
	{
		if (about[i] == '\n')
		{
			y -= 0.08;
			glRasterPos3f(x, y, z);
		}
		if (about[i] == '\t')
		{
			x -= 0.03;
		}
		else
		{
			wait();
			glutBitmapCharacter(en, about[i]);
		}
	}
	glPopMatrix();
	glFlush();
	enter = 1;
}

void about2(void)
{
	const char* about = "\t\t\tCONGRATULATIONS  !\n\n\nPLAYER  2  WON  THE  GAME.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nQ = QUIT   ENTER = RESTART";
	void* en = GLUT_BITMAP_TIMES_ROMAN_24;
	int i;
	float x = -0.4, y = 0.6, z = 0;

	in_about = 1;

	glPushMatrix();
	glLoadIdentity();

	glColor3f(0.9, 0.7, 0.6);
	glRasterPos3f(x, y, z);

	for (i = 0; about[i] != '\0'; i++)
	{
		if (about[i] == '\n')
		{
			y -= 0.08;
			glRasterPos3f(x, y, z);
		}
		if (about[i] == '\t')
		{
			x -= 0.03;
		}
		else
		{
			wait();
			glutBitmapCharacter(en, about[i]);
		}
	}
	glPopMatrix();
	glFlush();
	enter = 1;
}

void check_cond()
{
	if ((k1 > 27 && p1 == 0) && (k2 > 27 && p1 == 0) && (l1 > 27 && p2 == 0) && (l2 > 27 && p2 == 0))
	{
		dice1 = 0;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glFlush();
		about();

	}

	else if (s1 == 2)
	{
		dice1 = 0;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glFlush();
		about1();
	}



	else if (s2 == 2)
	{
		dice1 = 0;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glFlush();
		about2();
	}
}

void circle()
{
	float ang;
	int i;
	glPushMatrix();
	glLoadIdentity();


	glTranslatef(-1.47, 0.72, 0);
	if (ply1 == 1 && ply2 == 0)
	{
		glColor3f(1, 0, 0);
	}
	else
	{
		glColor3f(0, 0, 0);
	}
	glBegin(GL_POLYGON);
	for (i = 0; i <= 12; i++)
	{
		ang = (3.1415 / 6) * i;
		glVertex2f(0.02 * cos(ang), 0.02 * sin(ang));
	}
	glEnd();
	glColor3f(0, 1, 0);
	glFlush();
	glPopMatrix();
	glFlush();

	glPushMatrix();
	glLoadIdentity();

	glTranslatef(-1.47, 0.56, 0);
	if (ply1 == 0 && ply2 == 1)
	{
		glColor3f(1, 0, 0);
	}
	else
	{
		glColor3f(0, 0, 0);
	}
	glBegin(GL_POLYGON);
	for (i = 0; i <= 12; i++)
	{
		ang = (3.1415 / 6) * i;
		glVertex2f(0.02 * cos(ang), 0.02 * sin(ang));
	}
	glEnd();
	glColor3f(0, 1, 0);
	glFlush();
	glPopMatrix();
	glFlush();
}

void display2()
{
 //Bottom direction
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.15, -0.84);          
	glVertex2f(0, -0.84);
	glVertex2f(0, -0.6);

	glEnd();
	glFlush();


	glBegin(GL_LINES);
	glVertex2f(0, -0.6);
	glVertex2f(-0.04, -0.64);
	glVertex2f(0, -0.6);
	glVertex2f(0.04, -0.64);
	glEnd();


	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.15, 0.84);           //Top direction
	glVertex2f(0, 0.84);
	glVertex2f(0, 0.6);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glVertex2f(0, 0.6);
	glVertex2f(-0.04, 0.64);
	glVertex2f(0, 0.6);
	glVertex2f(0.04, 0.64);
	glEnd();
	glPointSize(25);
	glBegin(GL_POINTS);
	glColor3f(0, 1, 0);
	glVertex2f(c[0][0], c[0][1]);
	glVertex2f(c[1][0], c[1][1]);
	glColor3f(1, 0, 1);
	glVertex2f(d[0][0], d[0][1]);
	glVertex2f(d[1][0], d[1][1]);
	glEnd();
	glColor3f(0, 1, 0);
	glFlush();
	circle();
	check_cond();

}


void player1(int ch)
{
	GLint rand();


	if ((f1 == 0) && (h1 == 0))
	{
		glBegin(GL_POINTS);
		glVertex2f(c[0][0], c[0][1]);
		glEnd();
		glFlush();
	}
	else if (h1 == 1)
	{
		glBegin(GL_POINTS);
		glVertex2f(0.7, -0.5);
		glEnd();
	}
	else
	{
		glBegin(GL_POINTS);
		glVertex2f(a[k1][0], a[k1][1]);
		glEnd();

	}

	if ((f2 == 0) && (h2 == 0))
	{
		glBegin(GL_POINTS);
		glVertex2f(c[1][0], c[1][1]);

		glEnd();
	}
	else if (h2 == 1)
	{
		glBegin(GL_POINTS);
		glVertex2f(0.5, -0.7);
		glEnd();
	}
	else
	{
		glBegin(GL_POINTS);
		glVertex2f(a[k2][0], a[k2][1]);
		glEnd();
	}


	glColor3f(0, 1, 0);


	if (h1 == 1)
		ch = 2;
	else if (h2 == 1)
		ch = 1;
	else if (((ra1 + k1 > 57) || (ra1 + k1 > 51 && p1 == 0)) && ((ra1 + k2 > 57) || (ra1 + k2 > 51 && p1 == 0)))
	{
		ply1 = 0;
		ply2 = 1;

	}
	else if ((ra1 + k1 > 57 && ch == 1) || (ra1 + k1 > 51 && p1 == 0 && ch == 1))
	{
		if (a[ra1 + k2][0] == c[0][0] && a[ra1 + k2][1] == c[0][1])
			ch = 776;
		else
		{
			ch = 2;
		}
	}
	else if ((ra1 + k2 > 57 && ch == 2) || (ra1 + k2 > 51 && p1 == 0 && ch == 2))
	{
		if (a[ra1 + k1][0] == c[1][0] && a[ra1 + k1][1] == c[1][1])
			ch = 776;
		else
		{
			ch = 1;
		}
	}

	if (ch == 1 && a[ra1 + k1][0] == c[1][0] && a[ra1 + k1][1] == c[1][1])
	{
		display2();
		return;
	}
	else if (ch == 2 && a[ra1 + k2][0] == c[0][0] && a[ra1 + k2][1] == c[0][1])
	{
		display2();
		return;
	}


	switch (ch)
	{
	case 1:
		if (f1 == 0 && (ra1 == 6 || ra1 == 1))                    //y==4;
		{
			ra1 = 1;
			f1 = 1;

		}

		else
		{
			z = 1;
			z1 = 0;
			ply1 = 0; ply2 = 1;

		}




		if ((f1 == 1) && (ra1 + k1 <= 57) && (h1 == 0))
		{
			for (i = 0; i < 2; i++)
			{
				if (a[ra1 + k1][0] == d[i][0] && a[ra1 + k1][1] == d[i][1])
				{
					if (i == 0) { g1 = 0; l1 = 0; d[0][0] = 0.5; d[0][1] = 0.7; }
					if (i == 1) { g2 = 0; l2 = 0; d[1][0] = 0.7; d[1][1] = 0.5; }
					p1 = 1;

				}
			}


			if (((ra1 + k1) > 51 && p1 == 1) || (ra1 + k1 <= 51))
			{
				glColor3f(0, 0, 0);
				if (k1 == 0)
				{
					glBegin(GL_POINTS);
					glVertex2f(-0.5, -0.7);
					glEnd();
				}
				else if (k1 == 1 || k1 == 52 || k1 == 53 || k1 == 54 || k1 == 55 || k1 == 56)
				{
					glColor3f(1, 0, 0);
				}
				else if (k1 == 27)
				{
					glColor3f(0, 0, 1);
				}
				glBegin(GL_POINTS);
				glVertex2f(a[k1][0], a[k1][1]);
				glEnd();
				glColor3f(0, 1, 0);

				k1 = ra1 + k1;
				z = 1;

				c[0][0] = a[k1][0];
				c[0][1] = a[k1][1];
				if (ra1 == 6)
				{
					z1 = 0;
					ply1 = 1;
					ply2 = 0;
				}
				else
				{
					ply1 = 0;
					ply2 = 1;
				}

			}

		}ch = 0;

		if (k1 == 57)
		{
			k1 = 0;
			h1 = 1;
			glBegin(GL_POINTS);
			c[0][0] = 0.7; c[0][1] = -0.5;
			glVertex2f(c[0][0], c[0][1]);
			s1++;
			glEnd();
		}


		break;

	case 2:if (f2 == 0 && (ra1 == 6 || ra1 == 1))
	{
		ra1 = 1;
		f2 = 1;
	}

		  else
	{
		z = 1;
		z1 = 0;
		ply1 = 0; ply2 = 1;
	}

		  if ((f2 == 1) && (ra1 + k2 <= 57) && (h2 == 0))
		  {
			  for (i = 0; i < 2; i++)
			  {
				  if (a[ra1 + k2][0] == d[i][0] && a[ra1 + k2][1] == d[i][1])
				  {
					  if (i == 0) { g1 = 0; l1 = 0; d[0][0] = 0.5; d[0][1] = 0.7; }
					  if (i == 1) { g2 = 0; l2 = 0; d[1][0] = 0.7; d[1][1] = 0.5; }
					  p1 = 1;

				  }
			  }


			  if (((ra1 + k2) > 51 && p1 == 1) || (ra1 + k2 <= 51))
			  {
				  glColor3f(0, 0, 0);
				  if (k2 == 0)
				  {
					  glBegin(GL_POINTS);
					  glVertex2f(-0.7, -0.5);
					  glEnd();
				  }
				  else if (k2 == 1 || k2 == 52 || k2 == 53 || k2 == 54 || k2 == 55 || k2 == 56)
				  {
					  glColor3f(1, 0, 0);
				  }
				  else if (k2 == 27)
				  {
					  glColor3f(0, 0, 1);
				  }
				  glBegin(GL_POINTS);
				  glVertex2f(a[k2][0], a[k2][1]);
				  glEnd();
				  glColor3f(0, 1, 0);
				  k2 = ra1 + k2;
				  z = 1;
				  c[1][0] = a[k2][0];
				  c[1][1] = a[k2][1];
				  if (ra1 == 6)
				  {
					  z1 = 0;
					  ply1 = 1;
					  ply2 = 0;
				  }
				  else
				  {
					  ply1 = 0;
					  ply2 = 1;
				  }


			  }
		  }

		  if (k2 == 57)
		  {
			  k2 = 0;
			  h2 = 1;
			  c[1][0] = 0.5; c[1][1] = -0.7;
			  s1++;
		  }
		  break;
	case 776:ply1 = 0; ply2 = 1;
		break;




	}ch = 0;
	glColor3f(1, 0, 1);
	arrow();
	display2();

}


void player2(int ch1)
{

	glColor3f(1, 0, 1);
	if ((g1 == 0) && (h3 == 0))
	{
		glBegin(GL_POINTS);
		glVertex2f(d[0][0], d[0][1]);
		glEnd();
	}
	else if (h3 == 1)
	{
		glBegin(GL_POINTS);
		glVertex2f(-0.7, 0.5);
		glEnd();
	}
	else
	{
		glBegin(GL_POINTS);
		glVertex2f(b[l1][0], b[l1][1]);
		glEnd();
	}

	if ((g2 == 0) && (h4 == 0))
	{
		glBegin(GL_POINTS);
		glVertex2f(d[1][0], d[1][1]);
		glEnd();
	}
	else if (h4 == 1)
	{
		glBegin(GL_POINTS);
		glVertex2f(-0.5, 0.7);
		glEnd();
	}
	else
	{
		glBegin(GL_POINTS);
		glVertex2f(b[l2][0], b[l2][1]);
		glEnd();
	}
