#pragma once
#include <iostream>
#include "Item.h"
#include "Student.h"
using namespace std;

struct Room
{
    string name;
    Item item;
    Student* student;
};