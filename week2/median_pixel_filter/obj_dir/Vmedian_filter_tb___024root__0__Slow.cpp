// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmedian_filter_tb.h for the primary calling header

#include "Vmedian_filter_tb__pch.h"

void Vmedian_filter_tb___024root___timing_ready(Vmedian_filter_tb___024root* vlSelf);

VL_ATTR_COLD void Vmedian_filter_tb___024root___eval_static(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval_static\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__median_filter_tb__DOT__clk__0 
        = vlSelfRef.median_filter_tb__DOT__clk;
    Vmedian_filter_tb___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vmedian_filter_tb___024root___eval_final(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval_final\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmedian_filter_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmedian_filter_tb___024root___eval_phase__stl(Vmedian_filter_tb___024root* vlSelf);

VL_ATTR_COLD void Vmedian_filter_tb___024root___eval_settle(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval_settle\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vmedian_filter_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb/median_filter_tb.sv", 5, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vmedian_filter_tb___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vmedian_filter_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmedian_filter_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vmedian_filter_tb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vmedian_filter_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___trigger_anySet__stl\n"); );
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

void Vmedian_filter_tb___024root___act_comb__TOP__0(Vmedian_filter_tb___024root* vlSelf);

VL_ATTR_COLD bool Vmedian_filter_tb___024root___eval_phase__stl(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___eval_phase__stl\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmedian_filter_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vmedian_filter_tb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vmedian_filter_tb___024root___act_comb__TOP__0(vlSelf);
            }
        }
    }
    return (__VstlExecute);
}

bool Vmedian_filter_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmedian_filter_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vmedian_filter_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge median_filter_tb.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmedian_filter_tb___024root___ctor_var_reset(Vmedian_filter_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmedian_filter_tb___024root___ctor_var_reset\n"); );
    Vmedian_filter_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->median_filter_tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4612825299913595181ull);
    vlSelf->median_filter_tb__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16350760518490432016ull);
    vlSelf->median_filter_tb__DOT__start_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16772088356931127088ull);
    vlSelf->median_filter_tb__DOT__pixel_valid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12020238900474811544ull);
    vlSelf->median_filter_tb__DOT__pixel_i = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13080201022345899972ull);
    vlSelf->median_filter_tb__DOT__done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10133124671432688490ull);
    vlSelf->median_filter_tb__DOT__pixel_valid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11446888386678219298ull);
    vlSelf->median_filter_tb__DOT__pixel_o = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7712366132358024093ull);
    vlSelf->median_filter_tb__DOT__red_value = 0;
    vlSelf->median_filter_tb__DOT__green_value = 0;
    vlSelf->median_filter_tb__DOT__blue_value = 0;
    vlSelf->median_filter_tb__DOT__expected_red = 0;
    vlSelf->median_filter_tb__DOT__expected_green = 0;
    vlSelf->median_filter_tb__DOT__expected_blue = 0;
    vlSelf->median_filter_tb__DOT__dut__DOT__state_d = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1687414595429591838ull);
    vlSelf->median_filter_tb__DOT__dut__DOT__state_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3751164242288186726ull);
    vlSelf->median_filter_tb__DOT__dut__DOT__x_counter_d = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3733378058112811870ull);
    vlSelf->median_filter_tb__DOT__dut__DOT__y_counter_d = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10477976325040622985ull);
    vlSelf->median_filter_tb__DOT__dut__DOT__x_counter_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5925956738712292301ull);
    vlSelf->median_filter_tb__DOT__dut__DOT__y_counter_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12450810438184646891ull);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->median_filter_tb__DOT__dut__DOT__pixel_shift_reg_d[__Vi0] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8917030469475220544ull);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->median_filter_tb__DOT__dut__DOT__pixel_shift_reg_q[__Vi0] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8608057131131850864ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->median_filter_tb__DOT__dut__DOT__kernel[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13800798235338211284ull);
        }
    }
    vlSelf->median_filter_tb__DOT__dut__DOT__pixel_d = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5849608535461128539ull);
    vlSelf->median_filter_tb__DOT__dut__DOT__kernel_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17031107568889451464ull);
    vlSelf->median_filter_tb__DOT__dut__DOT__done_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4640669310753188832ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__median_filter_tb__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
