// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmedian_filter_tb.h for the primary calling header

#ifndef VERILATED_VMEDIAN_FILTER_TB___024UNIT_H_
#define VERILATED_VMEDIAN_FILTER_TB___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vmedian_filter_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmedian_filter_tb___024unit final {
  public:

    // INTERNAL VARIABLES
    Vmedian_filter_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vmedian_filter_tb___024unit();
    ~Vmedian_filter_tb___024unit();
    void ctor(Vmedian_filter_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vmedian_filter_tb___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
