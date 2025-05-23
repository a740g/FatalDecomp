#include "cdx.h"
#include <stdio.h>
#include <string.h>
//-------------------------------------------------------------------------------------------------

int track_playing = 0;    //000A7510
int last_audio_track = 0; //000A7514
int numCDdrives = 0;      //000A7518

//-------------------------------------------------------------------------------------------------

int FinishedAudio()
{
  return 0; /*
  int result; // eax
  char v1[20]; // [esp+0h] [ebp-14h] BYREF

  v1[0] = 12;
  WriteIOCTL(3, 11, v1);
  if ((io_variable_4 & 2) != 0)
    return 0;
  result = -1;
  track_playing = 0;
  return result;*/
}

//-------------------------------------------------------------------------------------------------

int OpenDoor()
{
  return 0; /*
  _BYTE v1[12]; // [esp+0h] [ebp-Ch] BYREF

  v1[0] = 0;
  return WriteIOCTL(12, 1, v1);*/
}

//-------------------------------------------------------------------------------------------------

void CloseDoor(int a1, int a2)
{
  /*
  char v2[12]; // [esp+0h] [ebp-Ch] BYREF

  *(_DWORD *)&v2[4] = a2;
  v2[0] = 5;
  WriteIOCTL(12, 1, v2);
  ResetDrive();*/
}

//-------------------------------------------------------------------------------------------------

void ResetDrive()
{
  ;
}

//-------------------------------------------------------------------------------------------------

void GetCDStatus()
{
  uint8 szBuf[16]; // [esp+0h] [ebp-10h] BYREF
  memset(szBuf, 0, sizeof(szBuf));

  szBuf[0] = 6;
  WriteIOCTL(3u, 5u, szBuf);
  printf("\n\nStatus:\n");
  if ((szBuf[1] & 1) != 0)
    printf("\nDoor Open");
  else
    printf("\nDoor Closed");
  if ((szBuf[1] & 2) != 0)
    printf("\nDoor unlocked");
  else
    printf("\nDoor locked");
  if ((szBuf[1] & 4) != 0)
    printf("\nSupports Cooked and Raw");
  else
    printf("\nSupports only Cooked");
  if ((szBuf[1] & 8) != 0)
    printf("\nRead/Write");
  else
    printf("\nRead only");
  if ((szBuf[1] & 0x10) != 0)
    printf("\nCan play Audio tracks");
  else
    printf("\nCannot play Audio tracks");
  if ((szBuf[1] & 0x20) != 0)
    printf("\nSupports interleaving");
  else
    printf("\nNo interleaving");
  if ((szBuf[1] & 0x80u) == 0)
    printf("\nNo prefetching");
  else
    printf("\nSupprots prefetching");
  if ((szBuf[2] & 1) != 0)
    printf("\nSupports audio channel manipulation");
  else
    printf("\nNo audio channel manipulation");
  if ((szBuf[2] & 2) != 0)
    printf("\nSupports HSG and Red Book addressing");
  else
    printf("\nSupports only HSG addressing, no Red Book");
  fflush(stdout);
}

//-------------------------------------------------------------------------------------------------

void WriteIOCTL(uint8 bySubCommand, unsigned int uiSize, void *pBuffer)
{
  /*
  char *v3; // edi

  io_variable_2 = bySubCommand;
  io_variable_3 = 0;
  io_variable_8 = 0;
  io = uiSize + 13;
  io_variable_1 = 0;
  io_variable_5 = 0;
  io_variable_9 = 0;
  io_variable_7 = uiSize;
  qmemcpy(cdbuffer, pBuffer, uiSize);
  v3 = (char *)iobuffer;
  io_variable_6 = (int)((char *)cdbuffer - __CFSHL__((int)cdbuffer >> 31, 4) + -16 * ((int)cdbuffer >> 31)) >> 4 << 16;
  qmemcpy(iobuffer, &io, 0x18u);
  qmemcpy(v3 + 24, &io + 24, 2u);
  memset(&RMIcd, 0, sizeof(RMIcd));
  RMIcd.ecx = (unsigned __int8)drive;
  RMIcd.ebx = 0;
  RMIcd.es = (int)((char *)iobuffer - __CFSHL__((int)iobuffer >> 31, 4) + -16 * ((int)iobuffer >> 31)) >> 4;
  RMIcd.eax = 5392;
  intRM(0x2Fu);
  qmemcpy(pBuffer, cdbuffer, uiSize);
  qmemcpy(&io, iobuffer, 0x18u);
  qmemcpy(&io + 24, (char *)iobuffer + 24, 2u);*/
}

//-------------------------------------------------------------------------------------------------

int AllocDOSMemory(int a1, void *a2)
{
  return 0; /*
  memset(&sregs, 0, 12);
  regs = 256;
  regs_variable_1 = ((a1 - (__CFSHL__(a1 >> 31, 4) + 16 * (a1 >> 31))) >> 4) + 1;
  int386x(49, (int)&regs, (int)&regs, (int)&sregs);
  if (regs_variable_6) {
    *a2 = -1;
    return 0;
  } else {
    *a2 = (unsigned __int16)regs_variable_4;
    return 16 * (unsigned __int16)regs;
  }*/
}

//-------------------------------------------------------------------------------------------------

int GetAudioInfo(int a1, int a2, int a3, int a4)
{
  return 0; /*
  int v4; // ecx
  int v5; // esi
  int v6; // ebx
  int result; // eax
  int v8; // esi
  int v9; // ecx
  int v10; // edx
  int v11; // esi
  int v12; // edi
  _DWORD v13[100]; // [esp+0h] [ebp-1B4h]
  _BYTE v14[2]; // [esp+190h] [ebp-24h] BYREF
  int v15; // [esp+192h] [ebp-22h]
  char v16; // [esp+198h] [ebp-1Ch] BYREF
  unsigned __int8 v17; // [esp+199h] [ebp-1Bh]
  unsigned __int8 v18; // [esp+19Ah] [ebp-1Ah]
  int v19; // [esp+19Bh] [ebp-19h]
  int v20; // [esp+1ACh] [ebp-8h]

  v20 = a4;
  v16 = 10;
  WriteIOCTL(3, 7u, &v16);
  first_track = v17;
  v4 = v17;
  last_track = v18;
  if (v17 <= (int)v18) {
    v5 = v17;
    do {
      v14[0] = 11;
      v14[1] = v4;
      WriteIOCTL(3, 7u, v14);
      ++v5;
      ++v4;
      v13[v5] = (unsigned __int8)v15 + 4500 * (v15 >> 16) + 75 * BYTE1(v15) - 150;
      v6 = last_track;
      thevtoc[v5] = v15;
    } while (v4 <= v6);
  }
  result = last_track;
  v8 = 4 * last_track;
  v13[last_track + 2] = 4500 * (v19 >> 16) + 75 * BYTE1(v19) + (unsigned __int8)v19 - 150;
  v9 = first_track;
  if (first_track <= result) {
    result = 4 * first_track;
    v10 = v8;
    do {
      v11 = *(_DWORD *)((char *)&v13[2] + result);
      v12 = *(_DWORD *)((char *)&v13[1] + result);
      result += 4;
      ++v9;
      *(int *)((char *)&sector_size + result) = v11 - v12;
    } while (result <= v10);
  }
  return result;*/
}

//-------------------------------------------------------------------------------------------------

int PlayTrack(int a1)
{
  return 0; /*
  int result; // eax

  play_variable_4 = 1;
  play_variable_5 = trackstarts[a1];
  play_variable_6 = tracklengths[a1];
  AudioIOCTL(132, -1);
  track_playing = -1;
  result = tracklengths[a1];
  last_audio_track = a1;
  track_duration = result;
  return result;*/
}

//-------------------------------------------------------------------------------------------------

int PlayTrack4(int a1)
{
  return 0; /*
  int v2; // ebx
  int v3; // ecx
  int v4; // ecx
  int v5; // ebx
  int result; // eax

  v2 = tracklengths[a1];
  v3 = tracklengths_variable_1[a1];
  play_variable_4 = 1;
  v4 = v3 + v2 + tracklengths_variable_2[a1];
  v5 = tracklengths_variable_3[a1];
  play_variable_5 = trackstarts[a1];
  track_duration = v5 + v4;
  play_variable_6 = v5 + v4;
  result = AudioIOCTL(132, a1);
  track_playing = -1;
  last_audio_track = a1;
  return result;*/
}

//-------------------------------------------------------------------------------------------------

void RepeatTrack()
{/*
  play.subCmd.reserved2[8] = 1;
  play.subCmd.start_lba = trackstarts[last_audio_track];
  play.subCmd.duration = track_duration;
  AudioIOCTL(0x84u);
  track_playing = -1;*/
}

//-------------------------------------------------------------------------------------------------

void StopTrack()
{
  AudioIOCTL(0x85); //stop track
  track_playing = 0;
}

//-------------------------------------------------------------------------------------------------

int SetAudioVolume(int a1)
{
  return 0; /*
  int v1; // eax
  _BYTE v3[20]; // [esp+0h] [ebp-14h] BYREF

  v1 = 2 * a1;
  if (v1 < 1)
    v1 = 1;
  if (v1 > 255)
    LOBYTE(v1) = -1;
  v3[2] = v1;
  v3[4] = v1;
  v3[6] = v1;
  v3[8] = v1;
  v3[0] = 3;
  v3[1] = 0;
  v3[3] = 1;
  v3[5] = 2;
  v3[7] = 3;
  return WriteIOCTL(12, 9u, v3);*/
}

//-------------------------------------------------------------------------------------------------

void AudioIOCTL(uint8 bySubCommand)
{
  /*
  char *pIoBuffer; // edi

  pIoBuffer = (char *)iobuffer;
  play_variable_2 = bySubCommand;
  play = 0x16;                                  // Send Audio Command
  play_variable_1 = 0;
  play_variable_3 = 0;
  qmemcpy(iobuffer, &play, 0x14u);
  qmemcpy(pIoBuffer + 20, (char *)&play + 20, 2u);
  memset(&RMIcd, 0, sizeof(RMIcd));
  RMIcd.ecx = (unsigned __int8)drive;           // CD drive number
  RMIcd.eax = 0x1510;                           //  (Function: Get CD-ROM Drive Information)
  RMIcd.es = (int)((char *)iobuffer - __CFSHL__((int)iobuffer >> 31, 4) + -16 * ((int)iobuffer >> 31)) >> 4;// segment_of(iobuffer)
  RMIcd.ebx = 0;
  intRM(0x2Fu);                                 // Get address of the driver for a specific CD-ROM drive
  qmemcpy(&play, iobuffer, 0x14u);
  qmemcpy((char *)&play + 20, (char *)iobuffer + 20, 2u);*/
}

//-------------------------------------------------------------------------------------------------

int FreeDOSMemory(uint16 a1)
{
  return 0; /*
  memset(&sregs, 0, sizeof(sregs));
  regs.w.dx = a1;
  regs.w.ax = 257;
  return int386x(49, &regs, &regs, &sregs);*/
}

//-------------------------------------------------------------------------------------------------

void intRM(uint8 byInterruptNumber)
{
  /*
  regs.w.ax = 768;                              // DPMI: Simulate Real Mode Interrupt
  regs.w.bx = byInterruptNumber;                // Interrupt number to simulate
  regs.w.cx = 0;                                // Reserved
  sregs.es = __DS__;                            // Segment of RMIcd
  regs.x.edi = (unsigned int)&RMIcd;            // Offset of RMIcd (real mode register set)
  int386x(0x31, &regs, &regs, &sregs);*/
}

//-------------------------------------------------------------------------------------------------

void GetFirstCDDrive()
{
  /*
  regs.w.ax = 0x1500;
  regs.w.bx = 0;
  int386(47, &regs, &regs);
  if (regs.w.bx) {
    drive = regs.h.cl;
    firstCDdrive = regs.h.cl;
    numCDdrives = regs.w.bx;
  }*/
}

//-------------------------------------------------------------------------------------------------

void cdxinit()
{/*
  int v0; // edx
  double v1; // st7
  __int16 v2; // fps
  _BOOL1 v3; // c0
  char v4; // c2
  _BOOL1 v5; // c3
  int v6; // eax
  float v7; // [esp+0h] [ebp-14h]
  int i; // [esp+4h] [ebp-10h]

  iobuffer = AllocDOSMemory(256, &ioselector);
  v0 = 0;
  cdbuffer = AllocDOSMemory(1024, &cdselector);
  for (i = 0; i < 129; ++i) {
    v1 = cdx_c_variable_21;
    IF_POW(cdx_c_variable_21);
    v3 = v1 < cdx_c_variable_22;
    v4 = 0;
    v5 = v1 == cdx_c_variable_22;
    LOWORD(v6) = v2;
    if (v1 > cdx_c_variable_22) {
      v0 = i;
      volscale[i] = 127;
    } else {
      _CHP(v6, v0);
      v0 = i;
      v7 = v1;
      volscale[i] = (int)v7;
    }
  }*/
}

//-------------------------------------------------------------------------------------------------

int cdxdone()
{
  return 0; /*
  __int16 v0; // cx
  __int16 v1; // cx

  v0 = cdselector;
  memset(&sregs, 0, 12);
  regs_variable_4 = v0;
  regs = 257;
  int386x(49, (int)&regs, (int)&regs, (int)&sregs);
  v1 = ioselector;
  memset(&sregs, 0, 12);
  regs_variable_4 = v1;
  regs = 257;
  return int386x(49, (int)&regs, (int)&regs, (int)&sregs);*/
}

//-------------------------------------------------------------------------------------------------

int cdpresent()
{
  return 0; /*
  int result; // eax
  int i; // edx

  result = 0;
  for (i = 0; i < numCDdrives; ++i) {
    if (!result)
      result = checkCD(i + firstCDdrive);
  }
  return result;*/
}

//-------------------------------------------------------------------------------------------------

int checkCD(char a1, int a2, int a3, int a4)
{
  return 0; /*
  int result; // eax
  int v5; // esi
  int v6; // edx
  char v7; // [esp+0h] [ebp-8Ch] BYREF
  char v8[99]; // [esp+1h] [ebp-8Bh] BYREF
  _BYTE v9[32]; // [esp+64h] [ebp-28h] BYREF
  int v10; // [esp+84h] [ebp-8h]

  v10 = a4;
  v7 = a1 + 65;
  strcpy(v8, ":\\FATAL.EXE");
  result = fopen(&v7, aRb_1);
  v5 = result;
  if (result) {
    v6 = fread(v9, 1, 20, result);
    fclose(v5);
    if (v6 == 20)
      return -1;
    else
      return 0;
  }
  return result;*/
}

//-------------------------------------------------------------------------------------------------

int criticalhandler()
{
  return 0; /*
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)(3);*/
}

//-------------------------------------------------------------------------------------------------
