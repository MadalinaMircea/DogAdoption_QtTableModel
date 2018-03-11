#pragma once
#include <QAbstractItemModel>
#include "Repository.h"

class DogTableModel : public QAbstractTableModel {
private:
	Repository* repo;
public:
	DogTableModel(Repository* r, QObject * parent = 0) : repo{ r } { };
	~DogTableModel() {};

	int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
	int columnCount(const QModelIndex& parent = QModelIndex{}) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};
