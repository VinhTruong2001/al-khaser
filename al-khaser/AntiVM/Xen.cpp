#include "pch.h"

#include "Xen.h"

/*
Check for process list
*/

BOOL xen_process()
{
	const TCHAR *szProcesses[] = {
		_T("xenservice.exe"),
	};

	WORD iLength = sizeof(szProcesses) / sizeof(szProcesses[0]);
	
	BOOL check = FALSE;

	for (int i = 0; i < iLength; i++)
	{
		TCHAR msg[256] = _T("");
		_stprintf_s(msg, sizeof(msg) / sizeof(TCHAR), _T("Checking Citrix Xen process %s"), szProcesses[i]);
		if (GetProcessIdFromName(szProcesses[i])) {
			print_results(TRUE, msg);
			check = TRUE;
		}
		else
			print_results(FALSE, msg);
	}

	return check;
}



/*
Check Xen NIC MAC address
*/
BOOL xen_check_mac()
{
	// Xensource, Inc. 
	return check_mac_addr(_T("\x00\x16\x3E"));
}
