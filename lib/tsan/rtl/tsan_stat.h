//===-- tsan_stat.h ---------------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a part of ThreadSanitizer (TSan), a race detector.
//
//===----------------------------------------------------------------------===//

#ifndef TSAN_STAT_H
#define TSAN_STAT_H

namespace __tsan {

enum StatType {
  // Memory access processing related stuff.
  StatMop,
  StatMopRead,
  StatMopWrite,
  StatMop1,  // These must be consequtive.
  StatMop2,
  StatMop4,
  StatMop8,
  StatMopSame,
  StatMopRange,
  StatMopRodata,
  StatMopRangeRodata,
  StatShadowProcessed,
  StatShadowZero,
  StatShadowNonZero,  // Derived.
  StatShadowSameSize,
  StatShadowIntersect,
  StatShadowNotIntersect,
  StatShadowSameThread,
  StatShadowAnotherThread,
  StatShadowReplace,

  // Func processing.
  StatFuncEnter,
  StatFuncExit,

  // Trace processing.
  StatEvents,

  // Threads.
  StatThreadCreate,
  StatThreadFinish,
  StatThreadReuse,
  StatThreadMaxTid,
  StatThreadMaxAlive,

  // Mutexes.
  StatMutexCreate,
  StatMutexDestroy,
  StatMutexLock,
  StatMutexUnlock,
  StatMutexRecLock,
  StatMutexRecUnlock,
  StatMutexReadLock,
  StatMutexReadUnlock,

  // Synchronization.
  StatSyncCreated,
  StatSyncDestroyed,
  StatSyncAcquire,
  StatSyncRelease,

  // Atomics.
  StatAtomic,
  StatAtomicLoad,
  StatAtomicStore,
  StatAtomicExchange,
  StatAtomicFetchAdd,
  StatAtomicFetchSub,
  StatAtomicFetchAnd,
  StatAtomicFetchOr,
  StatAtomicFetchXor,
  StatAtomicFetchNand,
  StatAtomicCAS,
  StatAtomicFence,
  StatAtomicRelaxed,
  StatAtomicConsume,
  StatAtomicAcquire,
  StatAtomicRelease,
  StatAtomicAcq_Rel,
  StatAtomicSeq_Cst,
  StatAtomic1,
  StatAtomic2,
  StatAtomic4,
  StatAtomic8,
  StatAtomic16,

  // Interceptors.
  StatInterceptor,
  StatInt_longjmp,
  StatInt_siglongjmp,
  StatInt_malloc,
  StatInt___libc_memalign,
  StatInt_calloc,
  StatInt_realloc,
  StatInt_free,
  StatInt_cfree,
  StatInt_malloc_usable_size,
  StatInt_mmap,
  StatInt_mmap64,
  StatInt_munmap,
  StatInt_memalign,
  StatInt_valloc,
  StatInt_pvalloc,
  StatInt_posix_memalign,
  StatInt__Znwm,
  StatInt__ZnwmRKSt9nothrow_t,
  StatInt__Znam,
  StatInt__ZnamRKSt9nothrow_t,
  StatInt__ZdlPv,
  StatInt__ZdlPvRKSt9nothrow_t,
  StatInt__ZdaPv,
  StatInt__ZdaPvRKSt9nothrow_t,
  StatInt_strlen,
  StatInt_memset,
  StatInt_memcpy,
  StatInt_strcmp,
  StatInt_memchr,
  StatInt_memrchr,
  StatInt_memmove,
  StatInt_memcmp,
  StatInt_strchr,
  StatInt_strchrnul,
  StatInt_strrchr,
  StatInt_strncmp,
  StatInt_strcpy,
  StatInt_strncpy,
  StatInt_strcasecmp,
  StatInt_strncasecmp,
  StatInt_strstr,
  StatInt_strdup,
  StatInt_atexit,
  StatInt__exit,
  StatInt___cxa_guard_acquire,
  StatInt___cxa_guard_release,
  StatInt___cxa_guard_abort,
  StatInt_pthread_create,
  StatInt_pthread_join,
  StatInt_pthread_detach,
  StatInt_pthread_mutex_init,
  StatInt_pthread_mutex_destroy,
  StatInt_pthread_mutex_lock,
  StatInt_pthread_mutex_trylock,
  StatInt_pthread_mutex_timedlock,
  StatInt_pthread_mutex_unlock,
  StatInt_pthread_spin_init,
  StatInt_pthread_spin_destroy,
  StatInt_pthread_spin_lock,
  StatInt_pthread_spin_trylock,
  StatInt_pthread_spin_unlock,
  StatInt_pthread_rwlock_init,
  StatInt_pthread_rwlock_destroy,
  StatInt_pthread_rwlock_rdlock,
  StatInt_pthread_rwlock_tryrdlock,
  StatInt_pthread_rwlock_timedrdlock,
  StatInt_pthread_rwlock_wrlock,
  StatInt_pthread_rwlock_trywrlock,
  StatInt_pthread_rwlock_timedwrlock,
  StatInt_pthread_rwlock_unlock,
  StatInt_pthread_cond_init,
  StatInt_pthread_cond_destroy,
  StatInt_pthread_cond_signal,
  StatInt_pthread_cond_broadcast,
  StatInt_pthread_cond_wait,
  StatInt_pthread_cond_timedwait,
  StatInt_pthread_barrier_init,
  StatInt_pthread_barrier_destroy,
  StatInt_pthread_barrier_wait,
  StatInt_pthread_once,
  StatInt_pthread_getschedparam,
  StatInt_pthread_setname_np,
  StatInt_sem_init,
  StatInt_sem_destroy,
  StatInt_sem_wait,
  StatInt_sem_trywait,
  StatInt_sem_timedwait,
  StatInt_sem_post,
  StatInt_sem_getvalue,
  StatInt_stat,
  StatInt___xstat,
  StatInt_stat64,
  StatInt___xstat64,
  StatInt_lstat,
  StatInt___lxstat,
  StatInt_lstat64,
  StatInt___lxstat64,
  StatInt_fstat,
  StatInt___fxstat,
  StatInt_fstat64,
  StatInt___fxstat64,
  StatInt_open,
  StatInt_open64,
  StatInt_creat,
  StatInt_creat64,
  StatInt_dup,
  StatInt_dup2,
  StatInt_dup3,
  StatInt_eventfd,
  StatInt_signalfd,
  StatInt_inotify_init,
  StatInt_inotify_init1,
  StatInt_socket,
  StatInt_socketpair,
  StatInt_connect,
  StatInt_bind,
  StatInt_listen,
  StatInt_accept,
  StatInt_accept4,
  StatInt_epoll_create,
  StatInt_epoll_create1,
  StatInt_close,
  StatInt___close,
  StatInt___res_iclose,
  StatInt_pipe,
  StatInt_pipe2,
  StatInt_read,
  StatInt_prctl,
  StatInt_pread,
  StatInt_pread64,
  StatInt_readv,
  StatInt_preadv,
  StatInt_preadv64,
  StatInt_write,
  StatInt_pwrite,
  StatInt_pwrite64,
  StatInt_writev,
  StatInt_pwritev,
  StatInt_pwritev64,
  StatInt_send,
  StatInt_sendmsg,
  StatInt_recv,
  StatInt_recvmsg,
  StatInt_unlink,
  StatInt_fopen,
  StatInt_freopen,
  StatInt_fclose,
  StatInt_fread,
  StatInt_fwrite,
  StatInt_fflush,
  StatInt_abort,
  StatInt_puts,
  StatInt_rmdir,
  StatInt_opendir,
  StatInt_epoll_ctl,
  StatInt_epoll_wait,
  StatInt_poll,
  StatInt_ppoll,
  StatInt_sigaction,
  StatInt_signal,
  StatInt_sigsuspend,
  StatInt_raise,
  StatInt_kill,
  StatInt_pthread_kill,
  StatInt_sleep,
  StatInt_usleep,
  StatInt_nanosleep,
  StatInt_gettimeofday,
  StatInt_fork,
  StatInt_vscanf,
  StatInt_vsscanf,
  StatInt_vfscanf,
  StatInt_scanf,
  StatInt_sscanf,
  StatInt_fscanf,
  StatInt___isoc99_vscanf,
  StatInt___isoc99_vsscanf,
  StatInt___isoc99_vfscanf,
  StatInt___isoc99_scanf,
  StatInt___isoc99_sscanf,
  StatInt___isoc99_fscanf,
  StatInt_on_exit,
  StatInt___cxa_atexit,
  StatInt_localtime,
  StatInt_localtime_r,
  StatInt_gmtime,
  StatInt_gmtime_r,
  StatInt_ctime,
  StatInt_ctime_r,
  StatInt_asctime,
  StatInt_asctime_r,
  StatInt_strptime,
  StatInt_frexp,
  StatInt_frexpf,
  StatInt_frexpl,
  StatInt_getpwnam,
  StatInt_getpwuid,
  StatInt_getgrnam,
  StatInt_getgrgid,
  StatInt_getpwnam_r,
  StatInt_getpwuid_r,
  StatInt_getgrnam_r,
  StatInt_getgrgid_r,
  StatInt_clock_getres,
  StatInt_clock_gettime,
  StatInt_clock_settime,
  StatInt_getitimer,
  StatInt_setitimer,
  StatInt_time,
  StatInt_glob,
  StatInt_glob64,
  StatInt_wait,
  StatInt_waitid,
  StatInt_waitpid,
  StatInt_wait3,
  StatInt_wait4,
  StatInt_inet_ntop,
  StatInt_inet_pton,
  StatInt_inet_aton,
  StatInt_getaddrinfo,
  StatInt_getnameinfo,
  StatInt_getsockname,
  StatInt_gethostent,
  StatInt_gethostbyname,
  StatInt_gethostbyname2,
  StatInt_gethostbyaddr,
  StatInt_gethostent_r,
  StatInt_gethostbyname_r,
  StatInt_gethostbyname2_r,
  StatInt_gethostbyaddr_r,
  StatInt_getsockopt,
  StatInt_modf,
  StatInt_modff,
  StatInt_modfl,
  StatInt_getpeername,
  StatInt_ioctl,
  StatInt_sysinfo,
  StatInt_readdir,
  StatInt_readdir64,
  StatInt_readdir_r,
  StatInt_readdir64_r,
  StatInt_ptrace,
  StatInt_setlocale,
  StatInt_getcwd,
  StatInt_get_current_dir_name,
  StatInt_strtoimax,
  StatInt_strtoumax,
  StatInt_mbstowcs,
  StatInt_mbsrtowcs,
  StatInt_mbsnrtowcs,
  StatInt_wcstombs,
  StatInt_wcsrtombs,
  StatInt_wcsnrtombs,
  StatInt_tcgetattr,
  StatInt_realpath,
  StatInt_canonicalize_file_name,
  StatInt_confstr,
  StatInt_sched_getaffinity,
  StatInt_strerror,
  StatInt_strerror_r,
  StatInt_scandir,
  StatInt_scandir64,
  StatInt_getgroups,
  StatInt_wordexp,
  StatInt_sigwait,
  StatInt_sigwaitinfo,
  StatInt_sigtimedwait,
  StatInt_sigemptyset,
  StatInt_sigfillset,
  StatInt_sigpending,
  StatInt_sigprocmask,
  StatInt_backtrace,
  StatInt_backtrace_symbols,
  StatInt_dlopen,
  StatInt_dlclose,
  StatInt_getmntent,
  StatInt_getmntent_r,
  StatInt_statfs,
  StatInt_statfs64,
  StatInt_fstatfs,
  StatInt_fstatfs64,
  StatInt_statvfs,
  StatInt_statvfs64,
  StatInt_fstatvfs,
  StatInt_fstatvfs64,
  StatInt_initgroups,
  StatInt_ether_ntoa,
  StatInt_ether_aton,
  StatInt_ether_ntoa_r,
  StatInt_ether_aton_r,
  StatInt_ether_ntohost,
  StatInt_ether_hostton,
  StatInt_ether_line,
  StatInt_shmctl,
  StatInt_random_r,
  StatInt_tmpnam,
  StatInt_tmpnam_r,
  StatInt_tempnam,
  StatInt_sincos,
  StatInt_sincosf,
  StatInt_sincosl,
  StatInt_remquo,
  StatInt_remquof,
  StatInt_remquol,
  StatInt_lgamma,
  StatInt_lgammaf,
  StatInt_lgammal,
  StatInt_lgamma_r,
  StatInt_lgammaf_r,
  StatInt_lgammal_r,
  StatInt_drand48_r,
  StatInt_lrand48_r,
  StatInt_getline,
  StatInt_getdelim,

  StatInt_pthread_attr_getdetachstate,
  StatInt_pthread_attr_getguardsize,
  StatInt_pthread_attr_getschedparam,
  StatInt_pthread_attr_getschedpolicy,
  StatInt_pthread_attr_getinheritsched,
  StatInt_pthread_attr_getscope,
  StatInt_pthread_attr_getstacksize,
  StatInt_pthread_attr_getstack,
  StatInt_pthread_attr_getaffinity_np,

  // Dynamic annotations.
  StatAnnotation,
  StatAnnotateHappensBefore,
  StatAnnotateHappensAfter,
  StatAnnotateCondVarSignal,
  StatAnnotateCondVarSignalAll,
  StatAnnotateMutexIsNotPHB,
  StatAnnotateCondVarWait,
  StatAnnotateRWLockCreate,
  StatAnnotateRWLockCreateStatic,
  StatAnnotateRWLockDestroy,
  StatAnnotateRWLockAcquired,
  StatAnnotateRWLockReleased,
  StatAnnotateTraceMemory,
  StatAnnotateFlushState,
  StatAnnotateNewMemory,
  StatAnnotateNoOp,
  StatAnnotateFlushExpectedRaces,
  StatAnnotateEnableRaceDetection,
  StatAnnotateMutexIsUsedAsCondVar,
  StatAnnotatePCQGet,
  StatAnnotatePCQPut,
  StatAnnotatePCQDestroy,
  StatAnnotatePCQCreate,
  StatAnnotateExpectRace,
  StatAnnotateBenignRaceSized,
  StatAnnotateBenignRace,
  StatAnnotateIgnoreReadsBegin,
  StatAnnotateIgnoreReadsEnd,
  StatAnnotateIgnoreWritesBegin,
  StatAnnotateIgnoreWritesEnd,
  StatAnnotateIgnoreSyncBegin,
  StatAnnotateIgnoreSyncEnd,
  StatAnnotatePublishMemoryRange,
  StatAnnotateUnpublishMemoryRange,
  StatAnnotateThreadName,

  // Internal mutex contentionz.
  StatMtxTotal,
  StatMtxTrace,
  StatMtxThreads,
  StatMtxReport,
  StatMtxSyncVar,
  StatMtxSyncTab,
  StatMtxSlab,
  StatMtxAnnotations,
  StatMtxAtExit,
  StatMtxMBlock,
  StatMtxJavaMBlock,
  StatMtxFD,

  // This must be the last.
  StatCnt
};

}  // namespace __tsan

#endif  // TSAN_STAT_H
