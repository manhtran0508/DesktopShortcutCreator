#include "DesktopShortcutCreator.h"

#include <QApplication>

#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DesktopShortcutCreator w;
    w.show();
    return a.exec();
}
