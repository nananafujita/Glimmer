#ifndef GLIMMERWINDOW_H
#define GLIMMERWINDOW_H

#include <QQuickItem>
#include <QOpenGLShaderProgram>
#include "openglwindow.h"

QT_FORWARD_DECLARE_CLASS(QPainter)
QT_FORWARD_DECLARE_CLASS(QOpenGLContext)
QT_FORWARD_DECLARE_CLASS(QOpenGLPaintDevice)

class GlimmerWindow : public OpenGLWindow
{
public:
    using OpenGLWindow::OpenGLWindow;

    void initialize() override;
    void render() override;

signals:

private:
    QOpenGLShaderProgram* mProgram = nullptr;
    GLint mPos = 0;
    GLint mCol = 0;
    GLint mMatrixUniform = 0;
    int mFrame = 0;
};

#endif // GLIMMERWINDOW_H
