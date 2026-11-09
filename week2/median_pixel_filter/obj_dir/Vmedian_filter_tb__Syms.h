// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMEDIAN_FILTER_TB__SYMS_H_
#define VERILATED_VMEDIAN_FILTER_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vmedian_filter_tb.h"

// INCLUDE MODULE CLASSES
#include "Vmedian_filter_tb___024root.h"
#include "Vmedian_filter_tb___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vmedian_filter_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmedian_filter_tb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmedian_filter_tb___024root    TOP;

    // CONSTRUCTORS
    Vmedian_filter_tb__Syms(VerilatedContext* contextp, const char* namep, Vmedian_filter_tb* modelp);
    ~Vmedian_filter_tb__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
