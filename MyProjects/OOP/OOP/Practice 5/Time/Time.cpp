#include "Time.h"
#include <sstream>
#include <string>

using namespace std;

Time::Time(Repository<Task> &r,QWidget *parent)
	:repo{ r }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->sort();
	this->populate();
	this->connectSignalsAndSlots();
	this->blodIt();
}

void Time::connectSignalsAndSlots()
{
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(showDuration()));
}

void Time::populate()
{
	this->sort();
	if (ui.listWidget->count() != 0)
		ui.listWidget->clear();
	for (auto m : this->repo.getAll())
	{
		stringstream buffer;
		buffer << "Description: " << m.getDescription() << ",  Priority: " << m.getPriority();
		QString listItem = QString::fromStdString(buffer.str());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.listWidget->addItem(listItemWidget);
	}
	if (this->repo.getLenght() > 0)
		ui.listWidget->setCurrentRow(-1);
}

void Time::sort()
{
	this->repo.sort();
}

void Time::blodIt()
{
	for (int k = 0;k < repo.getLenght();k++)
	{
		this->ui.listWidget->setCurrentRow(k);
		if (repo[k].getPriority() == 1)
		{
			QListWidgetItem *it = this->ui.listWidget->currentItem();
			QFont f = it->font();
			f.setBold(1);
			it->setFont(f);
		}
	}
	this->ui.listWidget->setCurrentRow(0);
}

void Time::showDuration()
{
	int s = this->ui.lineEdit->text().toInt();
	this->ui.lineEdit->clear();
	this->ui.ShowLabel->setText(QString::fromStdString(to_string(this->repo.calculateDuration(s))));
}