#include <iostream>
#include "Inventory.h"

using namespace std;
int main()
{
	Inventory<Item>* itemInventory = new Inventory<Item>();
	for (int i = 0; i < 11; ++i)
	{
		itemInventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();

	cout << "Size: " << itemInventory->GetSize() << endl;
	cout << "Capacity: " << itemInventory->GetCapacity() << endl;

	itemInventory->RemoveLastItem();

	itemInventory->PrintAllItems();

	delete itemInventory;

	return 0;
}

