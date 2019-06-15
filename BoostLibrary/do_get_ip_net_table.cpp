// do_get_ip_net_table.cpp
// Taken from:
// https://www.winsocketdotnetworkprogramming.com/winsock2programming/winsock2advancediphelperfunction13c.html
// Windows stuff; to satisfy the linker:
// Additional Dependencies Iphlpapi.lib 
#include <windows.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <cstdlib>
#include <assert.h>
#include <string>

using namespace std;
inline string IpAddrToStr(unsigned short c1,
	unsigned short c2, unsigned short c3, unsigned short c4) {
	string str = to_string(c1) + '.' +
		to_string(c2) + '.' +
		to_string(c3) + '.' +
		to_string(c4);
	return str;
}

inline DWORD MyGetIpNetTable(PMIB_IPNETTABLE& pIpNetTable, BOOL fOrder) {
	DWORD status = NO_ERROR;
	DWORD statusRetry = NO_ERROR;
	DWORD dwActualSize = 0;
	fOrder = FALSE;

	// query for buffer size needed
	dwActualSize = 0;
	status = GetIpNetTable(pIpNetTable, &dwActualSize, fOrder);

	if (status == NO_ERROR)
		return status;
	else
		if (status == ERROR_INSUFFICIENT_BUFFER) {
			// need more space
			pIpNetTable = (PMIB_IPNETTABLE)malloc(dwActualSize);
			assert(pIpNetTable);
			statusRetry = GetIpNetTable(pIpNetTable, &dwActualSize, fOrder);

			if (statusRetry == NO_ERROR)
				return statusRetry;
			else {
				printf("Retry failed\n");
				return statusRetry;
			}
		}
		else {
			printf("First GetIpNetTable() failed\n");
			return status;
		}
}

inline DWORD MyGetIpAddrTable(PMIB_IPADDRTABLE& pIpAddrTable, BOOL fOrder) {
	DWORD status = NO_ERROR;
	DWORD statusRetry = NO_ERROR;
	DWORD dwActualSize = 0;
	fOrder = FALSE;

	// query for buffer size needed
	dwActualSize = 0;
	status = GetIpAddrTable(pIpAddrTable, &dwActualSize, fOrder);

	if (status == NO_ERROR) {
		printf("No error!\n");
		return status;
	}
	else
		if (status == ERROR_INSUFFICIENT_BUFFER) {
			// need more space
			pIpAddrTable = (PMIB_IPADDRTABLE)malloc(dwActualSize);
			assert(pIpAddrTable);

			statusRetry = GetIpAddrTable(pIpAddrTable, &dwActualSize, fOrder);
			return statusRetry;
		}
		else
			return status;
}

inline BOOL InterfaceIdxToInterfaceIp(PMIB_IPADDRTABLE pIpAddrTable, DWORD dwIndex,
	char str[]) {
	struct in_addr inadTmp;
	char* szIpAddr;
	DWORD dwIdx;
	size_t INT_ADDRSTRLEN = 128;

	if (pIpAddrTable == NULL || str == NULL)
		return FALSE;

	str[0] = '\0';

	for (dwIdx = 0; dwIdx < pIpAddrTable->dwNumEntries; dwIdx++) {
		if (dwIndex == pIpAddrTable->table[dwIdx].dwIndex) {
			inadTmp.s_addr = pIpAddrTable->table[dwIdx].dwAddr;
			string str_ = IpAddrToStr(inadTmp.S_un.S_un_b.s_b1,
				inadTmp.S_un.S_un_b.s_b2,
				inadTmp.S_un.S_un_b.s_b3,
				inadTmp.S_un.S_un_b.s_b4);
			if (str_.length()) {
				strcpy_s(str, str_.length() + 1, str_.c_str());
				return TRUE;
			}
			else
				return FALSE;
		}
	}
	return FALSE;
}

inline BOOL PhysAddrToString(BYTE PhysAddr[], DWORD PhysAddrLen, char str[]) {
	DWORD dwIdx;

	if (PhysAddr == NULL || PhysAddrLen == 0 || str == NULL)
		return FALSE;

	str[0] = '\0';

	for (dwIdx = 0; dwIdx < PhysAddrLen; dwIdx++) {
		if (dwIdx == PhysAddrLen - 1)
			sprintf_s(str + (dwIdx * 3), sizeof(str + (dwIdx * 3)), "%02X",
			((int)PhysAddr[dwIdx]) & 0xff);
		else
			sprintf_s(str + (dwIdx * 3), sizeof(str + (dwIdx * 3)), "%02X-",
			((int)PhysAddr[dwIdx]) & 0xff);
	}
	return TRUE;
}

inline void PrintIpNetTable(const PMIB_IPNETTABLE& pIpNetTable) {
	DWORD i, dwStatus, dwCurrIndex;
	struct in_addr inadTmp;
	char szPrintablePhysAddr[256];
	char szType[128];
	char szIpAddr[128];
	PMIB_IPADDRTABLE pIpAddrTable = NULL;

	if (pIpNetTable == NULL) {
		printf("pIpNetTable == NULL in line %d\n", __LINE__);
		return;
	}

	// get IP Address Table for mapping interface index number to ip address
	if ((dwStatus = MyGetIpAddrTable(pIpAddrTable, FALSE)) != NO_ERROR) {
		printf("MyGetIpAddrTable() returned 0x%x\n", dwStatus);
		if (pIpAddrTable)
			free(pIpAddrTable);
		return;
	}
	assert(pIpAddrTable);

	// Note: the ARP table should be sorted in interface index
	dwCurrIndex = pIpNetTable->table[0].dwIndex;
	if (InterfaceIdxToInterfaceIp(pIpAddrTable, dwCurrIndex, szIpAddr)) {
		printf("Interface: %s on Interface 0x%X\n", szIpAddr, dwCurrIndex);
		printf("  Internet Address      Physical Address      Type\n");
	}
	else {
		printf("Error: Could not convert Interface number 0x%X to IP address.\n",
			pIpNetTable->table[0].dwIndex);
		return;
	}

	for (i = 0; i < pIpNetTable->dwNumEntries; ++i) {
		if (pIpNetTable->table[i].dwIndex != dwCurrIndex) {
			dwCurrIndex = pIpNetTable->table[i].dwIndex;
			if (InterfaceIdxToInterfaceIp(pIpAddrTable, dwCurrIndex, szIpAddr)) {
				printf("Interface: %s on Interface 0x%X\n", szIpAddr, dwCurrIndex);
				printf("  Internet Address      Physical Address      Type\n");
			}
			else {
				printf("Error: Could not convert Interface number 0x%X to IP address.\n",
					pIpNetTable->table[0].dwIndex);
				return;
			}
		}
		PhysAddrToString(pIpNetTable->table[i].bPhysAddr, pIpNetTable->table[i].dwPhysAddrLen, szPrintablePhysAddr);
		inadTmp.s_addr = pIpNetTable->table[i].dwAddr;
		switch (pIpNetTable->table[i].dwType) {
		case 1:
			strcpy_s(szType, sizeof(szType), "Other");
			break;
		case 2:
			strcpy_s(szType, sizeof(szType), "Invalidated");
			break;
		case 3:
			strcpy_s(szType, sizeof(szType), "Dynamic");
			break;
		case 4:
			strcpy_s(szType, sizeof(szType), "Static");
			break;
		default:
			strcpy_s(szType, sizeof(szType), "InvalidType");
		}
		string str_ = IpAddrToStr(inadTmp.S_un.S_un_b.s_b1,
			inadTmp.S_un.S_un_b.s_b2,
			inadTmp.S_un.S_un_b.s_b3,
			inadTmp.S_un.S_un_b.s_b4);
		printf("  %-16s      %-17s     %-11s\n", str_.c_str(), szPrintablePhysAddr, szType);
	}

	if (pIpAddrTable)
		free(pIpAddrTable);
}

inline void DoGetIpNetTable() {
	DWORD dwStatus;
	PMIB_IPNETTABLE pIpArpTable = NULL;

	if ((dwStatus = MyGetIpNetTable(pIpArpTable, TRUE)) == NO_ERROR) {
		printf("Some entries in arp cache\n");
		PrintIpNetTable(pIpArpTable);
		free(pIpArpTable);
		return;
	}
}