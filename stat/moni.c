       fstatat()
              POSIX.1-2008.  Linux 2.6.16, glibc 2.4.

       According to POSIX.1-2001, lstat() on a symbolic link need return valid information only in the st_size  field  and  the  file  type  of  the
       st_mode  field  of  the stat structure.  POSIX.1-2008 tightens the specification, requiring lstat() to return valid information in all fields
       except the mode bits in st_mode.

       Use of the st_blocks and st_blksize fields may be less portable.  (They were introduced in BSD.  The interpretation differs between  systems,
       and possibly on a single system when NFS mounts are involved.)

   C library/kernel differences
       Over  time,  increases  in  the  size  of the stat structure have led to three successive versions of stat(): sys_stat() (slot __NR_oldstat),
       sys_newstat() (slot __NR_stat), and sys_stat64() (slot __NR_stat64) on 32-bit platforms such as i386.  The first two  versions  were  already
       present in Linux 1.0 (albeit with different names); the last was added in Linux 2.4.  Similar remarks apply for fstat() and lstat().

       The kernel-internal versions of the stat structure dealt with by the different versions are, respectively:

       __old_kernel_stat
              The original structure, with rather narrow fields, and no padding.

       stat   Larger st_ino field and padding added to various parts of the structure to allow for future expansion.

       stat64 Even larger st_ino field, larger st_uid and st_gid fields to accommodate the Linux-2.4 expansion of UIDs and GIDs to 32 bits, and var‐
              ious  other  enlarged fields and further padding in the structure.  (Various
