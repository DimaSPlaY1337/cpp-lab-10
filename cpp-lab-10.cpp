#include <iostream>

using namespace std;

template <typename Item>
class MyPriorityQueue
{

public:
	friend ostream& operator <<(ostream& out, MyPriorityQueue& queue)
	{
		out << "Size: " << queue.size() << endl;
		return out;
	}

	MyPriorityQueue(int length, Item ZeroElement)
	{
		this->ZeroElement = ZeroElement;
		this->lenght = length;
		massive = new Item[lenght];
		PriorityMassive = new int[lenght];
	}
	~MyPriorityQueue()
	{
		delete[] massive;
		delete[] PriorityMassive;
	}

	void push(Item item, int priority)
	{
		massive[CurrentElement] = item;
		PriorityMassive[CurrentElement] = priority;
		if (CurrentElement == lenght - 1)
			CurrentElement = 0;
		else
			CurrentElement += 1;
		MaxPriority = Max(MaxPriority, priority);
		MinPriority = Min(MinPriority, priority);
	}
	void pop()
	{
		for (int i = 0; i < lenght; i++)
		{
			if (PriorityMassive[i] != 0)
				MinPriority = Min(MinPriority, PriorityMassive[i]);
		}

		for (int i = 0; i < lenght; i++)
		{
			if (PriorityMassive[i] == MinPriority)
			{
				PriorityMassive[i] = 0;
				massive[i] = ZeroElement;
				cout << "Deleted item with number " << i << endl;
				break;
			}
		}

	}
	Item peek()
	{
		Item item = ZeroElement;
		for (int i = 0; i < lenght; i++)
		{
			if (PriorityMassive[i] != 0)
				MaxPriority = Max(MaxPriority, PriorityMassive[i]);
		}

		for (int i = 0; i < lenght; i++)
		{
			if (PriorityMassive[i] == MaxPriority)
			{
				item = massive[i];
				cout << "Returned item with number " << i << endl;
				break;
			}
		}
		return item;
	}
	int size()
	{
		return lenght;
	}

private:
	int Max(int a, int b)
	{
		return a > b ? a : b;
	}
	int Min(int a, int b)
	{
		return a > b ? b : a;
	}

	Item ZeroElement;
	int CurrentElement = 0;
	int lenght = 0;
	int MaxPriority = 0;
	int MinPriority = 10000;
	Item* massive;
	int* PriorityMassive;
};

int main()
{
	MyPriorityQueue<char> Queue(3, 0);
	Queue.push('s', 1);
	Queue.push('a', 2);
	Queue.push(']', 1);
	Queue.peek();
	Queue.pop();
	Queue.pop();
	cout << Queue;
	return 0;
}