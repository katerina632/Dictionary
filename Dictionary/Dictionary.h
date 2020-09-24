#pragma once
#include<iostream>
#include<fstream>
#include<list>
#include<string>
#include<Windows.h>
#include<map>
using namespace std;
class Dictionary {
	map<string, list<string>>DicEN_RU;
	map<string, list<string>>DicRU_EN;
public:
	void AddEN(string key, const list<string>& translate);
	void AddRU(string key, const list<string>& translate);
	void FindEn(string key);
	void FindRu(string key);
	void Save(string path = "DictionaryBase.txt")const;
	void Load(string path = "DictionaryBase.txt");
};

