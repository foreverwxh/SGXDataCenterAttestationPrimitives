/*
 * Copyright (C) 2011-2019 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#pragma once
#define LE_SS_LEN 1808
const int sgx_le_ss_length = LE_SS_LEN;

const unsigned char sgx_le_ss[LE_SS_LEN] =
{
    0x06,0x00,0x00,0x00,0xe1,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
    0x86,0x80,0x00,0x00,0x15,0x06,0x18,0x20,0x01,0x01,0x00,0x00,0x60,0x00,0x00,0x00,
    0x60,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x31,0xec,0xdd,0x4f,0x85,0x40,0xf9,0xa0,0x7d,0x90,0x69,0x29,0x82,0x90,0x6b,0xab,
    0xe5,0x51,0x86,0x9f,0x27,0x58,0x7b,0x3e,0xc2,0x68,0x95,0x20,0x94,0xe3,0x02,0xd1,
    0x28,0xda,0x31,0x85,0xe1,0x75,0xea,0x52,0x07,0x50,0x1a,0xcf,0x88,0x68,0xbe,0xa5,
    0x1c,0x41,0xc1,0x1a,0x3c,0x8e,0x5b,0xcf,0xd1,0x07,0xf4,0x4e,0x20,0xb6,0xd7,0xa2,
    0x36,0x60,0x49,0x12,0x73,0x68,0x8b,0xf0,0x91,0x7e,0xf1,0x20,0xbf,0xea,0x56,0xda,
    0x61,0x0b,0xf3,0x04,0x87,0xec,0xb9,0x40,0x68,0xec,0x7a,0x88,0x03,0x51,0xdf,0xd3,
    0x94,0x6f,0x66,0x73,0x9c,0x40,0xe4,0xf0,0xe2,0x8d,0x24,0x71,0xf5,0x8c,0x17,0xe6,
    0x4f,0xf3,0xbf,0xb1,0x0c,0x6b,0x8c,0xae,0x0c,0xd9,0x67,0x71,0x4b,0xd0,0xc0,0x0d,
    0xdf,0xc1,0x0b,0x03,0xe4,0x27,0xf1,0xad,0xd7,0xa0,0xed,0xbc,0x4e,0xf5,0xac,0x06,
    0xeb,0x8a,0x99,0x86,0x6b,0x16,0x4a,0xd0,0x1d,0xaa,0x90,0x27,0x96,0x2d,0x19,0x23,
    0xf8,0xfd,0x2e,0xbb,0xe1,0xd4,0x0e,0x34,0xb3,0x16,0x53,0x8a,0xd9,0xa7,0xd3,0x7d,
    0x4c,0xda,0x81,0xc0,0x86,0xd4,0xd6,0x15,0xb6,0xdc,0x51,0x9c,0xb6,0xca,0xa4,0x3d,
    0x06,0xfc,0x68,0xfa,0x1d,0x16,0x00,0x02,0xf4,0x13,0xfb,0x88,0xe0,0x0a,0x49,0xfa,
    0xad,0x87,0xa5,0xb7,0x53,0xf1,0xfc,0x81,0x5c,0x52,0xca,0x9a,0x38,0x37,0xff,0x8e,
    0x92,0x20,0x66,0xf4,0xc7,0x06,0x97,0x0f,0x5d,0x87,0xfe,0x5a,0xc4,0xe7,0x02,0xe9,
    0xad,0x54,0x15,0x69,0x22,0xb4,0x21,0xed,0x56,0xf4,0xf7,0xf0,0x24,0xcd,0xa6,0xa6,
    0x0b,0x4b,0xc8,0x80,0xdb,0xed,0xa3,0x24,0xa3,0x79,0x04,0x41,0x4b,0x62,0x10,0xd4,
    0x61,0x51,0xe3,0x35,0xc9,0x23,0xdc,0x2a,0xbb,0x84,0x30,0xf8,0xe8,0x76,0x80,0x8b,
    0x19,0xc7,0x27,0x56,0x26,0x6a,0xec,0x5a,0x96,0x05,0x02,0x90,0xf0,0xa0,0x7e,0x66,
    0x18,0xe4,0xca,0xcf,0xe5,0x90,0x68,0x6a,0x5a,0x3b,0xa6,0x05,0xd8,0xc6,0x0a,0xc8,
    0x03,0xa7,0x72,0xe9,0x4f,0xa9,0xe6,0x7a,0xd9,0xe7,0x57,0x44,0xbb,0xa8,0x20,0x87,
    0x8f,0xc6,0xaf,0xff,0x2d,0x93,0x34,0x23,0x4c,0x4e,0x82,0x2e,0xfc,0x03,0x22,0xb1,
    0x9c,0x0c,0xab,0x9b,0x98,0xfb,0xc7,0x8d,0x74,0x0e,0x0e,0xc3,0x5c,0xf2,0x81,0x98,
    0x90,0x09,0x42,0xff,0xba,0x22,0xf0,0xd8,0x6f,0x2e,0xcd,0x4e,0x0f,0xdd,0x74,0x9f,
    0x03,0x00,0x00,0x00,0xcd,0x14,0x85,0xd0,0x80,0xd2,0x19,0xea,0x96,0xff,0xf7,0x13,
    0x79,0x7a,0xf5,0x87,0xa2,0x21,0x3d,0x37,0xdf,0xd9,0x2c,0xd0,0x8c,0xdc,0x41,0x5a,
    0x32,0x6e,0x4d,0xea,0x8f,0xa0,0x79,0x8a,0xdb,0x67,0x42,0x3a,0x0d,0xb1,0xb5,0x94,
    0x93,0x6f,0x74,0x3e,0xe1,0x93,0xe7,0xaa,0x39,0x23,0x9d,0x72,0xbd,0x1d,0x58,0x2d,
    0x1d,0x34,0xf3,0x9c,0x31,0x4a,0xd5,0xcf,0x16,0xa8,0x1a,0x68,0x18,0x37,0xb1,0xcb,
    0x52,0x8a,0xc4,0x2a,0xca,0x50,0xc8,0xa2,0x89,0x18,0xc9,0x4e,0xf4,0x3c,0xf8,0xd8,
    0x9f,0x70,0x8f,0x84,0x74,0xd0,0x92,0x8e,0xf7,0xe0,0xa5,0xd3,0x7f,0x0c,0xbf,0xd0,
    0x8a,0x0c,0x62,0xc2,0xf3,0x09,0xfe,0x51,0xfe,0xc5,0x42,0x71,0x59,0xb9,0x7a,0x42,
    0xcf,0x0b,0xec,0x68,0x2f,0x6f,0xb2,0xfa,0x0b,0x5a,0x70,0xd9,0xce,0x60,0x99,0xe8,
    0xf3,0xaf,0x97,0xb2,0x88,0x68,0xad,0xd8,0x85,0xde,0x96,0x68,0x9c,0xb9,0x3e,0xe7,
    0xfc,0x87,0x24,0xfe,0x96,0x8a,0x6f,0x74,0xd3,0x1b,0xee,0xa3,0x79,0x3b,0x1d,0xba,
    0xc6,0xde,0x0c,0x78,0xe8,0x6e,0x3c,0xe8,0x61,0x97,0x43,0x2c,0x45,0x3d,0x82,0x5f,
    0x7d,0xa9,0xfe,0x1f,0x2d,0x36,0x84,0xe0,0x8c,0x55,0x87,0x71,0x6a,0x48,0x79,0x15,
    0x69,0x09,0x6a,0x6a,0xaf,0xce,0x18,0x9c,0x49,0xd7,0xa5,0xa7,0x53,0x89,0xd3,0xa4,
    0x7a,0x0b,0x3b,0x84,0x7d,0x50,0x99,0xb7,0x7c,0x11,0xa1,0xa4,0x09,0x35,0xf0,0x61,
    0x58,0xce,0x82,0x09,0x5e,0x72,0xbe,0x05,0x0c,0x71,0xba,0x38,0x98,0x0e,0x92,0x78,
    0x94,0x8d,0x76,0x33,0xf8,0xd2,0xee,0xf4,0xba,0xa2,0x5b,0xa8,0x10,0x4c,0x05,0xa8,
    0x10,0xd7,0x6c,0x18,0xc3,0x84,0x86,0x7f,0xd9,0xe2,0x52,0x84,0xeb,0x7c,0x83,0x48,
    0x3e,0x3c,0x4d,0xc0,0x26,0x59,0xd2,0x4e,0x4b,0x95,0x9f,0x55,0xa2,0xfb,0x33,0x9a,
    0x99,0x68,0x2c,0x7c,0x88,0x7d,0x50,0xda,0x04,0x8b,0xca,0x59,0x63,0xd0,0xa2,0xa5,
    0x50,0x25,0x0c,0x3f,0x30,0xc5,0x6f,0xef,0x1f,0xe5,0xe5,0x0e,0x80,0xc4,0x7f,0x22,
    0x1a,0x56,0x15,0x0f,0x4d,0x57,0x81,0x67,0x61,0x99,0x00,0x02,0x3c,0x87,0x37,0x6f,
    0x21,0xaf,0x96,0x1a,0x61,0xdd,0xd5,0xdc,0x8c,0xb5,0x38,0x61,0x93,0x48,0x0b,0x41,
    0x86,0x66,0xe2,0x7e,0x48,0xa6,0xbc,0x87,0x69,0x2b,0x79,0xd3,0xd7,0x92,0x23,0xad,
    0xb9,0x7e,0x49,0x63,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    0x0c,0x40,0xc4,0x99,0xeb,0x93,0xc4,0x5f,0x20,0x46,0x3d,0x4b,0x09,0x8c,0xfa,0x2f,
    0x41,0x75,0xc9,0xdc,0x73,0x04,0x6d,0x0e,0x20,0x61,0xe7,0x5a,0xc2,0x11,0x28,0x4d,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xef,0xc8,0x3a,0xbc,0xf8,0x46,0x5c,0x50,0x93,0x13,0xc7,0xb0,0x58,0x03,0x95,0xe8,
    0x8a,0x14,0x63,0xef,0xb8,0xb0,0x1d,0x35,0xaa,0x4e,0xc5,0xe3,0xb4,0x84,0x2b,0xde,
    0x2e,0xec,0x6f,0x63,0x5a,0x89,0x46,0xba,0x31,0x82,0x39,0xcc,0x15,0x90,0x07,0xe7,
    0x20,0x19,0x46,0x86,0x5e,0xf9,0x68,0x6f,0x10,0x31,0x6e,0xc1,0x39,0x81,0xd8,0x47,
    0x53,0x2f,0x35,0xc1,0x03,0x72,0xfc,0x6a,0xa2,0x7c,0x3c,0x0f,0x3b,0x99,0x22,0x9d,
    0xc1,0xf3,0x66,0x2b,0x1d,0x5b,0x96,0x9e,0xf3,0x17,0xde,0x22,0x3e,0xe0,0xca,0xc0,
    0x38,0x02,0xa0,0x0b,0x96,0x1a,0x1e,0xf5,0x48,0xe0,0xe5,0xc0,0x0a,0x64,0xe7,0xcb,
    0x74,0x38,0x52,0x82,0xc2,0xe9,0xce,0x8f,0x70,0xcc,0x57,0xc6,0x4c,0xa8,0xf2,0xcd,
    0xb1,0xfe,0xe1,0x8d,0xa6,0xa1,0x8a,0x87,0xe0,0x0a,0x8a,0xf7,0xba,0xf4,0x17,0x49,
    0x6a,0x46,0x94,0x54,0xa1,0xf8,0x36,0x3b,0x27,0x73,0x14,0xde,0x6d,0xcb,0x0c,0x93,
    0xa9,0x82,0x26,0x38,0xa8,0xc2,0x35,0x39,0x75,0x35,0x85,0x38,0xaa,0x02,0xfd,0x5a,
    0x69,0xbd,0x8b,0xf2,0x5e,0x64,0xb2,0x7e,0x43,0xbf,0x17,0xbd,0x9f,0x12,0x6a,0x16,
    0xa0,0x32,0xb4,0x90,0xfa,0x3f,0x8e,0xa3,0x96,0xb6,0x66,0xc4,0x50,0x44,0xa3,0x64,
    0x7c,0x86,0xe8,0xdb,0x0c,0x04,0xc5,0x11,0x16,0xee,0xe0,0x8b,0xce,0x48,0x0e,0xff,
    0x12,0x87,0x0d,0xa4,0x53,0x8b,0x31,0x4b,0x29,0x9e,0x19,0x66,0x7e,0x7d,0x02,0xd0,
    0x24,0x5a,0xb0,0x14,0x1b,0x8d,0x73,0x06,0xe0,0xa9,0xf8,0xd4,0xa9,0x1b,0xa3,0xfa,
    0xaa,0x27,0x1d,0x69,0x31,0x83,0xc1,0xdf,0x2f,0x95,0x20,0x5a,0x96,0x1c,0xba,0x23,
    0x62,0x82,0x76,0x25,0xa6,0x7d,0x8b,0x5e,0x05,0xc3,0xbb,0x66,0x5c,0x96,0xa5,0x8e,
    0x97,0x87,0xb4,0x26,0xd0,0x2b,0xf7,0x20,0x5e,0x39,0x0c,0xcf,0xa2,0x3e,0x6f,0xf7,
    0x87,0x2e,0x7b,0x7d,0x64,0xb2,0xca,0x72,0xb3,0xfc,0xec,0x25,0xe5,0x03,0x6a,0xb0,
    0x88,0x97,0x40,0x89,0xe4,0x0a,0x37,0xc1,0xd2,0xcd,0xc2,0x66,0x3f,0xca,0x8d,0x8f,
    0x39,0x1e,0x00,0x4e,0x0f,0x1b,0x7e,0x29,0xfe,0x56,0x7d,0x31,0xa3,0x88,0x7f,0x33,
    0x38,0x24,0xb0,0x8d,0x11,0xa3,0x48,0xea,0xe9,0xa9,0x8b,0x21,0x1a,0x7d,0xfb,0x18,
    0x6e,0x6f,0xe5,0x01,0xd0,0x0c,0x1b,0xce,0xdc,0xea,0xca,0xf4,0x4d,0x71,0xd2,0x3d,
    0xb6,0x8c,0x49,0x1f,0xdd,0x1d,0xff,0xd4,0xf0,0xf2,0x98,0x76,0xbd,0x05,0x4f,0x8e,
    0x8e,0x27,0xb5,0xb7,0x1a,0x04,0x9a,0xdd,0x44,0x27,0xfc,0xf8,0xec,0x50,0xc5,0x10,
    0x1f,0x07,0xec,0x5e,0x75,0xb5,0x9a,0x61,0x59,0xa1,0xa7,0x51,0x09,0x82,0x80,0x33,
    0xc0,0x1d,0x7d,0xfd,0xd8,0x55,0x82,0xdb,0xb4,0x12,0x44,0xa3,0xca,0xb8,0xbd,0x19,
    0xd2,0x0b,0xea,0x91,0xbe,0x5b,0x40,0xec,0x4c,0x43,0x05,0xd5,0x03,0x99,0x97,0xd1,
    0x86,0x86,0xae,0x97,0x0b,0x59,0x5b,0x39,0xce,0x43,0x82,0x00,0x2e,0x66,0xf6,0x70,
    0x15,0x41,0x82,0xce,0xae,0x43,0x94,0x48,0x02,0x0b,0x57,0x46,0xf5,0x39,0x91,0xab,
    0x4f,0x69,0x7a,0x52,0x93,0x29,0xb6,0x71,0x76,0xe0,0x1a,0x89,0x0c,0x5d,0x13,0x09,
    0xfc,0xfb,0x76,0x7a,0xa3,0xf7,0x35,0x78,0x09,0x7e,0x4a,0x3f,0x69,0xc2,0x30,0x79,
    0x67,0x2f,0x53,0x47,0x38,0x90,0xe8,0x5e,0x52,0x36,0x86,0x2e,0x7a,0xc8,0x9f,0x35,
    0x72,0x19,0x67,0x33,0x90,0x6f,0x3d,0xf2,0xf9,0xc2,0xbb,0xe2,0x62,0xeb,0x74,0xa8,
    0xce,0x66,0xc8,0xaf,0xe7,0xa9,0xbe,0x79,0xe0,0xa7,0xde,0xf1,0x42,0x56,0xf0,0x41,
    0x06,0x27,0x74,0xfe,0xa0,0x54,0x70,0x18,0x6c,0xbb,0x3a,0x70,0x60,0x3b,0x49,0xf7,
    0x67,0x47,0x35,0x29,0x15,0x64,0x0c,0xda,0xf4,0x09,0x6c,0x40,0x54,0x6f,0xbd,0x7c,
    0x0a,0xb9,0x82,0xb0,0xff,0x26,0x8e,0x2e,0x82,0x61,0x0f,0x65,0x7c,0x3a,0x50,0xad,
    0xaf,0x97,0xba,0x82,0xf7,0xd3,0xfe,0x8b,0x18,0xb0,0x95,0xb2,0x33,0x96,0x0f,0x3a,
    0x98,0xec,0xe3,0x2d,0x9f,0xf2,0x4a,0x4f,0x6b,0xe3,0xc6,0x69,0xc1,0x94,0x98,0xa0,
    0xc3,0x68,0xf4,0xeb,0xcd,0xbb,0xaf,0xcb,0xea,0x0d,0xfa,0xe9,0xe4,0xc1,0xdf,0xaf,
    0x41,0x0e,0xee,0xcd,0x72,0xa1,0x45,0xbf,0x69,0x58,0x9d,0x30,0x80,0x6c,0x65,0x80,
    0x4a,0x3e,0x76,0x26,0x6d,0x3d,0x83,0x47,0x49,0x6a,0xc0,0xd5,0x90,0x9f,0xca,0x91,
    0xab,0xed,0xda,0x4a,0xf7,0xba,0x9e,0x33,0xa0,0x14,0x83,0xfa,0x60,0xda,0x33,0x02,
    0x2c,0x6b,0xc7,0x03,0x90,0xc8,0x2d,0x08,0x2b,0xf9,0xf6,0xa8,0xd8,0x2a,0xdb,0x32,
    0xe2,0xe1,0x5a,0xe1,0x0a,0x39,0x73,0x86,0x0a,0xdc,0x01,0xa7,0x7e,0x3a,0xc0,0x66,
    0x09,0xb4,0x56,0xd0,0x6a,0x53,0xaa,0x99,0x43,0x1f,0x7d,0xcc,0x33,0xa4,0xbb,0x04,
};
