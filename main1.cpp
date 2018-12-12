#if defined(linux) || defined(_WIN32)

#include <GL/glut.h>    /*Для Linux и Windows*/

#else
#include <GLUT/GLUT.h>  /*Для Mac OS*/
#endif

// g++ main.cpp -lGL -lGLU -lglut

void reshape(int w, int h) {
    glViewport(0, 0, w, h); // задаем область вывода изображения размером во все окно

    glMatrixMode(GL_PROJECTION); // загрузим матрицу проекции
    glLoadIdentity(); // заменим ее единичной
    gluOrtho2D(0, w, 0, h); // установим ортогональную проекцию

    glMatrixMode(GL_MODELVIEW); // загрузим модельно-видовую матрицу
    glLoadIdentity(); // заменим ее единичной
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // очистка буффера цвета

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(250, 450);
    glVertex2i(250, 150);
    glVertex2i(550, 150);
    glVertex2i(550, 450);
    glEnd();

//    glBegin(GL_QUADS);
//    glColor3f(0.0, 1.0, 0.0);
//    glVertex2i(650, 750);
//    glVertex2i(650, 350);
//    glVertex2i(250, 350);
//    glVertex2i(250, 450);
//    glEnd();

    glutSwapBuffers(); // смена экранных буфферов, так как мы используем двойную буфферизацию
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    // GLUT_DOUBLE — включает двойной экранный буфер
    // | GLUT_RGBA — включает четырехкомпонентный цвет
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(800, 600); // задаем размеры окна
    glutCreateWindow("OpenGL lesson 1"); // окно с именем

    glutReshapeFunc(reshape); // задает функцию обработки изменения размеров окна
    glutDisplayFunc(display); // задает функцию рисования изображения

    glutMainLoop();

    return 0;
}
