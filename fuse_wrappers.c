#define FUSE_USE_VERSION 30

#include <fuse.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include "disk_emu.h"
#include "sfs_api.h"

static int fuse_getattr(const char *path, struct stat *stbuf)
{
    int res = 0;
    int size;
    
    memset(stbuf, 0, sizeof(struct stat));
    
    if (strcmp(path, "/") == 0) {
        stbuf->st_mode = S_IFDIR | 0755;
        stbuf->st_nlink = 2;
    } else if((size = sfs_GetFileSize(path)) != -1) {
        stbuf->st_mode = S_IFREG | 0444;
        stbuf->st_nlink = 1;
        stbuf->st_size = size;
    } else
        res = -ENOENT;
    
    return res;
}

static int fuse_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
        off_t offset, struct fuse_file_info *fi)
{
    char file_name[MAXFILENAME];
    
    if (strcmp(path, "/") != 0)
        return -ENOENT;
    
    filler(buf, ".", NULL, 0);
    filler(buf, "..", NULL, 0);
    
    while(sfs_get_next_filename(file_name)) {
        filler(buf, &file_name[1], NULL, 0);
    }
    
    return 0;
}

static int fuse_unlink(const char *path)
{
    int res;
    char filename[MAXFILENAME];
    
    strcpy(filename, path);
    res = sfs_remove(filename);
    if (res == -1)
        return -errno;
    
    return 0;
}

static int fuse_open(const char *path, struct fuse_file_info *fi)
{
    int res;
    char filename[MAXFILENAME];
    
    strcpy(filename, path);
    
    res = sfs_fopen(filename);
    if (res == -1)
        return -errno;
    
    sfs_fclose(res);
    return 0;
}

static int fuse_read(const char *path, char *buf, size_t size, off_t offset,
        struct fuse_file_info *fi)
{
    int fd;
    int res;
    
    char filename[MAXFILENAME];
    
    strcpy(filename, path);
    
    fd = sfs_fopen(filename);
    if (fd == -1)
        return -errno;
    
    if(sfs_fseek(fd, offset) == -1)
        return -errno;
    
    res = sfs_fread(fd, buf, size);
    if (res == -1)
        return -errno;
    
    sfs_fclose(fd);
    return res;
}

static int fuse_write(const char *path, const char *buf, size_t size,
        off_t offset, struct fuse_file_info *fi)
{
    int fd;
    int res;
    
    char filename[MAXFILENAME];
    
    strcpy(filename, path);
    
    fd = sfs_fopen(filename);
    if (fd == -1) 
        return -errno;
    
    if(sfs_fseek(fd, offset) == -1)
        return -errno;
    
    res = sfs_fwrite(fd, buf, size);
    if (res == -1)
        return -errno;
    
    sfs_fclose(fd);
    return res;
}

static int fuse_truncate(const char *path, off_t size)
{
    char filename[MAXFILENAME];
    int fd;
    
    strcpy(filename, path);
    
    fd = sfs_remove(filename);
    if (fd == -1)
        return -errno;
    
    fd = sfs_fopen(filename);
    sfs_fclose(fd);
    return 0;
}

static int fuse_access(const char *path, int mask)
{
    return 0;
}

static int fuse_mknod(const char *path, mode_t mode, dev_t rdev)
{
    return 0;
}

static int fuse_create (const char *path, mode_t mode, struct fuse_file_info *fp)
{
    char filename[MAXFILENAME];
    int fd;
    
    strcpy(filename, path);
    fd = sfs_fopen(filename);
    
    sfs_fclose(fd);
    return 0;
}

static struct fuse_operations xmp_oper = {
    .getattr = fuse_getattr,
    .readdir = fuse_readdir,
    .mknod = fuse_mknod,
    .unlink = fuse_unlink,
    .truncate = fuse_truncate,
    .open = fuse_open, 
    .read = fuse_read, 
    .write = fuse_write, 
    .access = fuse_access,
    .create = fuse_create,
};

int main(int argc, char *argv[])
{
    mksfs(1);
    
    return fuse_main(argc, argv, &xmp_oper, NULL);
}
