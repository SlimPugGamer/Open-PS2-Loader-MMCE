/*
   Copyright 2006-2008, Romz
   Copyright 2010, Polo
   Licenced under Academic Free License version 3.0
   Review OpenUsbLd README & LICENSE files for further details.
   */

#ifndef __MCEMU_UTILS_H
#define __MCEMU_UTILS_H

#include <irx.h>

typedef struct
{
    int version;
    void **exports;
} modinfo_t;

typedef void (*oplShutdownCb_t)(void);

/* SMS Utils Imports */
#define smsutils_IMPORTS_start DECLARE_IMPORT_TABLE(smsutils, 1, 1)

void mips_memcpy(void *, const void *, unsigned);
#define I_mips_memcpy DECLARE_IMPORT(4, mips_memcpy)

void mips_memset(void *, int, unsigned);
#define I_mips_memset DECLARE_IMPORT(5, mips_memset)

#define smsutils_IMPORTS_end END_IMPORT_TABLE


#define oplutils_IMPORTS_start DECLARE_IMPORT_TABLE(oplutils, 1, 2)

int getModInfo(char *modname, modinfo_t *info);
#define I_getModInfo DECLARE_IMPORT(4, getModInfo)

int oplRegisterShutdownCallback(oplShutdownCb_t cb);
#define I_oplRegisterShutdownCallback DECLARE_IMPORT(5, oplRegisterShutdownCallback)

/* BDM Transfer Imports */
#ifdef BDM_DRIVER

void bdm_readSector(u64 lba, unsigned short int nsectors, unsigned char *buffer);
#define I_bdm_readSector DECLARE_IMPORT(6, bdm_readSector)

void bdm_writeSector(u64 lba, unsigned short int nsectors, const unsigned char *buffer);
#define I_bdm_writeSector DECLARE_IMPORT(7, bdm_writeSector)

#endif

#ifdef MMCE_DRIVER
void mmce_read_offset(int fd, unsigned int offset, unsigned int size, unsigned char *buffer);
#define I_mmce_read_offset DECLARE_IMPORT(6, mmce_read_offset)

void mmce_write_offset(int fd, unsigned int offset, unsigned int size, const unsigned char *buffer);
#define I_mmce_write_offset DECLARE_IMPORT(7, mmce_write_offset)
#endif

/* ATAD Transfer Imports */
#ifdef HDD_DRIVER

/* These are used with the dir parameter of sceAtaDmaTransfer().  */
#define ATA_DIR_READ  0
#define ATA_DIR_WRITE 1

int sceAtaDmaTransfer(unsigned int unit, void *buf, unsigned int lba, unsigned int sectors, int dir);
#define I_sceAtaDmaTransfer DECLARE_IMPORT(6, sceAtaDmaTransfer)

#endif

/* SMB Transfer Imports */
#ifdef SMB_DRIVER

int smb_OpenAndX(char *filename, u16 *FID, int Write);
#define I_smb_OpenAndX DECLARE_IMPORT(6, smb_OpenAndX)

int smb_ReadFile(u16 FID, u32 offsetlow, u32 offsethigh, void *readbuf, int nbytes);
#define I_smb_ReadFile DECLARE_IMPORT(7, smb_ReadFile)

int smb_WriteFile(u16 FID, u32 offsetlow, u32 offsethigh, void *writebuf, int nbytes);
#define I_smb_WriteFile DECLARE_IMPORT(8, smb_WriteFile)

int smb_Close(int FID);
#define I_smb_Close DECLARE_IMPORT(9, smb_Close)

#endif

#define oplutils_IMPORTS_end END_IMPORT_TABLE

#endif /* __MCEMU_UTILS_H */
