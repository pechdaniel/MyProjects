#include "AstroWindow.h"
#include <QMessageBox>

using namespace std;

AWindow::AWindow(Controller& c, Astronomer a, QWidget *parent)
	:contro{ c }, astro{ a }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(a.getName()));
	this->connectSignalsAndSlots();
	this->stars = this->contro.getStars().getAll();
	this->populate();
	ok = 1;
}

void AWindow::add()
{
	try {
		if (ui.NameLine->text().toStdString().length() == 0)
			throw Exception("There is no name for the star!");
		string con = astro.getConste();
		string name = ui.NameLine->text().toStdString();
		double lum = ui.LuminosityLine->text().toDouble();
		double tem = ui.TemperatureLine->text().toDouble();

		Star s{ name,con,lum,tem };
		this->contro.addStar(s);
		this->populate();
	}
	catch (Exception& e)
	{
		QMessageBox m;
		m.critical(0, "error", QString::fromStdString(e.what()));
	}
	ui.NameLine->clear();
	ui.TemperatureLine->clear();
	ui.LuminosityLine->clear();
}

void AWindow::modify()
{
	if (ok == 1)
	{
		this->stars = this->contro.filter(this->astro.getConste());
		ok = 0;
	}
	else
	{
		this->stars = this->contro.getStars().getAll();
		ok = 1;
	}
	this->populate();
}

void AWindow::connectSignalsAndSlots()
{
	QObject::connect(this->ui.AddButton, SIGNAL(clicked()), this, SLOT(add()));
	QObject::connect(this->ui.checkBox, SIGNAL(clicked(bool)), this, SLOT(modify()));
	QObject::connect(this->ui.FilterLine, SIGNAL(textChanged(const QString&)), this, SLOT(filterMe()));
}

void AWindow::populate()
{
	vector<Star> aici = this->contro.getStars().getAll();
	if (ui.StarsTable->count() != 0)
		ui.StarsTable->clear();
	for (auto m : stars)
	{
		QString listItem = QString::fromStdString(m.toString());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.StarsTable->addItem(listItemWidget);
	}
	if (stars.size() > 0)
		ui.StarsTable->setCurrentRow(0);
	this->contro.save();
}

void AWindow::populateList()
{
	if (ui.FilterList->count() != 0)
		ui.FilterList->clear();
	for (auto m : this->filter)
	{
		QString listItem = QString::fromStdString(m.toString());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.FilterList->addItem(listItemWidget);
	}
	if (this->filter.size() > 0)
		ui.FilterList->setCurrentRow(0);
}

void AWindow::filterMe()
{
	string w = ui.FilterLine->text().toStdString();
	this->filter = this->contro.search(w);
	this->populateList();
}
