/* @copyright (C) 2019 Nuvoton Technology Corp. All rights reserved.
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*   3. Neither the name of Nuvoton Technology Corp. nor the names of its contributors
*      may be used to endorse or promote products derived from this software
*      without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#ifndef __NUMEDIA_SAL_FS_H__
#define __NUMEDIA_SAL_FS_H__

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \anchor          NUMEDIA_SAL_PORTS
 * \name            NuMedia file system ports
 * \{
 *
 * List of already available system ports.
 * Configure \ref NUMEDIA_CFG_SYS_PORT with one of these values to use preconfigured ports
 */

#define NUMEDIA_SAL_FS_PORT_NONE                       0   /*!< Without SAL */
#define NUMEDIA_SAL_FS_PORT_NVTFAT                     1   /*!< FreeRTOS based port */
#define NUMEDIA_SAL_FS_PORT_RTTHREAD                   2   /*!< RTThread based port */
#define NUMEDIA_SAL_FS_PORT_USER                       99  /*!< User custom implementation.
                                                    When port is selected to user mode, user must provide "NuMedia_SAL_User.h" file,
                                                    which is not provided with library.
                                                    */

#define NUMEDIA_CFG_SAL_FS_PORT    NUMEDIA_SAL_FS_PORT_RTTHREAD


#if NUMEDIA_CFG_SAL_FS_PORT == NUMEDIA_SAL_FS_PORT_NONE
/* For a totally minimal and standalone system, we provide null
   definitions of the sys_ functions. */

#elif NUMEDIA_CFG_SAL_FS_PORT == NUMEDIA_SAL_FS_PORT_NVTFAT
#if defined (__N9H26__)

#include "wblib.h"
#include "N9H26_NVTFAT.h"
#endif

struct stat
{
    uint8_t st_mode;
    uint64_t st_size;
    uint64_t st_atime;
    uint64_t st_mtime;
    uint64_t st_ctime;
};

#define S_ISDIR(m) (m & FA_DIR)

struct dirent
{
    char d_name[256];
};

typedef struct __dirstream
{
    FILE_FIND_T tCurFieEnt;
    struct dirent sDirEnt;
    int bLastDirEnt;
} DIR;


int open(const char *path, int oflags);
int close(int fildes);
int read(int fildes, void *buf, int nbyte);
int write(int fildes, const void *buf, int nbyte);
int64_t lseek(int fildes, int64_t offset, int whence);
int stat(const char *path, struct stat *buf);
int fstat(int fildes, struct stat *buf);
int unlink(const char *pathname);       //delete file
int truncate(const char *path, uint64_t length);
int ftruncate(int fildes, int64_t length);
int fileno(FILE *pFile);

DIR *opendir(const char *name);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);

#elif NUMEDIA_CFG_SAL_FS_PORT == NUMEDIA_SAL_FS_PORT_RTTHREAD

#include "rtthread.h"
#include "dfs_file.h"
#include "unistd.h"
#include "stdio.h"
#include "sys/stat.h"
#include "sys/statfs.h"

#endif

#ifdef __cplusplus
}
#endif

#endif
