#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"
#include "SynchronizationPrimitives.h"
#include <string>

using namespace std;

void PrintInfo()
{
	cout << "Using: PP2.exe <clients count> <synchronization primitive>" << endl;
	cout << "<synchronization primitive> is not necessary" << endl;
	cout << endl;
	cout << "To use one of synchronization primitives" << endl;
	cout << "type needed number as program parameter:" << endl;
	cout << "1 - for critical section" << endl;
	cout << "2 - for mutex" << endl;
	cout << "3 - for semafor" << endl;
	cout << "4 - for event" << endl;
}

SyncPrimitives DetermineSyncPrimitive(string str)
{
	if (str == "1")
	{
		return SyncPrimitives::CriticalSection;
	}
	else if (str == "2")
	{
		return SyncPrimitives::Mutex;
	}
	else if (str == "3")
	{
		return SyncPrimitives::Semaphore;
	}
	else if (str == "4")
	{
		return SyncPrimitives::Event;
	}
	return SyncPrimitives::None;
}

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		PrintInfo();
		return 0;
	}
	if (argc > 1)
	{
		if (argv[0] == "/?")
		{
			PrintInfo();
		}
		else
		{
			CBank* bank;
			unsigned cliensCount;

			try
			{
				cliensCount = std::stoi(argv[1]);
			}
			catch (std::exception)
			{
				cout << "Invalid input" << endl;
				return 1;
			}

			if (argc == 3)
			{
				bank = new CBank(cliensCount, DetermineSyncPrimitive(argv[2]));
			}
			else
			{
				bank = new CBank(cliensCount, SyncPrimitives::None);
			}

			while (true)
			{
				bank->WaitForClients();
			}
		}
	}

    return 0;
}