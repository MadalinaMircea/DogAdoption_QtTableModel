#pragma once
#include <QStyledItemDelegate>
#include "Repository.h"

class PictureDelegate : public QStyledItemDelegate {
public:
	Repository* repo;
	PictureDelegate(Repository* r, QObject * parent = 0) : repo{ r } {};
	~PictureDelegate() {};
	void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const override;
	QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const override;
};
