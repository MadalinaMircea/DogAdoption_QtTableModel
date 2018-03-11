#include "GUI.h"
#include <QtWidgets/QApplication>
#include <qwidget.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include "Exceptions.h"
#include "Validator.h"
#include "HTMLList.h"
#include <time.h>
#include <qmessagebox.h>
#include "DogTableModel.h"
#include "PictureDelegate.h"

void clear(FileRepository* repo)
{
	while (repo->dogs.getSize() > 0)
		repo->remove(0);

	repo->writeToFile();
}

GUI::GUI(Controller* ctrl, QWidget *parent)
{
	QWidget{ parent };
	this->ctrl = ctrl;
	this->adoption = new CSVList{ "adoptionList.txt" };
	clear(this->adoption);
	this->initGUI();
	this->connectAll();
	this->populateDogList();
	this->undoCtrl = new UndoController();
}

void GUI::initGUI()
{
	QHBoxLayout* layout = new QHBoxLayout{ this };

	QWidget* leftSide = new QWidget{};
	QVBoxLayout* vLayout = new QVBoxLayout{ leftSide };

	QWidget* radioButtonsWidget = new QWidget{};
	QHBoxLayout* radioButtons = new QHBoxLayout{ radioButtonsWidget };
	this->sortedButton = new QRadioButton{ "Sorted" };
	this->shuffledButton = new QRadioButton{ "Shuffled" };
	radioButtons->addWidget(this->sortedButton);
	radioButtons->addWidget(this->shuffledButton);

	vLayout->addWidget(radioButtonsWidget);

	QLabel* dogsLabel = new QLabel{ "Dogs" };
	this->dogList = new QListWidget{};
	this->dogList->setSelectionMode(QAbstractItemView::SingleSelection);
	vLayout->addWidget(dogsLabel);
	vLayout->addWidget(this->dogList);

	QWidget* dogDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ dogDataWidget };
	this->breedTextBox = new QLineEdit{};
	this->nameTextBox = new QLineEdit{};
	this->ageTextBox = new QLineEdit{};
	this->photoTextBox = new QLineEdit{};
	
	QLabel* breedLabel = new QLabel{ "&Dog breed:" };
	breedLabel->setBuddy(this->breedTextBox);
	QLabel* nameLabel = new QLabel{ "&Dog name : " };
	nameLabel->setBuddy(this->nameTextBox);
	QLabel* ageLabel = new QLabel{ "&Dog age:" };
	ageLabel->setBuddy(this->ageTextBox);
	QLabel* photoLabel = new QLabel{ "&Dog photo:" };
	photoLabel->setBuddy(this->photoTextBox);
	nameLabel->setFont(this->f);
	breedLabel->setFont(this->f);
	ageLabel->setFont(this->f);
	photoLabel->setFont(this->f);
	this->breedTextBox->setFont(this->f);
	this->nameTextBox->setFont(this->f);
	this->ageTextBox->setFont(this->f);
	this->photoTextBox->setFont(this->f);
	formLayout->addRow(breedLabel, this->breedTextBox);
	formLayout->addRow(nameLabel, this->nameTextBox);
	formLayout->addRow(ageLabel, this->ageTextBox);
	formLayout->addRow(photoLabel, this->photoTextBox);

	vLayout->addWidget(dogDataWidget);

	QWidget* leftButtonsWidget = new QWidget{};
	QHBoxLayout* hLayout = new QHBoxLayout{ leftButtonsWidget };
	this->addDogButton = new QPushButton("Add Dog");
	this->addDogButton->setFont(this->f);
	this->deleteDogButton = new QPushButton("Delete Dog");
	this->deleteDogButton->setFont(this->f);
	this->updateDogButton = new QPushButton("Update Dog");
	this->updateDogButton->setFont(this->f);
	hLayout->addWidget(this->addDogButton);
	hLayout->addWidget(this->deleteDogButton);
	hLayout->addWidget(this->updateDogButton);

	vLayout->addWidget(leftButtonsWidget);

	layout->addWidget(leftSide);

	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* middleButtons = new QVBoxLayout{ middleWidget };

	this->undoButton = new QPushButton("Undo");
	this->undoButton->setFont(this->f);

	this->redoButton = new QPushButton("Redo");
	this->redoButton->setFont(this->f);

	this->seePhotoButton = new QPushButton("See Photo");
	this->seePhotoButton->setFont(this->f);

	this->adoptDogButton = new QPushButton("Adopt");
	this->adoptDogButton->setFont(this->f);

	this->showGraphButton = new QPushButton("Show Graph");
	this->showGraphButton->setFont(this->f);

	this->showTableButton = new QPushButton("Show Table");
	this->showTableButton->setFont(this->f);

	middleButtons->addWidget(this->undoButton);
	middleButtons->addWidget(this->redoButton);
	middleButtons->addWidget(this->seePhotoButton);
	middleButtons->addWidget(this->adoptDogButton);
	middleButtons->addWidget(this->showGraphButton);
	middleButtons->addWidget(this->showTableButton);

	layout->addWidget(middleWidget);

	QWidget* rightSideWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightSideWidget };

	QLabel* adoptionLabel = new QLabel{ "Adoption List" };
	this->adoptionList = new QListWidget{};

	rightSide->addWidget(adoptionLabel);
	rightSide->addWidget(this->adoptionList);

	QWidget* openButtonsWidget = new QWidget{};
	QHBoxLayout* openButtons = new QHBoxLayout{ openButtonsWidget };
	this->openCSVButton = new QPushButton{ "Open CSV file" };
	this->openCSVButton->setFont(this->f);
	openButtons->addWidget(this->openCSVButton);

	this->openHTMLButton = new QPushButton{ "Open HTML file" };
	this->openHTMLButton->setFont(this->f);
	openButtons->addWidget(this->openHTMLButton);

	rightSide->addWidget(openButtonsWidget);


	layout->addWidget(rightSideWidget);
}

void GUI::populateDogList()
{
	if (this->dogList->count() > 0)
		this->dogList->clear();

	for (auto d : this->ctrl->repo->dogs.elems)
	{
		QString dogString = QString::fromStdString(d.getName() + " - " + \
			d.getBreed());
		QListWidgetItem* dog = new QListWidgetItem{ dogString };
		dog->setFont(this->f);
		this->dogList->addItem(dog);
	}

	if (this->dogList->count() > 0)
		this->dogList->setCurrentRow(0);

	this->ctrl->repo->writeToFile();
}

void GUI::connectAll()
{
	QObject::connect(this->addDogButton, SIGNAL(clicked()), this, \
		SLOT(addDogButtonHandler()));

	QObject::connect(this->deleteDogButton, SIGNAL(clicked()), this, \
		SLOT(deleteDogButtonHandler()));

	QObject::connect(this->seePhotoButton, SIGNAL(clicked()), this, \
		SLOT(seePhotoButtonHandler()));

	QObject::connect(this->adoptDogButton, SIGNAL(clicked()), this, \
		SLOT(adoptButtonHandler()));

	QObject::connect(this->updateDogButton, SIGNAL(clicked()), this, \
		SLOT(updateDogButtonHandler()));

	QObject::connect(this->openCSVButton, SIGNAL(clicked()), this, \
		SLOT(openCSVButtonHandler()));

	QObject::connect(this->openHTMLButton, SIGNAL(clicked()), this, \
		SLOT(openHTMLButtonHandler()));

	QObject::connect(this->showGraphButton, SIGNAL(clicked()), this, \
		SLOT(plot()));

	QObject::connect(this->undoButton, SIGNAL(clicked()), this, \
		SLOT(undoButtonHandler()));

	QObject::connect(this->redoButton, SIGNAL(clicked()), this, \
		SLOT(redoButtonHandler()));

	QObject::connect(this->showTableButton, SIGNAL(clicked()), this, \
		SLOT(showTableButtonHandler()));

	QObject::connect(this->sortedButton, SIGNAL(toggled(bool)), this, \
		SLOT(sortedButtonHandler(bool)));

	QObject::connect(this->shuffledButton, SIGNAL(toggled(bool)), this, \
		SLOT(shuffledButtonHandler(bool)));

	QObject::connect(this, &GUI::updatedDogsSignal, this, \
		&GUI::populateDogList);

	QObject::connect(this, &GUI::updatedAdoptSignal, this, \
		&GUI::populateAdoptionList);

	QObject::connect(this->dogList, &QListWidget::itemSelectionChanged, this, \
		[this]() {this->listItemChanged(); });
}

void GUI::addDogButtonHandler()
{
	string breed = this->breedTextBox->text().toStdString();
	string name = this->nameTextBox->text().toStdString();
	string photo = this->photoTextBox->text().toStdString();
	int age = this->ageTextBox->text().toInt();

	try
	{
		this->ctrl->add(breed, name, age, photo);

		Dog d = Dog(breed, name, age, photo);
		UndoAction* add = new UndoAdd(d, *this->ctrl);
		this->undoCtrl->newOperation();
		this->undoCtrl->undoActions.push_back(add);
		this->undoCtrl->index = this->undoCtrl->index + 1;
	}
	catch (DuplicateDogException& e)
	{
		QMessageBox error;
		error.critical(0, "Duplicate Dog Exception", e.what());
		error.setFont(this->f);
		error.show();
	}
	catch (ValidatorException& v)
	{
		QMessageBox error;
		error.critical(0, "Validator Exception", v.what());
		error.setFont(this->f);
		error.show();
	}
	catch (...)
	{
		QLabel* error = new QLabel{ "Controller Add Exception." };
		error->setFont(this->f);
		error->show();
	}

	emit updatedDogsSignal();
}

void GUI::deleteDogButtonHandler()
{
	string breed = this->breedTextBox->text().toStdString();
	string name = this->nameTextBox->text().toStdString();

	try
	{
		int age;
		string photo;

		for (auto d : this->ctrl->repo->dogs.elems)
			if (d.getBreed() == breed && d.getName() == name)
			{
				age = d.getAge();
				photo = d.getPhoto();
				break;
			}

		this->ctrl->remove(breed, name);

		Dog d = Dog(breed, name, age, photo);
		UndoAction* remove = new UndoRemove(d, *this->ctrl);
		this->undoCtrl->newOperation();
		this->undoCtrl->undoActions.push_back(remove);
		this->undoCtrl->index++;
	}
	catch (DogNotFoundException& e)
	{
		QMessageBox error;
		error.critical(0, "Dog Not Found Exception", e.what());
		error.setFont(this->f);
		error.show();
	}
	catch (ValidatorException& v)
	{
		QMessageBox error;
		error.critical(0, "Validator Exception", v.what());
		error.setFont(this->f);
		error.show();
	}
	catch (...)
	{
		QMessageBox error;
		error.critical(0, "Error", "Controller Error");
		error.setFont(this->f);
		error.show();
	}

	emit updatedDogsSignal();
}

void GUI::updateDogButtonHandler()
{
	int index = this->getSelectedIndex();

	if (index < 0)
	{
		QLabel* error = new QLabel{ "The list is empty." };
		error->setFont(this->f);
		error->show();
	}
	else
	{
		string breed = this->ctrl->repo->dogs.elems[index].getBreed();
		string name = this->ctrl->repo->dogs.elems[index].getName();
		string newBreed = this->breedTextBox->text().toStdString();
		string newName = this->nameTextBox->text().toStdString();
		string newPhoto = this->photoTextBox->text().toStdString();
		int newAge = this->ageTextBox->text().toInt();

		try
		{
			int age;
			string photo;

			for(auto d : this->ctrl->repo->dogs.elems)
				if (d.getBreed() == breed && d.getName() == name)
				{
					age = d.getAge();
					photo = d.getPhoto();
					break;
				}

			this->ctrl->update(breed, name, newAge, newPhoto, newBreed, newName);
			Dog d1 = Dog(breed, name, age, photo);
			Dog d2 = Dog(newBreed, newName, newAge, newPhoto);

			UndoAction* update = new UndoUpdate{ d1, d2, *this->ctrl };
			this->undoCtrl->newOperation();
			this->undoCtrl->undoActions.push_back(update);
			this->undoCtrl->index = this->undoCtrl->index + 1;
		}
		catch (DogNotFoundException& e)
		{
			QMessageBox error;
			error.critical(0, "Dog Not Found Exception", e.what());
			error.setFont(this->f);
			error.show();
		}
		catch (ValidatorException& v)
		{
			QMessageBox error;
			error.critical(0, "Validator Exception", v.what());
			error.setFont(this->f);
			error.show();
		}

		emit updatedDogsSignal();
	}
}

int GUI::getSelectedIndex()
{
	if (this->dogList->count() == 0)
		return -1;

	QModelIndexList index = this->dogList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->breedTextBox->clear();
		this->nameTextBox->clear();
		this->ageTextBox->clear();
		this->photoTextBox->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void GUI::listItemChanged()
{
	int idx = this->getSelectedIndex();
	if (idx == -1)
		return;

	if (idx >= this->ctrl->repo->dogs.elems.size())
		return;
	Dog d = this->ctrl->repo->dogs.elems[idx];

	this->breedTextBox->setText(QString::fromStdString(d.getBreed()));
	this->nameTextBox->setText(QString::fromStdString(d.getName()));
	this->photoTextBox->setText(QString::fromStdString(d.getPhoto()));
	string ageString = to_string(d.getAge());
	this->ageTextBox->setText(QString::fromStdString(ageString));
}

void GUI::seePhotoButtonHandler()
{
	int index = this->getSelectedIndex();

	if (index < 0)
	{
		QMessageBox error;
		error.critical(0, "Error", "The list is empty.");
		error.setFont(this->f);
		error.show();
	}
	else
	{
		this->ctrl->repo->dogs.elems[index].showPicture();
	}
}

void GUI::adoptButtonHandler()
{
	int index = this->getSelectedIndex();

	if (index < 0)
	{
		QMessageBox error;
		error.critical(0, "Error", "The list is empty.");
		error.setFont(this->f);
		error.show();
	}
	else
	{
		Dog d = Dog{ this->ctrl->repo->dogs.elems[index].getBreed(),\
		this->ctrl->repo->dogs.elems[index].getName(),\
		this->ctrl->repo->dogs.elems[index].getAge(),\
		this->ctrl->repo->dogs.elems[index].getPhoto() };

		this->ctrl->repo->remove(index);

		this->adoption->add(d);

		emit updatedDogsSignal();
		emit updatedAdoptSignal();
	}
}

void GUI::populateAdoptionList()
{
	if (this->adoptionList->count() > 0)
		this->adoptionList->clear();

	for (auto d : this->adoption->dogs.elems)
	{
		QString dogString = QString::fromStdString(d.getName() + " - " + \
			d.getBreed());
		QListWidgetItem* dog = new QListWidgetItem{ dogString };
		dog->setFont(this->f);
		this->adoptionList->addItem(dog);
	}

	if (this->adoptionList->count() > 0)
		this->adoptionList->setCurrentRow(0);

	this->adoption->writeToFile();
}

void GUI::openCSVButtonHandler()
{
	this->adoption->displayList();
}

void GUI::openHTMLButtonHandler()
{
	HTMLList* htmlAdoption = new HTMLList{ "adoptionList.html" };

	clear(htmlAdoption);

	for (auto d : this->adoption->dogs.elems)
		htmlAdoption->add(d);

	htmlAdoption->writeToFile();

	htmlAdoption->displayList();
}

void GUI::sortedButtonHandler(bool checked)
{
	if (checked == true)
	{
		Dog aux;
		int n = this->ctrl->repo->dogs.getSize();

		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (this->ctrl->repo->dogs.elems[i].getName() > this->ctrl->repo->dogs.elems[j].getName())
				{
					aux = this->ctrl->repo->dogs.elems[i];
					this->ctrl->repo->dogs.elems[i] = this->ctrl->repo->dogs.elems[j];
					this->ctrl->repo->dogs.elems[j] = aux;
				}

		emit updatedDogsSignal();
	}
}

void GUI::shuffledButtonHandler(bool checked)
{
	if (checked == true)
	{
		srand(time(NULL));
		int x = rand() % 900 + 100;
		int i = 0;

		while (i < x)
		{
			int first = rand() % this->ctrl->repo->dogs.getSize();
			int second = rand() % this->ctrl->repo->dogs.getSize();

			Dog aux = this->ctrl->repo->dogs.elems[first];
			this->ctrl->repo->dogs.elems[first] = this->ctrl->repo->dogs.elems[second];
			this->ctrl->repo->dogs.elems[second] = aux;

			i++;
		}

		emit updatedDogsSignal();
	}
}

void GUI::plot()
{
	QVector<string> breeds;
	QVector<double> numbers;

	for (auto d : this->ctrl->repo->dogs.elems)
	{
		bool found = false;
		int i;

		for(i = 0; i < breeds.size(); i++)
			if (breeds[i] == d.getBreed())
			{
				found = true;
				break;
			}

		if (found == false)
		{
			breeds.push_back(d.getBreed());
			numbers.push_back(1);
		}
		else
			numbers[i]++;

	}

	this->customPlot = new QCustomPlot{};
	QLinearGradient gradient(0, 0, 0, 400);
	gradient.setColorAt(0, QColor(219, 255, 252));
	this->customPlot->setBackground(QBrush(gradient));

	QCPBars *dogNr = new QCPBars(this->customPlot->xAxis, this->customPlot->yAxis);
	dogNr->setAntialiased(false);
	dogNr->setStackingGap(1);
	dogNr->setName("Dogs");

	QVector<double> ticks;
	QVector<QString> labels;
	
	int maxx = 0;

	for (int i = 0; i < breeds.size(); i++)
	{
		ticks << i;
		labels << breeds[i].c_str();

		if (numbers[i] > maxx)
			maxx = numbers[i];
	}

	QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
	textTicker->addTicks(ticks, labels);

	this->customPlot->xAxis->setTicker(textTicker);
	this->customPlot->xAxis->setTickLength(0, 4);
	this->customPlot->xAxis->setRange(-0.8, 8);


	this->customPlot->yAxis->setLabel("Number of dogs");
	this->customPlot->yAxis->setRange(0, 8);
	
	this->customPlot->setFixedSize(QSize(160 * breeds.size(), 50 * maxx));
	dogNr->setData(ticks, numbers);

	this->customPlot->show();
}

void GUI::undoButtonHandler()
{
	try
	{
		this->undoCtrl->undo();
	}
	catch (ValidatorException& v)
	{
		QMessageBox error;
		error.critical(0, "Validator Exception", v.what());
		error.setFont(this->f);
		error.show();
	}
	catch (UndoException& e)
	{
		QMessageBox error;
		error.critical(0, "Error", e.what());
		error.setFont(this->f);
		error.show();
	}
	catch (exception& e)
	{
		QMessageBox error;
		error.critical(0, "Error", e.what());
		error.setFont(this->f);
		error.show();
	}

	emit updatedDogsSignal();
}

void GUI::redoButtonHandler()
{
	try
	{
		this->undoCtrl->redo();
	}
	catch (ValidatorException& v)
	{
		QMessageBox error;
		error.critical(0, "Validator Exception", v.what());
		error.setFont(this->f);
		error.show();
	}
	catch (UndoException& e)
	{
		QMessageBox error;
		error.critical(0, "Error", e.what());
		error.setFont(this->f);
		error.show();
	}
	catch (exception& e)
	{
		QMessageBox error;
		error.critical(0, "Error", e.what());
		error.setFont(this->f);
		error.show();
	}

	emit updatedDogsSignal();
}

void GUI::showTableButtonHandler()
{
	QTableView* table = new QTableView{};
	table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	this->dogModel = new DogTableModel(this->adoption);
	//this->dogModel = new DogTableModel(this->ctrl->repo);
	table->setModel(this->dogModel);
	table->setItemDelegate(new PictureDelegate{ this->adoption });
	//table->setItemDelegate(new PictureDelegate{ this->ctrl->repo });
	table->resizeColumnsToContents();
	table->resizeRowsToContents();
	table->show();
}