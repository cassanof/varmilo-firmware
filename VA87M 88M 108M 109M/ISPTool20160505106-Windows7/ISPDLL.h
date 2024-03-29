#pragma once

#ifndef WRITERCMD_API
#define WRITERCMD_API extern "C" __declspec(dllimport)
#endif

typedef struct MCUINFO_t
{
	DWORD cbSize;
	int	nPageSize;
	int nMaxProgramPage;
	int nMaxLockPage;
	int nBootloaderSize;
	char szMcuName[16]; //added
}MCUINFO;

// File Handle
WRITERCMD_API int  GetLoadFileErr();
WRITERCMD_API int  LoadFile(LPCTSTR szMtpPath, PBYTE& pProgramBuf, WORD& wProgramSize, PBYTE& pOptionBuf, WORD& wOptionSize, PBYTE& pDataBuf, WORD& wDataSize);
WRITERCMD_API int  LoadFileEx(LPCTSTR szMtpPath, PBYTE& pProgramBuf, DWORD& dwProgramSize, PBYTE& pOptionBuf, WORD& wOptionSize, PBYTE& pDataBuf, WORD& wDataSize);
WRITERCMD_API int  LoadProgdata(BYTE* pMtpBuf, DWORD dwMtpSize, PBYTE& pProgramBuf, WORD& wProgramSize, PBYTE& pOptionBuf, WORD& wOptionSize, PBYTE& pDataBuf, WORD& wDataSize);
WRITERCMD_API int  LoadProgdataEx(BYTE* pMtpBuf, DWORD dwMtpSize, PBYTE& pProgramBuf, DWORD& dwProgramSize, PBYTE& pOptionBuf, WORD& wOptionSize, PBYTE& pDataBuf, WORD& wDataSize);
WRITERCMD_API BOOL SaveFile(LPCTSTR szFilePath);
WRITERCMD_API int  GetChksum(BYTE calcMode);

// Programming
WRITERCMD_API int  BlankCheck(BYTE ucType);
WRITERCMD_API int  Program(BYTE ucType);
WRITERCMD_API int  PartialProgram(WORD wOffset, WORD wordLen);
WRITERCMD_API int  EraseByAddr(WORD wOffset, WORD wordLen, BYTE ucType);
WRITERCMD_API int  EraseByPage(WORD wPageStart, WORD wCnt, BYTE ucType);
WRITERCMD_API int  VerifyByAddr(WORD wOffset, WORD wordLen, BYTE ucType);
WRITERCMD_API int  VerifyByPage(WORD wPageStart, WORD wCnt, BYTE ucType);
WRITERCMD_API int  LockByAddr(WORD wOffset, WORD wordLen);
WRITERCMD_API int  LockByPage(WORD wStartPage, WORD wCnt);
WRITERCMD_API int  LockFromOption(PBYTE pOption, WORD wordLen);
WRITERCMD_API BOOL LockAll();
WRITERCMD_API void IgnoreBlank(BOOL bIgnore);
// Programming Progress
WRITERCMD_API int  GetTransProgress();	

// Miscellaneous
WRITERCMD_API BYTE GetBootloaderVer();
WRITERCMD_API int  ConnectToBootloader();
WRITERCMD_API int  ConnectToUserCode(WORD wUsage,WORD wUsagePage);
WRITERCMD_API WORD GotoBLMode(PBYTE pbyBuf,BYTE bySize);
WRITERCMD_API int  DisConnectBootloader();  
WRITERCMD_API void SwitchToUserProgram();
WRITERCMD_API int  ExecuteProgramFrom(BYTE byMode);
WRITERCMD_API BOOL i3kSys(WORD wOffset, WORD wSize, BYTE* buffer);
WRITERCMD_API BOOL GetMCUInfo(MCUINFO* pMcuInfo);