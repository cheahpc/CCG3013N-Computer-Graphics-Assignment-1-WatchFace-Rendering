#include "object.h"
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <stdarg.h>

// Default constructor
Object::Object() {}

Object::Object(GLfloat x, GLfloat y)
{
    this->x = x;
    this->y = y;
}

// Destructor
Object::~Object() {}

// 2D primitives
void Object::drawPoint(GLfloat x, GLfloat y, GLfloat size)
{
    glPushMatrix();
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex2i(x, y);

    this->glEndReset();
}

void Object::drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat thickness)
{
    glPushMatrix();
    glLineWidth(thickness);
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
    glPopMatrix();
    this->glEndReset();
}

void Object::drawTriangle(GLfloat x1, GLfloat y1,
                          GLfloat x2, GLfloat y2,
                          GLfloat x3, GLfloat y3)
{
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);

    this->glEndReset();
}

void Object::drawQuad(GLfloat x1, GLfloat y1,
                      GLfloat x2, GLfloat y2,
                      GLfloat x3, GLfloat y3,
                      GLfloat x4, GLfloat y4)
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);
    glEnd();
    glPopMatrix();
    this->glEndReset();
}

void Object::drawRect(GLfloat width, GLfloat height)
{
    GLfloat currentX, currentY;

    GLfloat startX, startY, endX, endY;
    startX = this->x - (width / 2);
    startY = this->y - (height / 2);
    endX = this->x + (width / 2);
    endY = this->y + (height / 2);

    currentX = startX;
    currentY = startY;

    // Draw the rectangle
    this->drawQuad(startX, startY, endX, startY, endX, endY, startX, endY);
}

void Object::drawRegularPolygon(GLfloat cx, GLfloat cy, GLfloat radius, GLint side, GLfloat orientation, GLfloat scale_x = 1, GLfloat scale_y = 1)
{
    // Convert orientation to radians
    orientation = orientation * M_PI / 180;
    if (side >= 3)
    {
        glPushMatrix();
        GLint xp, yp; // Interpolation points
        glBegin(GL_POLYGON);
        for (int i = 0; i < side; i++)
        {
            xp = (int)(cx + scale_x * radius * cos(orientation + 2 * M_PI / side * i));
            yp = (int)(cy + scale_y * radius * sin(orientation + 2 * M_PI / side * i));
            glVertex2i(xp, yp);
        }

        this->glEndReset();
    }
    else
    {
        cerr << "Could not render polygon with less than three sides." << endl;
    }
}

// 2D Circle & Torus
void Object::drawCircle(GLfloat radius, GLfloat startDegree, GLfloat endDegree)
{
    endDegree += startDegree > endDegree ? 360 : 0;
    GLfloat angle = (endDegree - startDegree) * M_PI / 180;    // get the angle in radian
    int triangleAmount = (int)((endDegree - startDegree) / 3); // Calculate the triangle amount base on the angle
    GLfloat cx = this->x;
    GLfloat cy = this->y;

    // Pre-rotate the circle to counter the drawing rotation
    this->rotate(90 - startDegree, cx, cy);

    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        GLfloat currentAngle = i * angle / triangleAmount;

        glVertex2f(
            cx + (radius * cos(currentAngle)),
            cy - (radius * sin(currentAngle)));
    }

    this->glEndReset();
}

void Object::drawTorus(GLfloat radius, GLfloat thickness, GLfloat startDegree, GLfloat endDegree)
{
    endDegree += startDegree > endDegree ? 360 : 0;
    GLfloat angle = (endDegree - startDegree) * M_PI / 180;  // get the angle in radian
    int triangleAmount = (int)(endDegree - startDegree) * 4; // Calculate the triangle amount base on the angle
    GLfloat cx = this->x;
    GLfloat cy = this->y;
    GLfloat currentX, currentY, currentAngle;
    GLfloat radius_outer = radius + (thickness / 2);
    GLfloat radius_inner = radius - (thickness / 2);

    // Pre-rotate the circle to counter the drawing rotation
    this->rotate(90 - startDegree, cx, cy);

    glPushMatrix();
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= triangleAmount; i++)
    {
        currentAngle = i * angle / triangleAmount;
        glVertex2f(
            cx + (radius_outer * cos(currentAngle)),
            cy - (radius_outer * sin(currentAngle)));
        glVertex2f(
            cx + (radius_inner * cos(currentAngle)),
            cy - (radius_inner * sin(currentAngle)));
    }
    this->glEndReset();
}

// Rounded rectangle
void Object::drawRoundedRectFill(GLfloat width, GLfloat height, GLfloat radius)
{
    GLfloat startX1, startX2, endX1, endX2;
    GLfloat startY1, startY2, endY1, endY2;
    startX1 = this->x - (width / 2);
    startX2 = this->x - (width / 2) + radius;
    endX1 = this->x + (width / 2) - radius;
    endX2 = this->x + (width / 2);
    startY1 = this->y - (height / 2);
    startY2 = this->y - (height / 2) + radius;
    endY1 = this->y + (height / 2) - radius;
    endY2 = this->y + (height / 2);

    GLfloat diameter = radius * 2;

    // Draw the rectangles
    // Center rectangle
    this->drawQuad(startX2, startY2, endX1, startY2, endX1, endY1, startX2, endY1);
    // Start rectangle
    this->drawQuad(startX1, startY2, startX2, startY2, startX2, endY1, startX1, endY1);
    // End rectangle
    this->drawQuad(endX1, startY2, endX2, startY2, endX2, endY1, endX1, endY1);
    // Top rectangle
    this->drawQuad(startX2, endY1, endX1, endY1, endX1, endY2, startX2, endY2);
    // Bottom rectangle
    this->drawQuad(startX2, startY1, endX1, startY1, endX1, startY2, startX2, startY2);

    // Draw the corners
    // Top left corner
    this->x = startX2;
    this->y = endY1;
    this->drawCircle(radius, 270, 360);

    // Top right corner
    this->x = endX1;
    this->y = endY1;
    this->drawCircle(radius, 0, 90);

    // Bottom right corner
    this->x = endX1;
    this->y = startY2;
    this->drawCircle(radius, 90, 180);

    // Bottom left corner
    this->x = startX2;
    this->y = startY2;
    this->drawCircle(radius, 180, 270);
}

// 2D transformation
void Object::translate(GLfloat tX, GLfloat tY)
{
    this->x = this->x + tX;
    this->y = this->y + tY;
}
void Object::rotate(GLfloat t, GLfloat pX, GLfloat pY)
{
    glTranslated(pX, pY, 0);
    glRotatef(t, 0.0f, 0.0f, 1.0f);
    glTranslated(-pX, -pY, 0);
}

// Utilities
void Object::drawText(char *string, GLfloat size)
{
    char *p;
    GLfloat x = this->x;
    GLfloat y = this->y;
    glPushMatrix();
    glLineWidth(size);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glDepthMask(false);
    glTranslatef(x, y, 0);
    for (p = string; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);

    this->glEndReset();
}