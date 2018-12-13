#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble size=1;

// The coordinates for the vertices of the cube
double x = 0.6;
double y = 0.6;
double z = 0.6;
float angle = 0.0;

void createCube() {
    // Create the 3D cube
    // BACK
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0.2);
    glVertex3f(x, -y, z);
    glVertex3f(x, y, z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, -y, z);
    glEnd();
    // FRONT
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.5, 0.0);
    glVertex3f(-x, y, -z);
    glVertex3f(-x, -y, -z);
    glVertex3f(x, -y, -z);
    glVertex3f(x, y, -z);
    glEnd();
    // LEFT
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x, -y, z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, y, -z);
    glEnd();
    // RIGHT
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(x, -y, -z);
    glVertex3f(x, -y, z);
    glVertex3f(x, y, z);
    glVertex3f(x, y, -z);
    glEnd();
    // TOP
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.0, 0.0);
    glVertex3f(x, y, z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, y, -z);
    glVertex3f(x, y, -z);
    glEnd();
    // BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.0, 0.3);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x, -y, z);
    glVertex3f(x, -y, z);
    glVertex3f(x, -y, -z);
    glEnd();
}

void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();

    glPushMatrix();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    // сдвинули чайник влево вниз
    glTranslatef(-3.5,-2,-12);  // glTranslate — multiply the current matrix by a translation matrix
    // Green color used to draw.
    glColor3f(0.0, 1.0, 0.0);
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0); // glRotate — multiply the current matrix by a rotation matrix
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation
    glScalef(1.0,1.0,1.0); // glScale — multiply the current matrix by a general scaling matrix
    // built-in (glut library) function , draw you a Teapot.
    glutSolidTeapot(size);
    glPopMatrix();


    glPushMatrix();
//    glTranslatef(0,0,-12);
//    glColor3f(0.0, 1.0, 0.0);
//    glRotatef(xRotated,1.0,0.0,0.0);
//    glRotatef(yRotated,0.0,1.0,0.0);
//    glRotatef(zRotated,0.0,0.0,1.0);
//    glScalef(1.0,1.0,1.0);
    glTranslatef(0,0,-12);
    glRotatef(angle, 1.0, 1.0, 1.0);
    glRotatef(angle, 1.0, 0.0, 1.0);
    glRotatef(angle, 0.0, 1.0, 1.0);
    glTranslatef(-0.5, -1.0, 0.0);
    createCube();
    glPopMatrix();

    glFlush();
    glutSwapBuffers(); // смена экранных буфферов, так как мы используем двойную буфферизацию
}

void update(int value)
{
    angle += 1.0f;
    if (angle > 360)
    {
        angle -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void reshapeFunc(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);

    glViewport(0,0,x,y);  //Use the whole window for rendering
}

void idleFunc(void)
{
    yRotated += 0.55;
    display();
}


int main (int argc, char **argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    //double buffering used to avoid flickering problem in animation
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // window size
    glutInitWindowSize(800, 600);
    // create the window
    glutCreateWindow("!!!!!!!!!!!!!!!!!!");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    zRotated = 30.0;
    xRotated=33;
    yRotated=40;

    // Set the color of the background
    glClearColor(0.0,0.0,0.0,0.0);


    //Assign  the function used in events
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFunc);
    // glutIdleFunc sets the global idle callback to be func so a
    // GLUT program can perform background processing tasks or continuous
    // animation when window system events are not being received.
    glutIdleFunc(idleFunc); // вращение чайника

    // Add a timer for the update(...) function
    glutTimerFunc(25, update, 0); // движение кубика

    //Let start glut loop
    glutMainLoop();
    return 0;
}
