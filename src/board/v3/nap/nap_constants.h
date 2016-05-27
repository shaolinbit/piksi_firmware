/*
 * Copyright (C) 2016 Swift Navigation Inc.
 * Contact: Jacob McNamee <jacob@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SWIFTNAV_NAP_CONSTANTS_H
#define SWIFTNAV_NAP_CONSTANTS_H

#if USE_PIKSI_V2_FE
	#define NAP_FRONTEND_SAMPLE_RATE_Hz	(16.368e6)
	#define NAP_ACQ_DECIMATION_RATE		(2)
	#define NAP_TRACK_DECIMATION_RATE	(1)
	//NAP_FE_BASEBAND_MIXER_PINC = 0xffffffff - (u32)round(4.092e6 * pow(2.0, 32.0) 
	//						/ NAP_FRONTEND_SAMPLE_RATE_Hz)
	#define NAP_FE_BASEBAND_MIXER_PINC	0xffffffff - (u32)(4.092e6 * 4294967296 \
		    		                	/ NAP_FRONTEND_SAMPLE_RATE_Hz + 0.5)
#else
	#define NAP_FRONTEND_SAMPLE_RATE_Hz     (99.375e6)
	#define NAP_ACQ_DECIMATION_RATE         (12)
	#define NAP_TRACK_DECIMATION_RATE       (4)
	//NAP_FE_BASEBAND_MIXER_PINC = (u32)round(14.58e6 * pow(2.0, 32.0) 
	//						/ NAP_FRONTEND_SAMPLE_RATE_Hz)
	#define NAP_FE_BASEBAND_MIXER_PINC	(u32)(14.58e6 * 4294967296 \
		                         		/ NAP_FRONTEND_SAMPLE_RATE_Hz + 0.5)
#endif

#define NAP_ACQ_SAMPLE_RATE_Hz                  (NAP_FRONTEND_SAMPLE_RATE_Hz  \
		                                           / NAP_ACQ_DECIMATION_RATE)

#define NAP_KEY_LENGTH				(16)
#warning Must set NAP_KEY_ARRAY based on Device DNA of target FPGA
#define NAP_KEY_ARRAY				{0x83,0xde,0x90,0x6d,0x12,0x60,0xf0,0xaa,0x63, \
							0x9b,0x24,0x4a,0xfb,0x58,0x31,0x77}

#define NAP_VERSION_STRING_OFFSET		(4)
#define NAP_VERSION_STRING_LENGTH		(52)

#define NAP_DNA_OFFSET				(56)
#define NAP_DNA_LENGTH				(8)

#endif /* SWIFTNAV_NAP_CONSTANTS_H */