#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void toUTF8(int symbol);
string toBinary(int num);

int main()
{
	int israiska;
	cout << "iveskite desimtaine israiska: ";
	cin >> israiska;
	toUTF8(israiska); // (0xc4)

	//fw << ConvertToUTF8(196); // (0xc4)
	system("pause");
	return 0;
}


void toUTF8(int symbol)
{
	string binary = toBinary(symbol);
	string newBinary;

	// ribos tarp tam tikru bitu nuo 1 iki 4
	if (0x0000 <= symbol && symbol <= 0x007F)
	{
		newBinary = "0xxxxxxx";
	}

	if (0x0080 <= symbol && symbol <= 0x07FF)
	{
		newBinary = "110xxxxx10xxxxxx";
	}

	if (0x0800 <= symbol && symbol <= 0xFFFF)
	{
		newBinary = "1110xxxx10xxxxxx10xxxxxx";
	}

	if (0x10000 <= symbol && symbol <= 0x10FFFF)
	{
		newBinary = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	}


	while (binary.size() < newBinary.size()) //uzpildome galimus tarpus sulyginus su nauja bitu reiksme 
	{
		binary = "0" + binary;
	}


	for (int i = binary.size() - 1, j = newBinary.size() - 1; i >= 0 || j >= 0; i--, j--) // Jeigu elementu masyve 5 elementai grazins 5. cikle nuo 0 skaiciuos pradedam nuo galo pagal pertvarkyta pavyzdi.
	{
		if (j < 0 || i > binary.size() - 1) // patikriname ar neuzeina indeksai uz ribu ir jei ne tai tikrinam ir vadam reiksmes i pertvarkyta utf-8
			break;
		if (newBinary[j] == 'x') // jeigu reiksme neuzblokuota bitu dydziui priskiriama reiskme 
		{
			newBinary[j] = binary[i]; // tada priskiriame tam vietai reiksme
		}

		else
		{
			j--; // utf-8 dvejetaine reiksme
			i++; // orginali reiksme
		}
	}


	cout << "UTF-8 reiksme(dvejetaine): " << newBinary << endl;
	//cout << "newBinary.size() = " << newBinary.size() << endl;
	// kad gauti UTF - 8 ( reikia pasiversti is pertvarkytos dvejetaines(Utf-8) i sesioliktaine(Utf-8) su raidem ir t.t


	string bin, hex;


	for (int i = 0; i < newBinary.size(); i += 4) // Kas idomu tai kad unicoda galima gauti jeigu lyginsime binary.size() t.y jeigu bendra dvejetaine nepertvarkyti versija.
	{
		bin = "";
		bin += newBinary[i];
		bin += newBinary[i + 1];
		bin += newBinary[i + 2];
		bin += newBinary[i + 3];

		if (bin == "0000")
			hex += "0";
		else if (bin == "0001")
			hex += "1";
		else if (bin == "0010")
			hex += "2";
		else if (bin == "0011")
			hex += "3";
		else if (bin == "0100")
			hex += "4";
		else if (bin == "0101")
			hex += "5";
		else if (bin == "0110")
			hex += "6";
		else if (bin == "0111")
			hex += "7";
		else if (bin == "1000")
			hex += "8";
		else if (bin == "1001")
			hex += "9";
		else if (bin == "1010")
			hex += "A";
		else if (bin == "1011")
			hex += "B";
		else if (bin == "1100")
			hex += "C";
		else if (bin == "1101")
			hex += "D";
		else if (bin == "1110")
			hex += "E";
		else if (bin == "1111")
			hex += "F";
	}

	cout << "hex: " << hex << endl;


}

string toBinary(int num)
{
	string binary = "";
	while (num != 0)
	{
		if (num % 2 == 0)
		{
			binary = "0" + binary;
		}

		else
		{
			binary = "1" + binary;
		}

		num /= 2;
	}

	cout << "Origanali reiksme paversta dvejaitaine forma: " << binary << endl;
	return binary;
}
