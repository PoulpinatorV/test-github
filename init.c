// gcc init.c -c -o init.o
#include "init.h"

int window;
GLvoid redimensionnement( GLsizei Width,GLsizei Height)
{
    glViewport(0,0,Width,Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(GLfloat)Width/(GLfloat)Height,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);

}

int notre_init(int argc,char** argv, void (*Modelisation)())
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    window=glutCreateWindow("OpenGl");
    glutDisplayFunc(Modelisation);
    glutIdleFunc(Modelisation);
    glutReshapeFunc(&redimensionnement);
    glutKeyboardFunc(&touche_pressee);
    glutSpecialFunc(&touche_speciale);
   glClearColor(0.0f,0.0f,0.0f,0.0f);

   glutMainLoop();

   return 1;
}
