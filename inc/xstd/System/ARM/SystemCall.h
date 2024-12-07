#pragma once

#include <xstd/stdafx.h>

enum {
	SYS(RESTART_SYSCALL)
	SYS(EXIT)
	SYS(FORK)
	SYS(READ)
	SYS(WRITE)
	SYS(OPEN)
	SYS(CLOSE)
	SYS(UNUSED0)
	SYS(CREAT)
	SYS(LINK)
	SYS(UNLINK)
	SYS(EXECVE)
	SYS(CHDIR)
	SYS(TIME)
	SYS(MKNOD)
	SYS(CHMOD)
	SYS(LCHOWN)
	SYS(UNUSED1)
	SYS(UNUSED2)
	SYS(LSEEK)
	SYS(GETPID)
	SYS(MOUNT)
	SYS(UMOUNT)
	SYS(SETUID)
	SYS(GETUID)
	SYS(STIME)
	SYS(PTRACE)
	SYS(ALARM)
	SYS(UNUSED3)
	SYS(PAUSE)
	SYS(UTIME)
	SYS(UNUSED4)
	SYS(UNUSED5)
	SYS(ACCESS)
	SYS(NICE)
	SYS(UNUSED6)
	SYS(SYNC)
	SYS(KILL)
	SYS(RENAME)
	SYS(MKDIR)
	SYS(RMDIR)
	SYS(DUP)
	SYS(PIPE)
	SYS(TIMES)
	SYS(UNUSED7)
	SYS(BRK)
	SYS(SETGID)
	SYS(GETGID)
	SYS(UNUSED8)
	SYS(GETEUID)
	SYS(GETEGID)
	SYS(ACCT)
	SYS(UMOUNT2)
	SYS(UNUSED9)
	SYS(IOCTL)
	SYS(FCNTL)
	SYS(UNUSED10)
	SYS(SETPGID)
	SYS(UNUSED11)
	SYS(UNUSED12)
	SYS(UMASK)
	SYS(CHROOT)
	SYS(USTAT)
	SYS(DUP2)
	SYS(GETPPID)
	SYS(GETPGRP)
	SYS(SETSID)
	SYS(SIGACTION)
	SYS(UNUSED13)
	SYS(UNUSED14)
	SYS(SETREUID)
	SYS(SETREGID)
	SYS(SIGSUSPEND)
	SYS(SIGPENDING)
	SYS(SETHOSTNAME)
	SYS(SETRLIMIT)
	SYS(GETRLIMIT)
	SYS(GETRUSAGE)
	SYS(GETTIMEOFDAY)
	SYS(SETTIMEOFDAY)
	SYS(GETGROUPS)
	SYS(SETGROUPS)
	SYS(SELECT)
	SYS(SYMLINK)
	SYS(UNUSED15)
	SYS(READLINK)
	SYS(USELIB)
	SYS(SWAPON)
	SYS(REBOOT)
	SYS(READDIR)
	SYS(MMAP)
	SYS(MUNMAP)
	SYS(TRUNCATE)
	SYS(FTRUNCATE)
	SYS(FCHMOD)
	SYS(FCHOWN)
	SYS(GETPRIORITY)
	SYS(SETPRIORITY)
	SYS(UNUSED16)
	SYS(STATFS)
	SYS(FSTATFS)
	SYS(UNUSED17)
	SYS(SOCKETCALL)
	SYS(SYSLOG)
	SYS(SETITIMER)
	SYS(GETITIMER)
	SYS(STAT)
	SYS(LSTAT)
	SYS(FSTAT)
	SYS(UNUSED18)
	SYS(UNUSED19)
	SYS(VHANGUP)
	SYS(UNUSED20)
	SYS(SYSCALL)
	SYS(WAIT4)
	SYS(SWAPOFF)
	SYS(SYSINFO)
	SYS(IPC)
	SYS(FSYNC)
	SYS(SIGRETURN)
	SYS(CLONE)
	SYS(SETDOMAINNAME)
	SYS(UNAME)
	SYS(UNUSED21)
	SYS(ADJTIMEX)
	SYS(MPROTECT)
	SYS(SIGPROCMASK)
	SYS(UNUSED22)
	SYS(INIT_MODULE)
	SYS(DELETE_MODULE)
	SYS(UNUSED23)
	SYS(QUOTACTL)
	SYS(GETPGID)
	SYS(FCHDIR)
	SYS(BDFLUSH)
	SYS(SYSFS)
	SYS(PERSONALITY)
	SYS(UNUSED24)
	SYS(SETFSUID)
	SYS(SETFSGID)
	SYS(LLSEEK)
	SYS(GETDENTS)
	SYS(NEWSELECT)
	SYS(FLOCK)
	SYS(MSYNC)
	SYS(READV)
	SYS(WRITEV)
	SYS(GETSID)
	SYS(FDATASYNC)
	SYS(SYSCTL)
	SYS(MLOCK)
	SYS(MUNLOCK)
	SYS(MLOCKALL)
	SYS(MUNLOCKALL)
	SYS(SCHED_SETPARAM)
	SYS(SCHED_GETPARAM)
	SYS(SCHED_SETSCHEDULER)
	SYS(SCHED_GETSCHEDULER)
	SYS(SCHED_YIELD)
	SYS(SCHED_GET_PRIORITY_MAX)
	SYS(SCHED_GET_PRIORITY_MIN)
	SYS(SCHED_RR_GET_INTERVAL)
	SYS(NANOSLEEP)
	SYS(MREMAP)
	SYS(SETRESUID)
	SYS(GETRESUID)
	SYS(UNUSED25)
	SYS(UNUSED26)
	SYS(POLL)
	SYS(UNUSED27)
	SYS(SETRESGID)
	SYS(GETRESGID)
	SYS(PRCTL)
	SYS(RT_SIGRETURN)
	SYS(RT_SIGACTION)
	SYS(RT_SIGPROCMASK)
	SYS(RT_SIGPENDING)
	SYS(RT_SIGTIMEDWAIT)
	SYS(RT_SIGQUEUEINFO)
	SYS(RT_SIGSUSPEND)
	SYS(PREAD64)
	SYS(PWRITE64)
	SYS(CHOWN)
	SYS(GETCWD)
	SYS(CAPGET)
	SYS(CAPSET)
	SYS(SIGALTSTACK)
	SYS(SENDFILE)
	SYS(UNUSED28)
	SYS(UNUSED29)
	SYS(VFORK)
	SYS(UGETRLIMIT)
	SYS(MMAP2)
	SYS(TRUNCATE64)
	SYS(FTRUNCATE64)
	SYS(STAT64)
	SYS(LSTAT64)
	SYS(FSTAT64)
	SYS(LCHOWN32)
	SYS(GETUID32)
	SYS(GETGID32)
	SYS(GETEUID32)
	SYS(GETEGID32)
	SYS(SETREUID32)
	SYS(SETREGID32)
	SYS(GETGROUPS32)
	SYS(SETGROUPS32)
	SYS(FCHOWN32)
	SYS(SETRESUID32)
	SYS(GETRESUID32)
	SYS(SETRESGID32)
	SYS(GETRESGID32)
	SYS(CHOWN32)
	SYS(SETUID32)
	SYS(SETGID32)
	SYS(SETFSUID32)
	SYS(SETFSGID32)
	SYS(GETDENTS64)
	SYS(PIVOT_ROOT)
	SYS(MINCORE)
	SYS(MADVISE)
	SYS(FCNTL64)
	SYS(UNUSED30)
	SYS(UNUSED31)
	SYS(GETTID)
	SYS(READAHEAD)
	SYS(SETXATTR)
	SYS(LSETXATTR)
	SYS(FSETXATTR)
	SYS(GETXATTR)
	SYS(LGETXATTR)
	SYS(FGETXATTR)
	SYS(LISTXATTR)
	SYS(LLISTXATTR)
	SYS(FLISTXATTR)
	SYS(REMOVEXATTR)
	SYS(LREMOVEXATTR)
	SYS(FREMOVEXATTR)
	SYS(TKILL)
	SYS(SENDFILE64)
	SYS(FUTEX)
	SYS(SCHED_SETAFFINITY)
	SYS(SCHED_GETAFFINITY)
	SYS(IO_SETUP)
	SYS(IO_DESTROY)
	SYS(IO_GETEVENTS)
	SYS(IO_SUBMIT)
	SYS(IO_CANCEL)
	SYS(EXIT_GROUP)
	SYS(LOOKUP_DCOOKIE)
	SYS(EPOLL_CREATE)
	SYS(EPOLL_CTL)
	SYS(EPOLL_WAIT)
	SYS(REMAP_FILE_PAGES)
	SYS(UNUSED32)
	SYS(UNUSED33)
	SYS(SET_TID_ADDRESS)
	SYS(TIMER_CREATE)
	SYS(TIMER_SETTIME)
	SYS(TIMER_GETTIME)
	SYS(TIMER_GETOVERRUN)
	SYS(TIMER_DELETE)
	SYS(CLOCK_SETTIME)
	SYS(CLOCK_GETTIME)
	SYS(CLOCK_GETRES)
	SYS(CLOCK_NANOSLEEP)
	SYS(STATFS64)
	SYS(FSTATFS64)
	SYS(TGKILL)
	SYS(UTIMES)
	SYS(ARM_FADVISE64_64)
	SYS(PCICONFIG_IOBASE)
	SYS(PCICONFIG_READ)
	SYS(PCICONFIG_WRITE)
	SYS(MQ_OPEN)
	SYS(MQ_UNLINK)
	SYS(MQ_TIMEDSEND)
	SYS(MQ_TIMEDRECEIVE)
	SYS(MQ_NOTIFY)
	SYS(MQ_GETSETATTR)
	SYS(WAITID)
	SYS(SOCKET)
	SYS(BIND)
	SYS(CONNECT)
	SYS(LISTEN)
	SYS(ACCEPT)
	SYS(GETSOCKNAME)
	SYS(GETPEERNAME)
	SYS(SOCKETPAIR)
	SYS(SEND)
	SYS(SENDTO)
	SYS(RECV)
	SYS(RECVFROM)
	SYS(SHUTDOWN)
	SYS(SETSOCKOPT)
	SYS(GETSOCKOPT)
	SYS(SENDMSG)
	SYS(RECVMSG)
	SYS(SEMOP)
	SYS(SEMGET)
	SYS(SEMCTL)
	SYS(MSGSND)
	SYS(MSGRCV)
	SYS(MSGGET)
	SYS(MSGCTL)
	SYS(SHMAT)
	SYS(SHMDT)
	SYS(SHMGET)
	SYS(SHMCTL)
	SYS(ADD_KEY)
	SYS(REQUEST_KEY)
	SYS(KEYCTL)
	SYS(SEMTIMEDOP)
	SYS(UNUSED34)
	SYS(IOPRIO_SET)
	SYS(IOPRIO_GET)
	SYS(INOTIFY_INIT)
	SYS(INOTIFY_ADD_WATCH)
	SYS(INOTIFY_RM_WATCH)
	SYS(MBIND)
	SYS(GET_MEMPOLICY)
	SYS(SET_MEMPOLICY)
	SYS(OPENAT)
	SYS(MKDIRAT)
	SYS(MKNODAT)
	SYS(FCHOWNAT)
	SYS(FUTIMESAT)
	SYS(FSTATAT64)
	SYS(UNLINKAT)
	SYS(RENAMEAT)
	SYS(LINKAT)
	SYS(SYMLINKAT)
	SYS(READLINKAT)
	SYS(FCHMODAT)
	SYS(FACCESSAT)
	SYS(PSELECT6)
	SYS(PPOLL)
	SYS(UNSHARE)
	SYS(SET_ROBUST_LIST)
	SYS(GET_ROBUST_LIST)
	SYS(SPLICE)
	SYS(ARM_SYNC_FILE_RANGE)
	SYS(TEE)
	SYS(VMSPLICE)
	SYS(MOVE_PAGES)
	SYS(GETCPU)
	SYS(EPOLL_PWAIT)
	SYS(KEXEC_LOAD)
	SYS(UTIMENSAT)
	SYS(SIGNALFD)
	SYS(TIMERFD_CREATE)
	SYS(EVENTFD)
	SYS(FALLOCATE)
	SYS(TIMERFD_SETTIME)
	SYS(TIMERFD_GETTIME)
	SYS(SIGNALFD4)
	SYS(EVENTFD2)
	SYS(EPOLL_CREATE1)
	SYS(DUP3)
	SYS(PIPE2)
	SYS(INOTIFY_INIT1)
	SYS(PREADV)
	SYS(PWRITEV)
	SYS(RT_TGSIGQUEUEINFO)
	SYS(PERF_EVENT_OPEN)
	SYS(RECVMMSG)
	SYS(ACCEPT4)
	SYS(FANOTIFY_INIT)
	SYS(FANOTIFY_MARK)
	SYS(PRLIMIT64)
	SYS(NAME_TO_HANDLE_AT)
	SYS(OPEN_BY_HANDLE_AT)
	SYS(CLOCK_ADJTIME)
	SYS(SYNCFS)
	SYS(SENDMMSG)
	SYS(SETNS)
	SYS(PROCESS_VM_READV)
	SYS(PROCESS_VM_WRITEV)
	SYS(KCMP)
	SYS(FINIT_MODULE)
	SYS(SCHED_SETATTR)
	SYS(SCHED_GETATTR)
	SYS(RENAMEAT2)
	SYS(SECCOMP)
	SYS(GETRANDOM)
	SYS(MEMFD_CREATE)
	SYS(BPF)
	SYS(EXECVEAT)
	SYS(USERFAULTFD)
	SYS(MEMBARRIER)
	SYS(MLOCK2)
	SYS(COPY_FILE_RANGE)
	SYS(PREADV2)
	SYS(PWRITEV2)
	SYS(PKEY_MPROTECT)
	SYS(PKEY_ALLOC)
	SYS(PKEY_FREE)
	SYS(STATX)
	SYS(RSEQ)
	SYS(IO_PGETEVENTS)
	SYS(MIGRATE_PAGES)
	SYS(KEXEC_FILE_LOAD)
	SYS(UNUSED35)
	SYS(CLOCK_GETTIME64)
	SYS(CLOCK_SETTIME64)
	SYS(CLOCK_ADJTIME64)
	SYS(CLOCK_GETRES_TIME64)
	SYS(CLOCK_NANOSLEEP_TIME64)
	SYS(TIMER_GETTIME64)
	SYS(TIMER_SETTIME64)
	SYS(TIMERFD_GETTIME64)
	SYS(TIMERFD_SETTIME64)
	SYS(UTIMENSAT_TIME64)
	SYS(PSELECT6_TIME64)
	SYS(PPOLL_TIME64)
	SYS(UNUSED36)
	SYS(IO_PGETEVENTS_TIME64)
	SYS(RECVMMSG_TIME64)
	SYS(MQ_TIMEDSEND_TIME64)
	SYS(MQ_TIMEDRECEIVE_TIME64)
	SYS(SEMTIMEDOP_TIME64)
	SYS(RT_SIGTIMEDWAIT_TIME64)
	SYS(FUTEX_TIME64)
	SYS(SCHED_RR_GET_INTERVAL_TIME64)
	SYS(PIDFD_SEND_SIGNAL)
	SYS(IO_URING_SETUP)
	SYS(IO_URING_ENTER)
	SYS(IO_URING_REGISTER)
	SYS(OPEN_TREE)
	SYS(MOVE_MOUNT)
	SYS(FSOPEN)
	SYS(FSCONFIG)
	SYS(FSMOUNT)
	SYS(FSPICK)
	SYS(PIDFD_OPEN)
	SYS(CLONE3)
	SYS(CLOSE_RANGE)
	SYS(OPENAT2)
	SYS(PIDFD_GETFD)
	SYS(FACCESSAT2)
	SYS(PROCESS_MADVISE)
	SYS(EPOLL_PWAIT2)
	SYS(MOUNT_SETATTR)
	SYS(QUOTACTL_FD)
	SYS(LANDLOCK_CREATE_RULESET)
	SYS(LANDLOCK_ADD_RULE)
	SYS(LANDLOCK_RESTRICT_SELF)
	SYS(UNUSED37)
	SYS(PROCESS_MRELEASE)
	SYS(FUTEX_WAITV)
	SYS(SET_MEMPOLICY_HOME_NODE)
	SYS(CACHESTAT)
	SYS(FCHMODAT2)
	SYS(MAP_SHADOW_STACK)
	SYS(FUTEX_WAKE)
	SYS(FUTEX_WAIT)
	SYS(FUTEX_REQUEUE)
};