#include "lab11.h"
#include <iostream>
#include "GUI.h"
#include "crtdbg.h"
#include "FileRepository.h"
#include "Exceptions.h"
#include "CSVList.h"
#include <QtWidgets/QApplication>
using namespace std;

int main(int argc, char *argv[])
{

	try
	{
		FileRepository* repo = new CSVList("dogs.txt");
		repo->loadFromFile();

		Controller* ctrl = new Controller{ repo };

		QApplication a(argc, argv);
		GUI* gui = new GUI{ ctrl };
		gui->show();
		return a.exec();
	}
	catch (FileException& e)
	{
		cout << e.what() << '\n';
		return 0;
	}
}