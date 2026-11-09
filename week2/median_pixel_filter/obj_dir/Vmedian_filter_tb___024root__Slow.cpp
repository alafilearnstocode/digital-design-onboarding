// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmedian_filter_tb.h for the primary calling header

#include "Vmedian_filter_tb__pch.h"

void Vmedian_filter_tb___024root___ctor_var_reset(Vmedian_filter_tb___024root* vlSelf);

Vmedian_filter_tb___024root::Vmedian_filter_tb___024root(Vmedian_filter_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vmedian_filter_tb___024root___ctor_var_reset(this);
}

void Vmedian_filter_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vmedian_filter_tb___024root::~Vmedian_filter_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
