#pragma once
#include "pch.hpp"

#include "data.hpp"


struct MemoryRegion {
    std::uintptr_t size;
    std::uint8_t* start_address;
};


[[nodiscard]] std::vector<HMODULE> EnumerateModules(data::ProcessInfo& pi);
bool VerifyModule(LPCWSTR source_file);
std::vector<unsigned long> PatternToByte(const std::string& signature);
std::uint8_t* PatternScan(const HMODULE module, const std::string& signature);
std::uint8_t* PatternScan(const std::string& signature, const MemoryRegion& mem_region);
void ModuleScan(const data::ProcessInfo& context, const bool unsigned_only);
void ModuleScan(const data::ProcessInfo& context, const MemoryRegion& memory_region);
