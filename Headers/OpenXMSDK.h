//
//  OpenXMSDK.h
//  OpenX_iOS_SDK
//
//  Created by Oleg Kovtun on 06.12.11.
//  Copyright (c) 2011 OpenX. All rights reserved.
//

#import <Availability.h>

#ifndef __IPHONE_4_3
#warning "OpenXMSDK.framework uses features only available in iOS SDK 4.3 and later."
#endif

#ifndef __IPHONE_6_0
#warning "It is recommended to use iOS SDK 6.0 with OpenXMSDK.framework"
#endif

/* Basic ad banner (wrapper above ad banner controller) */
#import "OXMAdBanner.h"

/* OpenX ad controllers and the request */
#import "OXMAdBannerController.h"
#import "OXMAdBannerView.h"
#import "OXMAdInterstitialController.h"
#import "OXMAdRequest.h"

/* console debugging information */
#import "OXMConsole.h"
#import "OXMErrors.h"