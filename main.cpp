#include <QApplication>
#include <QFile>
#include "lightweightbaby.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleFile(":/style/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        a.setStyleSheet(styleSheet);
        styleFile.close();
    }

    lightweightbaby w;

    w.show();
    return a.exec();
}
