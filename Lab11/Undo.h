#pragma once
#include "Controller.h"

class UndoException : public exception
{
	char* error;
public:
	UndoException(char* msg) { this->error = msg; }
	char* what() { return this->error; }
};

class UndoAction
{
public:
	~UndoAction() {};
	void virtual executeUndo() = 0;
	void virtual executeRedo() = 0;
};

class UndoAdd : public UndoAction
{
	Dog addedDog;
	Controller& ctrl;

public:
	UndoAdd(Dog& d, Controller& c) : addedDog(d), ctrl(c) {};
	void executeUndo() override;
	void executeRedo() override;
};

class UndoRemove : public UndoAction
{
	Dog removedDog;
	Controller& ctrl;

public:
	UndoRemove(Dog& d, Controller& c) : removedDog(d), ctrl(c) {};
	void executeUndo() override;
	void executeRedo() override;
};

class UndoUpdate : public UndoAction
{
	Dog old, updated;
	Controller& ctrl;

public:
	UndoUpdate(Dog& d1, Dog& d2, Controller& c) : old(d1), updated(d2), ctrl(c) {};
	void executeUndo() override;
	void executeRedo() override;
};

class UndoController
{
public:
	std::vector<UndoAction*> undoActions;
	int index;

	UndoController() { this->index = -1; }
	void undo();
	void redo();
	void newOperation();
};