#include "SynchronizationPrimitives.h"

CSynchronizationPrimitives::CSynchronizationPrimitives(SyncPrimitives primitive)
{
	m_primitive = primitive;
}

CSynchronizationPrimitives::~CSynchronizationPrimitives()
{
	if (m_primitive == SyncPrimitives::CriticalSection)
	{
		DeleteCriticalSection(&m_criticalSection);
	}
}

void CSynchronizationPrimitives::CreatePrimitive()
{
	switch (m_primitive)
	{
	case SyncPrimitives::CriticalSection:
		InitializeCriticalSection(&m_criticalSection);
		break;
	case SyncPrimitives::Mutex:
		m_mutex = CreateMutex(NULL, false, NULL);
		break;
	case SyncPrimitives::Semaphore:
		m_semaphore = CreateSemaphore(NULL, 1, 1, NULL);
		break;
	case SyncPrimitives::Event:
		m_event = CreateEvent(NULL, false, true, NULL);
		break;
	default:
		break;
	}
}

void CSynchronizationPrimitives::StartOfSyncZone()
{
	if (m_primitive == SyncPrimitives::CriticalSection)
	{
		EnterCriticalSection(&m_criticalSection);
	}
	else if (m_primitive == SyncPrimitives::Mutex)
	{
		WaitForSingleObject(m_semaphore, INFINITE);
	}
	else if (m_primitive == SyncPrimitives::Semaphore)
	{
		WaitForSingleObject(m_mutex, INFINITE);
	}
	else if (m_primitive == SyncPrimitives::Event)
	{
		WaitForSingleObject(m_event, INFINITE);
	}
}

void CSynchronizationPrimitives::EndOfSyncZone()
{
	if (m_primitive == SyncPrimitives::CriticalSection)
	{
		LeaveCriticalSection(&m_criticalSection);
	}
	else if (m_primitive == SyncPrimitives::Mutex)
	{
		ReleaseMutex(m_mutex);
	}
	else if (m_primitive == SyncPrimitives::Semaphore)
	{
		ReleaseSemaphore(m_semaphore, 1, NULL);
	}
	else if (m_primitive == SyncPrimitives::Event)
	{
		SetEvent(m_event);
	}
}
