// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmedian_filter_tb.h for the primary calling header

#include "Vmedian_filter_tb__pch.h"

VlCoroutine Vmedian_filter_tb___024root___eval_initial__TOP__Vtiming__0(Vmedian_filter_tb___024root* vlSelf);
VlCoroutine Vmedian_filter_tb___024root___eval_initial__TOP__Vtiming__1(Vmedian_filter_tb___024root* vlSelf);

void Vmedian_filter_tb___024root___eval_initial(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval_initial\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmedian_filter_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vmedian_filter_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vmedian_filter_tb___024root____VbeforeTrig_hc7fcfec1__0(Vmedian_filter_tb___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vmedian_filter_tb___024root___eval_initial__TOP__Vtiming__0(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ median_filter_tb__DOT__input_fd;
    median_filter_tb__DOT__input_fd = 0;
    IData/*31:0*/ median_filter_tb__DOT__expected_fd;
    median_filter_tb__DOT__expected_fd = 0;
    IData/*31:0*/ median_filter_tb__DOT__output_fd;
    median_filter_tb__DOT__output_fd = 0;
    IData/*31:0*/ median_filter_tb__DOT__scan_count;
    median_filter_tb__DOT__scan_count = 0;
    IData/*31:0*/ median_filter_tb__DOT__output_count;
    median_filter_tb__DOT__output_count = 0;
    IData/*31:0*/ median_filter_tb__DOT__mismatch_count;
    median_filter_tb__DOT__mismatch_count = 0;
    IData/*31:0*/ median_filter_tb__DOT__done_count;
    median_filter_tb__DOT__done_count = 0;
    IData/*31:0*/ median_filter_tb__DOT__unnamedblk1_1__DOT____Vrepeat0;
    median_filter_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ median_filter_tb__DOT__unnamedblk1__DOT__pixel_idx;
    median_filter_tb__DOT__unnamedblk1__DOT__pixel_idx = 0;
    IData/*31:0*/ median_filter_tb__DOT__unnamedblk1_2__DOT____Vrepeat1;
    median_filter_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    IData/*31:0*/ __Vtask_median_filter_tb__DOT__drive_pixel__4__red_i;
    __Vtask_median_filter_tb__DOT__drive_pixel__4__red_i = 0;
    IData/*31:0*/ __Vtask_median_filter_tb__DOT__drive_pixel__4__green_i;
    __Vtask_median_filter_tb__DOT__drive_pixel__4__green_i = 0;
    IData/*31:0*/ __Vtask_median_filter_tb__DOT__drive_pixel__4__blue_i;
    __Vtask_median_filter_tb__DOT__drive_pixel__4__blue_i = 0;
    // Body
    vlSelfRef.median_filter_tb__DOT__clk = 0U;
    vlSelfRef.median_filter_tb__DOT__rst = 1U;
    vlSelfRef.median_filter_tb__DOT__start_i = 0U;
    vlSelfRef.median_filter_tb__DOT__pixel_valid_i = 0U;
    vlSelfRef.median_filter_tb__DOT__pixel_i = 0U;
    median_filter_tb__DOT__output_count = 0U;
    median_filter_tb__DOT__mismatch_count = 0U;
    median_filter_tb__DOT__done_count = 0U;
    vlSelfRef.median_filter_tb__DOT__input_path = "tb/test_vectors/input_pixels.csv"s;
    vlSelfRef.median_filter_tb__DOT__expected_path = "tb/test_vectors/expected_pixels.csv"s;
    vlSelfRef.median_filter_tb__DOT__output_path = "tb/output_pixels.csv"s;
    median_filter_tb__DOT__scan_count = VL_VALUEPLUSARGS_INN(64, "INPUT=%s"s, 
                                                             vlSelfRef.median_filter_tb__DOT__input_path);
    median_filter_tb__DOT__scan_count = VL_VALUEPLUSARGS_INN(64, "EXPECTED=%s"s, 
                                                             vlSelfRef.median_filter_tb__DOT__expected_path);
    median_filter_tb__DOT__scan_count = VL_VALUEPLUSARGS_INN(64, "OUTPUT=%s"s, 
                                                             vlSelfRef.median_filter_tb__DOT__output_path);
    median_filter_tb__DOT__input_fd = VL_FOPEN_NN(vlSelfRef.median_filter_tb__DOT__input_path
                                                  , "r"s);
    ;
    if (VL_UNLIKELY(((0U == median_filter_tb__DOT__input_fd)))) {
        VL_WRITEF_NX("FAIL: could not open input file: %s\n",1
                     , 'S',&(vlSelfRef.median_filter_tb__DOT__input_path));
        VL_FINISH_MT("tb/median_filter_tb.sv", 140, "");
    }
    median_filter_tb__DOT__expected_fd = VL_FOPEN_NN(vlSelfRef.median_filter_tb__DOT__expected_path
                                                     , "r"s);
    ;
    if (VL_UNLIKELY(((0U == median_filter_tb__DOT__expected_fd)))) {
        VL_WRITEF_NX("FAIL: could not open expected file: %s\n",1
                     , 'S',&(vlSelfRef.median_filter_tb__DOT__expected_path));
        VL_FINISH_MT("tb/median_filter_tb.sv", 146, "");
    }
    median_filter_tb__DOT__output_fd = VL_FOPEN_NN(vlSelfRef.median_filter_tb__DOT__output_path
                                                   , "w"s);
    ;
    if (VL_UNLIKELY(((0U == median_filter_tb__DOT__output_fd)))) {
        VL_WRITEF_NX("FAIL: could not open output file: %s\n",1
                     , 'S',&(vlSelfRef.median_filter_tb__DOT__output_path));
        VL_FINISH_MT("tb/median_filter_tb.sv", 152, "");
    }
    median_filter_tb__DOT__scan_count = VL_FGETS_NI(vlSelfRef.median_filter_tb__DOT__header, median_filter_tb__DOT__input_fd);
    median_filter_tb__DOT__scan_count = VL_FGETS_NI(vlSelfRef.median_filter_tb__DOT__header, median_filter_tb__DOT__expected_fd);
    VL_FWRITEF_NX(median_filter_tb__DOT__output_fd,"red,green,blue\n",0);
    median_filter_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    while (VL_LTS_III(32, 0U, median_filter_tb__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        vlSelfRef.median_filter_tb__DOT__pixel_valid_i = 0U;
        vlSelfRef.median_filter_tb__DOT__pixel_i = 0U;
        Vmedian_filter_tb___024root____VbeforeTrig_hc7fcfec1__0(vlSelf, 
                                                                "@(posedge median_filter_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hc7fcfec1__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge median_filter_tb.clk)", 
                                                             "tb/median_filter_tb.sv", 
                                                             101);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/median_filter_tb.sv", 
                                             102);
        if (vlSelfRef.median_filter_tb__DOT__pixel_valid_o) {
            median_filter_tb__DOT__scan_count = VL_FSCANF_INX(median_filter_tb__DOT__expected_fd,"%d,%d,%d\n",3
                                                              , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_red)
                                                              , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_green)
                                                              , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_blue)) ;
            if ((3U != median_filter_tb__DOT__scan_count)) {
                VL_WRITEF_NX("FAIL: RTL produced more output pixels than expected.\n",0);
                median_filter_tb__DOT__mismatch_count 
                    = ((IData)(1U) + median_filter_tb__DOT__mismatch_count);
            } else {
                VL_FWRITEF_NX(median_filter_tb__DOT__output_fd,"%0d,%0d,%0d\n",3
                              , '#',8,(0x000000ffU 
                                       & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                          >> 0x00000010U))
                              , '#',8,(0x000000ffU 
                                       & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                          >> 8U)), '#',8,
                              (0x000000ffU & vlSelfRef.median_filter_tb__DOT__pixel_o));
                if (VL_UNLIKELY((((((0x000000ffU & 
                                     (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                      >> 0x00000010U)) 
                                    != (0x000000ffU 
                                        & vlSelfRef.median_filter_tb__DOT__expected_red)) 
                                   | ((0x000000ffU 
                                       & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                          >> 8U)) != 
                                      (0x000000ffU 
                                       & vlSelfRef.median_filter_tb__DOT__expected_green))) 
                                  | ((0x000000ffU & vlSelfRef.median_filter_tb__DOT__pixel_o) 
                                     != (0x000000ffU 
                                         & vlSelfRef.median_filter_tb__DOT__expected_blue)))))) {
                    VL_WRITEF_NX("FAIL: output %0d expected %0d,%0d,%0d got %0d,%0d,%0d\n",7
                                 , '~',32,median_filter_tb__DOT__output_count
                                 , '~',32,vlSelfRef.median_filter_tb__DOT__expected_red
                                 , '~',32,vlSelfRef.median_filter_tb__DOT__expected_green
                                 , '~',32,vlSelfRef.median_filter_tb__DOT__expected_blue
                                 , '#',8,(0x000000ffU 
                                          & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                             >> 0x00000010U))
                                 , '#',8,(0x000000ffU 
                                          & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                             >> 8U))
                                 , '#',8,(0x000000ffU 
                                          & vlSelfRef.median_filter_tb__DOT__pixel_o));
                    median_filter_tb__DOT__mismatch_count 
                        = ((IData)(1U) + median_filter_tb__DOT__mismatch_count);
                }
            }
            median_filter_tb__DOT__output_count = ((IData)(1U) 
                                                   + median_filter_tb__DOT__output_count);
        }
        if (vlSelfRef.median_filter_tb__DOT__done_o) {
            median_filter_tb__DOT__done_count = ((IData)(1U) 
                                                 + median_filter_tb__DOT__done_count);
        }
        median_filter_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (median_filter_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.median_filter_tb__DOT__rst = 0U;
    vlSelfRef.median_filter_tb__DOT__start_i = 1U;
    vlSelfRef.median_filter_tb__DOT__pixel_valid_i = 0U;
    vlSelfRef.median_filter_tb__DOT__pixel_i = 0U;
    Vmedian_filter_tb___024root____VbeforeTrig_hc7fcfec1__0(vlSelf, 
                                                            "@(posedge median_filter_tb.clk)");
    co_await vlSelfRef.__VtrigSched_hc7fcfec1__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge median_filter_tb.clk)", 
                                                         "tb/median_filter_tb.sv", 
                                                         101);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/median_filter_tb.sv", 
                                         102);
    if (vlSelfRef.median_filter_tb__DOT__pixel_valid_o) {
        median_filter_tb__DOT__scan_count = VL_FSCANF_INX(median_filter_tb__DOT__expected_fd,"%d,%d,%d\n",3
                                                          , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_red)
                                                          , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_green)
                                                          , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_blue)) ;
        if ((3U != median_filter_tb__DOT__scan_count)) {
            VL_WRITEF_NX("FAIL: RTL produced more output pixels than expected.\n",0);
            median_filter_tb__DOT__mismatch_count = 
                ((IData)(1U) + median_filter_tb__DOT__mismatch_count);
        } else {
            VL_FWRITEF_NX(median_filter_tb__DOT__output_fd,"%0d,%0d,%0d\n",3
                          , '#',8,(0x000000ffU & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                                  >> 0x00000010U))
                          , '#',8,(0x000000ffU & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                                  >> 8U))
                          , '#',8,(0x000000ffU & vlSelfRef.median_filter_tb__DOT__pixel_o));
            if (VL_UNLIKELY((((((0x000000ffU & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                                >> 0x00000010U)) 
                                != (0x000000ffU & vlSelfRef.median_filter_tb__DOT__expected_red)) 
                               | ((0x000000ffU & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                                  >> 8U)) 
                                  != (0x000000ffU & vlSelfRef.median_filter_tb__DOT__expected_green))) 
                              | ((0x000000ffU & vlSelfRef.median_filter_tb__DOT__pixel_o) 
                                 != (0x000000ffU & vlSelfRef.median_filter_tb__DOT__expected_blue)))))) {
                VL_WRITEF_NX("FAIL: output %0d expected %0d,%0d,%0d got %0d,%0d,%0d\n",7
                             , '~',32,median_filter_tb__DOT__output_count
                             , '~',32,vlSelfRef.median_filter_tb__DOT__expected_red
                             , '~',32,vlSelfRef.median_filter_tb__DOT__expected_green
                             , '~',32,vlSelfRef.median_filter_tb__DOT__expected_blue
                             , '#',8,(0x000000ffU & 
                                      (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                       >> 0x00000010U))
                             , '#',8,(0x000000ffU & 
                                      (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                       >> 8U)), '#',8,
                             (0x000000ffU & vlSelfRef.median_filter_tb__DOT__pixel_o));
                median_filter_tb__DOT__mismatch_count 
                    = ((IData)(1U) + median_filter_tb__DOT__mismatch_count);
            }
        }
        median_filter_tb__DOT__output_count = ((IData)(1U) 
                                               + median_filter_tb__DOT__output_count);
    }
    if (vlSelfRef.median_filter_tb__DOT__done_o) {
        median_filter_tb__DOT__done_count = ((IData)(1U) 
                                             + median_filter_tb__DOT__done_count);
    }
    vlSelfRef.median_filter_tb__DOT__start_i = 0U;
    median_filter_tb__DOT__unnamedblk1__DOT__pixel_idx = 0U;
    while (VL_GTS_III(32, 0x00000010U, median_filter_tb__DOT__unnamedblk1__DOT__pixel_idx)) {
        median_filter_tb__DOT__scan_count = VL_FSCANF_INX(median_filter_tb__DOT__input_fd,"%d,%d,%d\n",3
                                                          , '#',32,&(vlSelfRef.median_filter_tb__DOT__red_value)
                                                          , '#',32,&(vlSelfRef.median_filter_tb__DOT__green_value)
                                                          , '#',32,&(vlSelfRef.median_filter_tb__DOT__blue_value)) ;
        if (VL_UNLIKELY(((3U != median_filter_tb__DOT__scan_count)))) {
            VL_WRITEF_NX("FAIL: input CSV ended early at pixel %0d.\n",1
                         , '~',32,median_filter_tb__DOT__unnamedblk1__DOT__pixel_idx);
            median_filter_tb__DOT__mismatch_count = 
                ((IData)(1U) + median_filter_tb__DOT__mismatch_count);
        } else {
            __Vtask_median_filter_tb__DOT__drive_pixel__4__blue_i 
                = vlSelfRef.median_filter_tb__DOT__blue_value;
            __Vtask_median_filter_tb__DOT__drive_pixel__4__green_i 
                = vlSelfRef.median_filter_tb__DOT__green_value;
            __Vtask_median_filter_tb__DOT__drive_pixel__4__red_i 
                = vlSelfRef.median_filter_tb__DOT__red_value;
            vlSelfRef.median_filter_tb__DOT__pixel_valid_i = 1U;
            vlSelfRef.median_filter_tb__DOT__pixel_i 
                = ((0x00ff0000U & (__Vtask_median_filter_tb__DOT__drive_pixel__4__red_i 
                                   << 0x00000010U)) 
                   | ((0x0000ff00U & (__Vtask_median_filter_tb__DOT__drive_pixel__4__green_i 
                                      << 8U)) | (0x000000ffU 
                                                 & __Vtask_median_filter_tb__DOT__drive_pixel__4__blue_i)));
            Vmedian_filter_tb___024root____VbeforeTrig_hc7fcfec1__0(vlSelf, 
                                                                    "@(posedge median_filter_tb.clk)");
            co_await vlSelfRef.__VtrigSched_hc7fcfec1__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge median_filter_tb.clk)", 
                                                                 "tb/median_filter_tb.sv", 
                                                                 113);
            co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                                 nullptr, 
                                                 "tb/median_filter_tb.sv", 
                                                 114);
            if (vlSelfRef.median_filter_tb__DOT__pixel_valid_o) {
                median_filter_tb__DOT__scan_count = VL_FSCANF_INX(median_filter_tb__DOT__expected_fd,"%d,%d,%d\n",3
                                                                  , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_red)
                                                                  , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_green)
                                                                  , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_blue)) ;
                if ((3U != median_filter_tb__DOT__scan_count)) {
                    VL_WRITEF_NX("FAIL: RTL produced more output pixels than expected.\n",0);
                    median_filter_tb__DOT__mismatch_count 
                        = ((IData)(1U) + median_filter_tb__DOT__mismatch_count);
                } else {
                    VL_FWRITEF_NX(median_filter_tb__DOT__output_fd,"%0d,%0d,%0d\n",3
                                  , '#',8,(0x000000ffU 
                                           & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                              >> 0x00000010U))
                                  , '#',8,(0x000000ffU 
                                           & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                              >> 8U))
                                  , '#',8,(0x000000ffU 
                                           & vlSelfRef.median_filter_tb__DOT__pixel_o));
                    if (VL_UNLIKELY((((((0x000000ffU 
                                         & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                            >> 0x00000010U)) 
                                        != (0x000000ffU 
                                            & vlSelfRef.median_filter_tb__DOT__expected_red)) 
                                       | ((0x000000ffU 
                                           & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                              >> 8U)) 
                                          != (0x000000ffU 
                                              & vlSelfRef.median_filter_tb__DOT__expected_green))) 
                                      | ((0x000000ffU 
                                          & vlSelfRef.median_filter_tb__DOT__pixel_o) 
                                         != (0x000000ffU 
                                             & vlSelfRef.median_filter_tb__DOT__expected_blue)))))) {
                        VL_WRITEF_NX("FAIL: output %0d expected %0d,%0d,%0d got %0d,%0d,%0d\n",7
                                     , '~',32,median_filter_tb__DOT__output_count
                                     , '~',32,vlSelfRef.median_filter_tb__DOT__expected_red
                                     , '~',32,vlSelfRef.median_filter_tb__DOT__expected_green
                                     , '~',32,vlSelfRef.median_filter_tb__DOT__expected_blue
                                     , '#',8,(0x000000ffU 
                                              & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                                 >> 0x00000010U))
                                     , '#',8,(0x000000ffU 
                                              & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                                 >> 8U))
                                     , '#',8,(0x000000ffU 
                                              & vlSelfRef.median_filter_tb__DOT__pixel_o));
                        median_filter_tb__DOT__mismatch_count 
                            = ((IData)(1U) + median_filter_tb__DOT__mismatch_count);
                    }
                }
                median_filter_tb__DOT__output_count 
                    = ((IData)(1U) + median_filter_tb__DOT__output_count);
            }
            if (vlSelfRef.median_filter_tb__DOT__done_o) {
                median_filter_tb__DOT__done_count = 
                    ((IData)(1U) + median_filter_tb__DOT__done_count);
            }
        }
        median_filter_tb__DOT__unnamedblk1__DOT__pixel_idx 
            = ((IData)(1U) + median_filter_tb__DOT__unnamedblk1__DOT__pixel_idx);
    }
    median_filter_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 = 8U;
    while (VL_LTS_III(32, 0U, median_filter_tb__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        vlSelfRef.median_filter_tb__DOT__pixel_valid_i = 0U;
        vlSelfRef.median_filter_tb__DOT__pixel_i = 0U;
        Vmedian_filter_tb___024root____VbeforeTrig_hc7fcfec1__0(vlSelf, 
                                                                "@(posedge median_filter_tb.clk)");
        co_await vlSelfRef.__VtrigSched_hc7fcfec1__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge median_filter_tb.clk)", 
                                                             "tb/median_filter_tb.sv", 
                                                             101);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/median_filter_tb.sv", 
                                             102);
        if (vlSelfRef.median_filter_tb__DOT__pixel_valid_o) {
            median_filter_tb__DOT__scan_count = VL_FSCANF_INX(median_filter_tb__DOT__expected_fd,"%d,%d,%d\n",3
                                                              , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_red)
                                                              , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_green)
                                                              , '#',32,&(vlSelfRef.median_filter_tb__DOT__expected_blue)) ;
            if ((3U != median_filter_tb__DOT__scan_count)) {
                VL_WRITEF_NX("FAIL: RTL produced more output pixels than expected.\n",0);
                median_filter_tb__DOT__mismatch_count 
                    = ((IData)(1U) + median_filter_tb__DOT__mismatch_count);
            } else {
                VL_FWRITEF_NX(median_filter_tb__DOT__output_fd,"%0d,%0d,%0d\n",3
                              , '#',8,(0x000000ffU 
                                       & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                          >> 0x00000010U))
                              , '#',8,(0x000000ffU 
                                       & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                          >> 8U)), '#',8,
                              (0x000000ffU & vlSelfRef.median_filter_tb__DOT__pixel_o));
                if (VL_UNLIKELY((((((0x000000ffU & 
                                     (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                      >> 0x00000010U)) 
                                    != (0x000000ffU 
                                        & vlSelfRef.median_filter_tb__DOT__expected_red)) 
                                   | ((0x000000ffU 
                                       & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                          >> 8U)) != 
                                      (0x000000ffU 
                                       & vlSelfRef.median_filter_tb__DOT__expected_green))) 
                                  | ((0x000000ffU & vlSelfRef.median_filter_tb__DOT__pixel_o) 
                                     != (0x000000ffU 
                                         & vlSelfRef.median_filter_tb__DOT__expected_blue)))))) {
                    VL_WRITEF_NX("FAIL: output %0d expected %0d,%0d,%0d got %0d,%0d,%0d\n",7
                                 , '~',32,median_filter_tb__DOT__output_count
                                 , '~',32,vlSelfRef.median_filter_tb__DOT__expected_red
                                 , '~',32,vlSelfRef.median_filter_tb__DOT__expected_green
                                 , '~',32,vlSelfRef.median_filter_tb__DOT__expected_blue
                                 , '#',8,(0x000000ffU 
                                          & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                             >> 0x00000010U))
                                 , '#',8,(0x000000ffU 
                                          & (vlSelfRef.median_filter_tb__DOT__pixel_o 
                                             >> 8U))
                                 , '#',8,(0x000000ffU 
                                          & vlSelfRef.median_filter_tb__DOT__pixel_o));
                    median_filter_tb__DOT__mismatch_count 
                        = ((IData)(1U) + median_filter_tb__DOT__mismatch_count);
                }
            }
            median_filter_tb__DOT__output_count = ((IData)(1U) 
                                                   + median_filter_tb__DOT__output_count);
        }
        if (vlSelfRef.median_filter_tb__DOT__done_o) {
            median_filter_tb__DOT__done_count = ((IData)(1U) 
                                                 + median_filter_tb__DOT__done_count);
        }
        median_filter_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (median_filter_tb__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((9U != median_filter_tb__DOT__output_count)))) {
        VL_WRITEF_NX("FAIL: expected 9 outputs, got %0d.\n",1
                     , '~',32,median_filter_tb__DOT__output_count);
        median_filter_tb__DOT__mismatch_count = ((IData)(1U) 
                                                 + median_filter_tb__DOT__mismatch_count);
    }
    if (VL_UNLIKELY(((1U != median_filter_tb__DOT__done_count)))) {
        VL_WRITEF_NX("FAIL: expected done_o to pulse once, got %0d pulses.\n",1
                     , '~',32,median_filter_tb__DOT__done_count);
        median_filter_tb__DOT__mismatch_count = ((IData)(1U) 
                                                 + median_filter_tb__DOT__mismatch_count);
    }
    if ((0U == median_filter_tb__DOT__mismatch_count)) {
        VL_WRITEF_NX("PASS: median filter output matched expected CSV.\n",0);
    } else {
        VL_WRITEF_NX("FAIL: saw %0d mismatch(es).\n",1
                     , '~',32,median_filter_tb__DOT__mismatch_count);
    }
    VL_FCLOSE_I(median_filter_tb__DOT__input_fd); VL_FCLOSE_I(median_filter_tb__DOT__expected_fd); VL_FCLOSE_I(median_filter_tb__DOT__output_fd); VL_FINISH_MT("tb/median_filter_tb.sv", 203, "");
    co_return;
}

VlCoroutine Vmedian_filter_tb___024root___eval_initial__TOP__Vtiming__1(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "tb/median_filter_tb.sv", 
                                             57);
        vlSelfRef.median_filter_tb__DOT__clk = (1U 
                                                & (~ (IData)(vlSelfRef.median_filter_tb__DOT__clk)));
    }
    co_return;
}

bool Vmedian_filter_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vmedian_filter_tb___024root___act_comb__TOP__0(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___act_comb__TOP__0\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_2__find_median_channel;
    CData/*7:0*/ median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_1__find_median_channel;
    CData/*7:0*/ median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_0__find_median_channel;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_0_i;
    __Vfunc_find_median_channel__8__value_0_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_1_i;
    __Vfunc_find_median_channel__8__value_1_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_2_i;
    __Vfunc_find_median_channel__8__value_2_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_3_i;
    __Vfunc_find_median_channel__8__value_3_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_0;
    __Vfunc_find_median_channel__8__value_0 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_1;
    __Vfunc_find_median_channel__8__value_1 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_2;
    __Vfunc_find_median_channel__8__value_2 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_3;
    __Vfunc_find_median_channel__8__value_3 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__swap_value;
    __Vfunc_find_median_channel__8__swap_value = 0;
    SData/*8:0*/ __Vfunc_find_median_channel__8__median_sum;
    __Vfunc_find_median_channel__8__median_sum = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_0_i;
    __Vfunc_find_median_channel__9__value_0_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_1_i;
    __Vfunc_find_median_channel__9__value_1_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_2_i;
    __Vfunc_find_median_channel__9__value_2_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_3_i;
    __Vfunc_find_median_channel__9__value_3_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_0;
    __Vfunc_find_median_channel__9__value_0 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_1;
    __Vfunc_find_median_channel__9__value_1 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_2;
    __Vfunc_find_median_channel__9__value_2 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_3;
    __Vfunc_find_median_channel__9__value_3 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__swap_value;
    __Vfunc_find_median_channel__9__swap_value = 0;
    SData/*8:0*/ __Vfunc_find_median_channel__9__median_sum;
    __Vfunc_find_median_channel__9__median_sum = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_0_i;
    __Vfunc_find_median_channel__10__value_0_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_1_i;
    __Vfunc_find_median_channel__10__value_1_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_2_i;
    __Vfunc_find_median_channel__10__value_2_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_3_i;
    __Vfunc_find_median_channel__10__value_3_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_0;
    __Vfunc_find_median_channel__10__value_0 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_1;
    __Vfunc_find_median_channel__10__value_1 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_2;
    __Vfunc_find_median_channel__10__value_2 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_3;
    __Vfunc_find_median_channel__10__value_3 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__swap_value;
    __Vfunc_find_median_channel__10__swap_value = 0;
    SData/*8:0*/ __Vfunc_find_median_channel__10__median_sum;
    __Vfunc_find_median_channel__10__median_sum = 0;
    // Body
    vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q;
    if (vlSelfRef.median_filter_tb__DOT__pixel_valid_i) {
        vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d[0U] 
            = vlSelfRef.median_filter_tb__DOT__pixel_i;
        vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d[1U] 
            = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[0U];
        vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d[2U] 
            = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[1U];
        vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d[3U] 
            = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[2U];
        vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d[4U] 
            = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[3U];
    }
    vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_d 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q;
    vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel_valid = 0U;
    vlSelfRef.median_filter_tb__DOT__dut__DOT__done_d = 0U;
    if ((0U != (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q))) {
        if ((1U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q))) {
            if (vlSelfRef.median_filter_tb__DOT__pixel_valid_i) {
                vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel_valid 
                    = ((0U != (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q)) 
                       & (0U != (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q)));
                if ((3U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q))) {
                    if ((3U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q))) {
                        vlSelfRef.median_filter_tb__DOT__dut__DOT__done_d = 1U;
                    }
                }
            }
        }
    }
    vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_d 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q;
    vlSelfRef.median_filter_tb__DOT__dut__DOT__state_d 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q;
    if ((0U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q))) {
        vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_d = 0U;
        vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_d = 0U;
        if (vlSelfRef.median_filter_tb__DOT__start_i) {
            vlSelfRef.median_filter_tb__DOT__dut__DOT__state_d = 1U;
        }
    } else if ((1U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q))) {
        if (vlSelfRef.median_filter_tb__DOT__pixel_valid_i) {
            vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_d 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q)));
            if ((3U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q))) {
                vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_d = 0U;
                vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_d 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q)));
                if ((3U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q))) {
                    vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_d = 0U;
                    vlSelfRef.median_filter_tb__DOT__dut__DOT__state_d = 0U;
                }
            }
        }
    }
    vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][0U] 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[4U];
    vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][1U] 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[3U];
    vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][0U] 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[0U];
    vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][1U] 
        = vlSelfRef.median_filter_tb__DOT__pixel_i;
    __Vfunc_find_median_channel__8__value_3_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][1U] 
                                                    >> 0x00000010U));
    __Vfunc_find_median_channel__8__value_2_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][0U] 
                                                    >> 0x00000010U));
    __Vfunc_find_median_channel__8__value_1_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][1U] 
                                                    >> 0x00000010U));
    __Vfunc_find_median_channel__8__value_0_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][0U] 
                                                    >> 0x00000010U));
    __Vfunc_find_median_channel__8__swap_value = 0;
    __Vfunc_find_median_channel__8__value_0 = __Vfunc_find_median_channel__8__value_0_i;
    __Vfunc_find_median_channel__8__value_1 = __Vfunc_find_median_channel__8__value_1_i;
    __Vfunc_find_median_channel__8__value_2 = __Vfunc_find_median_channel__8__value_2_i;
    __Vfunc_find_median_channel__8__value_3 = __Vfunc_find_median_channel__8__value_3_i;
    if (((IData)(__Vfunc_find_median_channel__8__value_0) 
         > (IData)(__Vfunc_find_median_channel__8__value_1))) {
        __Vfunc_find_median_channel__8__swap_value 
            = __Vfunc_find_median_channel__8__value_0;
        __Vfunc_find_median_channel__8__value_0 = __Vfunc_find_median_channel__8__value_1;
        __Vfunc_find_median_channel__8__value_1 = __Vfunc_find_median_channel__8__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__8__value_2) 
         > (IData)(__Vfunc_find_median_channel__8__value_3))) {
        __Vfunc_find_median_channel__8__swap_value 
            = __Vfunc_find_median_channel__8__value_2;
        __Vfunc_find_median_channel__8__value_2 = __Vfunc_find_median_channel__8__value_3;
        __Vfunc_find_median_channel__8__value_3 = __Vfunc_find_median_channel__8__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__8__value_0) 
         > (IData)(__Vfunc_find_median_channel__8__value_2))) {
        __Vfunc_find_median_channel__8__swap_value 
            = __Vfunc_find_median_channel__8__value_0;
        __Vfunc_find_median_channel__8__value_0 = __Vfunc_find_median_channel__8__value_2;
        __Vfunc_find_median_channel__8__value_2 = __Vfunc_find_median_channel__8__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__8__value_1) 
         > (IData)(__Vfunc_find_median_channel__8__value_3))) {
        __Vfunc_find_median_channel__8__swap_value 
            = __Vfunc_find_median_channel__8__value_1;
        __Vfunc_find_median_channel__8__value_1 = __Vfunc_find_median_channel__8__value_3;
        __Vfunc_find_median_channel__8__value_3 = __Vfunc_find_median_channel__8__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__8__value_1) 
         > (IData)(__Vfunc_find_median_channel__8__value_2))) {
        __Vfunc_find_median_channel__8__swap_value 
            = __Vfunc_find_median_channel__8__value_1;
        __Vfunc_find_median_channel__8__value_1 = __Vfunc_find_median_channel__8__value_2;
        __Vfunc_find_median_channel__8__value_2 = __Vfunc_find_median_channel__8__swap_value;
    }
    __Vfunc_find_median_channel__8__median_sum = (0x000001ffU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     ((IData)(__Vfunc_find_median_channel__8__value_1) 
                                                      + (IData)(__Vfunc_find_median_channel__8__value_2))));
    median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_0__find_median_channel 
        = (0x000000ffU & ((IData)(__Vfunc_find_median_channel__8__median_sum) 
                          >> 1U));
    vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d 
        = ((0x0000ffffU & vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d) 
           | ((IData)(median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_0__find_median_channel) 
              << 0x00000010U));
    __Vfunc_find_median_channel__9__value_3_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][1U] 
                                                    >> 8U));
    __Vfunc_find_median_channel__9__value_2_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][0U] 
                                                    >> 8U));
    __Vfunc_find_median_channel__9__value_1_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][1U] 
                                                    >> 8U));
    __Vfunc_find_median_channel__9__value_0_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][0U] 
                                                    >> 8U));
    __Vfunc_find_median_channel__9__swap_value = 0;
    __Vfunc_find_median_channel__9__value_0 = __Vfunc_find_median_channel__9__value_0_i;
    __Vfunc_find_median_channel__9__value_1 = __Vfunc_find_median_channel__9__value_1_i;
    __Vfunc_find_median_channel__9__value_2 = __Vfunc_find_median_channel__9__value_2_i;
    __Vfunc_find_median_channel__9__value_3 = __Vfunc_find_median_channel__9__value_3_i;
    if (((IData)(__Vfunc_find_median_channel__9__value_0) 
         > (IData)(__Vfunc_find_median_channel__9__value_1))) {
        __Vfunc_find_median_channel__9__swap_value 
            = __Vfunc_find_median_channel__9__value_0;
        __Vfunc_find_median_channel__9__value_0 = __Vfunc_find_median_channel__9__value_1;
        __Vfunc_find_median_channel__9__value_1 = __Vfunc_find_median_channel__9__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__9__value_2) 
         > (IData)(__Vfunc_find_median_channel__9__value_3))) {
        __Vfunc_find_median_channel__9__swap_value 
            = __Vfunc_find_median_channel__9__value_2;
        __Vfunc_find_median_channel__9__value_2 = __Vfunc_find_median_channel__9__value_3;
        __Vfunc_find_median_channel__9__value_3 = __Vfunc_find_median_channel__9__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__9__value_0) 
         > (IData)(__Vfunc_find_median_channel__9__value_2))) {
        __Vfunc_find_median_channel__9__swap_value 
            = __Vfunc_find_median_channel__9__value_0;
        __Vfunc_find_median_channel__9__value_0 = __Vfunc_find_median_channel__9__value_2;
        __Vfunc_find_median_channel__9__value_2 = __Vfunc_find_median_channel__9__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__9__value_1) 
         > (IData)(__Vfunc_find_median_channel__9__value_3))) {
        __Vfunc_find_median_channel__9__swap_value 
            = __Vfunc_find_median_channel__9__value_1;
        __Vfunc_find_median_channel__9__value_1 = __Vfunc_find_median_channel__9__value_3;
        __Vfunc_find_median_channel__9__value_3 = __Vfunc_find_median_channel__9__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__9__value_1) 
         > (IData)(__Vfunc_find_median_channel__9__value_2))) {
        __Vfunc_find_median_channel__9__swap_value 
            = __Vfunc_find_median_channel__9__value_1;
        __Vfunc_find_median_channel__9__value_1 = __Vfunc_find_median_channel__9__value_2;
        __Vfunc_find_median_channel__9__value_2 = __Vfunc_find_median_channel__9__swap_value;
    }
    __Vfunc_find_median_channel__9__median_sum = (0x000001ffU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     ((IData)(__Vfunc_find_median_channel__9__value_1) 
                                                      + (IData)(__Vfunc_find_median_channel__9__value_2))));
    median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_1__find_median_channel 
        = (0x000000ffU & ((IData)(__Vfunc_find_median_channel__9__median_sum) 
                          >> 1U));
    vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d 
        = ((0x00ff00ffU & vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d) 
           | ((IData)(median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_1__find_median_channel) 
              << 8U));
    __Vfunc_find_median_channel__10__value_3_i = (0x000000ffU 
                                                  & vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][1U]);
    __Vfunc_find_median_channel__10__value_2_i = (0x000000ffU 
                                                  & vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][0U]);
    __Vfunc_find_median_channel__10__value_1_i = (0x000000ffU 
                                                  & vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][1U]);
    __Vfunc_find_median_channel__10__value_0_i = (0x000000ffU 
                                                  & vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][0U]);
    __Vfunc_find_median_channel__10__swap_value = 0;
    __Vfunc_find_median_channel__10__value_0 = __Vfunc_find_median_channel__10__value_0_i;
    __Vfunc_find_median_channel__10__value_1 = __Vfunc_find_median_channel__10__value_1_i;
    __Vfunc_find_median_channel__10__value_2 = __Vfunc_find_median_channel__10__value_2_i;
    __Vfunc_find_median_channel__10__value_3 = __Vfunc_find_median_channel__10__value_3_i;
    if (((IData)(__Vfunc_find_median_channel__10__value_0) 
         > (IData)(__Vfunc_find_median_channel__10__value_1))) {
        __Vfunc_find_median_channel__10__swap_value 
            = __Vfunc_find_median_channel__10__value_0;
        __Vfunc_find_median_channel__10__value_0 = __Vfunc_find_median_channel__10__value_1;
        __Vfunc_find_median_channel__10__value_1 = __Vfunc_find_median_channel__10__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__10__value_2) 
         > (IData)(__Vfunc_find_median_channel__10__value_3))) {
        __Vfunc_find_median_channel__10__swap_value 
            = __Vfunc_find_median_channel__10__value_2;
        __Vfunc_find_median_channel__10__value_2 = __Vfunc_find_median_channel__10__value_3;
        __Vfunc_find_median_channel__10__value_3 = __Vfunc_find_median_channel__10__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__10__value_0) 
         > (IData)(__Vfunc_find_median_channel__10__value_2))) {
        __Vfunc_find_median_channel__10__swap_value 
            = __Vfunc_find_median_channel__10__value_0;
        __Vfunc_find_median_channel__10__value_0 = __Vfunc_find_median_channel__10__value_2;
        __Vfunc_find_median_channel__10__value_2 = __Vfunc_find_median_channel__10__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__10__value_1) 
         > (IData)(__Vfunc_find_median_channel__10__value_3))) {
        __Vfunc_find_median_channel__10__swap_value 
            = __Vfunc_find_median_channel__10__value_1;
        __Vfunc_find_median_channel__10__value_1 = __Vfunc_find_median_channel__10__value_3;
        __Vfunc_find_median_channel__10__value_3 = __Vfunc_find_median_channel__10__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__10__value_1) 
         > (IData)(__Vfunc_find_median_channel__10__value_2))) {
        __Vfunc_find_median_channel__10__swap_value 
            = __Vfunc_find_median_channel__10__value_1;
        __Vfunc_find_median_channel__10__value_1 = __Vfunc_find_median_channel__10__value_2;
        __Vfunc_find_median_channel__10__value_2 = __Vfunc_find_median_channel__10__swap_value;
    }
    __Vfunc_find_median_channel__10__median_sum = (0x000001ffU 
                                                   & ((IData)(1U) 
                                                      + 
                                                      ((IData)(__Vfunc_find_median_channel__10__value_1) 
                                                       + (IData)(__Vfunc_find_median_channel__10__value_2))));
    median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_2__find_median_channel 
        = (0x000000ffU & ((IData)(__Vfunc_find_median_channel__10__median_sum) 
                          >> 1U));
    vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d 
        = ((0x00ffff00U & vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d) 
           | (IData)(median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_2__find_median_channel));
}

void Vmedian_filter_tb___024root___nba_comb__TOP__0(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___nba_comb__TOP__0\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_2__find_median_channel;
    CData/*7:0*/ median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_1__find_median_channel;
    CData/*7:0*/ median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_0__find_median_channel;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_0_i;
    __Vfunc_find_median_channel__8__value_0_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_1_i;
    __Vfunc_find_median_channel__8__value_1_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_2_i;
    __Vfunc_find_median_channel__8__value_2_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_3_i;
    __Vfunc_find_median_channel__8__value_3_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_0;
    __Vfunc_find_median_channel__8__value_0 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_1;
    __Vfunc_find_median_channel__8__value_1 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_2;
    __Vfunc_find_median_channel__8__value_2 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__value_3;
    __Vfunc_find_median_channel__8__value_3 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__8__swap_value;
    __Vfunc_find_median_channel__8__swap_value = 0;
    SData/*8:0*/ __Vfunc_find_median_channel__8__median_sum;
    __Vfunc_find_median_channel__8__median_sum = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_0_i;
    __Vfunc_find_median_channel__9__value_0_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_1_i;
    __Vfunc_find_median_channel__9__value_1_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_2_i;
    __Vfunc_find_median_channel__9__value_2_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_3_i;
    __Vfunc_find_median_channel__9__value_3_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_0;
    __Vfunc_find_median_channel__9__value_0 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_1;
    __Vfunc_find_median_channel__9__value_1 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_2;
    __Vfunc_find_median_channel__9__value_2 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__value_3;
    __Vfunc_find_median_channel__9__value_3 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__9__swap_value;
    __Vfunc_find_median_channel__9__swap_value = 0;
    SData/*8:0*/ __Vfunc_find_median_channel__9__median_sum;
    __Vfunc_find_median_channel__9__median_sum = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_0_i;
    __Vfunc_find_median_channel__10__value_0_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_1_i;
    __Vfunc_find_median_channel__10__value_1_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_2_i;
    __Vfunc_find_median_channel__10__value_2_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_3_i;
    __Vfunc_find_median_channel__10__value_3_i = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_0;
    __Vfunc_find_median_channel__10__value_0 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_1;
    __Vfunc_find_median_channel__10__value_1 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_2;
    __Vfunc_find_median_channel__10__value_2 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__value_3;
    __Vfunc_find_median_channel__10__value_3 = 0;
    CData/*7:0*/ __Vfunc_find_median_channel__10__swap_value;
    __Vfunc_find_median_channel__10__swap_value = 0;
    SData/*8:0*/ __Vfunc_find_median_channel__10__median_sum;
    __Vfunc_find_median_channel__10__median_sum = 0;
    // Body
    vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_d 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q;
    vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel_valid = 0U;
    vlSelfRef.median_filter_tb__DOT__dut__DOT__done_d = 0U;
    if ((0U != (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q))) {
        if ((1U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q))) {
            if (vlSelfRef.median_filter_tb__DOT__pixel_valid_i) {
                vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel_valid 
                    = ((0U != (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q)) 
                       & (0U != (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q)));
                if ((3U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q))) {
                    if ((3U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q))) {
                        vlSelfRef.median_filter_tb__DOT__dut__DOT__done_d = 1U;
                    }
                }
            }
        }
    }
    vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_d 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q;
    vlSelfRef.median_filter_tb__DOT__dut__DOT__state_d 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q;
    if ((0U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q))) {
        vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_d = 0U;
        vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_d = 0U;
        if (vlSelfRef.median_filter_tb__DOT__start_i) {
            vlSelfRef.median_filter_tb__DOT__dut__DOT__state_d = 1U;
        }
    } else if ((1U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q))) {
        if (vlSelfRef.median_filter_tb__DOT__pixel_valid_i) {
            vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_d 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q)));
            if ((3U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q))) {
                vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_d = 0U;
                vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_d 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q)));
                if ((3U == (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q))) {
                    vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_d = 0U;
                    vlSelfRef.median_filter_tb__DOT__dut__DOT__state_d = 0U;
                }
            }
        }
    }
    vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q;
    if (vlSelfRef.median_filter_tb__DOT__pixel_valid_i) {
        vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d[0U] 
            = vlSelfRef.median_filter_tb__DOT__pixel_i;
        vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d[1U] 
            = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[0U];
        vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d[2U] 
            = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[1U];
        vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d[3U] 
            = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[2U];
        vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d[4U] 
            = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[3U];
    }
    vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][0U] 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[4U];
    vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][1U] 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[3U];
    vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][0U] 
        = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[0U];
    vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][1U] 
        = vlSelfRef.median_filter_tb__DOT__pixel_i;
    __Vfunc_find_median_channel__8__value_3_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][1U] 
                                                    >> 0x00000010U));
    __Vfunc_find_median_channel__8__value_2_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][0U] 
                                                    >> 0x00000010U));
    __Vfunc_find_median_channel__8__value_1_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][1U] 
                                                    >> 0x00000010U));
    __Vfunc_find_median_channel__8__value_0_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][0U] 
                                                    >> 0x00000010U));
    __Vfunc_find_median_channel__8__swap_value = 0;
    __Vfunc_find_median_channel__8__value_0 = __Vfunc_find_median_channel__8__value_0_i;
    __Vfunc_find_median_channel__8__value_1 = __Vfunc_find_median_channel__8__value_1_i;
    __Vfunc_find_median_channel__8__value_2 = __Vfunc_find_median_channel__8__value_2_i;
    __Vfunc_find_median_channel__8__value_3 = __Vfunc_find_median_channel__8__value_3_i;
    if (((IData)(__Vfunc_find_median_channel__8__value_0) 
         > (IData)(__Vfunc_find_median_channel__8__value_1))) {
        __Vfunc_find_median_channel__8__swap_value 
            = __Vfunc_find_median_channel__8__value_0;
        __Vfunc_find_median_channel__8__value_0 = __Vfunc_find_median_channel__8__value_1;
        __Vfunc_find_median_channel__8__value_1 = __Vfunc_find_median_channel__8__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__8__value_2) 
         > (IData)(__Vfunc_find_median_channel__8__value_3))) {
        __Vfunc_find_median_channel__8__swap_value 
            = __Vfunc_find_median_channel__8__value_2;
        __Vfunc_find_median_channel__8__value_2 = __Vfunc_find_median_channel__8__value_3;
        __Vfunc_find_median_channel__8__value_3 = __Vfunc_find_median_channel__8__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__8__value_0) 
         > (IData)(__Vfunc_find_median_channel__8__value_2))) {
        __Vfunc_find_median_channel__8__swap_value 
            = __Vfunc_find_median_channel__8__value_0;
        __Vfunc_find_median_channel__8__value_0 = __Vfunc_find_median_channel__8__value_2;
        __Vfunc_find_median_channel__8__value_2 = __Vfunc_find_median_channel__8__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__8__value_1) 
         > (IData)(__Vfunc_find_median_channel__8__value_3))) {
        __Vfunc_find_median_channel__8__swap_value 
            = __Vfunc_find_median_channel__8__value_1;
        __Vfunc_find_median_channel__8__value_1 = __Vfunc_find_median_channel__8__value_3;
        __Vfunc_find_median_channel__8__value_3 = __Vfunc_find_median_channel__8__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__8__value_1) 
         > (IData)(__Vfunc_find_median_channel__8__value_2))) {
        __Vfunc_find_median_channel__8__swap_value 
            = __Vfunc_find_median_channel__8__value_1;
        __Vfunc_find_median_channel__8__value_1 = __Vfunc_find_median_channel__8__value_2;
        __Vfunc_find_median_channel__8__value_2 = __Vfunc_find_median_channel__8__swap_value;
    }
    __Vfunc_find_median_channel__8__median_sum = (0x000001ffU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     ((IData)(__Vfunc_find_median_channel__8__value_1) 
                                                      + (IData)(__Vfunc_find_median_channel__8__value_2))));
    median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_0__find_median_channel 
        = (0x000000ffU & ((IData)(__Vfunc_find_median_channel__8__median_sum) 
                          >> 1U));
    vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d 
        = ((0x0000ffffU & vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d) 
           | ((IData)(median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_0__find_median_channel) 
              << 0x00000010U));
    __Vfunc_find_median_channel__9__value_3_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][1U] 
                                                    >> 8U));
    __Vfunc_find_median_channel__9__value_2_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][0U] 
                                                    >> 8U));
    __Vfunc_find_median_channel__9__value_1_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][1U] 
                                                    >> 8U));
    __Vfunc_find_median_channel__9__value_0_i = (0x000000ffU 
                                                 & (vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][0U] 
                                                    >> 8U));
    __Vfunc_find_median_channel__9__swap_value = 0;
    __Vfunc_find_median_channel__9__value_0 = __Vfunc_find_median_channel__9__value_0_i;
    __Vfunc_find_median_channel__9__value_1 = __Vfunc_find_median_channel__9__value_1_i;
    __Vfunc_find_median_channel__9__value_2 = __Vfunc_find_median_channel__9__value_2_i;
    __Vfunc_find_median_channel__9__value_3 = __Vfunc_find_median_channel__9__value_3_i;
    if (((IData)(__Vfunc_find_median_channel__9__value_0) 
         > (IData)(__Vfunc_find_median_channel__9__value_1))) {
        __Vfunc_find_median_channel__9__swap_value 
            = __Vfunc_find_median_channel__9__value_0;
        __Vfunc_find_median_channel__9__value_0 = __Vfunc_find_median_channel__9__value_1;
        __Vfunc_find_median_channel__9__value_1 = __Vfunc_find_median_channel__9__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__9__value_2) 
         > (IData)(__Vfunc_find_median_channel__9__value_3))) {
        __Vfunc_find_median_channel__9__swap_value 
            = __Vfunc_find_median_channel__9__value_2;
        __Vfunc_find_median_channel__9__value_2 = __Vfunc_find_median_channel__9__value_3;
        __Vfunc_find_median_channel__9__value_3 = __Vfunc_find_median_channel__9__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__9__value_0) 
         > (IData)(__Vfunc_find_median_channel__9__value_2))) {
        __Vfunc_find_median_channel__9__swap_value 
            = __Vfunc_find_median_channel__9__value_0;
        __Vfunc_find_median_channel__9__value_0 = __Vfunc_find_median_channel__9__value_2;
        __Vfunc_find_median_channel__9__value_2 = __Vfunc_find_median_channel__9__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__9__value_1) 
         > (IData)(__Vfunc_find_median_channel__9__value_3))) {
        __Vfunc_find_median_channel__9__swap_value 
            = __Vfunc_find_median_channel__9__value_1;
        __Vfunc_find_median_channel__9__value_1 = __Vfunc_find_median_channel__9__value_3;
        __Vfunc_find_median_channel__9__value_3 = __Vfunc_find_median_channel__9__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__9__value_1) 
         > (IData)(__Vfunc_find_median_channel__9__value_2))) {
        __Vfunc_find_median_channel__9__swap_value 
            = __Vfunc_find_median_channel__9__value_1;
        __Vfunc_find_median_channel__9__value_1 = __Vfunc_find_median_channel__9__value_2;
        __Vfunc_find_median_channel__9__value_2 = __Vfunc_find_median_channel__9__swap_value;
    }
    __Vfunc_find_median_channel__9__median_sum = (0x000001ffU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     ((IData)(__Vfunc_find_median_channel__9__value_1) 
                                                      + (IData)(__Vfunc_find_median_channel__9__value_2))));
    median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_1__find_median_channel 
        = (0x000000ffU & ((IData)(__Vfunc_find_median_channel__9__median_sum) 
                          >> 1U));
    vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d 
        = ((0x00ff00ffU & vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d) 
           | ((IData)(median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_1__find_median_channel) 
              << 8U));
    __Vfunc_find_median_channel__10__value_3_i = (0x000000ffU 
                                                  & vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][1U]);
    __Vfunc_find_median_channel__10__value_2_i = (0x000000ffU 
                                                  & vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[1U][0U]);
    __Vfunc_find_median_channel__10__value_1_i = (0x000000ffU 
                                                  & vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][1U]);
    __Vfunc_find_median_channel__10__value_0_i = (0x000000ffU 
                                                  & vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel[0U][0U]);
    __Vfunc_find_median_channel__10__swap_value = 0;
    __Vfunc_find_median_channel__10__value_0 = __Vfunc_find_median_channel__10__value_0_i;
    __Vfunc_find_median_channel__10__value_1 = __Vfunc_find_median_channel__10__value_1_i;
    __Vfunc_find_median_channel__10__value_2 = __Vfunc_find_median_channel__10__value_2_i;
    __Vfunc_find_median_channel__10__value_3 = __Vfunc_find_median_channel__10__value_3_i;
    if (((IData)(__Vfunc_find_median_channel__10__value_0) 
         > (IData)(__Vfunc_find_median_channel__10__value_1))) {
        __Vfunc_find_median_channel__10__swap_value 
            = __Vfunc_find_median_channel__10__value_0;
        __Vfunc_find_median_channel__10__value_0 = __Vfunc_find_median_channel__10__value_1;
        __Vfunc_find_median_channel__10__value_1 = __Vfunc_find_median_channel__10__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__10__value_2) 
         > (IData)(__Vfunc_find_median_channel__10__value_3))) {
        __Vfunc_find_median_channel__10__swap_value 
            = __Vfunc_find_median_channel__10__value_2;
        __Vfunc_find_median_channel__10__value_2 = __Vfunc_find_median_channel__10__value_3;
        __Vfunc_find_median_channel__10__value_3 = __Vfunc_find_median_channel__10__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__10__value_0) 
         > (IData)(__Vfunc_find_median_channel__10__value_2))) {
        __Vfunc_find_median_channel__10__swap_value 
            = __Vfunc_find_median_channel__10__value_0;
        __Vfunc_find_median_channel__10__value_0 = __Vfunc_find_median_channel__10__value_2;
        __Vfunc_find_median_channel__10__value_2 = __Vfunc_find_median_channel__10__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__10__value_1) 
         > (IData)(__Vfunc_find_median_channel__10__value_3))) {
        __Vfunc_find_median_channel__10__swap_value 
            = __Vfunc_find_median_channel__10__value_1;
        __Vfunc_find_median_channel__10__value_1 = __Vfunc_find_median_channel__10__value_3;
        __Vfunc_find_median_channel__10__value_3 = __Vfunc_find_median_channel__10__swap_value;
    }
    if (((IData)(__Vfunc_find_median_channel__10__value_1) 
         > (IData)(__Vfunc_find_median_channel__10__value_2))) {
        __Vfunc_find_median_channel__10__swap_value 
            = __Vfunc_find_median_channel__10__value_1;
        __Vfunc_find_median_channel__10__value_1 = __Vfunc_find_median_channel__10__value_2;
        __Vfunc_find_median_channel__10__value_2 = __Vfunc_find_median_channel__10__swap_value;
    }
    __Vfunc_find_median_channel__10__median_sum = (0x000001ffU 
                                                   & ((IData)(1U) 
                                                      + 
                                                      ((IData)(__Vfunc_find_median_channel__10__value_1) 
                                                       + (IData)(__Vfunc_find_median_channel__10__value_2))));
    median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_2__find_median_channel 
        = (0x000000ffU & ((IData)(__Vfunc_find_median_channel__10__median_sum) 
                          >> 1U));
    vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d 
        = ((0x00ffff00U & vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d) 
           | (IData)(median_filter_tb__DOT__dut__DOT__median_kernel_calc_inst__DOT____VlemCall_2__find_median_channel));
}

void Vmedian_filter_tb___024root___timing_ready(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___timing_ready\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hc7fcfec1__0.ready("@(posedge median_filter_tb.clk)");
    }
}

void Vmedian_filter_tb___024root___timing_resume(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___timing_resume\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_hc7fcfec1__0.moveToResumeQueue(
                                                          "@(posedge median_filter_tb.clk)");
    vlSelfRef.__VtrigSched_hc7fcfec1__0.resume("@(posedge median_filter_tb.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vmedian_filter_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmedian_filter_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vmedian_filter_tb___024root___eval_phase__act(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval_phase__act\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.median_filter_tb__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__median_filter_tb__DOT__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__median_filter_tb__DOT__clk__0 
            = vlSelfRef.median_filter_tb__DOT__clk;
    }
    Vmedian_filter_tb___024root___timing_ready(vlSelf);
    Vmedian_filter_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmedian_filter_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vmedian_filter_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vmedian_filter_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vmedian_filter_tb___024root___timing_resume(vlSelf);
        {
            // Inlined CFunc: _eval_act
            if ((3ULL & vlSelfRef.__VactTriggered[0U])) {
                Vmedian_filter_tb___024root___act_comb__TOP__0(vlSelf);
            }
        }
    }
    return (__VactExecute);
}

bool Vmedian_filter_tb___024root___eval_phase__inact(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval_phase__inact\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb/median_filter_tb.sv", 5, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vmedian_filter_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vmedian_filter_tb___024root___eval_phase__nba(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval_phase__nba\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vmedian_filter_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    vlSelfRef.median_filter_tb__DOT__done_o 
                        = ((1U & (~ (IData)(vlSelfRef.median_filter_tb__DOT__rst))) 
                           && (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__done_d));
                    vlSelfRef.median_filter_tb__DOT__pixel_valid_o 
                        = ((1U & (~ (IData)(vlSelfRef.median_filter_tb__DOT__rst))) 
                           && (IData)(vlSelfRef.median_filter_tb__DOT__dut__DOT__kernel_valid));
                    if (vlSelfRef.median_filter_tb__DOT__rst) {
                        vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q = 0U;
                        vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q = 0U;
                        vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q = 0U;
                    } else {
                        vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_q 
                            = vlSelfRef.median_filter_tb__DOT__dut__DOT__y_counter_d;
                        vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_q 
                            = vlSelfRef.median_filter_tb__DOT__dut__DOT__x_counter_d;
                        vlSelfRef.median_filter_tb__DOT__dut__DOT__state_q 
                            = vlSelfRef.median_filter_tb__DOT__dut__DOT__state_d;
                    }
                    if ((1U & (~ (IData)(vlSelfRef.median_filter_tb__DOT__rst)))) {
                        vlSelfRef.median_filter_tb__DOT__pixel_o 
                            = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_d;
                        vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q 
                            = vlSelfRef.median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d;
                    }
                }
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vmedian_filter_tb___024root___nba_comb__TOP__0(vlSelf);
            }
        }
        Vmedian_filter_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vmedian_filter_tb___024root___eval(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vmedian_filter_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/median_filter_tb.sv", 5, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tb/median_filter_tb.sv", 5, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vmedian_filter_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tb/median_filter_tb.sv", 5, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vmedian_filter_tb___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vmedian_filter_tb___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vmedian_filter_tb___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vmedian_filter_tb___024root____VbeforeTrig_hc7fcfec1__0(Vmedian_filter_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root____VbeforeTrig_hc7fcfec1__0\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.median_filter_tb__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__median_filter_tb__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__median_filter_tb__DOT__clk__0 
        = vlSelfRef.median_filter_tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hc7fcfec1__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc7fcfec1__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc7fcfec1__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hc7fcfec1__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vmedian_filter_tb___024root___eval_debug_assertions(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval_debug_assertions\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
