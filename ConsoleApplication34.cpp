#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class MainFile {

public:
	virtual void Display(const char* path) {
		ifstream fin(path);
			if (fin.is_open())
			{
				string line;
				while (getline(fin, line))
				{
					cout << line << endl;
				}
				fin.close();
			}
			else {
				cerr << "Cant opened this file\n";
			}
	}
	
};

class FileASCII : public MainFile {
public:
	void Display(const char* path) override {
		ifstream fin(path);
		if (!fin.is_open())
		{
			cerr << "Cant opened this file\n";
		}
		else {
			char ch;
		
			while (fin.get(ch)) {
				cout << static_cast<int>(ch) << ' ';

			}
			cout << endl;
			fin.close();
		}
	}

};

class File0101 : public MainFile {
public:
	void Display(const char* path) override {
		ifstream fin(path, iostream::binary);
		if (!fin.is_open())
		{
			cerr << "Cant opened this file\n";
		}
		else {
			char byte;
			while (fin.get(byte)) {
				for (int  i =7; i >= 0; i--)
				{
					cout << ((byte >> i) & 1);
				}
				cout << ' ';
			}
			cout << endl;
			fin.close();
		}
	}
};




int main() {
	MainFile ptr1;
	ptr1.Display("artem.txt");

	FileASCII ptr2;
	ptr2.Display("artem.txt");

	File0101 ptr3;
	ptr3.Display("artem.txt");
}