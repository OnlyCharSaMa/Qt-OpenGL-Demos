#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core
{
    Q_OBJECT
public:
    enum PaintObject { Rectangle, Circle, TwoTriangles, None };


    MyGLWidget(QWidget* parent = nullptr);
    ~MyGLWidget();


public slots:
    void setPaintObject(PaintObject paintObject);
    void renderLine();
    void renderFill();

private:
    inline void paintTwoTriangles();
    inline void paintRectangle();

private:
    QOpenGLShaderProgram shaderProgram1, shaderProgram2;
    GLuint VAOs[2], VBOs[2];
    GLuint rectVBO = 0;
    GLuint rectVAO = 0;
    GLuint EBO = 0;

    // 009 - new code
    QOpenGLTexture *texture0;


    float vertices1[18] = {
        // position(vec3)    // color(vec3)    //
        -0.70f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.00f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.35f,  0.1f, 0.0f, 0.0f, 0.0f, 1.0f
    };
    float vertices2[18] = {
        // position(vec3)  color(vec3)
        0.00f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.70f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.35f,  0.1f, 0.0f, 1.0f, 0.0f, 0.0f
    };
    float rectVertices[32] = {
        // position(vec3)   // color(vec3)
        -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // left top
         0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // right top
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // left bottom
         0.5f, -0.5f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f  // right bottom
    };
    unsigned int indexes[6] = {
        0, 1, 2,
        1, 2, 3
    };





    PaintObject m_paintObject = TwoTriangles;

protected:
    virtual void initializeGL();
    virtual void paintGL();

};

#endif // MYGLWIDGET_H
