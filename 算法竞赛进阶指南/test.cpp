#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(300, 300);
    
    glutCreateWindow("OpenGL 3D View");
    
    
    glutMainLoop();
    return 0;
}