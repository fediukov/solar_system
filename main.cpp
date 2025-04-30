#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "system_qt_wrapper.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/qml/main.qml"_qs);
    engine.addImportPath("C:/Users/sf/vcpkg/installed/x64-windows/Qt6/qml");

    SystemQtWrapper* wrapper = new SystemQtWrapper();
    engine.rootContext()->setContextProperty("SolarSystem", wrapper);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}