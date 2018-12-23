#include "VegetablesProb.h"

VegetablesProb::VegetablesProb(Repository<Vegetable> &r,QWidget *parent)
	:repo{ r }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
	this->sort();
	this->populateFamily();
}

void VegetablesProb::connectSignalsAndSlots()
{
	QObject::connect(ui.FamilyList, SIGNAL(itemSelectionChanged()), this, SLOT(filter()));
}

void VegetablesProb::sort()
{
	this->repo.sort();
}

void VegetablesProb::filter()
{
	int i = this->getSelectedIndex();
	if (i == -1)
		return;
	std::string fam = this->list[i].getFamily();
	this->flt=this->repo.filter(fam);
	this->populateVegetable();
}

void VegetablesProb::populateFamily()
{
	this->list= this->repo.getOnly();

	this->sort();
	if (ui.FamilyList->count() != 0)
		ui.FamilyList->clear();
	for (auto m : this->list)
	{
		QString listItem = QString::fromStdString(m.getFamily());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.FamilyList->addItem(listItemWidget);
	}
	if (list.size() > 0)
		ui.FamilyList->setCurrentRow(-1);
}

void VegetablesProb::populateVegetable()
{
	if (ui.VegetableList->count() != 0)
		ui.VegetableList->clear();
	for (auto m : flt)
	{
		int hi;
		stringstream buff;
		buff << "Name: " << m.getName() << ",  Parts: ";
		for (hi = 0;hi < m.getParts().size() - 1;hi++)
			buff << m.getParts()[hi] << ', ';
		buff << m.getParts()[hi];
		QString listItem = QString::fromStdString(buff.str());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.VegetableList->addItem(listItemWidget);
	}
	if (flt.size() > 0)
		ui.VegetableList->setCurrentRow(0);
}

int VegetablesProb::getSelectedIndex()
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
