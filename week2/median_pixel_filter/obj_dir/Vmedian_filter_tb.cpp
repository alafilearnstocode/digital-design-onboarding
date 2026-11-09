// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmedian_filter_tb__pch.h"

//============================================================
// Constructors

Vmedian_filter_tb::Vmedian_filter_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmedian_filter_tb__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmedian_filter_tb::Vmedian_filter_tb(const char* _vcname__)
    : Vmedian_filter_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmedian_filter_tb::~Vmedian_filter_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmedian_filter_tb___024root___eval_debug_assertions(Vmedian_filter_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vmedian_filter_tb___024root___eval_static(Vmedian_filter_tb___024root* vlSelf);
void Vmedian_filter_tb___024root___eval_initial(Vmedian_filter_tb___024root* vlSelf);
void Vmedian_filter_tb___024root___eval_settle(Vmedian_filter_tb___024root* vlSelf);
void Vmedian_filter_tb___024root___eval(Vmedian_filter_tb___024root* vlSelf);

void Vmedian_filter_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmedian_filter_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmedian_filter_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmedian_filter_tb___024root___eval_static(&(vlSymsp->TOP));
        Vmedian_filter_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vmedian_filter_tb___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmedian_filter_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmedian_filter_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vmedian_filter_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vmedian_filter_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmedian_filter_tb___024root___eval_final(Vmedian_filter_tb___024root* vlSelf);

VL_ATTR_COLD void Vmedian_filter_tb::final() {
    contextp()->executingFinal(true);
    Vmedian_filter_tb___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmedian_filter_tb::hierName() const { return vlSymsp->name(); }
const char* Vmedian_filter_tb::modelName() const { return "Vmedian_filter_tb"; }
unsigned Vmedian_filter_tb::threads() const { return 1; }
void Vmedian_filter_tb::prepareClone() const { contextp()->prepareClone(); }
void Vmedian_filter_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
