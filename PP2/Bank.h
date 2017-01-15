#pragma once
#include <iostream>
#include <vector>

#include "SynchronizationPrimitives.h"
#include "BankClient.h"

class CBank
{
public:
	CBank(const unsigned& clientsCount, SyncPrimitives primitivesType);
	CBankClient* CreateClient();
	void UpdateClientBalance(CBankClient& client, int value);
	size_t GetClientsCount();
	DWORD WaitForClients();

private:
	std::vector<CBankClient> m_clients;
	std::vector<HANDLE> m_threads;
	int m_totalBalance;
	CSynchronizationPrimitives m_syncPrimitives;

	int GetTotalBalance();
	void SetTotalBalance(int value);
	void SomeLongOperations();
};