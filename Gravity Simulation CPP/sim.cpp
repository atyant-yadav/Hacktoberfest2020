#include <GL/glut.h>
#include <vector>
#include <cmath>
#include <stdio.h>

#define dim 1024
// g++ -o sim sim.cpp -lglut -lGLU -lGL

using namespace std;

struct Particle {
    float x;
    float y;
    float r;
    float vx;
    float vy;
    long double m;
    float color[3];
};
 
struct Line {
    float x1;
    float y1;
    float x2;
    float y2;
} line;
 


void timer(int = 0);
void display();
void mouse(int, int, int, int);
void mouseMotion(int, int);
void addParticle(float, float, bool = true, float = 0, float = 0);
void removeParticles();
void keyboard(unsigned char, int, int);
 
int Mx, My, WIN;
bool PRESSED_LEFT = false, PRESSED_RIGHT = false,
     PRESSED_MIDDLE = false, SPEED_PARTICLES = false;
 
vector<Particle> particles;
vector<vector<pair<int,int>>> paths;
 
int main(int argc, char **argv)
{
    Particle p;
    //initial centered Huge mass particle
    p.x = 0;
    p.y = 0;
    p.vx = p.vy = 0;
    p.m = 10000;
    p.r = 30;
    p.color[0] = 1;
    p.color[1] = 0.5;
    p.color[2] = 0;
    vector<pair<int,int>> path;
    path.push_back(make_pair(p.x,p.y));
    paths.push_back(path);
    particles.push_back(p);
 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(dim, dim);
    glutInitWindowPosition(50, 50);
    WIN = glutCreateWindow("Gravity");
 
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION); //Specifies which matrix stack is the target for subsequent matrix operations
    glLoadIdentity();
    glOrtho(-dim/2, dim/2, dim/2, -dim/2, 0, 1); //left, right, bottom, top, nearVal, farVal
    //left bottom - nearVal and right top - nearVal specify the points on the near clipping plane
    //that are mapped to the lower left and upper right corners of the window, respectively, 
    
    glutDisplayFunc(display); // display callback for the current window.
    glutMouseFunc(mouse); //Mouse callback
    glutMotionFunc(mouseMotion); //Reports mouse-motion while a button is held. 
    glutKeyboardFunc(keyboard); //Keyboard call back
    timer();
    
    glutMainLoop();
    return 0;
}
 
void timer(int)
{
    display();
    if(PRESSED_LEFT && !SPEED_PARTICLES)
    {
        addParticle(10, 10); //add tiny particle
        PRESSED_LEFT = false;
    }
 
    if(PRESSED_RIGHT  && !SPEED_PARTICLES)
    {
        addParticle(10000, 30, 0); //add huge particle
        PRESSED_RIGHT = false;
    }
 
    if(PRESSED_MIDDLE)
        removeParticles(); //remove all particles
 
    for(int i = 0; i < particles.size(); i++)
    {   
        

        Particle &p = particles[i];

        //Remove particles if out of bound:
        if(p.x<-1000 || p.x > 2000 || p.y<-1000 || p.y > 2000){
            particles.erase(particles.begin()+i);
                    paths.erase(paths.begin()+i);
                    continue;
        }

        bool not_fall = true;
        //Updating the path
        paths[i].push_back(make_pair(p.x,p.y));

        for(int j = 0; j < particles.size(); j++)
        {
            if(j == i ) // Not moving big mass, and no self effect
                continue; 
 
            Particle &p1 = particles[j];
 
            float d = sqrt((p1.x - p.x)*(p1.x - p.x) + (p1.y - p.y)*(p1.y - p.y));


 
            if(d > (p1.r)*1.2)
            {   
                //Ignoring G as it is very small compared to the chosen wieghts.
                p.vx += 0.03 * (p1.m / (d*d)) * (p1.x - p.x)/d; //f = ma => a = f/m, v = f*t, if time is small. v*cos(0)
                p.vy += 0.03 * (p1.m / (d*d)) * (p1.y - p.y)/d; //v*sin(0)
            }
            else{ //collided
                not_fall = false;
                if(p.m > p1.m){
                    p.m+=p1.m;
                    

                    //Conservation of mass
                    p.vx = (p.m*p.vx + p1.m*p1.vx)/p.m;
                    p.vy = (p.m*p.vy + p1.m*p1.vy)/p.m;

                    particles.erase(particles.begin()+j);
                    paths.erase(paths.begin()+j);
                }
                else{
                    p1.m+=p.m;
                    

                    //Conservation of mass
                    p1.vx = (p.m*p.vx + p1.m*p1.vx)/p1.m;
                    p1.vy = (p.m*p.vy + p1.m*p1.vy)/p1.m;
                    particles.erase(particles.begin()+i);
                    paths.erase(paths.begin()+i);
                    break;
                }


            }
        }
 
        if(not_fall)    
        {
            p.x += p.vx;
            p.y += p.vy;
        }
    }
 
    glutTimerFunc(1, timer, 0); //callback after 1ms.
}
 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Draw the trail lines
    for(int i=0; i<paths.size(); ++i){
        Particle &p = particles[i];
        vector<pair<int,int>> path = paths[i];
        //printf("%d %d\n",path[0].first, path[0].second);
        for(int j=0;j<path.size()-1;++j){
            glColor3f(p.color[0], p.color[1], p.color[2]);
            glBegin(GL_LINES);
                glVertex2f(path[j].first, path[j].second);
                glVertex2f(path[j+1].first, path[j+1].second);
            glEnd();
        }
    }

 
    //draw the drag line
    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
        glVertex2f(line.x1, line.y1);
        glVertex2f(line.x2, line.y2);
    glEnd();
 
    //draw particles
    for(int i = 0; i < particles.size(); i++)
    {
        Particle &p = particles[i];
        glColor3f(p.color[0], p.color[1], p.color[2]);
        glBegin(GL_POLYGON);
        for(float a = 0; a < 2*M_PI; a+=0.2)
            glVertex2f(p.r*cos(a) + p.x, p.r*sin(a) + p.y);
        glEnd();    
    }
 
    glFlush();
    glutSwapBuffers();
}
 
void mouse(int button, int state, int x, int y)
{
    //set the coordinates, captures where the mouse was initially pressed
    printf("%d %d\n",x,y);
    Mx = x - dim/2;
    My = y - dim/2;
 
    //add speed particles by line draging
    if(SPEED_PARTICLES)
    {
        if(line.x2 != 0 && line.y2 != 0 && state == GLUT_UP && (PRESSED_LEFT || PRESSED_RIGHT)){
            if(PRESSED_LEFT)
                addParticle(100, 10, 1, line.x1 - line.x2, line.y1 - line.y2); //add a speed particle
            else if(PRESSED_RIGHT)
                addParticle(10000, 30, 0, line.x1 - line.x2, line.y1 - line.y2);

            printf("%d %d\n",x,y);}

        else
        {
            line.x1 = line.x2 = Mx;
            line.y1 = line.y2 = My;
        }
    }
 
    //set the pressed value
    if(button == GLUT_LEFT_BUTTON)
        PRESSED_LEFT = state == GLUT_DOWN;
    else if(button == GLUT_RIGHT_BUTTON)
        PRESSED_RIGHT = state == GLUT_DOWN;
    else if(button == GLUT_MIDDLE_BUTTON)
        PRESSED_MIDDLE = state == GLUT_DOWN;
}
 
void mouseMotion(int x, int y)
{
    Mx = x - dim/2;
    My = y - dim/2;   
 
    //end of line with draging
    if(SPEED_PARTICLES && (PRESSED_LEFT || PRESSED_RIGHT))
    {
        line.x2 = Mx;
        line.y2 = My;
    }
}
 
void addParticle(float m, float r, bool randColor, float vx, float vy)
{
    Particle p;
    p.x = Mx;
    p.y = My;
    p.vx = vx/10; //in case it is a speed particle,
    p.vy = vy/10; //To slow down slightly
    p.m = m;
    p.r = r;
    if(randColor)
    {
        p.color[0] = rand()%200 / 200.0;
        p.color[1] = rand()%200 / 200.0;
        p.color[2] = rand()%200 / 200.0;
    }
    else // if is huge particle make it yellow
    {
        p.color[0] = 1;
        p.color[1] = 0.6;
        p.color[2] = 0;
    }
    particles.push_back(p); 
    vector<pair<int,int>> path;
    path.push_back(make_pair(p.x,p.y));
    paths.push_back(path);


    if(line.x1 != 0)
        line.x1 = line.x2 = line.y1 = line.y2 = 0;  
}
 
void removeParticles()
{
    for(int i = 0; i < particles.size(); i++)
        particles.pop_back();
    for(int i = 0; i < paths.size(); i++)
        paths.pop_back();
}
 
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 's':
            SPEED_PARTICLES = !SPEED_PARTICLES;
            break;  
        case 27: //esc
            removeParticles();
            glutDestroyWindow(WIN);
            exit(0);
            break;
    }
}