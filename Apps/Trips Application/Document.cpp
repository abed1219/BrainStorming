#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Document.h"
#define L 50

using namespace std;


void Document::setId(long id) {
    this->id = id;
}

void Document::setName(char* name) {
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}
void Document::setWords(int words) {
    this->words = words;
}


Document::Document() :id(1), words(0) {
    char t1[L] = "Trip";
    this->name = new char[strlen(t1)+1];
    strcpy(this->name, t1);
}

Document::Document(char* name, long id, int words) {
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->id = id;
    this->words = words;
}

Document::Document(const Document& other) :name(other.name), id(other.id), words(other.words) {
    *this = other;
}


const Document& Document:: operator=(const Document& other) {
    this->name = other.name;
    this->id = other.id;
    this->words = other.words;
    return *this;
}

bool Document:: operator==(Document& other) {
    if (!(strcmp(this->name, other.name)) && (this->id == other.id) && (this->words == other.words))
        return 1;
    return 0;
}

Document& Document:: operator+(const Document& o) {
    this->words += o.words;
    return *this;
}


ostream& operator<<(ostream& out, const Document& d) {
    d.show();
    out << "\nDocument ID: " << d.id << endl <<
        "Document Name: " << d.name << endl <<
        "Document Word count: " << d.words << endl;
    return out;
}



bool Document::Long() {
    return (this->words > 1000); // check if > 1k
}

Document::~Document() {


}
