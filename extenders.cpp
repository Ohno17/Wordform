#include "extenders.h"

using namespace std;

// ------------------ JJexe -------------------------

#define UNIT_COUNT 101

const string units[UNIT_COUNT] = {
	"One",
	"Ten",
	"Hundered",
	"Thousand",
	"Ten Thousand",
	"Hundred Thousand",
	"Million",
	"Ten Million",
	"Hundred Million",
	"Billion",
	"Ten Billion",
	"Hundred Billion",
	"Trillion",
	"Ten Trillion",
	"Hundred Trillion",
	"Quadrillion",
	"Ten Quadrillion",
	"Hundred Quadrillion",
	"Quintillion",
	"Ten Quintillion",
	"Hundred Quintillion",
	"Sextillion",
	"Ten Sextillion",
	"Hundred Sextillion",
	"Septillion",
	"Ten Septillion",
	"Hundred Septillion",
	"Octillion",
	"Ten Octillion",
	"Hundred Octillion",
	"Nonillion",
	"Ten Nonillion",
	"Hundred Nonillion",
	"Decillion",
	"Ten Decillion",
	"Hundred Decillion",
	"Undecillion",
	"Ten Undecillion",
	"Hundred Undecillion",
	"Duodecillion",
	"Ten Duodecillion",
	"Hundred Duodecillion",
	"Tredecillion",
	"Ten Tredecillion",
	"Hundred Tredecillion",
	"Quattuordecillion",
	"Ten Quattuordecillion",
	"Hundred Quattuordecillion"
	"Quindecillion",
	"Ten Quindecillion",
	"Hundred Quindecillion",
	"Hexdecillion",
	"Ten Hexdecillion",
	"Hundred Hexdecillion",
	"Septendecillion",
	"Ten Septendecillion",
	"Hundred Septendecillion",
	"Octodecillion",
	"Ten Octodecillion",
	"Hundred Octodecillion",
	"Novemdecillion",
	"Ten Novemdecillion",
	"Hundred Novemdecillion",
	"Vigintillion",
	"Ten Vigintillion",
	"Hundred Vigintillion",
	"Googol",
	"Ten Googol",
	"Hundred Googol",
	"Centillion",
	"Ten Centillion",
	"Hundred Centillion"
};

int sanitize(string number) {
	if (number.length() > UNIT_COUNT || number.length() == 0) {
		cout << "Number must be at least 1 digit and at most " << UNIT_COUNT << "!" << endl;
		return 1;
	}
	return 0;
}

string removeExtraneousZeros(string number) {

	bool encounteredNonZero = false;
	string newstring = "";
	

	for (int i = 0; i < number.length(); i++) {

		char c = number.at(i);
		
		if (c != '0' && c != '+' && c != '-') {
			encounteredNonZero = true;
		}

		if (encounteredNonZero) {
			newstring = newstring + c;
		}
		
	}

	return newstring;
	
}

string convertPlural(string str)
{
	return str+"s";
}

string getUnit(int index, char c) {
	int num = c - '0';
	return (num > 1 || num == 0) ? convertPlural(units[index]) : units[index];
}

void jjexe_ExtendedNumber(string number)
{
	string sanitized;
	sanitized = removeExtraneousZeros(number);
	if (number.find('.') != string::npos) {
		sanitized = number.substr(0, number.find('.'));
		cout << "Only integers allowed! The numbers after the decimal have been chopped off." << endl;
	}
	bool negitive = false;
	if (number.at(0) == '-') {
		sanitized = sanitized.substr(1, sanitized.length()-1);
		negitive = true;
	}
	if (sanitize(sanitized)) return;

	cout << endl;
	
	bool hidez;
	cout << "Do you want to hide the zeros? [Y/N]: ";
	string answer;
	cin >> answer;

	hidez = (answer == "Y" || answer == "y") ? true : false;

	cout << endl << (negitive ? "-" : "") + sanitized << " in word form is:" << endl;
	
	int i = sanitized.length();
	int u = 0;
	while (i > 0)
	{
		i--;
		char c = sanitized.at(i);

		if (!(hidez && c == '0'))
			cout << 
				(i > 0 ? "" : "and ") <<
				c <<
				" " +
				getUnit(u, c) +
				(i > 0 ? ", " : ".");
		u++;
	}
}

// ------------ stub --------------

void stub_ExtendedNumber(string x)
{
int numberlength = x.length(); 
if (numberlength == 1) { 
    stringstream geek(x); 
    int xint = 0; 
    geek >> xint; 
    if (xint == 1) { 
        string oneorones = "one"; 
        cout << x << " = " << x << " " << oneorones; } else { 
        string oneorones = "ones"; 
        cout << x << " = " << x << " " << oneorones; } 
    } else if (numberlength == 2) { 
        stringstream geek(x); 
        int xint = 0; 
        geek >> xint; 
        double xtenslength2 = xint/10; 
        int tens = xtenslength2 * 10; 
        int ones = xint - tens; 
        string tensorten; 
        if (xtenslength2 == 1) { 
            tensorten = "ten"; 
        } else { 
            tensorten = "tens"; 
        } 
        string oneorones; 
        if (ones == 1) {
            oneorones = "one"; 
        } else { 
            oneorones = "ones"; 
        } 
        cout << x << " = " << xtenslength2 << " " << tensorten << " and " << ones << " " << oneorones; 
    } else if (numberlength == 3) { 
        stringstream geek(x); 
        int xint = 0; 
        geek >> xint; 
        int hundreds = xint/100; 
        double xtenslength3 = xint/10; 
        xtenslength3 = xtenslength3 - hundreds*10; 
        int tens = xtenslength3 * 10; 
        int hundredslength3 = hundreds*100; 
        int ones = xint - tens - hundredslength3; 
        string whatarethehundreds; 
        if (hundreds == 1) { 
            whatarethehundreds = "hundred"; 
        } else { 
            whatarethehundreds = "hundreds"; 
        } 
        string tensorten; 
        if (xtenslength3 == 1) { 
            tensorten = "ten"; 
} else { 
tensorten = "tens"; 
} 
string oneorones; 
if (ones == 1) { 
oneorones = "one"; 
} else { 
oneorones = "ones"; 
} 
cout << x << " = " << hundreds << " " << whatarethehundreds << ", " << xtenslength3 << " " << tensorten << " and " << ones << " " << oneorones; 
} else if (numberlength == 4) { 
stringstream geek(x); 
int xint = 0; 
geek >> xint; 
int thousands = xint/1000; 
thousands = thousands*1000;
xint = xint - thousands; 
int hundreds = xint/100; 
hundreds = hundreds*100; 
xint = xint - hundreds; 
int tens = xint/10; 
tens = tens*10; 
xint = xint - tens; 
int ones = xint; 
thousands = thousands/1000; 
hundreds = hundreds/100; 
tens = tens/10; 
ones = ones; 
string whatarethethousands; 
if (thousands == 1) { 
whatarethethousands = "thousand"; 
} else { 
whatarethethousands = "thousands"; 
} 
string whatarethehundreds; 
if (hundreds == 1) { 
whatarethehundreds = "hundred"; 
} else { 
whatarethehundreds = "hundreds"; 
} 
string tensorten; 
if (tens == 1) { 
tensorten = "ten"; 
} else { 
tensorten = "tens"; 
} 
string oneorones; 
if (ones == 1) { 
oneorones = "one"; 
} else { 
oneorones = "ones"; 
} 
cout << x << " = " << thousands << " " << whatarethethousands << ", " << hundreds << " " << whatarethehundreds << ", " << tens << " " << tensorten << ", and " << ones << " " << oneorones; 
} else if (numberlength == 5) { 
stringstream geek (x); 
int xint = 0;
geek >> xint; 
int tenthousands = xint/10000; tenthousands = tenthousands*10000; xint = xint - tenthousands; 
int thousands = xint/1000; 
thousands = thousands*1000; 
xint = xint - thousands; 
int hundreds = xint/100; 
hundreds = hundreds*100; 
xint = xint - hundreds; 
int tens = xint/10; 
tens = tens*10; 
xint = xint - tens; 
int ones = xint; 
tenthousands = tenthousands/10000; thousands = thousands/1000; 
hundreds = hundreds/100; 
tens = tens/10; 
ones = ones; 
string tenthousandsor; 
if (tenthousands == 1) { 
tenthousandsor = "ten thousand"; 
} else { 
tenthousandsor = "ten thousands"; } 
string whatarethethousands; 
if (thousands == 1) { 
whatarethethousands = "thousand"; } else { 
whatarethethousands = "thousands"; } 
string whatarethehundreds; 
if (hundreds == 1) { 
whatarethehundreds = "hundred"; } else { 
whatarethehundreds = "hundreds"; } 
string tensorten; 
if (tens == 1) { 
tensorten = "ten"; 
} else { 
tensorten = "tens"; 
} 
string oneorones;
if (ones == 1) { 
oneorones = "one"; 
} else { 
oneorones = "ones"; 
} 
cout << x << " = " << tenthousands << " " << tenthousandsor << ", " << thousands << " " << whatarethethousands << ", " << hundreds << " " << whatarethehundreds << ", " << tens << " " << tensorten << ", and " << ones << " " << oneorones; 
} else if (numberlength == 6) { 
stringstream geek (x); 
int xint = 0; 
geek >> xint; 
int hundredthousands = xint/100000; 
hundredthousands = hundredthousands*100000; 
xint = xint - hundredthousands; 
int tenthousands = xint/10000; 
tenthousands = tenthousands*10000; 
xint = xint - tenthousands; 
int thousands = xint/1000; 
thousands = thousands*1000; 
xint = xint - thousands; 
int hundreds = xint/100; 
hundreds = hundreds*100; 
xint = xint - hundreds; 
int tens = xint/10; 
tens = tens*10; 
xint = xint - tens; 
int ones = xint; 
hundredthousands = hundredthousands/100000; 
tenthousands = tenthousands/10000; 
thousands = thousands/1000; 
hundreds = hundreds/100; 
tens = tens/10; 
ones = ones; 
string hundredthousandor; 
if (hundredthousands == 1) { 
hundredthousandor = "hundred thousand"; 
} else { 
hundredthousandor = "hundred thousands"; 
} 
string tenthousandsor; 
if (tenthousands == 1) { 
tenthousandsor = "ten thousand";
} else { 
tenthousandsor = "ten thousands"; 
} 
string whatarethethousands; 
if (thousands == 1) { 
whatarethethousands = "thousand"; 
} else { 
whatarethethousands = "thousands"; 
} 
string whatarethehundreds; 
if (hundreds == 1) { 
whatarethehundreds = "hundred"; 
} else { 
whatarethehundreds = "hundreds"; 
} 
string tensorten; 
if (tens == 1) { 
tensorten = "ten"; 
} else { 
tensorten = "tens"; 
} 
string oneorones; 
if (ones == 1) { 
oneorones = "one"; 
} else { 
oneorones = "ones"; 
} 
cout << x << " = " << hundredthousands << " " << 
hundredthousandor << ", " << tenthousands << " " << tenthousandsor << ", " << thousands << " " << whatarethethousands << ", " << hundreds << " " << whatarethehundreds << ", " << tens << " " << tensorten << ", and " << ones << " " << oneorones; 
} else if (numberlength == 7) { 
stringstream geek (x); 
int xint = 0; 
geek >> xint; 
int millions = xint/1000000; 
millions = millions * 1000000; 
xint = xint - millions; 
int hundredthousands = xint/100000; 
hundredthousands = hundredthousands*100000; 
xint = xint - hundredthousands; 
int tenthousands = xint/10000;
tenthousands = tenthousands*10000; xint = xint - tenthousands; 
int thousands = xint/1000; 
thousands = thousands*1000; 
xint = xint - thousands; 
int hundreds = xint/100; 
hundreds = hundreds*100; 
xint = xint - hundreds; 
int tens = xint/10; 
tens = tens*10; 
xint = xint - tens; 
int ones = xint; 
millions = millions/1000000; 
hundredthousands = hundredthousands/100000; tenthousands = tenthousands/10000; thousands = thousands/1000; 
hundreds = hundreds/100; 
tens = tens/10; 
ones = ones; 
string millionsor; 
if (millions == 1) { 
millionsor = "million"; 
} else { 
millionsor = "millions"; 
} 
string hundredthousandor; 
if (hundredthousands == 1) { 
hundredthousandor = "hundred thousand"; } else { 
hundredthousandor = "hundred thousands"; } 
string tenthousandsor; 
if (tenthousands == 1) { 
tenthousandsor = "ten thousand"; 
} else { 
tenthousandsor = "ten thousands"; 
} 
string whatarethethousands; 
if (thousands == 1) { 
whatarethethousands = "thousand"; } else { 
whatarethethousands = "thousands"; } 
string whatarethehundreds;
if (hundreds == 1) { 
whatarethehundreds = "hundred"; 
} else { 
whatarethehundreds = "hundreds"; 
} 
string tensorten; 
if (tens == 1) { 
tensorten = "ten"; 
} else { 
tensorten = "tens"; 
} 
string oneorones; 
if (ones == 1) { 
oneorones = "one"; 
} else { 
oneorones = "ones"; 
} 
cout << x << " = " << millions << " " << millionsor << ", " << hundredthousands << " " << hundredthousandor << ", " << tenthousands << " " << tenthousandsor << ", " << thousands << " " << 
whatarethethousands << ", " << hundreds << " " << whatarethehundreds << ", " << tens << " " << tensorten << ", and " << ones << " " << oneorones; 
} else if (numberlength == 8) { 
stringstream geek (x); 
int xint = 0; 
geek >> xint; 
int tenmillions = xint/10000000;
tenmillions = tenmillions*10000000;
xint = xint - tenmillions;
int millions = xint/1000000; 
millions = millions * 1000000; 
xint = xint - millions; 
int hundredthousands = xint/100000; 
hundredthousands = hundredthousands*100000; 
xint = xint - hundredthousands; 
int tenthousands = xint/10000;
tenthousands = tenthousands*10000; xint = xint - tenthousands; 
int thousands = xint/1000; 
thousands = thousands*1000; 
xint = xint - thousands; 
int hundreds = xint/100; 
hundreds = hundreds*100; 
xint = xint - hundreds; 
int tens = xint/10; 
tens = tens*10; 
xint = xint - tens; 
int ones = xint; 
tenmillions = tenmillions/10000000;
millions = millions/1000000; 
hundredthousands = hundredthousands/100000; tenthousands = tenthousands/10000; thousands = thousands/1000; 
hundreds = hundreds/100; 
tens = tens/10; 
ones = ones; 
string tenmillionsor;
if (tenmillions == 1) {
    tenmillionsor = "ten million";
} else {
    tenmillionsor = "ten millions";
}
string millionsor; 
if (millions == 1) { 
millionsor = "million"; 
} else { 
millionsor = "millions"; 
} 
string hundredthousandor; 
if (hundredthousands == 1) { 
hundredthousandor = "hundred thousand"; } else { 
hundredthousandor = "hundred thousands"; } 
string tenthousandsor; 
if (tenthousands == 1) { 
tenthousandsor = "ten thousand"; 
} else { 
tenthousandsor = "ten thousands"; 
} 
string whatarethethousands; 
if (thousands == 1) { 
whatarethethousands = "thousand"; } else { 
whatarethethousands = "thousands"; } 
string whatarethehundreds;
if (hundreds == 1) { 
whatarethehundreds = "hundred"; 
} else { 
whatarethehundreds = "hundreds"; 
} 
string tensorten; 
if (tens == 1) { 
tensorten = "ten"; 
} else { 
tensorten = "tens"; 
} 
string oneorones; 
if (ones == 1) { 
oneorones = "one"; 
} else { 
oneorones = "ones"; 
} 
cout << x << " = " << tenmillions << " " << tenmillionsor << ", " <<  millions << " " << millionsor << ", " << hundredthousands << " " << hundredthousandor << ", " << tenthousands << " " << tenthousandsor << ", " << thousands << " " << 
whatarethethousands << ", " << hundreds << " " << whatarethehundreds << ", " << tens << " " << tensorten << ", and " << ones << " " << oneorones; 
} else if (numberlength == 9) { 
stringstream geek (x); 
int xint = 0; 
geek >> xint; 
int hundredmillions;
hundredmillions = xint/100000000;
hundredmillions = hundredmillions*100000000;
xint = xint - hundredmillions;
int tenmillions = xint/10000000;
tenmillions = tenmillions*10000000;
xint = xint - tenmillions;
int millions = xint/1000000; 
millions = millions * 1000000; 
xint = xint - millions; 
int hundredthousands = xint/100000; 
hundredthousands = hundredthousands*100000; 
xint = xint - hundredthousands; 
int tenthousands = xint/10000;
tenthousands = tenthousands*10000; xint = xint - tenthousands; 
int thousands = xint/1000; 
thousands = thousands*1000; 
xint = xint - thousands; 
int hundreds = xint/100; 
hundreds = hundreds*100; 
xint = xint - hundreds; 
int tens = xint/10; 
tens = tens*10; 
xint = xint - tens; 
int ones = xint; 
hundredmillions = hundredmillions/100000000;
tenmillions = tenmillions/10000000;
millions = millions/1000000; 
hundredthousands = hundredthousands/100000; tenthousands = tenthousands/10000; thousands = thousands/1000; 
hundreds = hundreds/100; 
tens = tens/10; 
ones = ones; 
string hundredmillionsor;
if (hundredmillions == 1) {
    hundredmillionsor = "hundred million";
} else {
    hundredmillionsor = "hundred millions";
}
string tenmillionsor;
if (tenmillions == 1) {
    tenmillionsor = "ten million";
} else {
    tenmillionsor = "ten millions";
}
string millionsor; 
if (millions == 1) { 
millionsor = "million"; 
} else { 
millionsor = "millions"; 
} 
string hundredthousandor; 
if (hundredthousands == 1) { 
hundredthousandor = "hundred thousand"; } else { 
hundredthousandor = "hundred thousands"; } 
string tenthousandsor; 
if (tenthousands == 1) { 
tenthousandsor = "ten thousand"; 
} else { 
tenthousandsor = "ten thousands"; 
} 
string whatarethethousands; 
if (thousands == 1) { 
whatarethethousands = "thousand"; } else { 
whatarethethousands = "thousands"; } 
string whatarethehundreds;
if (hundreds == 1) { 
whatarethehundreds = "hundred"; 
} else { 
whatarethehundreds = "hundreds"; 
} 
string tensorten; 
if (tens == 1) { 
tensorten = "ten"; 
} else { 
tensorten = "tens"; 
} 
string oneorones; 
if (ones == 1) { 
oneorones = "one"; 
} else { 
oneorones = "ones"; 
} 
cout << x << " = " << hundredmillions << " " << hundredmillionsor << ", " << tenmillions << " " << tenmillionsor << ", " <<  millions << " " << millionsor << ", " << hundredthousands << " " << hundredthousandor << ", " << tenthousands << " " << tenthousandsor << ", " << thousands << " " << 
whatarethethousands << ", " << hundreds << " " << whatarethehundreds << ", " << tens << " " << tensorten << ", and " << ones << " " << oneorones; 
} else {
    cout << "Your number was too big or you entered a string. ";
}
}