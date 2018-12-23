#include "view.h"
#include <QSortFilterProxyModel>

View::View(Repository & r, Repository &l, QWidget * parent) :repo{ r }, list{ l }, QMainWindow{ parent }
{
	ui.setupUi(this);
	this->wTable = new MovieTable(this->list );
	this->mTable = new MovieTable(this->repo );
	this->ui.MovieTable->setModel(this->mTable);
	this->ui.WatchTable->setModel(this->wTable);
}

View::~View()
{
	delete this->wTable;
	delete this->mTable;
}


