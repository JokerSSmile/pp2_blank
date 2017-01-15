#pragma once
#include <windows.h>

enum class SyncPrimitives
{
	CriticalSection,
	Mutex,
	Semaphore,
	Event,
	None,
};

class CSynchronizationPrimitives
{
public:
	CSynchronizationPrimitives(SyncPrimitives primitive);
	~CSynchronizationPrimitives();

	void CreatePrimitive();
	void StartOfSyncZone();
	void EndOfSyncZone();

private:
	SyncPrimitives m_primitive;
	HANDLE m_mutex;
	HANDLE m_semaphore;
	HANDLE m_event;
	CRITICAL_SECTION m_criticalSection;
};

