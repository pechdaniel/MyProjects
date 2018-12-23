#include "table.h"
#include <vector>
#include <string>
#include <QFont>
#include <QBrush>

MovieTable::MovieTable(Repository & r, QObject * parent) :QAbstractTableModel{ parent },repo{ r }
{
}

MovieTable::~MovieTable()
{
}

int MovieTable::rowCount(const QModelIndex & parent) const
{
	int nr = this->repo.getLenght();
	return nr + 1;
}

int MovieTable::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant MovieTable::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int column = index.column();

	std::vector<Movie> mov = this->repo.getAll();

	if (row == mov.size())
	{
		return QVariant();
	}
	Movie m = mov[row];
	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(m.getTitle());
		case 1:
			return QString::fromStdString(m.getGenre());
		case 2:
			return QString::fromStdString(std::to_string(m.getYear()));
		case 3:
			return QString::fromStdString(std::to_string(m.getLikes()));
		case 4:
			return QString::fromStdString(m.getTrailer());
		default:
			break;
		}
	}
	if (role = Qt::FontRole)
	{
		QFont font("Times", 10, 10, true);
		font.setItalic(false);
		return font;
	}
	if (role == Qt::BackgroundRole)
	{
		if (row % 2 == 1)
		{
			return QBrush{ QColor{ 0, 250, 154 } };
		}
	}
	return QVariant{};
}

QVariant MovieTable::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Title" };
			case 1:
				return QString{ "Genre" };
			case 2:
				return QString{ "Year" };
			case 3:
				return QString{ "Likes" };
			case 4:
				return QString{ "Trailer" };
			default:
				break;
			}
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 10, 10, true);
		font.setBold(true);
		font.setItalic(false);
		return font;
	}

	return QVariant{};
}

bool MovieTable::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	// set the new data to the gene
	int geneIndex = index.row();

	// get the genes
	std::vector<Movie> genes = this->repo.getAll();

	// Allow adding in the table
	//if the index is >= number of genes => a new gene is added
	if (geneIndex == genes.size())
	{
		this->beginInsertRows(QModelIndex{}, geneIndex, geneIndex);

		switch (index.column())
		{
		case 0:
			this->repo.add(Movie{ value.toString().toStdString(), "",{} ,{} ,"" });
			break;
		case 1:
			this->repo.add(Movie{"", value.toString().toStdString(),{} ,{} ,""});
			break;
		case 2:
			this->repo.add(Movie{"","", stoi(value.toString().toStdString()),{} ,"" });
			break;
		case 3:
			this->repo.add(Movie{ "","",{}, stoi(value.toString().toStdString()) ,"" });
			break;
		case 4:
			this->repo.add(Movie{ "","",{},{}, value.toString().toStdString() });
			break;
		}

		this->endInsertRows();
		return true;
	}

	Movie currentGene = genes[geneIndex];
	switch (index.column())
	{
	case 0:
		currentGene.setTitle(value.toString().toStdString());
		break;
	case 1:
		currentGene.setGenre(value.toString().toStdString());
		break;
	case 2:
		currentGene.setYear(stoi(value.toString().toStdString()));
		break;
	case 3:
		currentGene.setLikes(stoi(value.toString().toStdString()));
		break;
	case 4:
		currentGene.setTrailer(value.toString().toStdString());
	}
	this->repo.update(genes[geneIndex].getTitle(), currentGene.getTitle(),currentGene.getGenre(),currentGene.getYear(),currentGene.getLikes(),currentGene.getTrailer());

	// emit the dataChanged signal
	emit dataChanged(index, index);

	return true;
}

Qt::ItemFlags MovieTable::flags(const QModelIndex & index) const
{
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
