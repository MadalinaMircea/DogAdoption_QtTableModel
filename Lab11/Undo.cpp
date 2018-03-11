#include "Undo.h"

void UndoAdd::executeUndo()
{
	this->ctrl.remove(this->addedDog.getBreed(), this->addedDog.getName());
}

void UndoRemove::executeUndo()
{
	this->ctrl.add(this->removedDog.getBreed(), this->removedDog.getName(), \
		this->removedDog.getAge(), this->removedDog.getPhoto());
}

void UndoUpdate::executeUndo()
{
	this->ctrl.update(this->updated.getBreed(), this->updated.getName(), \
		this->old.getAge(), this->old.getPhoto(), this->old.getBreed(), this->old.getName());
}

void UndoAdd::executeRedo()
{
	this->ctrl.add(this->addedDog.getBreed(), this->addedDog.getName(), \
		this->addedDog.getAge(), this->addedDog.getPhoto());
}

void UndoRemove::executeRedo()
{
	this->ctrl.remove(this->removedDog.getBreed(), this->removedDog.getName());
}

void UndoUpdate::executeRedo()
{
	this->ctrl.update(this->old.getBreed(), this->old.getName(), \
		this->updated.getAge(), this->updated.getPhoto(), this->updated.getBreed(), \
		this->updated.getName());
}

void UndoController::newOperation()
{
	while (this->undoActions.size() > this->index + 1)
		this->undoActions.pop_back();
}

void UndoController::undo()
{
	if (index == -1)
		throw UndoException("No operations to undo.");

	this->undoActions[this->index]->executeUndo();
	this->index = this->index - 1;

}

void UndoController::redo()
{
	if (index == this->undoActions.size() - 1)
		throw UndoException("No operations to redo.");

	this->undoActions[this->index + 1]->executeRedo();
	this->index = this->index + 1;

}