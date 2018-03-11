#pragma once
#include "lab11.h"
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "Controller.h"
#include "CSVList.h"
#include <QRadioButton>
#include "qcustomplot.h"
#include "Undo.h"

class GUI : public QWidget
{
	Q_OBJECT
public:
	Controller* ctrl;
	UndoController* undoCtrl;
	CSVList* adoption;

	QListWidget* dogList;
	QListWidget* adoptionList;
	QLineEdit* breedTextBox;
	QLineEdit* nameTextBox;
	QLineEdit* ageTextBox;
	QLineEdit* photoTextBox;
	QPushButton* addDogButton;
	QPushButton* deleteDogButton;
	QPushButton* updateDogButton;
	QPushButton* adoptDogButton;
	QPushButton* seePhotoButton;
	QPushButton* openCSVButton;
	QPushButton* openHTMLButton;
	QPushButton* showGraphButton;
	QPushButton* undoButton;
	QPushButton* redoButton;
	QPushButton* showTableButton;
	QRadioButton* sortedButton;
	QRadioButton* shuffledButton;
	QCustomPlot* customPlot;
	QFont f{ "Calibri", 12 };
	QAbstractTableModel* dogModel;

	GUI(Controller* ctrl, QWidget *parent = 0);
	~GUI() {}

	void initGUI();
	void populateDogList();
	void populateAdoptionList();
	void connectAll();
	void listItemChanged();
	int getSelectedIndex();

public slots:
	void addDogButtonHandler();
	void deleteDogButtonHandler();
	void updateDogButtonHandler();
	void seePhotoButtonHandler();
	void adoptButtonHandler();
	void openCSVButtonHandler();
	void openHTMLButtonHandler();
	void sortedButtonHandler(bool);
	void shuffledButtonHandler(bool);
	void plot();
	void undoButtonHandler();
	void redoButtonHandler();
	void showTableButtonHandler();

signals:
	void updatedDogsSignal();
	void updatedAdoptSignal();
};