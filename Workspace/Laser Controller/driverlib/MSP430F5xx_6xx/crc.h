/* --COPYRIGHT--,BSD
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
#ifndef __MSP430WARE_CRC_H__
#define __MSP430WARE_CRC_H__

//*****************************************************************************
//
//The following are the defines to include the required modules for this
//peripheral in msp430xgeneric.h file
//
//*****************************************************************************
#define __MSP430_HAS_CRC__

#include "inc/hw_regaccess.h"

//*****************************************************************************
//
//Prototypes for the APIs.
//
//*****************************************************************************

extern void CRC_setSeed (uint32_t baseAddress,
    uint16_t seed);

extern void CRC_set16BitData (uint32_t baseAddress,
    uint16_t signature);
	
extern void CRC_set8BitData (uint32_t baseAddress,
    uint8_t dataIn);

extern void CRC_setSignatureByteReversed (uint32_t baseAddress,
    uint16_t signature);

extern uint16_t CRC_getSignature (uint32_t baseAddress);

extern uint16_t CRC_getResult (uint32_t baseAddress);

extern uint16_t CRC_getResultBitsReversed (uint32_t baseAddress);

extern void CRC_setDataByteBitsReversed (uint32_t baseAddress,
    uint16_t dataIn);

extern uint16_t CRC_getData (uint32_t baseAddress);

#define CRC_setData  CRC_set16BitData

#endif
