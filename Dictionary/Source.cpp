
#include"Dictionary.h"

int main() {
	system("chcp 1251");
	Dictionary dic,dictionary;
	string word;
	dic.AddEN("Run",list<string>{ "работать", "бежать", "управлять", "бегать", "прогон", "работа", "бег", "пробег", "ход", "показ", "трасса"});
	dic.AddEN("Mind", list<string>({ "разум", "ум", "внимание", "взгляд", "возражать", "помнить", "мягкий", "слабый" }));
	dic.AddEN("Bad", list<string>({ "плохой", "нехороший"," нехорошо", "неудача", "несчастье", "убыток" }));
	dic.AddRU("Человек", list<string>({ "man", "person", "human", "individual", "human being", "fellow", "subject", "body", "soul" }));
	dic.AddRU("Ехать", list<string>({"go", "ride", "drive", "travel", "fare"  }));
	dic.AddRU("Милый", list<string>({  "cute","dear", "sweet", "nice", "darling"," lovely", "honey", "pleasant", "lovable" }));
	dic.Save();
	int action, mode=0;
	do {
		system("cls");
		cout << "Choose action:\n1.Load dictionary base\n2.Select mode\n3.Find word\n4.Exit\n";
		cin >> action;
		system("cls");
		switch (action) {
		case 1:
			dictionary.Load();
			
			cout << "Dictionary base successufully loaded.\n";
			Sleep(2000);
			break;
		case 2:
			do {
				cout << "Select mode:\n1.English-Russian\n2.Russian-English\n";
				cin >> mode;
				if (mode != 1 && mode != 2) {
					cout << "Invalid value.\n";
					Sleep(2000);
				}
			} while (mode != 1 && mode != 2);
			break;
		case 3:
			word = "";
			if (mode != 1 && mode != 2) {
				cout << "First select the operating mode.\n";
				Sleep(2000);
				break;
			}
			cout << "Enter word:";
			cin >> word;
			system("cls");
			if (mode == 1)
				dictionary.FindEn(word);
			else
				dictionary.FindRu(word);
			cout << endl;
			system("pause");
			break;
		case 4:
			break;
		default:
			cout << "Invalid value.";
			Sleep(2000);
			break;
		}

	} while (action != 4);

	return 0;
}

