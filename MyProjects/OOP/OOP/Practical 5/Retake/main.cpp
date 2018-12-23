#include "Retake.h"
#include <QtWidgets/QApplication>
#include "AstroWindow.h"
#include "controller.h"
#include "AstroRepo.h"
#include "StarRepo.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	StarRepo sr{ "Stars.txt" };
	AstroRepo ar{ "Astronomers.txt" };
	Controller c{ sr,ar };
	for (auto i : ar.getAll())
	{
		AWindow* a1 = new AWindow(c, i);
		a1->show();
	}
	return a.exec();
}
