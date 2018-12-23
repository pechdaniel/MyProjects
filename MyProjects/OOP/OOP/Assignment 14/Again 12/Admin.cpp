#include "Admin.h"
#include <QtWidgets\qmessagebox.h>
#include <vector>
#include <QKeySequence>
#include <QShortcut>
#include <QtWidgets\QLineEdit>


Admin::Admin(Repository r,QWidget *parent)
	:repo{ r }, flt{ r }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
	this->populate();
	Operation* u1 = new Undo(r);
	Operation* u2 = new Redo(r);
	und = u1;
	red = u2;
}

Admin::~Admin()
{
	delete und;
	delete red;
}

void Admin::readFromFile()
{
	this->repo.clr();
	this->repo.readFromFile();
	this->flt = this->repo;
	this->populate();
}

void Admin::populate()
{
	if (ui.MovieList->count() != 0)
		ui.MovieList->clear();
	for (auto m : flt.getAll())
	{
		QString listItem = QString::fromStdString(m.toString());
		QListWidgetItem * listItemWidget = new QListWidgetItem(listItem);
		this->ui.MovieList->addItem(listItemWidget);
	}
	if (flt.getLenght() > 0)
		ui.MovieList->setCurrentRow(0);
}

int Admin::getSelectedIndex()
{
	if (ui.MovieList->count() == 0)
		return -1;
	QModelIndexList indexList = this->ui.MovieList->selectionModel()->selectedIndexes();
	if (indexList.size() == 0)
	{
		ui.TitleLine->clear();
		ui.GenreLine->clear();
		ui.YearLine->clear();
		ui.LikesLine->clear();
		ui.TrailerLine->clear();
		return -1;
	}
	int index = indexList.at(0).row();
	return index;
}

void Admin::add()
{
	int t1 = ui.TitleLine->text().length();
	int g1 = ui.GenreLine->text().length();
	int y1 = ui.YearLine->text().length();
	int l1 = ui.LikesLine->text().length();
	int tr1 = ui.TrailerLine->text().length();

	std::string t = ui.TitleLine->text().toStdString();
	std::string g = ui.GenreLine->text().toStdString();
	int y = ui.YearLine->text().toInt();
	int l = ui.LikesLine->text().toInt();
	std::string tr = ui.TrailerLine->text().toStdString();
	Movie m{ t,g,y,l,tr };

	ui.TitleLine->clear();
	ui.GenreLine->clear();
	ui.YearLine->clear();
	ui.LikesLine->clear();
	ui.TrailerLine->clear();

	if (t1 == 0 || g1 == 0 || y1 == 0 || l1 == 0 || tr1 == 0)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "error", QString::fromStdString("Fill in the text lines to add a movie!"));
		return;
	}

	int f = this->repo.findByTitle(m.getTitle());
	if (f != -1)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "error", QString::fromStdString("You cannot have 2 movies with the same title!"));
		return;
	}

	repo.add(m);
	flt.add(m);
	und->setE(repo.getAll());
	red->setE(repo.getAll());
	this->populate();
	OperationElement ope{ m,m,"delete" };
	this->und->push(ope);
}

void Admin::del()
{
	if (this->repo.getLenght() == 0)
	{
		QMessageBox m;
		m.critical(0, "error", QString::fromStdString("Nothing to delete!"));
		return;
	}
	int i = this->getSelectedIndex();
	std::string s = this->flt[i].getTitle();
	flt.del(i);
	int k = this->repo.findByTitle(s);
	OperationElement ope{ this->repo[k],this->repo[k],"add" };
	repo.del(k);
	und->setE(repo.getAll());
	red->setE(repo.getAll());
	this->populate();
	this->und->push(ope);
}

void Admin::update()
{
	std::string t = ui.TitleLine->text().toStdString();
	std::string g = ui.GenreLine->text().toStdString();
	int y = ui.YearLine->text().toInt();
	int l = ui.LikesLine->text().toInt();
	std::string tr = ui.TrailerLine->text().toStdString();
	std::string ot = ui.UpdateTitleLine->text().toStdString();

	int t1 = ui.TitleLine->text().length();
	int g1 = ui.GenreLine->text().length();
	int y1 = ui.YearLine->text().length();
	int l1 = ui.LikesLine->text().length();
	int tr1 = ui.TrailerLine->text().length();
	int ot1 = ui.UpdateTitleLine->text().length();

	ui.TitleLine->clear();
	ui.GenreLine->clear();
	ui.YearLine->clear();
	ui.LikesLine->clear();
	ui.TrailerLine->clear();
	ui.UpdateTitleLine->clear();

	if (t1 == 0 || g1 == 0 || y1 == 0 || l1 == 0 || tr1 == 0)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "error", QString::fromStdString("Fill in the text lines to update a movie!"));
		return;
	}

	int f = this->repo.findByTitle(ot);
	if (f == -1)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "error", QString::fromStdString("No movie found with that title!"));
		return;
	}

	Movie m{ t,g,y,l,tr };
	Movie m1 = this->repo[this->repo.findByTitle(ot)];
	OperationElement ope{ m1, m, "update" };
	this->und->push(ope);

	repo.update(ot, t, g, y, l, tr);
	und->setE(repo.getAll());
	red->setE(repo.getAll());
	flt.update(ot, t, g, y, l, tr);
	this->populate();
}

void Admin::filter()
{
	und->setE(repo.getAll());
	red->setE(repo.getAll());
	this->flt = this->repo;
	std::string t = ui.FilterLine->text().toStdString();
	std::vector<Movie> r=this->flt.filterRepo(t);
	this->flt.setElems(r);
	this->populate();
}

void Admin::undoFcT()
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
		repo.setElems(und->getRepo().getAll());
		this->flt = this->repo;
		this->populate();
		return;
	}
	if (e.getOperation() == "delete")
	{
		e.setOperation("add");
		this->red->push(e);
		this->und->execute();
		red->setE(und->getRepo().getAll());
		repo.setElems(und->getRepo().getAll());
		this->flt = this->repo;
		this->populate();
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
		repo.setElems(und->getRepo().getAll());
		this->flt = this->repo;
		this->populate();
		return;
	}
}

void Admin::redoFcT()
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
		repo.setElems(red->getRepo().getAll());
		this->flt = this->repo;
		this->populate();
		return;
	}
	if (e.getOperation() == "delete")
	{
		e.setOperation("add");
		this->und->push(e);
		this->red->execute();
		und->setE(red->getRepo().getAll());
		repo.setElems(red->getRepo().getAll());
		this->flt = this->repo;
		this->populate();
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
		repo.setElems(red->getRepo().getAll());
		this->flt = this->repo;
		this->populate();
		return;
	}
}

void Admin::connectSignalsAndSlots()
{
	QObject::connect(ui.MovieList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	QObject::connect(this->ui.AddButton, SIGNAL(clicked()), this, SLOT(add()));

	QObject::connect(this->ui.DeleteButton, SIGNAL(clicked()), this, SLOT(del()));

	QObject::connect(this->ui.UpdateButton, SIGNAL(clicked()), this, SLOT(update()));

	QObject::connect(this->ui.UndoButton, SIGNAL(clicked()), this, SLOT(undoFcT()));

	QObject::connect(this->ui.RedoButton, SIGNAL(clicked()), this, SLOT(redoFcT()));
	
	QObject::connect(this->ui.FilterLine, SIGNAL(textChanged(const QString&)), this, SLOT(filter()));

	QShortcut *shortcut1 =new QShortcut(QKeySequence("Ctrl+Z"),this);
	QShortcut *shortcut2 = new QShortcut(QKeySequence("Ctrl+Y"), this);
	
	QObject::connect(shortcut1, SIGNAL(activated()), this, SLOT(undoFcT()));
	QObject::connect(shortcut2, SIGNAL(activated()), this, SLOT(redoFcT()));
}
