#include "redo.h"

void Redo::execute()
{
	int n = this->operation.size() - 1;
	if (this->operation[n].getOperation() == "add")
	{
		this->repo.add(this->operation[n].getMovie());
		this->pop();
		return;
	}
	if (this->operation[n].getOperation() == "delete")
	{
		int k = this->repo.findByTitle(this->operation[n].getMovie().getTitle());
		this->repo.del(k);
		this->pop();
		return;
	}
	if (this->operation[n].getOperation() == "update")
	{
		{
			OperationElement m = this->operation[n];
			this->repo.update(m.getMovieUpdate().getTitle(), m.getMovie().getTitle(), m.getMovie().getGenre(), m.getMovie().getYear(), m.getMovie().getLikes(), m.getMovie().getTrailer());
			this->pop();
		}
		return;
	}
}