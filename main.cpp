#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "glimmerwindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);

    GlimmerWindow window;
    window.setFormat(format);
    window.resize(800, 600);
    window.show();

    window.setAnimating(true);

    return app.exec();
}
