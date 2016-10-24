// ConsoleApplication2.cpp : Defines the entry point for the console application.
//


#include "coach.h"
#include "player.h"
#include "supporters.h"
#include "field.h"
#include "goaly.h"
#include <iostream>
using namespace std;
int main()
{
	Goaly g;
	int a;
	cout << "введите а";
	cin >> a;
	g.setLuck (a);
	
    return 0;
}

