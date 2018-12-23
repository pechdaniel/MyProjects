#include "Vegetables.h"
#include <QMessageBox>
#include <sstream>
#include <string>

using namespace std;

Vegetables::Vegetables(Repository &r,QWidget *parent)
	:repo{ r }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->sort();
	this->connectSignalsAndSlots();
	this->populateFam();
	Repository rw{};
	this->flt = rw;
}

void Vegetables::connectSignalsAndSlots()
{
	QObject::connect(ui.FamilyList, SIGNAL(itemSelectionChanged()), this, SLOT(filterR()));

}

void Vegetables::populateFam()
{
	this->sort();
	if (ui.FamilyList->count() != 0)
		ui.FamilyList->clear();
	for (auto m : repo.getAll())
	{
		QString listItem = QString::fromStdString(m.getFamily());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.FamilyList->addItem(listItemWidget);
	}
	if (repo.getLenght() > 0)
		ui.FamilyList->setCurrentRow(-1);
}

void Vegetables::populateVeg()
{
	if (ui.VegetableList->count() != 0)
		ui.VegetableList->clear();
	for (auto m : flt.getAll())
	{
		int hi;
		stringstream buff;
		buff << "Name: " << m.getName() << ",  Parts: ";
		for (hi = 0;hi < m.getParts().size()-1;hi++)
			buff << m.getParts()[hi]<<', ';
		buff << m.getParts()[hi];
		QString listItem = QString::fromStdString(buff.str());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.VegetableList->addItem(listItemWidget);
	}
	if (flt.getLenght() > 0)
		ui.VegetableList->setCurrentRow(0);
}

int Vegetables::getSelectedIndex()
{
	if (ui.FamilyList->count() == 0)
		return -1;
	QModelIndexList indexList = this->ui.FamilyList->selectionModel()->selectedIndexes();
	if (indexList.size() == 0)
	{
		return -1;
	}
	int index = indexList.at(0).row();
	return index;
}

void Vegetables::sort()
{
	this->repo.sort();
}

void Vegetables::filterR()
{
	int i = this->getSelectedIndex();
	if (i == -1)
		return;
	std::string fam = this->repo[i].getFamily();
	this->flt.setElems(this->repo.filter(fam));
	this->populateVeg();
}