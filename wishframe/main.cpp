#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


      //QWidget mainWidget;
      /*QHBoxLayout *horizontalLayout = new QHBoxLayout(&mainWidget);
      DragWidget * dragWidget = new DragWidget();
      horizontalLayout->addWidget(new DragWidget);
      dragWidget->setWindowTitle(QObject::tr("Wishframe By Americkas and Rachmanimir"));
      dragWidget->show();*/

     MainWindow w;

    w.show();

    return app.exec();
}
