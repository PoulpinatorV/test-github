#include "actions.h"

extern GLfloat xrot;   
extern GLfloat yrot; 

void touche_pressee(unsigned char key, int x, int y) 
{
    usleep(100);

    switch (key) {    
    case ESCAPE: 
	exit(1);                   	
	break; 
    }	
}

void touche_speciale(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        yrot-=5;
        break;
    case GLUT_KEY_RIGHT:
        yrot+=5;
        break;
    
    case GLUT_KEY_UP:
        xrot+=5;
        break;
    case GLUT_KEY_DOWN:
        xrot-=5;
        break;
    }
}