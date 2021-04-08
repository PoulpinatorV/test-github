#include <GL/gl.h>
#include "init.h"
#include "axes.h"
#include "VM_init.h"
//-lm -lGL -lGLU -lglut -o

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f;


GLfloat angle_paume_auriculaire = 0.0f;
GLfloat angle_auriculaire_phalange_phalangine = 0.0f;
GLfloat angle_auriculaire_phalangine_phalangette = 0.0f;

GLvoid Rectangle(GLfloat x, GLfloat y, GLfloat z)
{
  glPushMatrix();
  {
    glScalef(x,y,z);
    glutSolidCube(1.0f);
  }
  glPopMatrix();  
} 

GLvoid Paume(GLfloat x, GLfloat y, GLfloat z)
{
  Rectangle(x,y,z);
}

GLvoid Doigt(GLfloat angle,
	     GLfloat angle_phalange_phalangine, 
	     GLfloat angle_phalangine_phalangette, 
	     GLfloat proportion,
	     GLfloat taille_doigt)
{
  glPushMatrix();
  {      
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(proportion * 0.5f, 0.0f, 0.0f);
    Rectangle(proportion * 1.0f, taille_doigt, taille_doigt);


    glTranslatef(proportion * 0.5f, 0.0f, 0.0f);
    glRotatef(angle_phalange_phalangine, 0.0f, 0.0f, 1.0f);
    glTranslatef(proportion * 0.4f, 0.0f, 0.0f);
    

    // Rotation incorrecte    
    //    glTranslatef(proportion * 0.9f, 0.0f, 0.0f);
    //    glRotatef(angle_phalange_phalangine, 0.0f, 0.0f, 1.0f);
    
    glColor3f(0.0, 1.0, 0.0);
    Rectangle(proportion * 0.8f, taille_doigt, taille_doigt);

    glTranslatef(proportion * 0.4f, 0.0f, 0.0f);
    glRotatef(angle_phalangine_phalangette, 0.0f, 0.0f, 1.0f);
    glTranslatef(proportion * 0.3f, 0.0f, 0.0f);


    // Rotation incorrecte
    //    glRotatef(angle_phalangine_phalangette, 0.0f, 0.0f, 1.0f);
    //    glTranslatef(proportion * 0.7f, 0.0f, 0.0f);

    glColor3f(1.0, 1.0, 0.0);
    Rectangle(proportion * 0.6f, taille_doigt, taille_doigt);
  }
  glPopMatrix();
}


GLvoid Modelisation()
{
  VM_init();


  glPushMatrix();
  {
   

    // auriculaire
      
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST) ;
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 1.0f, 0.0f);
    //GLUquadric * quadric = gluNewQuadric();
    glutSolidSphere(0.5,50,50);
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.25f, 0.25f, 0.25f);
    GLUquadric * quadricoeil1 = gluNewQuadric();
    gluSphere(quadricoeil1,0.1,50,50);
      glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(-0.25f, -1.35f, -0.25f);
  //  GLUquadric * quadric2 = gluNewQuadric();
    glutSolidSphere(1,50,50);
  /*  
    glColor3f(0.5, 0.5, 0.5);  
    GLfloat largeur_paume = 0.2;
    GLfloat longueur_paume = 0.48;
    GLfloat taille_doigt = 0.24;

    Paume(longueur_paume, 0.04, largeur_paume);
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(longueur_paume/2, 0.0, largeur_paume/2.0);
    Doigt(angle_paume_auriculaire, angle_auriculaire_phalange_phalangine, angle_auriculaire_phalangine_phalangette, 0.5, taille_doigt);
    
    //gluSphere(quadric,1,20,20);*/
    //glutSolidCube(0.5);
  }
  glPopMatrix();

 // axes();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  return notre_init(argc, argv, &Modelisation);
}
