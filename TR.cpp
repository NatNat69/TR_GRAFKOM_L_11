#include <gl/glut.h>
#include <windows.h> 

void inisial(void);
void tampilkuy(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void size(int, int);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

bool mouseDown = false;
int is_depth;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1300, 600);
	glutInitWindowPosition(30, 75);
	glutCreateWindow("TR KELOMPOK 11 | KELAS GRAFIKA KOMPUTER L");
	inisial();
	glutDisplayFunc(tampilkuy);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutReshapeFunc(size);
	glutMainLoop();
	return 0;
}

void inisial(void)
{
	glClearColor(0.1, 1.1, 1.1, 1.1);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(20.0);
	glLineWidth(4.0f);
}


void lapangan()
{
	glBegin(GL_QUADS);
	glColor3f(0.1, 1.1, 0.1);//////////////lapangan 
	glVertex3f(-350.0, -20.0, 150.0);
	glVertex3f(-350.0, -20.0, -150.0);
	glVertex3f(350.0, -20.0, -150.0);
	glVertex3f(350.0, -20.0, 150.0);





	glColor3f(1.0, 1.0, 1.0);/////////////Garis lapangan kiri
	glVertex3f(-350.0, -19.0, 150.0);
	glVertex3f(-350.0, -19.0, -150.0);
	glVertex3f(-345.0, -19.0, -150.0);
	glVertex3f(-345.0, -19.0, 150.0);
	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis lapangan atas
	glVertex3f(-350.0, -19.0, -145.0);
	glVertex3f(-350.0, -19.0, -150.0);
	glVertex3f(350.0, -19.0, -150.0);
	glVertex3f(350.0, -19.0, -145.0);
	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis lapangan bawah
	glVertex3f(-350.0, -19.0, 150.0);
	glVertex3f(-350.0, -19.0, 145.0);
	glVertex3f(350.0, -19.0, 145.0);
	glVertex3f(350.0, -19.0, 150.0);
	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis lapangan kanan
	glVertex3f(345.0, -19.0, 150.0);
	glVertex3f(345.0, -19.0, -150.0);
	glVertex3f(350.0, -19.0, -150.0);
	glVertex3f(350.0, -19.0, 150.0);
	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis lapangan tengah
	glVertex3f(-2.0, -19.0, 150.0);
	glVertex3f(-2.0, -19.0, -150.0);
	glVertex3f(2.0, -19.0, -150.0);
	glVertex3f(2.0, -19.0, 150.0);
	
	
	
	
	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan depan------------------//
	glVertex3f(295.0, -19.0, 45.0);													//
	glVertex3f(295.0, -19.0, -45.0);												//
	glVertex3f(290.0, -19.0, -45.0);												//
	glVertex3f(290.0, -19.0, 45.0);													//
																					//	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan bawah					//
	glVertex3f(290.0, -19.0, 40.0);													//
	glVertex3f(290.0, -19.0, 45.0);													//----- Garasi dalam kanan 	
	glVertex3f(350.0, -19.0, 45.0);													//
	glVertex3f(350.0, -19.0, 40.0);													//		
																					//
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan atas					//
	glVertex3f(295.0, -19.0, -45.0);												//
	glVertex3f(295.0, -19.0, -40.0);												//
	glVertex3f(350.0, -19.0, -40.0);												//	
	glVertex3f(350.0, -19.0, -45.0);//----------------------------------------------//													
	
	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan depan------------------//
	glVertex3f(230.0, -19.0, 90.0);													//
	glVertex3f(230.0, -19.0, -90.0);												//
	glVertex3f(225.0, -19.0, -90.0);												//
	glVertex3f(225.0, -19.0, 90.0);													//
																					//	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan bawah					//
	glVertex3f(225.0, -19.0, 85.0);													//
	glVertex3f(225.0, -19.0, 90.0);													//----- Garasi luar kanan	
	glVertex3f(350.0, -19.0, 90.0);													//
	glVertex3f(350.0, -19.0, 85.0);													//
																					//
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan atas					//
	glVertex3f(225.0, -19.0, -85.0);												//
	glVertex3f(225.0, -19.0, -90.0);												//
	glVertex3f(350.0, -19.0, -90.0);												//	
	glVertex3f(350.0, -19.0, -85.0);//----------------------------------------------//	
	
	
	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan depan------------------//
	glVertex3f(-295.0, -19.0, 45.0);												//
	glVertex3f(-295.0, -19.0, -45.0);												//
	glVertex3f(-290.0, -19.0, -45.0);												//
	glVertex3f(-290.0, -19.0, 45.0);												//
																					//	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan bawah					//
	glVertex3f(-290.0, -19.0, 40.0);												//
	glVertex3f(-290.0, -19.0, 45.0);												//----- Garasi dalam kiri
	glVertex3f(-350.0, -19.0, 45.0);												//
	glVertex3f(-350.0, -19.0, 40.0);												//		
																					//
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan atas					//
	glVertex3f(-295.0, -19.0, -45.0);												//
	glVertex3f(-295.0, -19.0, -40.0);												//
	glVertex3f(-350.0, -19.0, -40.0);												//	
	glVertex3f(-350.0, -19.0, -45.0);//----------------------------------------------//													
	
	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan depan------------------//
	glVertex3f(-230.0, -19.0, 90.0);												//
	glVertex3f(-230.0, -19.0, -90.0);												//
	glVertex3f(-225.0, -19.0, -90.0);												//
	glVertex3f(-225.0, -19.0, 90.0);												//
																					//	
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan bawah					//
	glVertex3f(-225.0, -19.0, 85.0);												//
	glVertex3f(-225.0, -19.0, 90.0);												//----- Garasi luar kiri	
	glVertex3f(-350.0, -19.0, 90.0);												//
	glVertex3f(-350.0, -19.0, 85.0);												//
																					//
	glColor3f(1.0, 1.0, 1.0);/////////////Garis Gawang kanan atas					//
	glVertex3f(-225.0, -19.0, -85.0);												//
	glVertex3f(-225.0, -19.0, -90.0);												//
	glVertex3f(-350.0, -19.0, -90.0);												//	
	glVertex3f(-350.0, -19.0, -85.0);//----------------------------------------------//	
	
	
	glEnd();
}


void bangku()
{
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 0.8);///////////////////////////////////dasar bangku depan
	glVertex3f(-350.0, -20.0, -200.0);
	glVertex3f(-350.0, -20.0, -400.0);
	glVertex3f(350.0, -20.0, -400.0);
	glVertex3f(350.0, -20.0, -200.0);
	
	glVertex3f(-350.0, -20.0, -200.0);/////samping kiri 1
	glVertex3f(-350.0, -20.0, -250.0);
	glVertex3f(-350.0, 30.0, -250.0);
	glVertex3f(-350.0, 30.0, -200.0);

	glVertex3f(350.0, -20.0, -200.0);/////samping kanan 1
	glVertex3f(350.0, -20.0, -250.0);
	glVertex3f(350.0, 30.0, -250.0);
	glVertex3f(350.0, 30.0, -200.0);
	
	glVertex3f(-350.0, -20.0, -200.0);/////depan 1
	glVertex3f(-350.0, 30.0, -200.0);
	glVertex3f(350.0, 30.0, -200.0);
	glVertex3f(350.0, -20.0, -200.0);

	glColor3f(1.1, 0.0, 0.0);//////////////atas 1
	glVertex3f(-350.0, 30.0, -200.0);
	glVertex3f(-350.0, 30.0, -250.0);
	glVertex3f(350.0, 30.0, -250.0);
	glVertex3f(350.0, 30.0, -200.0);
	
	
	
	
	glColor3f(0.8, 0.8, 0.8);/////samping kiri 2
	glVertex3f(-350.0, -20.0, -300.0);
	glVertex3f(-350.0, -20.0, -250.0);
	glVertex3f(-350.0, 50.0, -250.0);
	glVertex3f(-350.0, 50.0, -300.0);
	
	glVertex3f(350.0, -20.0, -300.0);/////samping kanan 2
	glVertex3f(350.0, -20.0, -250.0);
	glVertex3f(350.0, 50.0, -250.0);
	glVertex3f(350.0, 50.0, -300.0);
	
	glColor3f(1.1, 0.1, 0.1);/////depan 2
	glVertex3f(-350.0, -20.0, -250.0);
	glVertex3f(-350.0, 50.0, -250.0);
	glVertex3f(350.0, 50.0, -250.0);
	glVertex3f(350.0, -20.0, -250.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 1 & 2
	glVertex3f(-350.0, 30.5, -245.0);
	glVertex3f(-350.0, 30.5, -250.0);
	glVertex3f(350.0, 30.5, -250.0);
	glVertex3f(350.0, 30.5, -245.0);
	
	glColor3f(1.1, 0.0, 0.0);//////////////atas 2
	glVertex3f(-350.0, 50.0, -300.0);
	glVertex3f(-350.0, 50.0, -250.0);
	glVertex3f(350.0, 50.0, -250.0);
	glVertex3f(350.0, 50.0, -300.0);
	
	
	
	
	glColor3f(0.8, 0.8, 0.8);/////samping kiri 3
	glVertex3f(-350.0, -20.0, -350.0);
	glVertex3f(-350.0, -20.0, -300.0);
	glVertex3f(-350.0, 70.0, -300.0);
	glVertex3f(-350.0, 70.0, -350.0);
	
	glColor3f(0.8, 0.8, 0.8);/////samping kanan 3
	glVertex3f(350.0, -20.0, -350.0);
	glVertex3f(350.0, -20.0, -300.0);
	glVertex3f(350.0, 70.0, -300.0);
	glVertex3f(350.0, 70.0, -350.0);
	
	glColor3f(1.1, 0.1, 0.1);/////depan 3
	glVertex3f(-350.0, -20.0, -300.0);
	glVertex3f(-350.0, 70.0, -300.0);
	glVertex3f(350.0, 70.0, -300.0);
	glVertex3f(350.0, -20.0, -300.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 2 & 3
	glVertex3f(-350.0, 50.5, -295.0);
	glVertex3f(-350.0, 50.5, -300.0);
	glVertex3f(350.0, 50.5, -300.0);
	glVertex3f(350.0, 50.5, -295.0);
	
	glColor3f(1.1, 0.0, 0.0);//////////////atas 3
	glVertex3f(-350.0, 70.0, -350.0);
	glVertex3f(-350.0, 70.0, -300.0);
	glVertex3f(350.0, 70.0, -300.0);
	glVertex3f(350.0, 70.0, -350.0);
	
	
	
	
	glColor3f(0.8, 0.8, 0.8);/////samping kiri 4
	glVertex3f(-350.0, -20.0, -400.0);
	glVertex3f(-350.0, -20.0, -350.0);
	glVertex3f(-350.0, 90.0, -350.0);
	glVertex3f(-350.0, 90.0, -400.0);
	
	glColor3f(0.8, 0.8, 0.8);/////samping kanan 4
	glVertex3f(350.0, -20.0, -400.0);
	glVertex3f(350.0, -20.0, -350.0);
	glVertex3f(350.0, 90.0, -350.0);
	glVertex3f(350.0, 90.0, -400.0);
	
	glColor3f(1.1, 0.1, 0.1);/////depan 4
	glVertex3f(-350.0, -20.0, -350.0);
	glVertex3f(-350.0, 90.0, -350.0);
	glVertex3f(350.0, 90.0, -350.0);
	glVertex3f(350.0, -20.0, -350.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 2 & 3
	glVertex3f(-350.0, 70.5, -345.0);
	glVertex3f(-350.0, 70.5, -350.0);
	glVertex3f(350.0, 70.5, -350.0);
	glVertex3f(350.0, 70.5, -345.0);
	
	glColor3f(1.1, 0.0, 0.0);//////////////atas 4
	glVertex3f(-350.0, 90.0, -400.0);
	glVertex3f(-350.0, 90.0, -350.0);
	glVertex3f(350.0, 90.0, -350.0);
	glVertex3f(350.0, 90.0, -400.0);
	
	glColor3f(0.8, 0.8, 0.8);///// belakang 4
	glVertex3f(-350.0, -20.0, -400.0);
	glVertex3f(-350.0, 90.0, -400.0);
	glVertex3f(350.0, 90.0, -400.0);
	glVertex3f(350.0, -20.0, -400.0);
	
	
	
	
	
	
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 0.8);/////////////////////////////////////dasar bangku kiri
	glVertex3f(-400.0, -20.0, 150.0);
	glVertex3f(-400.0, -20.0, -150.0);
	glVertex3f(-600.0, -20.0, -150.0);
	glVertex3f(-600.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kiri 1
	glVertex3f(-400.0, -20.0, 150.0);
	glVertex3f(-400.0, 30.0, 150.0);
	glVertex3f(-450.0, 30.0, 150.0);
	glVertex3f(-450.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kanan 1
	glVertex3f(-400.0, -20.0, -150.0);
	glVertex3f(-400.0, 30.0, -150.0);
	glVertex3f(-450.0, 30.0, -150.0);
	glVertex3f(-450.0, -20.0, -150.0);
	
	glColor3f(0.8, 0.8, 0.8);////////////// depan 1
	glVertex3f(-400.0, -20.0, 150.0);
	glVertex3f(-400.0, -20.0, -150.0);
	glVertex3f(-400.0, 30.0, -150.0);
	glVertex3f(-400.0, 30.0, 150.0);
	
	glColor3f(1.1, 0.0, 0.0);///////////// atas 1
	glVertex3f(-400.0, 30.0, 150.0);
	glVertex3f(-400.0, 30.0, -150.0);
	glVertex3f(-450.0, 30.0, -150.0);
	glVertex3f(-450.0, 30.0, 150.0);
	
	
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kiri 2
	glVertex3f(-450.0, -20.0, 150.0);
	glVertex3f(-450.0, 50.0, 150.0);
	glVertex3f(-500.0, 50.0, 150.0);
	glVertex3f(-500.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kanan 2
	glVertex3f(-450.0, -20.0, -150.0);
	glVertex3f(-450.0, 50.0, -150.0);
	glVertex3f(-500.0, 50.0, -150.0);
	glVertex3f(-500.0, -20.0, -150.0);
	
	glColor3f(1.1, 0.1, 0.1);////////////// depan 2
	glVertex3f(-450.0, 50.0, 150.0);
	glVertex3f(-450.0, 50.0, -150.0);
	glVertex3f(-450.0, -20.0, -150.0);
	glVertex3f(-450.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 1 & 2
	glVertex3f(-445.0, 30.5, 150.0);
	glVertex3f(-445.0, 30.5, -150.0);
	glVertex3f(-450.0, 30.5, -150.0);
	glVertex3f(-450.0, 30.5, 150.0);
	
	glColor3f(1.1, 0.0, 0.0);///////////// atas 2
	glVertex3f(-450.0, 50.0, 150.0);
	glVertex3f(-450.0, 50.0, -150.0);
	glVertex3f(-500.0, 50.0, -150.0);
	glVertex3f(-500.0, 50.0, 150.0);
	
	
	
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kiri 3
	glVertex3f(-500.0, -20.0, 150.0);
	glVertex3f(-500.0, 70.0, 150.0);
	glVertex3f(-550.0, 70.0, 150.0);
	glVertex3f(-550.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kanan 3
	glVertex3f(-500.0, -20.0, -150.0);
	glVertex3f(-500.0, 70.0, -150.0);
	glVertex3f(-550.0, 70.0, -150.0);
	glVertex3f(-550.0, -20.0, -150.0);
	
	glColor3f(1.1, 0.1, 0.1);////////////// depan 3
	glVertex3f(-500.0, 70.0, 150.0);
	glVertex3f(-500.0, 70.0, -150.0);
	glVertex3f(-500.0, -20.0, -150.0);
	glVertex3f(-500.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 2 & 3
	glVertex3f(-495.0, 50.5, 150.0);
	glVertex3f(-495.0, 50.5, -150.0);
	glVertex3f(-500.0, 50.5, -150.0);
	glVertex3f(-500.0, 50.5, 150.0);
	
	glColor3f(1.1, 0.0, 0.0);///////////// atas 3
	glVertex3f(-500.0, 70.0, 150.0);
	glVertex3f(-500.0, 70.0, -150.0);
	glVertex3f(-550.0, 70.0, -150.0);
	glVertex3f(-550.0, 70.0, 150.0);
	
	
	
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kiri 4
	glVertex3f(-550.0, -20.0, 150.0);
	glVertex3f(-550.0, 90.0, 150.0);
	glVertex3f(-600.0, 90.0, 150.0);
	glVertex3f(-600.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kanan 4
	glVertex3f(-550.0, -20.0, -150.0);
	glVertex3f(-550.0, 90.0, -150.0);
	glVertex3f(-600.0, 90.0, -150.0);
	glVertex3f(-600.0, -20.0, -150.0);
	
	glColor3f(1.1, 0.1, 0.1);////////////// depan 4
	glVertex3f(-550.0, 90.0, 150.0);
	glVertex3f(-550.0, 90.0, -150.0);
	glVertex3f(-550.0, -20.0, -150.0);
	glVertex3f(-550.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 3 & 4
	glVertex3f(-545.0, 70.5, 150.0);
	glVertex3f(-545.0, 70.5, -150.0);
	glVertex3f(-550.0, 70.5, -150.0);
	glVertex3f(-550.0, 70.5, 150.0);
	
	glColor3f(1.1, 0.0, 0.0);///////////// atas 4
	glVertex3f(-550.0, 90.0, 150.0);
	glVertex3f(-550.0, 90.0, -150.0);
	glVertex3f(-600.0, 90.0, -150.0);
	glVertex3f(-600.0, 90.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);////////////// belakang 4
	glVertex3f(-600.0, 90.0, 150.0);
	glVertex3f(-600.0, 90.0, -150.0);
	glVertex3f(-600.0, -20.0, -150.0);
	glVertex3f(-600.0,-20.0, 150.0);
	
	
	
	
	
	
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 0.8);//////////////dasar bangku kanan
	glVertex3f(400.0, -20.0, 150.0);
	glVertex3f(400.0, -20.0, -150.0);
	glVertex3f(600.0, -20.0, -150.0);
	glVertex3f(600.0, -20.0, 150.0);
	
		glColor3f(0.8, 0.8, 0.8);//////////////samping kiri 1
	glVertex3f(400.0, -20.0, 150.0);
	glVertex3f(400.0, 30.0, 150.0);
	glVertex3f(450.0, 30.0, 150.0);
	glVertex3f(450.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kanan 1
	glVertex3f(400.0, -20.0, -150.0);
	glVertex3f(400.0, 30.0, -150.0);
	glVertex3f(450.0, 30.0, -150.0);
	glVertex3f(450.0, -20.0, -150.0);
	
	glColor3f(0.8, 0.8, 0.8);////////////// depan 1
	glVertex3f(400.0, -20.0, 150.0);
	glVertex3f(400.0, -20.0, -150.0);
	glVertex3f(400.0, 30.0, -150.0);
	glVertex3f(400.0, 30.0, 150.0);
	
	glColor3f(1.1, 0.0, 0.0);///////////// atas 1
	glVertex3f(400.0, 30.0, 150.0);
	glVertex3f(400.0, 30.0, -150.0);
	glVertex3f(450.0, 30.0, -150.0);
	glVertex3f(450.0, 30.0, 150.0);
	
	
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kiri 2
	glVertex3f(450.0, -20.0, 150.0);
	glVertex3f(450.0, 50.0, 150.0);
	glVertex3f(500.0, 50.0, 150.0);
	glVertex3f(500.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kanan 2
	glVertex3f(450.0, -20.0, -150.0);
	glVertex3f(450.0, 50.0, -150.0);
	glVertex3f(500.0, 50.0, -150.0);
	glVertex3f(500.0, -20.0, -150.0);
	
	glColor3f(1.1, 0.1, 0.1);////////////// depan 2
	glVertex3f(450.0, 50.0, 150.0);
	glVertex3f(450.0, 50.0, -150.0);
	glVertex3f(450.0, -20.0, -150.0);
	glVertex3f(450.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 1 & 2
	glVertex3f(445.0, 30.5, 150.0);
	glVertex3f(445.0, 30.5, -150.0);
	glVertex3f(450.0, 30.5, -150.0);
	glVertex3f(450.0, 30.5, 150.0);
	
	glColor3f(1.1, 0.0, 0.0);///////////// atas 2
	glVertex3f(450.0, 50.0, 150.0);
	glVertex3f(450.0, 50.0, -150.0);
	glVertex3f(500.0, 50.0, -150.0);
	glVertex3f(500.0, 50.0, 150.0);
	
	
	
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kiri 3
	glVertex3f(500.0, -20.0, 150.0);
	glVertex3f(500.0, 70.0, 150.0);
	glVertex3f(550.0, 70.0, 150.0);
	glVertex3f(550.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kanan 3
	glVertex3f(500.0, -20.0, -150.0);
	glVertex3f(500.0, 70.0, -150.0);
	glVertex3f(550.0, 70.0, -150.0);
	glVertex3f(550.0, -20.0, -150.0);
	
	glColor3f(1.1, 0.1, 0.1);////////////// depan 3
	glVertex3f(500.0, 70.0, 150.0);
	glVertex3f(500.0, 70.0, -150.0);
	glVertex3f(500.0, -20.0, -150.0);
	glVertex3f(500.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 2 & 3
	glVertex3f(495.0, 50.5, 150.0);
	glVertex3f(495.0, 50.5, -150.0);
	glVertex3f(500.0, 50.5, -150.0);
	glVertex3f(500.0, 50.5, 150.0);
	
	glColor3f(1.1, 0.0, 0.0);///////////// atas 3
	glVertex3f(500.0, 70.0, 150.0);
	glVertex3f(500.0, 70.0, -150.0);
	glVertex3f(550.0, 70.0, -150.0);
	glVertex3f(550.0, 70.0, 150.0);
	
	
	
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kiri 4
	glVertex3f(550.0, -20.0, 150.0);
	glVertex3f(550.0, 90.0, 150.0);
	glVertex3f(600.0, 90.0, 150.0);
	glVertex3f(600.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////samping kanan 4
	glVertex3f(550.0, -20.0, -150.0);
	glVertex3f(550.0, 90.0, -150.0);
	glVertex3f(600.0, 90.0, -150.0);
	glVertex3f(600.0, -20.0, -150.0);
	
	glColor3f(1.1, 0.1, 0.1);////////////// depan 4
	glVertex3f(550.0, 90.0, 150.0);
	glVertex3f(550.0, 90.0, -150.0);
	glVertex3f(550.0, -20.0, -150.0);
	glVertex3f(550.0, -20.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 3 & 4
	glVertex3f(545.0, 70.5, 150.0);
	glVertex3f(545.0, 70.5, -150.0);
	glVertex3f(550.0, 70.5, -150.0);
	glVertex3f(550.0, 70.5, 150.0);
	
	glColor3f(1.1, 0.0, 0.0);///////////// atas 4
	glVertex3f(550.0, 90.0, 150.0);
	glVertex3f(550.0, 90.0, -150.0);
	glVertex3f(600.0, 90.0, -150.0);
	glVertex3f(600.0, 90.0, 150.0);
	
	glColor3f(0.8, 0.8, 0.8);////////////// belakang 4
	glVertex3f(600.0, 90.0, 150.0);
	glVertex3f(600.0, 90.0, -150.0);
	glVertex3f(600.0, -20.0, -150.0);
	glVertex3f(600.0,-20.0, 150.0);
	
	
	
	
	
	
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 0.8);///////////////////////////////////dasar bangku belakang
	glVertex3f(-350.0, -20.0, 200.0);
	glVertex3f(-350.0, -20.0, 400.0);
	glVertex3f(350.0, -20.0, 400.0);
	glVertex3f(350.0, -20.0, 200.0);
	
	glVertex3f(-350.0, -20.0, 200.0);/////samping kiri 1
	glVertex3f(-350.0, -20.0, 250.0);
	glVertex3f(-350.0, 30.0, 250.0);
	glVertex3f(-350.0, 30.0, 200.0);

	glVertex3f(350.0, -20.0, 200.0);/////samping kanan 1
	glVertex3f(350.0, -20.0, 250.0);
	glVertex3f(350.0, 30.0, 250.0);
	glVertex3f(350.0, 30.0, 200.0);
	
	glVertex3f(-350.0, -20.0, 200.0);/////depan 1
	glVertex3f(-350.0, 30.0, 200.0);
	glVertex3f(350.0, 30.0, 200.0);
	glVertex3f(350.0, -20.0, 200.0);

	glColor3f(1.1, 0.0, 0.0);//////////////atas 1
	glVertex3f(-350.0, 30.0, 200.0);
	glVertex3f(-350.0, 30.0, 250.0);
	glVertex3f(350.0, 30.0, 250.0);
	glVertex3f(350.0, 30.0, 200.0);
	
	
	
	
	glColor3f(0.8, 0.8, 0.8);/////samping kiri 2
	glVertex3f(-350.0, -20.0, 300.0);
	glVertex3f(-350.0, -20.0, 250.0);
	glVertex3f(-350.0, 50.0, 250.0);
	glVertex3f(-350.0, 50.0, 300.0);
	
	glVertex3f(350.0, -20.0, 300.0);/////samping kanan 2
	glVertex3f(350.0, -20.0, 250.0);
	glVertex3f(350.0, 50.0, 250.0);
	glVertex3f(350.0, 50.0, 300.0);
	
	glColor3f(1.1, 0.1, 0.1);/////depan 2
	glVertex3f(-350.0, -20.0, 250.0);
	glVertex3f(-350.0, 50.0, 250.0);
	glVertex3f(350.0, 50.0, 250.0);
	glVertex3f(350.0, -20.0, 250.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 1 & 2
	glVertex3f(-350.0, 30.5, 245.0);
	glVertex3f(-350.0, 30.5, 250.0);
	glVertex3f(350.0, 30.5, 250.0);
	glVertex3f(350.0, 30.5, 245.0);
	
	glColor3f(1.1, 0.0, 0.0);//////////////atas 2
	glVertex3f(-350.0, 50.0, 300.0);
	glVertex3f(-350.0, 50.0, 250.0);
	glVertex3f(350.0, 50.0, 250.0);
	glVertex3f(350.0, 50.0, 300.0);
	
	
	
	
	glColor3f(0.8, 0.8, 0.8);/////samping kiri 3
	glVertex3f(-350.0, -20.0, 350.0);
	glVertex3f(-350.0, -20.0, 300.0);
	glVertex3f(-350.0, 70.0, 300.0);
	glVertex3f(-350.0, 70.0, 350.0);
	
	glColor3f(0.8, 0.8, 0.8);/////samping kanan 3
	glVertex3f(350.0, -20.0, 350.0);
	glVertex3f(350.0, -20.0, 300.0);
	glVertex3f(350.0, 70.0, 300.0);
	glVertex3f(350.0, 70.0, 350.0);
	
	glColor3f(1.1, 0.1, 0.1);/////depan 3
	glVertex3f(-350.0, -20.0, 300.0);
	glVertex3f(-350.0, 70.0, 300.0);
	glVertex3f(350.0, 70.0, 300.0);
	glVertex3f(350.0, -20.0, 300.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 2 & 3
	glVertex3f(-350.0, 50.5, 295.0);
	glVertex3f(-350.0, 50.5, 300.0);
	glVertex3f(350.0, 50.5, 300.0);
	glVertex3f(350.0, 50.5, 295.0);
	
	glColor3f(1.1, 0.0, 0.0);//////////////atas 3
	glVertex3f(-350.0, 70.0, 350.0);
	glVertex3f(-350.0, 70.0, 300.0);
	glVertex3f(350.0, 70.0, 300.0);
	glVertex3f(350.0, 70.0, 350.0);
	
	
	
	
	glColor3f(0.8, 0.8, 0.8);/////samping kiri 4
	glVertex3f(-350.0, -20.0, 400.0);
	glVertex3f(-350.0, -20.0, 350.0);
	glVertex3f(-350.0, 90.0, 350.0);
	glVertex3f(-350.0, 90.0, 400.0);
	
	glColor3f(0.8, 0.8, 0.8);/////samping kanan 4
	glVertex3f(350.0, -20.0, 400.0);
	glVertex3f(350.0, -20.0, 350.0);
	glVertex3f(350.0, 90.0, 350.0);
	glVertex3f(350.0, 90.0, 400.0);
	
	glColor3f(1.1, 0.1, 0.1);/////depan 4
	glVertex3f(-350.0, -20.0, 350.0);
	glVertex3f(-350.0, 90.0, 350.0);
	glVertex3f(350.0, 90.0, 350.0);
	glVertex3f(350.0, -20.0, 350.0);
	
	glColor3f(0.8, 0.8, 0.8);//////////////garis penghalang bangku 2 & 3
	glVertex3f(-350.0, 70.5, 345.0);
	glVertex3f(-350.0, 70.5, 350.0);
	glVertex3f(350.0, 70.5, 350.0);
	glVertex3f(350.0, 70.5, 345.0);
	
	glColor3f(1.1, 0.0, 0.0);//////////////atas 4
	glVertex3f(-350.0, 90.0, 400.0);
	glVertex3f(-350.0, 90.0, 350.0);
	glVertex3f(350.0, 90.0, 350.0);
	glVertex3f(350.0, 90.0, 400.0);
	
	glColor3f(0.8, 0.8, 0.8);///// belakang 4
	glVertex3f(-350.0, -20.0, 400.0);
	glVertex3f(-350.0, 90.0, 400.0);
	glVertex3f(350.0, 90.0, 400.0);
	glVertex3f(350.0, -20.0, 400.0);
	
	glEnd();
}


void gawang()
{
	glBegin(GL_QUADS);
	glColor3f(1.20, 1.20, 1.20);/////////////////////////tiang gawang kiri				
	glVertex3f(-350.0, 19.0, 40.0);// 1	kiri									
	glVertex3f(-350.0, 19.0, 45.0);										
	glVertex3f(-350.0, -19.0, 45.0);												
	glVertex3f(-350.0, -19.0, 40.0);	

	glVertex3f(-350.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(-350.0, 19.0, 45.0);										
	glVertex3f(-345.0, 19.0, 45.0);												
	glVertex3f(-345.0, -19.0, 45.0);

	glVertex3f(-345.0, 19.0, 40.0);// 1 kanan								
	glVertex3f(-345.0, 19.0, 45.0);										
	glVertex3f(-345.0, -19.0, 45.0);												
	glVertex3f(-345.0, -19.0, 40.0);	

	glVertex3f(-350.0, -19.0, 45.0);// 1 atas										
	glVertex3f(-350.0, 19.0, 45.0);										
	glVertex3f(-350.0, 19.0, 45.0);												
	glVertex3f(-350.0, -19.0, 45.0);
	
	
	
	
	glColor3f(1.20, 1.20, 1.20);		
	glVertex3f(-350.0, 19.0, -45.0);//2	kiri											
	glVertex3f(-350.0, 19.0, -40.0);											
	glVertex3f(-350.0, -19.0, -40.0);										
	glVertex3f(-350.0, -19.0, -45.0);
	
	glVertex3f(-350.0, -19.0, -40.0);// 2 bawah										
	glVertex3f(-350.0, 19.0, -40.0);										
	glVertex3f(-345.0, 19.0, -40.0);												
	glVertex3f(-345.0, -19.0, -40.0);
	
	glVertex3f(-345.0, 19.0, -40.0);// 2 kanan								
	glVertex3f(-345.0, 19.0, -45.0);										
	glVertex3f(-345.0, -19.0, -45.0);												
	glVertex3f(-345.0, -19.0, -40.0);
	
	glVertex3f(-350.0, -19.0, -45.0);// 2 atas										
	glVertex3f(-350.0, 19.0, -45.0);										
	glVertex3f(-350.0, 19.0, -45.0);												
	glVertex3f(-350.0, -19.0, -45.0);
	
	
	
	glVertex3f(-350.0, 19.0, 45.0);//3 atas
	glVertex3f(-350.0, 19.0, -45.0);
	glVertex3f(-345.0, 19.0, -45.0);
	glVertex3f(-345.0, 19.0, 45.0);
	
	glVertex3f(-350.0, 19.0, 45.0);//3 kiri
	glVertex3f(-350.0, 19.0, -45.0);
	glVertex3f(-350.0, 14.0, -45.0);
	glVertex3f(-350.0, 14.0, 45.0);
	
	glVertex3f(-345.0, 19.0, 45.0);//3 kanan
	glVertex3f(-345.0, 19.0, -45.0);
	glVertex3f(-345.0, 14.0, -45.0);
	glVertex3f(-345.0, 14.0, 45.0);
	
	
	
	
	
	
	glBegin(GL_QUADS);
	glColor3f(1.20, 1.20, 1.20);////////////////////////tiang gawang kanan				
	glVertex3f(350.0, 19.0, 40.0);// 1	kiri									
	glVertex3f(350.0, 19.0, 45.0);										
	glVertex3f(350.0, -19.0, 45.0);												
	glVertex3f(350.0, -19.0, 40.0);	

	glVertex3f(350.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(350.0, 19.0, 45.0);										
	glVertex3f(345.0, 19.0, 45.0);												
	glVertex3f(345.0, -19.0, 45.0);

	glVertex3f(345.0, 19.0, 40.0);// 1 kanan								
	glVertex3f(345.0, 19.0, 45.0);										
	glVertex3f(345.0, -19.0, 45.0);												
	glVertex3f(345.0, -19.0, 40.0);	

	glVertex3f(350.0, -19.0, 45.0);// 1 atas										
	glVertex3f(350.0, 19.0, 45.0);										
	glVertex3f(350.0, 19.0, 45.0);												
	glVertex3f(350.0, -19.0, 45.0);
	
	
	
	
	glColor3f(1.20, 1.20, 1.20);		
	glVertex3f(350.0, 19.0, -45.0);//2	kiri											
	glVertex3f(350.0, 19.0, -40.0);											
	glVertex3f(350.0, -19.0, -40.0);										
	glVertex3f(350.0, -19.0, -45.0);
	
	glVertex3f(350.0, -19.0, -40.0);// 2 bawah										
	glVertex3f(350.0, 19.0, -40.0);										
	glVertex3f(345.0, 19.0, -40.0);												
	glVertex3f(345.0, -19.0, -40.0);
	
	glVertex3f(345.0, 19.0, -40.0);// 2 kanan								
	glVertex3f(345.0, 19.0, -45.0);										
	glVertex3f(345.0, -19.0, -45.0);												
	glVertex3f(345.0, -19.0, -40.0);
	
	glVertex3f(350.0, -19.0, -45.0);// 2 atas										
	glVertex3f(350.0, 19.0, -45.0);										
	glVertex3f(350.0, 19.0, -45.0);												
	glVertex3f(350.0, -19.0, -45.0);
	
	
	
	glVertex3f(350.0, 19.0, 45.0);//3 atas
	glVertex3f(350.0, 19.0, -45.0);
	glVertex3f(345.0, 19.0, -45.0);
	glVertex3f(345.0, 19.0, 45.0);
	
	glVertex3f(350.0, 19.0, 45.0);//3 kiri
	glVertex3f(350.0, 19.0, -45.0);
	glVertex3f(350.0, 14.0, -45.0);
	glVertex3f(350.0, 14.0, 45.0);
	
	glVertex3f(345.0, 19.0, 45.0);//3 kanan
	glVertex3f(345.0, 19.0, -45.0);
	glVertex3f(345.0, 14.0, -45.0);
	glVertex3f(345.0, 14.0, 45.0);
	
	
	
	
	
	glEnd();
}

void garissudut()
{
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);/////////////Garis sudut lapangan kiri
	glVertex3f(-330.0, -19.0, 150.0);//1
	glVertex3f(-330.0, -19.0, 135.0);
	glVertex3f(-335.0, -19.0, 135.0);
	glVertex3f(-335.0, -19.0, 150.0);
	
	glVertex3f(-350.0, -19.0, 135.0);//2
	glVertex3f(-350.0, -19.0, 130.0);
	glVertex3f(-335.0, -19.0, 130.0);
	glVertex3f(-335.0, -19.0, 135.0);
	
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);/////////////Garis sudut lapangan kiri
	glVertex3f(-330.0, -19.0, -150.0);//3
	glVertex3f(-330.0, -19.0, -135.0);
	glVertex3f(-335.0, -19.0, -135.0);
	glVertex3f(-335.0, -19.0, -150.0);
	
	glVertex3f(-350.0, -19.0, -135.0);//4
	glVertex3f(-350.0, -19.0, -130.0);
	glVertex3f(-335.0, -19.0, -130.0);
	glVertex3f(-335.0, -19.0, -135.0);
	
	
	
	
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);/////////////Garis sudut lapangan kanan
	glVertex3f(330.0, -19.0, 150.0);//1
	glVertex3f(330.0, -19.0, 135.0);
	glVertex3f(335.0, -19.0, 135.0);
	glVertex3f(335.0, -19.0, 150.0);
	
	glVertex3f(350.0, -19.0, 135.0);//2
	glVertex3f(350.0, -19.0, 130.0);
	glVertex3f(335.0, -19.0, 130.0);
	glVertex3f(335.0, -19.0, 135.0);
	
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);/////////////Garis sudut lapangan kanan
	glVertex3f(330.0, -19.0, -150.0);//3
	glVertex3f(330.0, -19.0, -135.0);
	glVertex3f(335.0, -19.0, -135.0);
	glVertex3f(335.0, -19.0, -150.0);
	
	glVertex3f(350.0, -19.0, -135.0);//4
	glVertex3f(350.0, -19.0, -130.0);
	glVertex3f(335.0, -19.0, -130.0);
	glVertex3f(335.0, -19.0, -135.0);
	glEnd();
}

void jaring()
{
	glBegin(GL_QUADS);
	glColor3f(0.00, 0.00, 0.0);/////////////////////////tiang gawang belakang kiri				
	glVertex3f(-380.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(-380.0, 19.0, 45.0);										
	glVertex3f(-378.0, 19.0, 45.0);												
	glVertex3f(-378.0, -19.0, 45.0);

	glVertex3f(-380.0, -19.0, -45.0);// 2 atas										
	glVertex3f(-380.0, 19.0, -45.0);										
	glVertex3f(-378.0, 19.0, -45.0);												
	glVertex3f(-378.0, -19.0, -45.0);
	


	glVertex3f(-380.0, 19.0, 45.0);//3 atas
	glVertex3f(-380.0, 19.0, -45.0);
	glVertex3f(-378.0, 19.0, -45.0);
	glVertex3f(-378.0, 19.0, 45.0);
	
	glVertex3f(-376.0, 19.0, 45.0);///3 atas
	glVertex3f(-376.0, 19.0, -45.0);
	glVertex3f(-374.0, 19.0, -45.0);
	glVertex3f(-374.0, 19.0, 45.0);
	
	glVertex3f(-372.0, 19.0, 45.0);///3 atas
	glVertex3f(-372.0, 19.0, -45.0);
	glVertex3f(-370.0, 19.0, -45.0);
	glVertex3f(-370.0, 19.0, 45.0);
	
	glVertex3f(-368.0, 19.0, 45.0);///3 atas
	glVertex3f(-368.0, 19.0, -45.0);
	glVertex3f(-366.0, 19.0, -45.0);
	glVertex3f(-366.0, 19.0, 45.0);
	
	glVertex3f(-364.0, 19.0, 45.0);///3 atas
	glVertex3f(-364.0, 19.0, -45.0);
	glVertex3f(-362.0, 19.0, -45.0);
	glVertex3f(-362.0, 19.0, 45.0);
	
	glVertex3f(-360.0, 19.0, 45.0);///3 atas
	glVertex3f(-360.0, 19.0, -45.0);
	glVertex3f(-358.0, 19.0, -45.0);
	glVertex3f(-358.0, 19.0, 45.0);
	
	glVertex3f(-356.0, 19.0, 45.0);///3 atas
	glVertex3f(-356.0, 19.0, -45.0);
	glVertex3f(-354.0, 19.0, -45.0);
	glVertex3f(-354.0, 19.0, 45.0);
	
	
	
	glVertex3f(-380.0, 19.0, 45.0);//3 kiri
	glVertex3f(-380.0, 19.0, -45.0);
	glVertex3f(-380.0, 17.0, -45.0);
	glVertex3f(-380.0, 17.0, 45.0);
	
	glVertex3f(-380.0, 13.0, 45.0);//3 kiri
	glVertex3f(-380.0, 13.0, -45.0);
	glVertex3f(-380.0, 11.0, -45.0);
	glVertex3f(-380.0, 11.0, 45.0);
	
	glVertex3f(-380.0, 7.0, 45.0);//3 kiri
	glVertex3f(-380.0, 7.0, -45.0);
	glVertex3f(-380.0, 5.0, -45.0);
	glVertex3f(-380.0, 5.0, 45.0);
	
	glVertex3f(-380.0, 1.0, 45.0);//3 kiri
	glVertex3f(-380.0, 1.0, -45.0);
	glVertex3f(-380.0, -1.0, -45.0);
	glVertex3f(-380.0, -1.0, 45.0);
	
	glVertex3f(-380.0, -5.0, 45.0);//3 kiri
	glVertex3f(-380.0, -5.0, -45.0);
	glVertex3f(-380.0, -7.0, -45.0);
	glVertex3f(-380.0, -7.0, 45.0);
	
	glVertex3f(-380.0, -11.0, 45.0);//3 kiri
	glVertex3f(-380.0, -11.0, -45.0);
	glVertex3f(-380.0, -13.0, -45.0);
	glVertex3f(-380.0, -13.0, 45.0);
	
	glVertex3f(-380.0, -17.0, 45.0);//3 kiri
	glVertex3f(-380.0, -17.0, -45.0);
	glVertex3f(-380.0, -19.0, -45.0);
	glVertex3f(-380.0, -19.0, 45.0);
	
	
	
	glVertex3f(-376.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(-376.0, 19.0, 45.0);										
	glVertex3f(-374.0, 19.0, 45.0);												
	glVertex3f(-374.0, -19.0, 45.0);
	
	glVertex3f(-370.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(-370.0, 19.0, 45.0);										
	glVertex3f(-368.0, 19.0, 45.0);												
	glVertex3f(-368.0, -19.0, 45.0);
	
	glVertex3f(-364.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(-364.0, 19.0, 45.0);										
	glVertex3f(-362.0, 19.0, 45.0);												
	glVertex3f(-362.0, -19.0, 45.0);
	
	glVertex3f(-358.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(-358.0, 19.0, 45.0);										
	glVertex3f(-356.0, 19.0, 45.0);												
	glVertex3f(-356.0, -19.0, 45.0);
	
	glVertex3f(-352.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(-352.0, 19.0, 45.0);										
	glVertex3f(-348.0, 19.0, 45.0);												
	glVertex3f(-348.0, -19.0, 45.0);
	
	
	
	glVertex3f(-376.0, -19.0, -45.0);// 2 bawah										
	glVertex3f(-376.0, 19.0, -45.0);										
	glVertex3f(-374.0, 19.0, -45.0);												
	glVertex3f(-374.0, -19.0, -45.0);
	
	glVertex3f(-370.0, -19.0, -45.0);// 2 bawah										
	glVertex3f(-370.0, 19.0, -45.0);										
	glVertex3f(-368.0, 19.0, -45.0);												
	glVertex3f(-368.0, -19.0, -45.0);
	
	glVertex3f(-364.0, -19.0, -45.0);// 2 bawah										
	glVertex3f(-364.0, 19.0, -45.0);										
	glVertex3f(-362.0, 19.0, -45.0);												
	glVertex3f(-362.0, -19.0, -45.0);
	
	glVertex3f(-358.0, -19.0, -45.0);// 2 bawah										
	glVertex3f(-358.0, 19.0, -45.0);										
	glVertex3f(-356.0, 19.0, -45.0);												
	glVertex3f(-356.0, -19.0, -45.0);
	
	glVertex3f(-352.0, -19.0, -45.0);// 2 bawah										
	glVertex3f(-352.0, 19.0, -45.0);										
	glVertex3f(-348.0, 19.0, -45.0);												
	glVertex3f(-348.0, -19.0, -45.0);
	
	
	
	
	
	
	glBegin(GL_QUADS);
	glColor3f(0.00, 0.00, 0.0);/////////////////////////tiang gawang belakang kanan				
	glVertex3f(380.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(380.0, 19.0, 45.0);										
	glVertex3f(378.0, 19.0, 45.0);												
	glVertex3f(378.0, -19.0, 45.0);

	glVertex3f(380.0, -19.0, -45.0);// 2 atas										
	glVertex3f(380.0, 19.0, -45.0);										
	glVertex3f(378.0, 19.0, -45.0);												
	glVertex3f(378.0, -19.0, -45.0);
	
	
	glVertex3f(380.0, 19.0, 45.0);//3 atas
	glVertex3f(380.0, 19.0, -45.0);
	glVertex3f(378.0, 19.0, -45.0);
	glVertex3f(378.0, 19.0, 45.0);
	
	glVertex3f(376.0, 19.0, 45.0);///3 atas
	glVertex3f(376.0, 19.0, -45.0);
	glVertex3f(374.0, 19.0, -45.0);
	glVertex3f(374.0, 19.0, 45.0);
	
	glVertex3f(372.0, 19.0, 45.0);///3 atas
	glVertex3f(372.0, 19.0, -45.0);
	glVertex3f(370.0, 19.0, -45.0);
	glVertex3f(370.0, 19.0, 45.0);
	
	glVertex3f(368.0, 19.0, 45.0);///3 atas
	glVertex3f(368.0, 19.0, -45.0);
	glVertex3f(366.0, 19.0, -45.0);
	glVertex3f(366.0, 19.0, 45.0);
	
	glVertex3f(364.0, 19.0, 45.0);///3 atas
	glVertex3f(364.0, 19.0, -45.0);
	glVertex3f(362.0, 19.0, -45.0);
	glVertex3f(362.0, 19.0, 45.0);
	
	glVertex3f(360.0, 19.0, 45.0);///3 atas
	glVertex3f(360.0, 19.0, -45.0);
	glVertex3f(358.0, 19.0, -45.0);
	glVertex3f(358.0, 19.0, 45.0);
	
	glVertex3f(356.0, 19.0, 45.0);///3 atas
	glVertex3f(356.0, 19.0, -45.0);
	glVertex3f(354.0, 19.0, -45.0);
	glVertex3f(354.0, 19.0, 45.0);
	
	
	
	glVertex3f(380.0, 19.0, 45.0);//3 kiri
	glVertex3f(380.0, 19.0, -45.0);
	glVertex3f(380.0, 17.0, -45.0);
	glVertex3f(380.0, 17.0, 45.0);
	
	glVertex3f(380.0, 13.0, 45.0);//3 kiri
	glVertex3f(380.0, 13.0, -45.0);
	glVertex3f(380.0, 11.0, -45.0);
	glVertex3f(380.0, 11.0, 45.0);
	
	glVertex3f(380.0, 7.0, 45.0);//3 kiri
	glVertex3f(380.0, 7.0, -45.0);
	glVertex3f(380.0, 5.0, -45.0);
	glVertex3f(380.0, 5.0, 45.0);
	
	glVertex3f(380.0, 1.0, 45.0);//3 kiri
	glVertex3f(380.0, 1.0, -45.0);
	glVertex3f(380.0, -1.0, -45.0);
	glVertex3f(380.0, -1.0, 45.0);
	
	glVertex3f(380.0, -5.0, 45.0);//3 kiri
	glVertex3f(380.0, -5.0, -45.0);
	glVertex3f(380.0, -7.0, -45.0);
	glVertex3f(380.0, -7.0, 45.0);
	
	glVertex3f(380.0, -11.0, 45.0);//3 kiri
	glVertex3f(380.0, -11.0, -45.0);
	glVertex3f(380.0, -13.0, -45.0);
	glVertex3f(380.0, -13.0, 45.0);
	
	glVertex3f(380.0, -17.0, 45.0);//3 kiri
	glVertex3f(380.0, -17.0, -45.0);
	glVertex3f(380.0, -19.0, -45.0);
	glVertex3f(380.0, -19.0, 45.0);
	
	
	
	glVertex3f(376.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(376.0, 19.0, 45.0);										
	glVertex3f(374.0, 19.0, 45.0);												
	glVertex3f(374.0, -19.0, 45.0);
	
	glVertex3f(370.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(370.0, 19.0, 45.0);										
	glVertex3f(368.0, 19.0, 45.0);												
	glVertex3f(368.0, -19.0, 45.0);
	
	glVertex3f(364.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(364.0, 19.0, 45.0);										
	glVertex3f(362.0, 19.0, 45.0);												
	glVertex3f(362.0, -19.0, 45.0);
	
	glVertex3f(358.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(358.0, 19.0, 45.0);										
	glVertex3f(356.0, 19.0, 45.0);												
	glVertex3f(356.0, -19.0, 45.0);
	
	glVertex3f(352.0, -19.0, 45.0);// 1 bawah										
	glVertex3f(352.0, 19.0, 45.0);										
	glVertex3f(348.0, 19.0, 45.0);												
	glVertex3f(348.0, -19.0, 45.0);
	
	
	
	glVertex3f(376.0, -19.0, -45.0);// 2 bawah										
	glVertex3f(376.0, 19.0, -45.0);										
	glVertex3f(374.0, 19.0, -45.0);												
	glVertex3f(374.0, -19.0, -45.0);
	
	glVertex3f(370.0, -19.0, -45.0);// 2 bawah										
	glVertex3f(370.0, 19.0, -45.0);										
	glVertex3f(368.0, 19.0, -45.0);												
	glVertex3f(368.0, -19.0, -45.0);
	
	glVertex3f(364.0, -19.0, -45.0);// 2 bawah										
	glVertex3f(364.0, 19.0, -45.0);										
	glVertex3f(362.0, 19.0, -45.0);												
	glVertex3f(362.0, -19.0, -45.0);
	
	glVertex3f(358.0, -19.0, -45.0);// 2 bawah										
	glVertex3f(358.0, 19.0, -45.0);										
	glVertex3f(356.0, 19.0, -45.0);												
	glVertex3f(356.0, -19.0, -45.0);
	
	glVertex3f(352.0, -19.0, -45.0);// 2 bawah										
	glVertex3f(352.0, 19.0, -45.0);										
	glVertex3f(348.0, 19.0, -45.0);												
	glVertex3f(348.0, -19.0, -45.0);
	
	
	
	glEnd();
}


void mouse(int button, int state, int x, int y){///////////// Fungsi Mouse
	if (button == GLUT_LEFT_BUTTON){
			mouseDown = true;
			xdiff = x - yrot;
			ydiff = -y + xrot;
		}
	else
	mouseDown = false;
}
 
void mouseMotion(int x, int y){////////////// Fungsi Mouse 
	if (mouseDown){
		yrot = x - xdiff;
		xrot = y + ydiff;
		glutPostRedisplay();
	}
}

void tampilkuy(void)
{
	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);
	lapangan();
	bangku();
	gawang();
	garissudut();
	jaring();
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key){
		case 'w':///////////////////////Gerak ke (belakang)
		case 'W':
			glTranslatef(0.0, 0.0, 3.0);
			break;
		case 'd':///////////////////////Gerak ke (kanan)
		case 'D':
			glTranslatef(3.0, 0.0, 0.0);
			break;
		case 's':///////////////////////Gerak ke (depan)
		case 'S':
			glTranslatef(0.0, 0.0, -3.0);
			break;
		case 'a':///////////////////////Gerak ke (kiri)
		case 'A':
			glTranslatef(-3.0, 0.0, 0.0);
			break;
		case '2'://////////////////////Rotate ke (depan)
			glRotatef(2.0, 1.0, 0.0, 0.0);
			break;
		case '6'://///////////////////Rotate ke (kiri)
			glRotatef(2.0, 0.0, 1.0, 0.0);
			break;
		case '7'://///////////////////Rotate ke (atas)
        	glTranslatef(0.0, -3.0, 0.0);
        	break;
        case '8'://///////////////////Rotate ke (bawah)
        	glTranslatef(0.0, 3.0, 0.0);
        	break;
		case '4'://///////////////////Rotate ke (kanan)
			glRotatef(-2.0, 0.0, 1.0, 0.0);
			break;
		case '1'://///////////////////Rotate ke samping (kanan)
			glRotatef(2.0, 0.0, 0.0, 1.0);
			break;
		case '3'://///////////////////Rotate ke samping (kanan)
			glRotatef(-2.0, 0.0, 0.0, 1.0);
			break;
		case '5':
			if(is_depth){
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			}
			else{
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
	}
	tampilkuy();
}

void size(int lebar, int tinggi)
{
	if(tinggi == 0) tinggi = 1;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

