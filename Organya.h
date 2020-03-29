#pragma once

#include "WindowsWrapper.h"

#define MAXTRACK 16
#define MAXMELODY 8
#define MAXDRAM 8

extern BOOL g_mute[MAXTRACK];	// Used by the debug Mute menu

void GetORGinfo(int*Wait, unsigned char Track[8], unsigned short Freq[8], int*CurrentMeasure, long*TotalMeasure, int*CurrentStep, int*TotalStep);


BOOL MakeOrganyaWave(signed char track, signed char wave_no, signed char pipi);
void OrganyaPlayData(void);
void SetPlayPointer(long x);
BOOL LoadOrganya(const char *name);
void SetOrganyaPosition(unsigned int x);
unsigned int GetOrganyaPosition(void);
void PlayOrganyaMusic(void);
BOOL ChangeOrganyaVolume(signed int volume);
void StopOrganyaMusic(void);
void SetOrganyaFadeout(void);
BOOL StartOrganya(const char *wave_filename);
void EndOrganya(void);
void UpdateOrganya(void);
