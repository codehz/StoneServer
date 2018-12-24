#pragma once

#include <functional>
#include <sys/mman.h>

template <typename R, typename T, bool POD = std::is_pod_v<R>> struct FunctionWrapper;

template <typename R, typename T> struct FunctionWrapper<R, T, true> {
  unsigned char push = 0x68; // push (next dword)
  T *payload;                // [placeholder] payload
  unsigned char call = 0xe8; // call (next dword)
  int dest;                  // [placeholder] target func
  unsigned ret = 0xc304c483; // add esp, 0x4; ret

  FunctionWrapper(T *payload, R (*func)(T *))
      : payload(payload)
      , dest((char *)func - (char *)this - offsetof(FunctionWrapper, dest) - 4) {}
} __attribute__((packed));

template <typename R, typename T> struct FunctionWrapper<R, T, false> {
  using byte    = unsigned char;
  byte asm00[1] = { 0x53 };                   // push ebx
  byte asm01[3] = { 0x83, 0xec, 0x10 };       // sub esp, 0x10
  byte asm04[4] = { 0x8b, 0x5c, 0x24, 0x18 }; // mov ebx, DWORD PTR [esp+0x18]
  byte asm08[1] = { 0x68 };                   // push (next dword)
  T *payload;                                 // [placeholder] payload
  byte asm0d[1] = { 0x53 };                   // push ebx
  byte asm0e[1] = { 0xe8 };                   // call (next dword)
  int dest;                                   // [placeholder] target func
  byte asm13[3] = { 0x83, 0xc4, 0x14 };       // add esp, 0x14
  byte asm16[2] = { 0x89, 0xd8 };             // mov eax,ebx
  byte asm18[1] = { 0x5b };                   // pop ebx
  byte asm19[3] = { 0xc2, 0x04, 0x00 };       // ret 0x4
  FunctionWrapper(T *payload, R (*func)(T *))
      : payload(payload)
      , dest((char *)func - (char *)this - offsetof(FunctionWrapper, dest) - 4) {}
} __attribute__((packed));

template <typename T, size_t unit = 100> void *alloc_executable_memory() {
  static T *stop = nullptr;
  static T *cur  = nullptr;
  if (stop == cur) {
    cur = (T *)mmap(0, sizeof(T) * unit, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (cur == (void *)-1) {
      perror("mmap");
      return NULL;
    }
    stop = cur + unit;
  }
  return cur++;
}

template <typename T, typename R> auto gen_function(T *payload, R (*func)(T *)) {
  return (R(*)()) new (alloc_executable_memory<FunctionWrapper<R, T>>()) FunctionWrapper<R, T>(payload, func);
}