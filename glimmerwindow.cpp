#include "glimmerwindow.h"

void GlimmerWindow::initialize()
{
    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertshader.vert");
    mProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragshader.frag");
    mProgram->link();

    mPos = mProgram->attributeLocation("pos");
    Q_ASSERT(mPos != -1);
    mCol = mProgram->attributeLocation("col");
    mMatrixUniform = mProgram->uniformLocation("matrix");
}

void GlimmerWindow::render()
{
    const qreal retinaRatio = devicePixelRatio();
    glViewport(0, 0, width() * retinaRatio, height() * retinaRatio);

    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();

    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);
    matrix.rotate(100.0f * mFrame / screen()->refreshRate(), 0, 1, 0);

    mProgram->setUniformValue(mMatrixUniform, matrix);


    static const GLfloat vertices[] = {
        0.0f,  0.707f,
        -0.5f, -0.5f,
        0.5f, -0.5f
    };

    static const GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    glVertexAttribPointer(mPos, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(mCol, 3, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(mPos);
    glEnableVertexAttribArray(mCol);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(mCol);
    glDisableVertexAttribArray(mPos);

    mProgram->release();

    ++mFrame;
}
