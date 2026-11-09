// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmedian_filter_tb.h for the primary calling header

#include "Vmedian_filter_tb__pch.h"


Vmedian_filter_tb___024unit::Vmedian_filter_tb___024unit() = default;
Vmedian_filter_tb___024unit::~Vmedian_filter_tb___024unit() = default;

void Vmedian_filter_tb___024unit::ctor(Vmedian_filter_tb__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
}

void Vmedian_filter_tb___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vmedian_filter_tb___024unit::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
