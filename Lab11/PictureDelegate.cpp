#include "PictureDelegate.h"
#include <qpainter.h>
#include <string>

void PictureDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	if (index.column() != 1)
	{
		QStyledItemDelegate::paint(painter, option, index);
		return;
	}

	Dog current = this->repo->dogs.elems[index.row()];
	std::string photo;

	photo = current.getBreed() + '-' + current.getName() + ".jpg";
	QPixmap pixMap(photo.c_str());
	painter->drawPixmap(option.rect, pixMap);
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	if (index.column() == 1)
	{
		return QSize(32, 100);
	}

	return QStyledItemDelegate::sizeHint(option, index);
}