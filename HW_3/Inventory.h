#include <string>
#include <iostream>
#pragma once
using namespace std;

class Item
{
public:
	Item() : name_(""), price_(0) {}
	Item(const string& name, int price):name_(name), price_(price) {}

	const string& GetName() const {
		return name_;
	}

	int GetPrice() const { return price_; }
	void Clear()
	{
		name_ = "";
		price_ = 0;
	}
	void PrintInfo() const {
		cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
	}

private:
	std::string name_;
	int price_;
};

template<typename T>
class Inventory
{
public:
	Inventory(int capacity = 10);  
	~Inventory();                  

	
	void AddItem(const T& item);
	void RemoveLastItem();         
	int GetSize() const;          
	int GetCapacity() const;       
	void PrintAllItems() const;    

private:
	T* pItems_;
	int capacity_;
	int size_;
};

template<typename T>
Inventory<T>::Inventory(int capacity)
{
	if (capacity <= 0)
	{
		capacity_ = 1;
	}
	else {
		capacity_ = capacity;
	}
	size_ = 0;
	pItems_ = new T[capacity_];
}

template<typename T>
Inventory<T>::~Inventory() {
	delete[] pItems_;
	pItems_ = nullptr;
}

template<typename T>
void Inventory<T>::AddItem(const T& item) {
	if (size_ < capacity_)
	{
		pItems_[size_] = item;
		size_++;
	}
	else
	{
		cout << "인벤토리가 꽉 찼습니다!" << endl;
	}
}

template<typename T>
void Inventory<T>::RemoveLastItem() {
	if (size_ > 0)
	{

		size_--;
	}
	else {
		cout << "인벤토리가 비어있습니다." << endl;
	}
}

template<typename T>
int Inventory<T>::GetSize()const {
	return size_;
}

template<typename T>
int Inventory<T>::GetCapacity()const {
	return capacity_;
}

template<typename T>
void Inventory<T>::PrintAllItems()const {
	if (size_ == 0)
	{
		std::cout << "비어있음" << std::endl;
		return;
	}

	for (int i = 0; i < size_; i++)
	{
		pItems_[i].PrintInfo();
	}
}

