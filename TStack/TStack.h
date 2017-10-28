
template <class T>

class TStack
{
private:
	int Size;
	int MaxSize;
	T *Mas;

public:
	TStack(int _MaxSize = 100)
	{
		MaxSize=_MaxSize;
		Size=0;
		Mas=new T[MaxSize];
	}

	~TStack()
	{
		delete[] mas;
	}
	TStack(const T &ts)
	{
		MaxSize=ts.MaxSize;
		Size=ts.Size;

	}
	bool IsEmpty();
	bool IsFull();

};


