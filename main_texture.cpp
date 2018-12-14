#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "SOIL.h"

void init(void)
{
    /* texture */
    GLuint tex_2d = SOIL_load_OGL_texture
            (
                    "/home/axreldable/Yandex.Disk/semester_7/graphics/simple_example/basketball.png",
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            );

    glClearColor ( 0.80, 0.85, 0.95, 1.0 );

    /* check for an error during the load process */
    if( 0 == tex_2d )
    {
        //printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
    } else {
        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, tex_2d );
    }

    /* light */
    GLfloat light_ambient[] =
            {0.8, 0.85, 0.95, 1.0};
    GLfloat light_diffuse[] =
            {1.0, 0.95, 0.8, 1.0};
    GLfloat light_specular[] =
            {1.0, 0.95, 0.8, 1.0};
    GLfloat light_position[] =
            {1.0, 0.5, 1.0, 0.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glHint ( GL_POLYGON_SMOOTH_HINT,         GL_NICEST );
    glHint ( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

void drawBox (GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, GLfloat z1, GLfloat z2)
{
    glBegin(GL_POLYGON);

    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1, y1, z2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x2, y1, z2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x2, y2, z2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1, y2, z2);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 0.0, -1.0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x2, y1, z1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1, y1, z1);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1, y2, z1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x2, y2, z1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1, y1, z1);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1, y1, z2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x1, y2, z2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x1, y2, z1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x2, y1, z2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x2, y1, z1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x2, y2, z1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x2, y2, z2);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1, y2, z2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x2, y2, z2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x2, y2, z1);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1, y2, z1);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0, -1.0, 0.0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x2, y1, z2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x1, y1, z2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x1, y1, z1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x2, y1, z1);
    glEnd();
}

GLfloat angle = 0.0;
GLfloat height = 0.0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotatef(angle, 0.0, 0.0, 1.0);
    glRotatef(angle, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, angle / 100.0f);
    drawBox(1.0, 2.0, 0.0, 1.0, 0.0, 1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, height, 0.0);
    drawBox(0.0, 1.0, 0.0, 1.0, 3.0, 4.0);
    glPopMatrix();

    glFlush();
}

void idle(void) {
    angle = sin(glutGet ( GLUT_ELAPSED_TIME ) * 0.00015f) * 360.0f;
    height = 0.1f * sin(glutGet(GLUT_ELAPSED_TIME) * 0.003);
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective ( 60.0, (GLfloat)w/(GLfloat)h, 1.0, 60.0 );
    gluLookAt(2.0, -2.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void key(unsigned char key, int x, int y)
{
    if ( key == 27 || key == 'q' || key == 'Q' )    //    quit requested
        exit ( 0 );
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(500, 500);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Computer Graphics Task");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}