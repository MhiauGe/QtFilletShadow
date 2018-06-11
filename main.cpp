#include <QtWidgets/QApplication>
#include "dialogeffect.h"
#include "QTestWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//example:
	QTestWidget w;
	DialogEffect* mDialogEffect = new DialogEffect(&w);
	w.show();

	return a.exec();
}
