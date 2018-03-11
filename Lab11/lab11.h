#ifndef LAB11_H
#define LAB11_H

#include <QtWidgets/QMainWindow>
#include "ui_lab11.h"

class Lab11 : public QMainWindow
{
	Q_OBJECT

public:
	Lab11(QWidget *parent = 0);
	~Lab11();

private:
	Ui::Lab11Class ui;
};

#endif // LAB11_H
