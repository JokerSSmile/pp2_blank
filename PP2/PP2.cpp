#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"

using namespace std;

void PrintInfo()
{
	cout << "To use one of synchronization primitives" << endl;
	cout << "type needed number as program parameter:" << endl;
	cout << "1 - for critical section" << endl;
	cout << "2 - for mutex" << endl;
	cout << "3 - for semafor" << endl;
	cout << "4 - for event" << endl;
}

int main(int argc, *char argv[])
{
	CBank* bank = new CBank();
	CBankClient* client1 = bank->CreateClient();
	CBankClient* client2 = bank->CreateClient();



	// TODO: WaitForMultipleObjects
	while (true)
	{
		//WaitForMultipleObjects(bank->GetClientCount(), )
	}

    return 0;
}