#include "pch.h"
#include "HyperV.h"


BOOL check_hyperv_driver_objects()
{
	auto driverList = enumerate_object_directory(L"\\Driver");
	BOOL check = FALSE;
	if (driverList == nullptr)
	{
		return check;
	}
	for (wchar_t* driver : *driverList)
	{
		if (StrCmpCW(driver, L"VMBusHID") == 0)
		{
			check = TRUE;
		}
		if (StrCmpCW(driver, L"vmbus") == 0)
		{
			check = TRUE;
		}
		if (StrCmpCW(driver, L"vmgid") == 0)
		{
			check = TRUE;
		}
		if (StrCmpCW(driver, L"IndirectKmd") == 0)
		{
			check = TRUE;
		}
		if (StrCmpCW(driver, L"HyperVideo") == 0)
		{
			check = TRUE;
		}
		if (StrCmpCW(driver, L"hyperkbd") == 0)
		{
			check = TRUE;
		}
	}
	return check;
}


BOOL check_hyperv_global_objects()
{
	auto globalObjs = enumerate_object_directory(L"\\GLOBAL??");
	if (globalObjs == nullptr)
	{
		return FALSE;
	}
	for (wchar_t* globalObj : *globalObjs)
	{
		if (StrStrW(globalObj, L"VMBUS#") != NULL)
		{
			return TRUE;
		}
		if (StrCmpCW(globalObj, L"VDRVROOT") == 0)
		{
			return TRUE;
		}
		if (StrCmpCW(globalObj, L"VmGenerationCounter") == 0)
		{
			return TRUE;
		}
		if (StrCmpCW(globalObj, L"VmGid") == 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}
