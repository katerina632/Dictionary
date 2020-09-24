#include "Dictionary.h"

void Dictionary::AddEN(string key, const list<string>& translate) {
	if (DicEN_RU.find(key) != DicEN_RU.end())
		for (auto elem : translate)
			DicEN_RU[key].push_back(elem);
	else
		DicEN_RU.insert(make_pair(key, translate));
}

void Dictionary::AddRU(string key, const list<string>& translate) {
	if (DicRU_EN.find(key) != DicRU_EN.end())
		for (auto elem : translate)
			DicRU_EN[key].push_back(elem);

	else
		DicRU_EN.insert(make_pair(key, translate));
}

void Dictionary::FindEn(string key) {
	if (DicEN_RU.find(key) != DicEN_RU.end()) {
		cout << key << " - ";
		for (string elem : DicEN_RU[key])
			cout << elem << ", ";
		cout << endl;
	}
	else
		cout << "Word not found.";
}

void Dictionary::FindRu(string key) {
	if (DicRU_EN.find(key) != DicRU_EN.end()) {
		cout << key << " - ";
		for (string elem : DicRU_EN[key])
			cout << elem << ", ";
		cout << endl;
	}
	else
		cout << "Word not found.";
}

void Dictionary::Save(string path) const {
	ofstream fout(path);
	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "The file couldn't be opened.\n";
		return;
	}
	fout << DicEN_RU.size() << endl;
	for (auto i = DicEN_RU.begin(); i != DicEN_RU.end(); ++i) {
		fout << i->first << endl;
		fout << i->second.size() << endl;
		for (auto j = i->second.begin(); j != i->second.end(); j++) {
			fout << *j << endl;
		}
	}
	fout << DicRU_EN.size() << endl;
	for (auto i = DicRU_EN.begin(); i != DicRU_EN.end(); ++i) {
		fout << i->first << endl;
		fout << i->second.size() << endl;
		for (auto j = i->second.begin(); j != i->second.end(); j++) {
			fout << *j << endl;
		}
	}
	fout.close();
}

void Dictionary::Load(string path) {
	ifstream fin(path);
	bool isOpen = fin.is_open();
	if (isOpen == false) {
		cout << "The file couldn't be opened.\n";
		return;
	}
	string key, word;
	int sizeDic, sizeList;
	list<string>tmp;
	fin >> sizeDic;
	fin.ignore(1111, '\n');
	for (int i = 0; i < sizeDic; i++) {
		getline(fin, key);
		fin >> sizeList;
		fin.ignore(1111, '\n');
		for (int j = 0; j < sizeList; j++) {
			getline(fin, word);
			tmp.push_back(word);
			word = "";
		}
		DicEN_RU.insert(make_pair(key, tmp));
		key = "";
		tmp.clear();
	}
	fin >> sizeDic;
	fin.ignore(1111, '\n');
	for (int i = 0; i < sizeDic; i++) {
		getline(fin, key);
		fin >> sizeList;
		fin.ignore(1111, '\n');
		for (int j = 0; j < sizeList; j++) {
			getline(fin, word);
			tmp.push_back(word);
		}
		DicRU_EN.insert(make_pair(key, tmp));
		tmp.clear();
	}
	fin.close();
}