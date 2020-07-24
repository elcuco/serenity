/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <AK/Types.h>

namespace X86 {

class Instruction;

class Interpreter {
public:
    virtual void AAA(const Instruction&) = 0;
    virtual void AAD(const Instruction&) = 0;
    virtual void AAM(const Instruction&) = 0;
    virtual void AAS(const Instruction&) = 0;
    virtual void ADC_AL_imm8(const Instruction&) = 0;
    virtual void ADC_AX_imm16(const Instruction&) = 0;
    virtual void ADC_EAX_imm32(const Instruction&) = 0;
    virtual void ADC_RM16_imm16(const Instruction&) = 0;
    virtual void ADC_RM16_imm8(const Instruction&) = 0;
    virtual void ADC_RM16_reg16(const Instruction&) = 0;
    virtual void ADC_RM32_imm32(const Instruction&) = 0;
    virtual void ADC_RM32_imm8(const Instruction&) = 0;
    virtual void ADC_RM32_reg32(const Instruction&) = 0;
    virtual void ADC_RM8_imm8(const Instruction&) = 0;
    virtual void ADC_RM8_reg8(const Instruction&) = 0;
    virtual void ADC_reg16_RM16(const Instruction&) = 0;
    virtual void ADC_reg32_RM32(const Instruction&) = 0;
    virtual void ADC_reg8_RM8(const Instruction&) = 0;
    virtual void ADD_AL_imm8(const Instruction&) = 0;
    virtual void ADD_AX_imm16(const Instruction&) = 0;
    virtual void ADD_EAX_imm32(const Instruction&) = 0;
    virtual void ADD_RM16_imm16(const Instruction&) = 0;
    virtual void ADD_RM16_imm8(const Instruction&) = 0;
    virtual void ADD_RM16_reg16(const Instruction&) = 0;
    virtual void ADD_RM32_imm32(const Instruction&) = 0;
    virtual void ADD_RM32_imm8(const Instruction&) = 0;
    virtual void ADD_RM32_reg32(const Instruction&) = 0;
    virtual void ADD_RM8_imm8(const Instruction&) = 0;
    virtual void ADD_RM8_reg8(const Instruction&) = 0;
    virtual void ADD_reg16_RM16(const Instruction&) = 0;
    virtual void ADD_reg32_RM32(const Instruction&) = 0;
    virtual void ADD_reg8_RM8(const Instruction&) = 0;
    virtual void AND_AL_imm8(const Instruction&) = 0;
    virtual void AND_AX_imm16(const Instruction&) = 0;
    virtual void AND_EAX_imm32(const Instruction&) = 0;
    virtual void AND_RM16_imm16(const Instruction&) = 0;
    virtual void AND_RM16_imm8(const Instruction&) = 0;
    virtual void AND_RM16_reg16(const Instruction&) = 0;
    virtual void AND_RM32_imm32(const Instruction&) = 0;
    virtual void AND_RM32_imm8(const Instruction&) = 0;
    virtual void AND_RM32_reg32(const Instruction&) = 0;
    virtual void AND_RM8_imm8(const Instruction&) = 0;
    virtual void AND_RM8_reg8(const Instruction&) = 0;
    virtual void AND_reg16_RM16(const Instruction&) = 0;
    virtual void AND_reg32_RM32(const Instruction&) = 0;
    virtual void AND_reg8_RM8(const Instruction&) = 0;
    virtual void ARPL(const Instruction&) = 0;
    virtual void BOUND(const Instruction&) = 0;
    virtual void BSF_reg16_RM16(const Instruction&) = 0;
    virtual void BSF_reg32_RM32(const Instruction&) = 0;
    virtual void BSR_reg16_RM16(const Instruction&) = 0;
    virtual void BSR_reg32_RM32(const Instruction&) = 0;
    virtual void BSWAP_reg32(const Instruction&) = 0;
    virtual void BTC_RM16_imm8(const Instruction&) = 0;
    virtual void BTC_RM16_reg16(const Instruction&) = 0;
    virtual void BTC_RM32_imm8(const Instruction&) = 0;
    virtual void BTC_RM32_reg32(const Instruction&) = 0;
    virtual void BTR_RM16_imm8(const Instruction&) = 0;
    virtual void BTR_RM16_reg16(const Instruction&) = 0;
    virtual void BTR_RM32_imm8(const Instruction&) = 0;
    virtual void BTR_RM32_reg32(const Instruction&) = 0;
    virtual void BTS_RM16_imm8(const Instruction&) = 0;
    virtual void BTS_RM16_reg16(const Instruction&) = 0;
    virtual void BTS_RM32_imm8(const Instruction&) = 0;
    virtual void BTS_RM32_reg32(const Instruction&) = 0;
    virtual void BT_RM16_imm8(const Instruction&) = 0;
    virtual void BT_RM16_reg16(const Instruction&) = 0;
    virtual void BT_RM32_imm8(const Instruction&) = 0;
    virtual void BT_RM32_reg32(const Instruction&) = 0;
    virtual void CALL_FAR_mem16(const Instruction&) = 0;
    virtual void CALL_FAR_mem32(const Instruction&) = 0;
    virtual void CALL_RM16(const Instruction&) = 0;
    virtual void CALL_RM32(const Instruction&) = 0;
    virtual void CALL_imm16(const Instruction&) = 0;
    virtual void CALL_imm16_imm16(const Instruction&) = 0;
    virtual void CALL_imm16_imm32(const Instruction&) = 0;
    virtual void CALL_imm32(const Instruction&) = 0;
    virtual void CBW(const Instruction&) = 0;
    virtual void CDQ(const Instruction&) = 0;
    virtual void CLC(const Instruction&) = 0;
    virtual void CLD(const Instruction&) = 0;
    virtual void CLI(const Instruction&) = 0;
    virtual void CLTS(const Instruction&) = 0;
    virtual void CMC(const Instruction&) = 0;
    virtual void CMOVcc_reg16_RM16(const Instruction&) = 0;
    virtual void CMOVcc_reg32_RM32(const Instruction&) = 0;
    virtual void CMPSB(const Instruction&) = 0;
    virtual void CMPSD(const Instruction&) = 0;
    virtual void CMPSW(const Instruction&) = 0;
    virtual void CMPXCHG_RM16_reg16(const Instruction&) = 0;
    virtual void CMPXCHG_RM32_reg32(const Instruction&) = 0;
    virtual void CMPXCHG_RM8_reg8(const Instruction&) = 0;
    virtual void CMP_AL_imm8(const Instruction&) = 0;
    virtual void CMP_AX_imm16(const Instruction&) = 0;
    virtual void CMP_EAX_imm32(const Instruction&) = 0;
    virtual void CMP_RM16_imm16(const Instruction&) = 0;
    virtual void CMP_RM16_imm8(const Instruction&) = 0;
    virtual void CMP_RM16_reg16(const Instruction&) = 0;
    virtual void CMP_RM32_imm32(const Instruction&) = 0;
    virtual void CMP_RM32_imm8(const Instruction&) = 0;
    virtual void CMP_RM32_reg32(const Instruction&) = 0;
    virtual void CMP_RM8_imm8(const Instruction&) = 0;
    virtual void CMP_RM8_reg8(const Instruction&) = 0;
    virtual void CMP_reg16_RM16(const Instruction&) = 0;
    virtual void CMP_reg32_RM32(const Instruction&) = 0;
    virtual void CMP_reg8_RM8(const Instruction&) = 0;
    virtual void CPUID(const Instruction&) = 0;
    virtual void CWD(const Instruction&) = 0;
    virtual void CWDE(const Instruction&) = 0;
    virtual void DAA(const Instruction&) = 0;
    virtual void DAS(const Instruction&) = 0;
    virtual void DEC_RM16(const Instruction&) = 0;
    virtual void DEC_RM32(const Instruction&) = 0;
    virtual void DEC_RM8(const Instruction&) = 0;
    virtual void DEC_reg16(const Instruction&) = 0;
    virtual void DEC_reg32(const Instruction&) = 0;
    virtual void DIV_RM16(const Instruction&) = 0;
    virtual void DIV_RM32(const Instruction&) = 0;
    virtual void DIV_RM8(const Instruction&) = 0;
    virtual void ENTER16(const Instruction&) = 0;
    virtual void ENTER32(const Instruction&) = 0;
    virtual void ESCAPE(const Instruction&) = 0;
    virtual void HLT(const Instruction&) = 0;
    virtual void IDIV_RM16(const Instruction&) = 0;
    virtual void IDIV_RM32(const Instruction&) = 0;
    virtual void IDIV_RM8(const Instruction&) = 0;
    virtual void IMUL_RM16(const Instruction&) = 0;
    virtual void IMUL_RM32(const Instruction&) = 0;
    virtual void IMUL_RM8(const Instruction&) = 0;
    virtual void IMUL_reg16_RM16(const Instruction&) = 0;
    virtual void IMUL_reg16_RM16_imm16(const Instruction&) = 0;
    virtual void IMUL_reg16_RM16_imm8(const Instruction&) = 0;
    virtual void IMUL_reg32_RM32(const Instruction&) = 0;
    virtual void IMUL_reg32_RM32_imm32(const Instruction&) = 0;
    virtual void IMUL_reg32_RM32_imm8(const Instruction&) = 0;
    virtual void INC_RM16(const Instruction&) = 0;
    virtual void INC_RM32(const Instruction&) = 0;
    virtual void INC_RM8(const Instruction&) = 0;
    virtual void INC_reg16(const Instruction&) = 0;
    virtual void INC_reg32(const Instruction&) = 0;
    virtual void INSB(const Instruction&) = 0;
    virtual void INSD(const Instruction&) = 0;
    virtual void INSW(const Instruction&) = 0;
    virtual void INT3(const Instruction&) = 0;
    virtual void INTO(const Instruction&) = 0;
    virtual void INT_imm8(const Instruction&) = 0;
    virtual void INVLPG(const Instruction&) = 0;
    virtual void IN_AL_DX(const Instruction&) = 0;
    virtual void IN_AL_imm8(const Instruction&) = 0;
    virtual void IN_AX_DX(const Instruction&) = 0;
    virtual void IN_AX_imm8(const Instruction&) = 0;
    virtual void IN_EAX_DX(const Instruction&) = 0;
    virtual void IN_EAX_imm8(const Instruction&) = 0;
    virtual void IRET(const Instruction&) = 0;
    virtual void JCXZ_imm8(const Instruction&) = 0;
    virtual void JMP_FAR_mem16(const Instruction&) = 0;
    virtual void JMP_FAR_mem32(const Instruction&) = 0;
    virtual void JMP_RM16(const Instruction&) = 0;
    virtual void JMP_RM32(const Instruction&) = 0;
    virtual void JMP_imm16(const Instruction&) = 0;
    virtual void JMP_imm16_imm16(const Instruction&) = 0;
    virtual void JMP_imm16_imm32(const Instruction&) = 0;
    virtual void JMP_imm32(const Instruction&) = 0;
    virtual void JMP_short_imm8(const Instruction&) = 0;
    virtual void Jcc_NEAR_imm(const Instruction&) = 0;
    virtual void Jcc_imm8(const Instruction&) = 0;
    virtual void LAHF(const Instruction&) = 0;
    virtual void LAR_reg16_RM16(const Instruction&) = 0;
    virtual void LAR_reg32_RM32(const Instruction&) = 0;
    virtual void LDS_reg16_mem16(const Instruction&) = 0;
    virtual void LDS_reg32_mem32(const Instruction&) = 0;
    virtual void LEAVE16(const Instruction&) = 0;
    virtual void LEAVE32(const Instruction&) = 0;
    virtual void LEA_reg16_mem16(const Instruction&) = 0;
    virtual void LEA_reg32_mem32(const Instruction&) = 0;
    virtual void LES_reg16_mem16(const Instruction&) = 0;
    virtual void LES_reg32_mem32(const Instruction&) = 0;
    virtual void LFS_reg16_mem16(const Instruction&) = 0;
    virtual void LFS_reg32_mem32(const Instruction&) = 0;
    virtual void LGDT(const Instruction&) = 0;
    virtual void LGS_reg16_mem16(const Instruction&) = 0;
    virtual void LGS_reg32_mem32(const Instruction&) = 0;
    virtual void LIDT(const Instruction&) = 0;
    virtual void LLDT_RM16(const Instruction&) = 0;
    virtual void LMSW_RM16(const Instruction&) = 0;
    virtual void LODSB(const Instruction&) = 0;
    virtual void LODSD(const Instruction&) = 0;
    virtual void LODSW(const Instruction&) = 0;
    virtual void LOOPNZ_imm8(const Instruction&) = 0;
    virtual void LOOPZ_imm8(const Instruction&) = 0;
    virtual void LOOP_imm8(const Instruction&) = 0;
    virtual void LSL_reg16_RM16(const Instruction&) = 0;
    virtual void LSL_reg32_RM32(const Instruction&) = 0;
    virtual void LSS_reg16_mem16(const Instruction&) = 0;
    virtual void LSS_reg32_mem32(const Instruction&) = 0;
    virtual void LTR_RM16(const Instruction&) = 0;
    virtual void MOVSB(const Instruction&) = 0;
    virtual void MOVSD(const Instruction&) = 0;
    virtual void MOVSW(const Instruction&) = 0;
    virtual void MOVSX_reg16_RM8(const Instruction&) = 0;
    virtual void MOVSX_reg32_RM16(const Instruction&) = 0;
    virtual void MOVSX_reg32_RM8(const Instruction&) = 0;
    virtual void MOVZX_reg16_RM8(const Instruction&) = 0;
    virtual void MOVZX_reg32_RM16(const Instruction&) = 0;
    virtual void MOVZX_reg32_RM8(const Instruction&) = 0;
    virtual void MOV_AL_moff8(const Instruction&) = 0;
    virtual void MOV_AX_moff16(const Instruction&) = 0;
    virtual void MOV_CR_reg32(const Instruction&) = 0;
    virtual void MOV_DR_reg32(const Instruction&) = 0;
    virtual void MOV_EAX_moff32(const Instruction&) = 0;
    virtual void MOV_RM16_imm16(const Instruction&) = 0;
    virtual void MOV_RM16_reg16(const Instruction&) = 0;
    virtual void MOV_RM16_seg(const Instruction&) = 0;
    virtual void MOV_RM32_imm32(const Instruction&) = 0;
    virtual void MOV_RM32_reg32(const Instruction&) = 0;
    virtual void MOV_RM8_imm8(const Instruction&) = 0;
    virtual void MOV_RM8_reg8(const Instruction&) = 0;
    virtual void MOV_moff16_AX(const Instruction&) = 0;
    virtual void MOV_moff32_EAX(const Instruction&) = 0;
    virtual void MOV_moff8_AL(const Instruction&) = 0;
    virtual void MOV_reg16_RM16(const Instruction&) = 0;
    virtual void MOV_reg16_imm16(const Instruction&) = 0;
    virtual void MOV_reg32_CR(const Instruction&) = 0;
    virtual void MOV_reg32_DR(const Instruction&) = 0;
    virtual void MOV_reg32_RM32(const Instruction&) = 0;
    virtual void MOV_reg32_imm32(const Instruction&) = 0;
    virtual void MOV_reg8_RM8(const Instruction&) = 0;
    virtual void MOV_reg8_imm8(const Instruction&) = 0;
    virtual void MOV_seg_RM16(const Instruction&) = 0;
    virtual void MOV_seg_RM32(const Instruction&) = 0;
    virtual void MUL_RM16(const Instruction&) = 0;
    virtual void MUL_RM32(const Instruction&) = 0;
    virtual void MUL_RM8(const Instruction&) = 0;
    virtual void NEG_RM16(const Instruction&) = 0;
    virtual void NEG_RM32(const Instruction&) = 0;
    virtual void NEG_RM8(const Instruction&) = 0;
    virtual void NOP(const Instruction&) = 0;
    virtual void NOT_RM16(const Instruction&) = 0;
    virtual void NOT_RM32(const Instruction&) = 0;
    virtual void NOT_RM8(const Instruction&) = 0;
    virtual void OR_AL_imm8(const Instruction&) = 0;
    virtual void OR_AX_imm16(const Instruction&) = 0;
    virtual void OR_EAX_imm32(const Instruction&) = 0;
    virtual void OR_RM16_imm16(const Instruction&) = 0;
    virtual void OR_RM16_imm8(const Instruction&) = 0;
    virtual void OR_RM16_reg16(const Instruction&) = 0;
    virtual void OR_RM32_imm32(const Instruction&) = 0;
    virtual void OR_RM32_imm8(const Instruction&) = 0;
    virtual void OR_RM32_reg32(const Instruction&) = 0;
    virtual void OR_RM8_imm8(const Instruction&) = 0;
    virtual void OR_RM8_reg8(const Instruction&) = 0;
    virtual void OR_reg16_RM16(const Instruction&) = 0;
    virtual void OR_reg32_RM32(const Instruction&) = 0;
    virtual void OR_reg8_RM8(const Instruction&) = 0;
    virtual void OUTSB(const Instruction&) = 0;
    virtual void OUTSD(const Instruction&) = 0;
    virtual void OUTSW(const Instruction&) = 0;
    virtual void OUT_DX_AL(const Instruction&) = 0;
    virtual void OUT_DX_AX(const Instruction&) = 0;
    virtual void OUT_DX_EAX(const Instruction&) = 0;
    virtual void OUT_imm8_AL(const Instruction&) = 0;
    virtual void OUT_imm8_AX(const Instruction&) = 0;
    virtual void OUT_imm8_EAX(const Instruction&) = 0;
    virtual void PADDB_mm1_mm2m64(const Instruction&) = 0;
    virtual void PADDW_mm1_mm2m64(const Instruction&) = 0;
    virtual void PADDD_mm1_mm2m64(const Instruction&) = 0;
    virtual void POPA(const Instruction&) = 0;
    virtual void POPAD(const Instruction&) = 0;
    virtual void POPF(const Instruction&) = 0;
    virtual void POPFD(const Instruction&) = 0;
    virtual void POP_DS(const Instruction&) = 0;
    virtual void POP_ES(const Instruction&) = 0;
    virtual void POP_FS(const Instruction&) = 0;
    virtual void POP_GS(const Instruction&) = 0;
    virtual void POP_RM16(const Instruction&) = 0;
    virtual void POP_RM32(const Instruction&) = 0;
    virtual void POP_SS(const Instruction&) = 0;
    virtual void POP_reg16(const Instruction&) = 0;
    virtual void POP_reg32(const Instruction&) = 0;
    virtual void PUSHA(const Instruction&) = 0;
    virtual void PUSHAD(const Instruction&) = 0;
    virtual void PUSHF(const Instruction&) = 0;
    virtual void PUSHFD(const Instruction&) = 0;
    virtual void PUSH_CS(const Instruction&) = 0;
    virtual void PUSH_DS(const Instruction&) = 0;
    virtual void PUSH_ES(const Instruction&) = 0;
    virtual void PUSH_FS(const Instruction&) = 0;
    virtual void PUSH_GS(const Instruction&) = 0;
    virtual void PUSH_RM16(const Instruction&) = 0;
    virtual void PUSH_RM32(const Instruction&) = 0;
    virtual void PUSH_SP_8086_80186(const Instruction&) = 0;
    virtual void PUSH_SS(const Instruction&) = 0;
    virtual void PUSH_imm16(const Instruction&) = 0;
    virtual void PUSH_imm32(const Instruction&) = 0;
    virtual void PUSH_imm8(const Instruction&) = 0;
    virtual void PUSH_reg16(const Instruction&) = 0;
    virtual void PUSH_reg32(const Instruction&) = 0;
    virtual void RCL_RM16_1(const Instruction&) = 0;
    virtual void RCL_RM16_CL(const Instruction&) = 0;
    virtual void RCL_RM16_imm8(const Instruction&) = 0;
    virtual void RCL_RM32_1(const Instruction&) = 0;
    virtual void RCL_RM32_CL(const Instruction&) = 0;
    virtual void RCL_RM32_imm8(const Instruction&) = 0;
    virtual void RCL_RM8_1(const Instruction&) = 0;
    virtual void RCL_RM8_CL(const Instruction&) = 0;
    virtual void RCL_RM8_imm8(const Instruction&) = 0;
    virtual void RCR_RM16_1(const Instruction&) = 0;
    virtual void RCR_RM16_CL(const Instruction&) = 0;
    virtual void RCR_RM16_imm8(const Instruction&) = 0;
    virtual void RCR_RM32_1(const Instruction&) = 0;
    virtual void RCR_RM32_CL(const Instruction&) = 0;
    virtual void RCR_RM32_imm8(const Instruction&) = 0;
    virtual void RCR_RM8_1(const Instruction&) = 0;
    virtual void RCR_RM8_CL(const Instruction&) = 0;
    virtual void RCR_RM8_imm8(const Instruction&) = 0;
    virtual void RDTSC(const Instruction&) = 0;
    virtual void RET(const Instruction&) = 0;
    virtual void RETF(const Instruction&) = 0;
    virtual void RETF_imm16(const Instruction&) = 0;
    virtual void RET_imm16(const Instruction&) = 0;
    virtual void ROL_RM16_1(const Instruction&) = 0;
    virtual void ROL_RM16_CL(const Instruction&) = 0;
    virtual void ROL_RM16_imm8(const Instruction&) = 0;
    virtual void ROL_RM32_1(const Instruction&) = 0;
    virtual void ROL_RM32_CL(const Instruction&) = 0;
    virtual void ROL_RM32_imm8(const Instruction&) = 0;
    virtual void ROL_RM8_1(const Instruction&) = 0;
    virtual void ROL_RM8_CL(const Instruction&) = 0;
    virtual void ROL_RM8_imm8(const Instruction&) = 0;
    virtual void ROR_RM16_1(const Instruction&) = 0;
    virtual void ROR_RM16_CL(const Instruction&) = 0;
    virtual void ROR_RM16_imm8(const Instruction&) = 0;
    virtual void ROR_RM32_1(const Instruction&) = 0;
    virtual void ROR_RM32_CL(const Instruction&) = 0;
    virtual void ROR_RM32_imm8(const Instruction&) = 0;
    virtual void ROR_RM8_1(const Instruction&) = 0;
    virtual void ROR_RM8_CL(const Instruction&) = 0;
    virtual void ROR_RM8_imm8(const Instruction&) = 0;
    virtual void SAHF(const Instruction&) = 0;
    virtual void SALC(const Instruction&) = 0;
    virtual void SAR_RM16_1(const Instruction&) = 0;
    virtual void SAR_RM16_CL(const Instruction&) = 0;
    virtual void SAR_RM16_imm8(const Instruction&) = 0;
    virtual void SAR_RM32_1(const Instruction&) = 0;
    virtual void SAR_RM32_CL(const Instruction&) = 0;
    virtual void SAR_RM32_imm8(const Instruction&) = 0;
    virtual void SAR_RM8_1(const Instruction&) = 0;
    virtual void SAR_RM8_CL(const Instruction&) = 0;
    virtual void SAR_RM8_imm8(const Instruction&) = 0;
    virtual void SBB_AL_imm8(const Instruction&) = 0;
    virtual void SBB_AX_imm16(const Instruction&) = 0;
    virtual void SBB_EAX_imm32(const Instruction&) = 0;
    virtual void SBB_RM16_imm16(const Instruction&) = 0;
    virtual void SBB_RM16_imm8(const Instruction&) = 0;
    virtual void SBB_RM16_reg16(const Instruction&) = 0;
    virtual void SBB_RM32_imm32(const Instruction&) = 0;
    virtual void SBB_RM32_imm8(const Instruction&) = 0;
    virtual void SBB_RM32_reg32(const Instruction&) = 0;
    virtual void SBB_RM8_imm8(const Instruction&) = 0;
    virtual void SBB_RM8_reg8(const Instruction&) = 0;
    virtual void SBB_reg16_RM16(const Instruction&) = 0;
    virtual void SBB_reg32_RM32(const Instruction&) = 0;
    virtual void SBB_reg8_RM8(const Instruction&) = 0;
    virtual void SCASB(const Instruction&) = 0;
    virtual void SCASD(const Instruction&) = 0;
    virtual void SCASW(const Instruction&) = 0;
    virtual void SETcc_RM8(const Instruction&) = 0;
    virtual void SGDT(const Instruction&) = 0;
    virtual void SHLD_RM16_reg16_CL(const Instruction&) = 0;
    virtual void SHLD_RM16_reg16_imm8(const Instruction&) = 0;
    virtual void SHLD_RM32_reg32_CL(const Instruction&) = 0;
    virtual void SHLD_RM32_reg32_imm8(const Instruction&) = 0;
    virtual void SHL_RM16_1(const Instruction&) = 0;
    virtual void SHL_RM16_CL(const Instruction&) = 0;
    virtual void SHL_RM16_imm8(const Instruction&) = 0;
    virtual void SHL_RM32_1(const Instruction&) = 0;
    virtual void SHL_RM32_CL(const Instruction&) = 0;
    virtual void SHL_RM32_imm8(const Instruction&) = 0;
    virtual void SHL_RM8_1(const Instruction&) = 0;
    virtual void SHL_RM8_CL(const Instruction&) = 0;
    virtual void SHL_RM8_imm8(const Instruction&) = 0;
    virtual void SHRD_RM16_reg16_CL(const Instruction&) = 0;
    virtual void SHRD_RM16_reg16_imm8(const Instruction&) = 0;
    virtual void SHRD_RM32_reg32_CL(const Instruction&) = 0;
    virtual void SHRD_RM32_reg32_imm8(const Instruction&) = 0;
    virtual void SHR_RM16_1(const Instruction&) = 0;
    virtual void SHR_RM16_CL(const Instruction&) = 0;
    virtual void SHR_RM16_imm8(const Instruction&) = 0;
    virtual void SHR_RM32_1(const Instruction&) = 0;
    virtual void SHR_RM32_CL(const Instruction&) = 0;
    virtual void SHR_RM32_imm8(const Instruction&) = 0;
    virtual void SHR_RM8_1(const Instruction&) = 0;
    virtual void SHR_RM8_CL(const Instruction&) = 0;
    virtual void SHR_RM8_imm8(const Instruction&) = 0;
    virtual void SIDT(const Instruction&) = 0;
    virtual void SLDT_RM16(const Instruction&) = 0;
    virtual void SMSW_RM16(const Instruction&) = 0;
    virtual void STC(const Instruction&) = 0;
    virtual void STD(const Instruction&) = 0;
    virtual void STI(const Instruction&) = 0;
    virtual void STOSB(const Instruction&) = 0;
    virtual void STOSD(const Instruction&) = 0;
    virtual void STOSW(const Instruction&) = 0;
    virtual void STR_RM16(const Instruction&) = 0;
    virtual void SUB_AL_imm8(const Instruction&) = 0;
    virtual void SUB_AX_imm16(const Instruction&) = 0;
    virtual void SUB_EAX_imm32(const Instruction&) = 0;
    virtual void SUB_RM16_imm16(const Instruction&) = 0;
    virtual void SUB_RM16_imm8(const Instruction&) = 0;
    virtual void SUB_RM16_reg16(const Instruction&) = 0;
    virtual void SUB_RM32_imm32(const Instruction&) = 0;
    virtual void SUB_RM32_imm8(const Instruction&) = 0;
    virtual void SUB_RM32_reg32(const Instruction&) = 0;
    virtual void SUB_RM8_imm8(const Instruction&) = 0;
    virtual void SUB_RM8_reg8(const Instruction&) = 0;
    virtual void SUB_reg16_RM16(const Instruction&) = 0;
    virtual void SUB_reg32_RM32(const Instruction&) = 0;
    virtual void SUB_reg8_RM8(const Instruction&) = 0;
    virtual void TEST_AL_imm8(const Instruction&) = 0;
    virtual void TEST_AX_imm16(const Instruction&) = 0;
    virtual void TEST_EAX_imm32(const Instruction&) = 0;
    virtual void TEST_RM16_imm16(const Instruction&) = 0;
    virtual void TEST_RM16_reg16(const Instruction&) = 0;
    virtual void TEST_RM32_imm32(const Instruction&) = 0;
    virtual void TEST_RM32_reg32(const Instruction&) = 0;
    virtual void TEST_RM8_imm8(const Instruction&) = 0;
    virtual void TEST_RM8_reg8(const Instruction&) = 0;
    virtual void UD0(const Instruction&) = 0;
    virtual void UD1(const Instruction&) = 0;
    virtual void UD2(const Instruction&) = 0;
    virtual void VERR_RM16(const Instruction&) = 0;
    virtual void VERW_RM16(const Instruction&) = 0;
    virtual void WAIT(const Instruction&) = 0;
    virtual void WBINVD(const Instruction&) = 0;
    virtual void XADD_RM16_reg16(const Instruction&) = 0;
    virtual void XADD_RM32_reg32(const Instruction&) = 0;
    virtual void XADD_RM8_reg8(const Instruction&) = 0;
    virtual void XCHG_AX_reg16(const Instruction&) = 0;
    virtual void XCHG_EAX_reg32(const Instruction&) = 0;
    virtual void XCHG_reg16_RM16(const Instruction&) = 0;
    virtual void XCHG_reg32_RM32(const Instruction&) = 0;
    virtual void XCHG_reg8_RM8(const Instruction&) = 0;
    virtual void XLAT(const Instruction&) = 0;
    virtual void XOR_AL_imm8(const Instruction&) = 0;
    virtual void XOR_AX_imm16(const Instruction&) = 0;
    virtual void XOR_EAX_imm32(const Instruction&) = 0;
    virtual void XOR_RM16_imm16(const Instruction&) = 0;
    virtual void XOR_RM16_imm8(const Instruction&) = 0;
    virtual void XOR_RM16_reg16(const Instruction&) = 0;
    virtual void XOR_RM32_imm32(const Instruction&) = 0;
    virtual void XOR_RM32_imm8(const Instruction&) = 0;
    virtual void XOR_RM32_reg32(const Instruction&) = 0;
    virtual void XOR_RM8_imm8(const Instruction&) = 0;
    virtual void XOR_RM8_reg8(const Instruction&) = 0;
    virtual void XOR_reg16_RM16(const Instruction&) = 0;
    virtual void XOR_reg32_RM32(const Instruction&) = 0;
    virtual void XOR_reg8_RM8(const Instruction&) = 0;
    virtual void MOVQ_mm1_mm2m64(const Instruction&) = 0;
    virtual void EMMS(const Instruction&) = 0;
    virtual void MOVQ_mm1_m64_mm2(const Instruction&) = 0;
    virtual void wrap_0xC0(const Instruction&) = 0;
    virtual void wrap_0xC1_16(const Instruction&) = 0;
    virtual void wrap_0xC1_32(const Instruction&) = 0;
    virtual void wrap_0xD0(const Instruction&) = 0;
    virtual void wrap_0xD1_16(const Instruction&) = 0;
    virtual void wrap_0xD1_32(const Instruction&) = 0;
    virtual void wrap_0xD2(const Instruction&) = 0;
    virtual void wrap_0xD3_16(const Instruction&) = 0;
    virtual void wrap_0xD3_32(const Instruction&) = 0;
};

typedef void (Interpreter::*InstructionHandler)(const Instruction&);

}
