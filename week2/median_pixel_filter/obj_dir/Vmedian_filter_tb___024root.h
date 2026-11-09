// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmedian_filter_tb.h for the primary calling header

#ifndef VERILATED_VMEDIAN_FILTER_TB___024ROOT_H_
#define VERILATED_VMEDIAN_FILTER_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vmedian_filter_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmedian_filter_tb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ median_filter_tb__DOT__clk;
    CData/*0:0*/ median_filter_tb__DOT__rst;
    CData/*0:0*/ median_filter_tb__DOT__start_i;
    CData/*0:0*/ median_filter_tb__DOT__pixel_valid_i;
    CData/*0:0*/ median_filter_tb__DOT__done_o;
    CData/*0:0*/ median_filter_tb__DOT__pixel_valid_o;
    CData/*1:0*/ median_filter_tb__DOT__dut__DOT__state_d;
    CData/*1:0*/ median_filter_tb__DOT__dut__DOT__state_q;
    CData/*1:0*/ median_filter_tb__DOT__dut__DOT__x_counter_d;
    CData/*1:0*/ median_filter_tb__DOT__dut__DOT__y_counter_d;
    CData/*1:0*/ median_filter_tb__DOT__dut__DOT__x_counter_q;
    CData/*1:0*/ median_filter_tb__DOT__dut__DOT__y_counter_q;
    CData/*0:0*/ median_filter_tb__DOT__dut__DOT__kernel_valid;
    CData/*0:0*/ median_filter_tb__DOT__dut__DOT__done_d;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__median_filter_tb__DOT__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*23:0*/ median_filter_tb__DOT__pixel_i;
    IData/*23:0*/ median_filter_tb__DOT__pixel_o;
    IData/*31:0*/ median_filter_tb__DOT__red_value;
    IData/*31:0*/ median_filter_tb__DOT__green_value;
    IData/*31:0*/ median_filter_tb__DOT__blue_value;
    IData/*31:0*/ median_filter_tb__DOT__expected_red;
    IData/*31:0*/ median_filter_tb__DOT__expected_green;
    IData/*31:0*/ median_filter_tb__DOT__expected_blue;
    IData/*23:0*/ median_filter_tb__DOT__dut__DOT__pixel_d;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<IData/*23:0*/, 5> median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d;
    VlUnpacked<IData/*23:0*/, 5> median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q;
    VlUnpacked<VlUnpacked<IData/*23:0*/, 2>, 2> median_filter_tb__DOT__dut__DOT__kernel;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    std::string median_filter_tb__DOT__input_path;
    std::string median_filter_tb__DOT__expected_path;
    std::string median_filter_tb__DOT__output_path;
    std::string median_filter_tb__DOT__header;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hc7fcfec1__0;

    // INTERNAL VARIABLES
    Vmedian_filter_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vmedian_filter_tb___024root(Vmedian_filter_tb__Syms* symsp, const char* namep);
    ~Vmedian_filter_tb___024root();
    VL_UNCOPYABLE(Vmedian_filter_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
