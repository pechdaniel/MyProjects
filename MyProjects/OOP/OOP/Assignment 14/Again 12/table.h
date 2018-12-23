#pragma once
#include <QAbstractTableModel>
#include "repository.h"

class MovieTable :public QAbstractTableModel
{
private:
	Repository& repo;

public:
	MovieTable(Repository& r, QObject* parent = Q_NULLPTR);
	~MovieTable();

	int rowCount(const QModelIndex & parent = QModelIndex{})const override;

	int columnCount(const QModelIndex & parent = QModelIndex{})const override;

	//Value at a given pos
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole)const override;

	//add header data
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole)const override;

	//will be called when a cell is edited
	bool setData(const QModelIndex & index, const QVariant &value, int role = Qt::EditRole)override;

	//used to set certain properties of a cell
	Qt::ItemFlags flags(const QModelIndex & index)const override;
};