#include "DogTableModel.h"
#include "qbrush.h"

int DogTableModel::rowCount(const QModelIndex& parent) const
{
	return this->repo->dogs.getSize();
}

int DogTableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant DogTableModel::data(const QModelIndex& index, int role) const
{
	Dog currentDog = this->repo->dogs.elems[index.row()];
	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:
			return QString::fromStdString(currentDog.getName());
		case 2:
			return QString::fromStdString(currentDog.getBreed());
		case 3:
			return QString::number(currentDog.getAge());
		case 4:
			return QString::fromStdString(currentDog.getPhoto());
		}
	}

	return QVariant{};
}

QVariant DogTableModel::headerData(int section, Qt::Orientation orientation, \
	int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Name" };
			case 2:
				return QString{ "Breed" };
			case 3:
				return QString{ "Age" };
			case 4:
				return QString{ "Photo" };
			}
		}
	}

	return QVariant{};
}