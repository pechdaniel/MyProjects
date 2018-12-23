#include "User.h"
#include "repoException.h"
#include "QtWidgets\qmessagebox.h"
#include <sstream>
#include <QShortcut>

User::User(Controller c,QWidget *parent)
	:contro{ c }, lastDeleted{ -1 }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
	this->populateWatchList();
	Operation* u1 = new Undo(contro.getList());
	Operation* u2 = new Redo(contro.getList());
	und = u1;
	red = u2;
}

void User::filterMovies()
{
	this->filter.clr();
	std::string f = this->ui.FilterByTitleLine->text().toStdString();
	this->ui.FilterByTitleLine->clear();
	this->filter.setElems(this->contro.filterByGenre(f));
	this->populateFilter();
	this->filter.setCurrent(-1);
}

void User::connectSignalsAndSlots()
{
	QObject::connect(ui.MovieList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	QObject::connect(this->ui.AddButton, SIGNAL(clicked()), this, SLOT(addMovie()));

	QObject::connect(this->ui.DeleteButton, SIGNAL(clicked()), this, SLOT(delMovie()));

	QObject::connect(this->ui.NextButton, SIGNAL(clicked()), this, SLOT(nextMovie()));

	QObject::connect(this->ui.FilterButton, SIGNAL(clicked()), this, SLOT(filterMovies()));

	QObject::connect(this->ui.ShowCSVButton, SIGNAL(clicked()), this, SLOT(showCSV()));

	QObject::connect(this->ui.ShowHTMLButton, SIGNAL(clicked()), this, SLOT(showHTML()));

	QObject::connect(this->ui.LikeButton, SIGNAL(clicked()), this, SLOT(likeMovie()));

	QObject::connect(this->ui.FilterByTitleLine, SIGNAL(returnPressed()), this, SLOT(filterMovies()));

	QObject::connect(this->ui.UndoButton, SIGNAL(clicked()), this, SLOT(undoFct()));

	QObject::connect(this->ui.RedoButton, SIGNAL(clicked()), this, SLOT(redoFct()));

	QShortcut *shortcut3 = new QShortcut(QKeySequence("Ctrl+Z"), this);
	QShortcut *shortcut4 = new QShortcut(QKeySequence("Ctrl+Y"), this);

	QObject::connect(shortcut3, SIGNAL(activated()), this, SLOT(undoFct()));
	QObject::connect(shortcut4, SIGNAL(activated()), this, SLOT(redoFct()));
}

void User::populateWatchList()
{
	if (ui.MovieList->count() != 0)
		ui.MovieList->clear();
	for (auto m : contro.getList().getAll())
	{
		QString listItem = QString::fromStdString(m.toString());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.MovieList->addItem(listItemWidget);
	}
	if (contro.getList().getLenght() > 0)
		ui.MovieList->setCurrentRow(0);
	this->contro.saveFile();
}

void User::populateFilter()
{
	if (ui.FilteredList->count() != 0)
		ui.FilteredList->clear();
	for (auto m : filter.getAll())
	{
		QString listItem = QString::fromStdString(m.toString());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.FilteredList->addItem(listItemWidget);
	}
	if (filter.getLenght() > 0)
		ui.FilteredList->setCurrentRow(0);
	this->contro.getAll().writeToFile();
}

User::~User()
{
	delete und;
	delete red;
}

void User::readFromFile()
{
	this->contro.readFromList();
	this->populateWatchList();
}

int User::getSelectedIndex()
{
	if (ui.MovieList->count() == 0)
		return -1;
	QModelIndexList indexList = this->ui.MovieList->selectionModel()->selectedIndexes();
	if (indexList.size() == 0)
	{
		return -1;
	}
	int index = indexList.at(0).row();
	return index;
}

void User::addMovie()
{
	try {
		if (this->filter.getLenght() == 0)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "error", QString::fromStdString("You have to filter by genre first!"));
			return;
		}
		if(this->filter.getCurrent()==-1)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "error", QString::fromStdString("You have to watch the trailer first!"));
			return;
		}
		if (this->filter.getCurrent() == 0)
		{
			this->contro.addList(this->filter[this->filter.getCurrent()]);
			und->setE(contro.getList().getAll());
			red->setE(contro.getList().getAll());
			OperationElement ope{ this->filter[this->filter.getCurrent()] ,this->filter[this->filter.getCurrent()] ,"delete" };
			this->und->push(ope);
		}
		else
		{
			this->contro.addList(this->filter[this->filter.getCurrent() - 1]);
			und->setE(contro.getList().getAll());
			red->setE(contro.getList().getAll());
			OperationElement ope{ this->filter[this->filter.getCurrent()-1] ,this->filter[this->filter.getCurrent() - 1] ,"delete" };
			this->und->push(ope);
		}
	}
	catch (FoundException e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "error", QString::fromStdString(e.what()));
	}
	this->populateWatchList();
}

void User::delMovie()
{
	try {
		int i = this->getSelectedIndex();
		if (this->contro.getList().getLenght() == 0)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "error", QString::fromStdString("The list is empty!"));
			return;
		}
		if (i == -1 )
			i = 0;
		std::string t = this->contro.getList()[i].getTitle();
		Movie m = this->contro.getList()[i];
		this->lastDeleted = this->contro.findByTitle(t);
		this->contro.delList(t);
		und->setE(contro.getList().getAll());
		red->setE(contro.getList().getAll());
		OperationElement ope{ m,m,"add" };
		und->push(ope);
	}
	catch (NoMovieFoundException e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "error", QString::fromStdString(e.what()));
	}
	this->populateWatchList();
}

void User::likeMovie()
{
	if (this->lastDeleted == -1)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "error", QString::fromStdString("You have to delete a movie first!"));
		return;
	}
	this->contro.incLikes(this->lastDeleted);
	this->contro.getAll().writeToFile();
	this->lastDeleted = -1;
}

void User::showCSV()
{
	this->contro.displayCSV();
}

void User::showHTML()
{
	this->contro.saveFile();
	this->contro.displayHTML();
}

void User::nextMovie()
{
	if (this->filter.getLenght() == 0)
	{
		QMessageBox m;
		m.critical(0, "error", QString::fromStdString("You have to filter something first!"));
		return;
	}
	this->filter.next();
}

void User::undoFct()
{
	if (this->und->len() == 0)
	{
		QMessageBox m;
		m.critical(0, "error", QString::fromStdString("Nothing to undo!"));
		return;
	}
	OperationElement e = this->und->get();
	if (e.getOperation() == "add")
	{
		e.setOperation("delete");
		this->red->push(e);
		this->und->execute();
		red->setE(und->getRepo().getAll());
		contro.setElems(und->getRepo().getAll());
		this->populateWatchList();
		return;
	}
	if (e.getOperation() == "delete")
	{
		e.setOperation("add");
		this->red->push(e);
		this->und->execute();
		red->setE(und->getRepo().getAll());
		contro.setElems(und->getRepo().getAll());
		this->populateWatchList();
		return;
	}
	if (e.getOperation() == "update")
	{
		Movie m = e.getMovie();
		Movie m1 = e.getMovieUpdate();
		e.setMovie(m1);
		e.setMovieUpdate(m);
		this->red->push(e);
		this->und->execute();
		red->setE(und->getRepo().getAll());
		contro.setElems(und->getRepo().getAll());
		this->populateWatchList();
		return;
	}
}

void User::redoFct()
{
	if (this->red->len() == 0)
	{
		QMessageBox m;
		m.critical(0, "error", QString::fromStdString("Nothing to redo!"));
		return;
	}
	OperationElement e = this->red->get();
	if (e.getOperation() == "add")
	{
		e.setOperation("delete");
		this->und->push(e);
		this->red->execute();
		und->setE(red->getRepo().getAll());
		contro.setElems(red->getRepo().getAll());
		this->populateWatchList();
		return;
	}
	if (e.getOperation() == "delete")
	{
		e.setOperation("add");
		this->und->push(e);
		this->red->execute();
		und->setE(red->getRepo().getAll());
		contro.setElems(red->getRepo().getAll());
		this->populateWatchList();
		return;
	}
	if (e.getOperation() == "update")
	{
		Movie m = e.getMovie();
		Movie m1 = e.getMovieUpdate();
		e.setMovie(m1);
		e.setMovieUpdate(m);
		this->und->push(e);
		this->red->execute();
		und->setE(red->getRepo().getAll());
		contro.setElems(red->getRepo().getAll());
		this->populateWatchList();
		return;
	}
}
