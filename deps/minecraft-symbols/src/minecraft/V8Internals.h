#pragma once

#include <cstdint>

namespace v8 {
class Isolate;
}

namespace v8::internal {

using Address                  = uintptr_t;
constexpr Address kNullAddress = 0;

constexpr auto kApiSystemPointerSize = sizeof(void *);
constexpr auto kApiTaggedSize        = kApiSystemPointerSize;
constexpr auto kApiPointerSize       = sizeof(void *);
constexpr auto kApiIntSize           = sizeof(int);
constexpr auto kApiDoubleSize        = sizeof(double);
constexpr auto kApiInt64Size         = sizeof(int64_t);

constexpr int kHeapObjectTag          = 1;
constexpr int kWeakHeapObjectTag      = 3;
constexpr int kHeapObjectTagSize      = 2;
constexpr intptr_t kHeapObjectTagMask = (1 << kHeapObjectTagSize) - 1;

constexpr int kSmiTag          = 0;
constexpr int kSmiTagSize      = 1;
constexpr intptr_t kSmiTagMask = (1 << kSmiTagSize) - 1;

inline namespace Internals {
constexpr int kHeapObjectMapOffset   = 0;
constexpr int kMapInstanceTypeOffset = 1 * kApiPointerSize + kApiIntSize;
constexpr int kStringResourceOffset  = 3 * kApiPointerSize;

constexpr int kOddballKindOffset                = 4 * kApiPointerSize + kApiDoubleSize;
constexpr int kForeignAddressOffset             = kApiPointerSize;
constexpr int kJSObjectHeaderSize               = 3 * kApiPointerSize;
constexpr int kFixedArrayHeaderSize             = 2 * kApiPointerSize;
constexpr int kContextHeaderSize                = 2 * kApiPointerSize;
constexpr int kContextEmbedderDataIndex         = 5;
constexpr int kFullStringRepresentationMask     = 0x0f;
constexpr int kStringEncodingMask               = 0x8;
constexpr int kExternalTwoByteRepresentationTag = 0x02;
constexpr int kExternalOneByteRepresentationTag = 0x0a;

constexpr int kIsolateEmbedderDataOffset             = 0 * kApiPointerSize;
constexpr int kExternalMemoryOffset                  = 4 * kApiPointerSize;
constexpr int kExternalMemoryLimitOffset             = kExternalMemoryOffset + kApiInt64Size;
constexpr int kExternalMemoryAtLastMarkCompactOffset = kExternalMemoryLimitOffset + kApiInt64Size;
constexpr int kIsolateRootsOffset                    = kExternalMemoryLimitOffset + kApiInt64Size + kApiInt64Size + kApiPointerSize + kApiPointerSize;
constexpr int kUndefinedValueRootIndex               = 4;
constexpr int kTheHoleValueRootIndex                 = 5;
constexpr int kNullValueRootIndex                    = 6;
constexpr int kTrueValueRootIndex                    = 7;
constexpr int kFalseValueRootIndex                   = 8;
constexpr int kEmptyStringRootIndex                  = 9;

constexpr int kNodeClassIdOffset         = 1 * kApiPointerSize;
constexpr int kNodeFlagsOffset           = 1 * kApiPointerSize + 3;
constexpr int kNodeStateMask             = 0x7;
constexpr int kNodeStateIsWeakValue      = 2;
constexpr int kNodeStateIsPendingValue   = 3;
constexpr int kNodeStateIsNearDeathValue = 4;
constexpr int kNodeIsIndependentShift    = 3;
constexpr int kNodeIsActiveShift         = 4;

constexpr int kFirstNonstringType     = 0x80;
constexpr int kOddballType            = 0x83;
constexpr int kForeignType            = 0x87;
constexpr int kJSSpecialApiObjectType = 0x410;
constexpr int kJSApiObjectType        = 0x420;
constexpr int kJSObjectType           = 0x421;

constexpr int kUndefinedOddballKind = 5;
constexpr int kNullOddballKind      = 3;

constexpr uint32_t kNumIsolateDataSlots = 4;

inline static internal::Address *GetRoot(v8::Isolate *isolate, int index) {
  internal::Address addr = reinterpret_cast<internal::Address>(isolate) + kIsolateRootsOffset + index * kApiSystemPointerSize;
  return reinterpret_cast<internal::Address *>(addr);
}

}
}