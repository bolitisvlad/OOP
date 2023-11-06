#include <iostream>
#include <string>

using namespace std;

enum finantare
{
	TAXA = 1,
	BUGET = 2,
	BUGET_BURSA = 3
};


class Student
{
	string nume;
	char* adresa;
	int varsta;
	int an_studii;
public:

	//constructori
	Student()
	{
		this->note = nullptr;
		this->adresa = nullptr;
		this->nume = "";
		this->varsta = -1;
	}

	Student(string _nume, char* _adresa, int _varsta, int _an_studii, int* _note, int _numar_materii, string _numar_matricol, finantare _finantare) :
		nume(_nume), varsta(_varsta), an_studii(_an_studii), numar_matricol(_numar_matricol), finantare(_finantare), numar_materii(_numar_materii)
	{
		//care este diferenta?
		// 
		//this->adresa = _adresa;

		this->setAdress(_adresa);

		this->set_note(_note, _numar_materii);
		//this->note = new int[_numar_materii];
		//for (int index = 0; index < _numar_materii; index++)
		//{
		//	this->note[index] = _note[index];
		//}

	}

	Student(Student& stud) {
		this->setName(stud.nume);
		this->setAdress(stud.adresa);
		this->setVarsta(stud.varsta);
		this->setAnStudii(stud.an_studii);
		this->set_note(stud.note, stud.numar_materii);
		this->set_numar_matricol(stud.numar_matricol);
		this->set_finantare(stud.finantare);
	}

	// Implementarea constructorului de copiere va rezolva problema care genereaza exceptiile lansate la executia destructorului - incercarea de a 
				//dezaloca a doua oara aceeasi zona de memorie care a fost anterior dezalocata
	// Aceasta implementare apeleazza constructorul cu parametri. In cadrul constructorului cu parametri alocarea memoriei este facuta corect pentru cele doua variabile membre de tip pointer

	/*
	Student(const Student& student):
		Student(student.nume, student.adresa, student.varsta, student.an_studii, student.note, student.numar_materii, student.numar_matricol, student.finantare)
	{

	}
	*/

	//Sa se implementeze constructorul de copiere fara a apela constructorul cu parametri astfel incat:
   //				- copierea valorilor (in noul obiect) sa se realizeze corect  
   //              - dezalocarea memoriei sa se realizeze fara a genera exceptii

   /*
   Student(const Student& student)
   {

   }
   */

   //setters
	void set_note(int* _note, int _numar_materii)
	{
		this->numar_materii = _numar_materii;
		//this->note = _note;

		if (this->note != nullptr)
			delete[] this->note;
		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	void set_numar_matricol(string _nr_matricol)
	{
		this->numar_matricol = _nr_matricol;
	}

	void set_finantare(finantare _finantare)
	{
		this->finantare = _finantare;
	}

	void setName(string name) {
		this->nume = name;
	}

	void setAdress(char* adresa) {
		if (this->adresa != nullptr)
			delete[] this->adresa;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
	}

	void setVarsta(int varsta) {
		this->varsta = varsta;
	}

	void setAnStudii(int an) {
		this->an_studii = an;
	}

	//getters
	int* get_note() { return this->note; }
	string get_numar_matricol() { return this->numar_matricol; }
	finantare get_finantare() { return this->finantare; }
	int get_numar_materii() { return this->numar_materii; }


	//destructor
	~Student()
	{
		delete[] this->adresa;
		delete[] this->note;
	}
private:
	int* note;
	string numar_matricol;
	finantare finantare;
	int numar_materii;
};

class Book {
	char* author;
	string title;
	int pages_no;
	int* pages_word_count;
	bool online;

public:
	void setAuthor(char* author) {
		if (this->author != nullptr)
			delete[] this->author;
		this->author = new char[strlen(author) + 1];
		strcpy_s(this->author, strlen(author) + 1, author);
	}

	void setTitle(string title) {
		this->title = title;
	}

	void setPageNO(int pages_no) {
		this->pages_no = pages_no;
	}

	void setPagesWordCount(int* pages_word_count) {
		if (this->pages_word_count != nullptr)
			delete[] this->pages_word_count;

		this->pages_word_count = new int[pages_no];
		for (int i = 0; i < pages_no; i++) {
			this->pages_word_count[i] = pages_word_count[i];
		}
	}

	void setOnline(bool online) {
		this->online = online;
	}

	string getTitle() { return this->title; }
	int getPagesNo() { return this->pages_no; }
	bool getOnline() { return this->online; }

	char* getAuthor() {
		char* authorCopy = new char[strlen(this->author) + 1];
		strcpy_s(authorCopy, strlen(this->author) + 1, this->author);
		return authorCopy;
	}

	int* getPagesWordCount() {
		int* copy = new int[pages_no];
		for (int i = 0; i < pages_no; i++)
			copy[i] = pages_word_count[i];
		return copy;
	}

	Book(char* author, string title, int pages_no, int* pages_word_count, bool online) {
		this->setAuthor(author);
		this->setTitle(title);
		this->setPageNO(pages_no);
		this->setPagesWordCount(pages_word_count);
		this->setOnline(online);
	}

	Book(Book& book) {
		this->setAuthor(book.author);
		this->setTitle(book.title);
		this->setPageNO(book.pages_no);
		this->setPagesWordCount(book.pages_word_count);
		this->setOnline(book.online);
	}

	~Book() {
		delete[] this->author;
		delete[] this->pages_word_count;
	}
};

//exemple vizibilitate - constructori/destructori/metode/atribute
//exemplu constructor de copiere

int main()
{
	Student s0;

	//s0.setName("Anghel Mihai");

	//s0.adresa = new char[20];
	//strcpy_s(s0.adresa, 20, "Bucuresti, Sector 1");

	s0.setName("Anghel Mihai");
	s0.setAdress((char*)"Bcuresti, Sector 6");
	s0.setVarsta(24);
	s0.setAnStudii(2025);
	//s0.varsta = 21;
	//s0.an_studii = 2;

	//de ce este generata eroarea?
	//s0.note = new int[20];

	s0.set_numar_matricol("A689867");
	s0.set_finantare(finantare::BUGET_BURSA);

	// discutie eroare invalid heap pointer
	int note[10] = { 9,10,10,10,8,9,7,10,5,10 };
	s0.set_note(note, 10);

	//Student s1 = Student("Popescu I", (char*)"Bucuresti, Sector 1", 21, 2, note, 10, "A689867", finantare::BUGET_BURSA);

	//Student s2 = s1;
	//s2.nume = "Ionescu C";

	int* array = new int[3];
	for (int i = 0; i < 3; i++)
		array[i] = 5;

	Book b0((char*)"George", "Title", 3, array, false);

	Book b1 = b0;

	cout << b1.getAuthor();
	delete[] array;
}