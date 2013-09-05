//
//  OXMErrors.h
//  OpenX_iOS_SDK
//
//  Copyright (c) 2013 OpenX. All rights reserved.
//

/** Possible SDK errors */
typedef enum {
    /** Unknown error */
	OXMAdError_Unknown = 1000,
    /** Internet connection is down */
	OXMAdError_NoConnection,
    /** OpenX server problem */
	OXMAdError_Server,
    /** Wrong response */
	OXMAdError_Response,
    /** No ads loaded (empty response) */
    OXMAdError_NoAdsLoaded
} OXMAdError;

NSError* OXMErrorWithCode(OXMAdError code);