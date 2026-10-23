#pragma once

#include "Alias.hpp"

namespace Raw
{
constexpr auto InitTweakDB = Core::RawFunc<
    /* addr = */ Red::AddressLib::TweakDB_Init,
    /* type = */ void (*)(void*, void*)>();

#if defined(RED4EXT_GAME_VERSION_25)
// 2.5 LoadOptimized takes a bool before the path.
constexpr auto LoadTweakDB = Core::RawFunc<
    /* addr = */ Red::AddressLib::TweakDB_Load,
    /* type = */ void (*)(Red::TweakDB*, bool, Red::CString&)>();
#else
constexpr auto LoadTweakDB = Core::RawFunc<
    /* addr = */ Red::AddressLib::TweakDB_Load,
    /* type = */ void (*)(Red::TweakDB*, Red::CString&)>();
#endif

#if defined(RED4EXT_GAME_VERSION_25)
// 2.5 appends a bool (the LoadOptimized flag; false on the fallback call).
constexpr auto TryLoadTweakDB = Core::RawFunc<
    /* addr = */ Red::AddressLib::TweakDB_TryLoad,
    /* type = */ bool (*)(void* a1, Red::TweakDB*, Red::CString&, void* a4, bool a5)>();
#else
constexpr auto TryLoadTweakDB = Core::RawFunc<
    /* addr = */ Red::AddressLib::TweakDB_TryLoad,
    /* type = */ bool (*)(void* a1, Red::TweakDB*, Red::CString&, void* a4)>();
#endif

constexpr auto CreateRecord = Core::RawFunc<
    /* addr = */ Red::AddressLib::TweakDB_CreateRecord,
    /* type = */ void (*)(Red::TweakDB*, uint32_t, Red::TweakDBID)>();

constexpr auto CreateTweakDBID = Core::RawFunc<
    /* addr = */ Red::AddressLib::TweakDBID_Derive,
    /* type = */ void (*)(const Red::TweakDBID*, const Red::TweakDBID*, const char*)>();
}
