#include <iostream>
#include <string>

using namespace std;

class Product
{
	int id = NULL;
	char* name = nullptr;
	char* description = nullptr;
	double price = NULL;
	double* priceHistory = nullptr;

public:
	Product(int id,const char* name,const char* description, double price)
		:id(id), price(price)
	{
		this->setName(name);
		this->setDescrioption(description);
	}

	//all setters
	//....

	void setId(int id) {
		this->id = id;
	}

	void setName(const char* name) {
		if (this->name != nullptr)
			delete[] this->name;

		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void setDescrioption(const char* description) {
		if (this->description != nullptr)
			delete[] this->description;

		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}

	void setPrice(double price) {
		if (this->priceHistory == nullptr) {
			this->priceHistory = new double[1];
			this->priceHistory[0] = price;
		}

		else {
			double* historyCopy = new double[historySize + 1];
			for (int i = 0; i < historySize; i++)
				historyCopy[i] = this->priceHistory[i];

			historyCopy[historySize] = price;
			delete[] this->priceHistory;
			this->priceHistory = new double[historySize + 1];

			for (int i = 0; i < historySize + 1; i++)
				this->priceHistory[i] = historyCopy[i];
			delete[] historyCopy;
		}
		this->price = price;
		historySize++;
	}

	//all getters
	//.....

	int getId() { return this->id; }
	double getPrice() { return this->price; }

	char* getName() {
		char* nameCopy = new char[strlen(this->name) + 1];
		strcpy_s(nameCopy, strlen(this->name) + 1, this->name);
		return nameCopy;
	}

	double* getPriceHistory() {
		double* priceHistoryCopy = new double[historySize];
		for (int i = 0; i < historySize; i++)
			priceHistoryCopy[i] = priceHistory[i];
		return priceHistoryCopy;
	}

	double getPriceAverage()
	{
		double priceSum = 0;
		for (int i = 0; i < historySize; i++)
			priceSum += priceHistory[i];

		return priceSum / historySize;
	}

	Product(Product& product)
		:id(product.id), price(product.price), priceHistory(product.priceHistory)
	{
		this->setName(product.name);
		this->setDescrioption(product.description);
	}

	~Product()
	{
		delete[] this->name;
		delete[] this->description;
		delete[] this->priceHistory;
	}
private:
	int historySize = 0;
};

int main() {
	Product p0(23, (char*)"George", (char*)"Description", 23);
	cout << p0.getName() << endl;

	Product p1 = p0;
	p0.setName("Matei");
	cout << p1.getName();

	cout << endl;

	int id;
	cout << "Enter id: ";
	cin >> id;

	char* name= new char[100];
	cout << "Enter name: ";
	cin.ignore();
	cin.getline(name, 100);

	char* description = new char[100];
	cout << "Enter description: ";
	cin.getline(description, 100);

	double price;
	cout << "Enter price: ";
	cin >> price;

	Product p2(id, name, description, price);
	cout << p2.getName();
	
	delete[] name;
	delete[] description;
}