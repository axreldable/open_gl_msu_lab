#include <GL/glut.h>
#include <cstdio>
#include "SOIL.h"

// g++ main.cpp -lGL -lGLU -lglut -lSOIL

GLfloat xRotated, yRotated, zRotated;
GLdouble size = 1;
float angle = 0.0;
GLuint tex_2d;

void createCube() {
    glBegin(GL_POLYGON);
    // Передняя грань
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);    // Низ лево
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);    // Низ право
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);    // Верх право
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Верх лево
    glEnd();

    // Задняя грань
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);    // Низ право
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);    // Верх право
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);    // Верх лево
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);    // Низ лево
    glEnd();

    // Верхняя грань
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);    // Верх лево
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Низ лево
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);    // Низ право
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);    // Верх право
    glEnd();

    // Нижняя грань
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);    // Верх право
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);    // Верх лево
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);    // Низ лево
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);    // Низ право
    glEnd();

    // Правая грань
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);    // Низ право
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);    // Верх право
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);    // Верх лево
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);    // Низ лево
    glEnd();

    // Левая грань
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);    // Низ лево
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);    // Низ право
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Верх право
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);    // Верх лево
    glEnd();
}

void display(void) {
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();

    // включить текстурирование перед кубиком
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex_2d);
    glPushMatrix();
    glTranslatef(2, 2, -12);
    glRotatef(angle, 1.0, 1.0, 1.0);
    glRotatef(angle, 1.0, 0.0, 1.0);
    glRotatef(angle, 0.0, 1.0, 1.0);
    glTranslatef(-0.5, -1.0, 0.0);
    createCube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D); // выключаем текстуру

    glPushMatrix();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    // сдвинули чайник влево вниз
    glTranslatef(-3.5, -2, -12);  // glTranslate — multiply the current matrix by a translation matrix
    // Green color used to draw.
    glColor3f(0.439216, 0.858824, 0.576471); // Aquamarine
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated, 1.0, 0.0, 0.0); // glRotate — multiply the current matrix by a rotation matrix
    // rotation about Y axis
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    // rotation about Z axis
    glRotatef(zRotated, 0.0, 0.0, 1.0);
    // scaling transfomation
    glScalef(1.0, 1.0, 1.0); // glScale — multiply the current matrix by a general scaling matrix
    // built-in (glut library) function , draw you a Teapot.
    glutSolidTeapot(size);
    glPopMatrix();

    glFlush();
    glutSwapBuffers(); // смена экранных буфферов, так как мы используем двойную буфферизацию
}

void update(int value) {
    angle += 1.0f;
    if (angle > 360) {
        angle -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void reshapeFunc(int x, int y) {
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(40.0, (GLdouble) x / (GLdouble) y, 0.5, 20.0);
    glViewport(0, 0, x, y);  //Use the whole window for rendering
}

void idleFunc(void) {
    yRotated += 0.01;
    display();
}

void init_texture() {
    tex_2d = SOIL_load_OGL_texture(
            "/home/axreldable/Yandex.Disk/semester_7/graphics/simple_example/basketball.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB
    );

    /* check for an error during the load process */
    if (0 == tex_2d) {
        printf("SOIL loading error: '%s'\n", SOIL_last_result());
    } else {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, tex_2d);
    }
}

void init_light() {
    GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {100.0, 100.0, 0.0, 0.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

int main(int argc, char **argv) {
    //Initialize GLUT
    glutInit(&argc, argv);
    //double buffering used to avoid flickering problem in animation
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // window size
    glutInitWindowSize(800, 600);
    // create the window
    glutCreateWindow("Teapot-cube dance");

    init_texture();
    init_light();
// чтобы не были видны невидимые части кубика
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    zRotated = 30;
    xRotated = 33;
    yRotated = 40;

    // Set the color of the background
    glClearColor(0.0, 0.0, 0.0, 0.0);

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
