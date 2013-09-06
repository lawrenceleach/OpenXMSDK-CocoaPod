//
//  OXMAdRequest.h
//  OpenX_iOS_SDK
//
//  Created by Oleg Kovtun on 06.12.11.
//  Copyright (c) 2011 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/** 
 * @ingroup gender types */
typedef enum {
	OXMGender_Male = 0,
	OXMGender_Female,
	OXMGender_Other
} OXMGender;

/** 
 * @ingroup marital status types */
typedef enum {
	OXMMaritalStatus_Single = 0,
	OXMMaritalStatus_Married,
	OXMMaritalStatus_Divorced
} OXMMaritalStatus;

/** 
 * @ingroup ethnicity types */
typedef enum {
	OXMEthnicity_African_American = 0,
	OXMEthnicity_Asian,
	OXMEthnicity_Hispanic,
    OXMEthnicity_White,
    OXMEthnicity_Other
} OXMEthnicity;

/** 
 * @ingroup network connection types */
typedef enum {
	OXMNetworkType_Offline = 0,
	OXMNetworkType_Wifi,
	OXMNetworkType_Cell
} OXMNetworkType;

/** This is a container class for ad request parameters (developer provided, auto-detected, other OpenX and custom params).
 You do not create an instance of this class, but use methods of the request property of _OXMAdBanner_, _OXMAdBannerController_, or _OXMAdInterstitialController_.
 */

@interface OXMAdRequest : NSObject {
}


/** @name User and demographic information */

/** Enable location autodetection (YES by default). */
@property (nonatomic, assign) BOOL autodetectLocation;

/** Indicates the end-user's age, in years. */
- (void) setUserAge:(NSUInteger)age; 
/** Indicates the end-user's gender. */
- (void) setUserGender:(OXMGender)gen; 
/** Indicates the end-user's marital status. */
- (void) setUserMaritalStatus:(OXMMaritalStatus)mar; 
/** Indicates the end-user's ethnicity. */
- (void) setUserEthnicity:(OXMEthnicity)eth; 
/** Indicates the end-user's annual household income, in US Dollars (no commas (,) or periods (.)). */
- (void) setUserAnnualIncomeInUS:(NSUInteger)inc;
/** Indicates the customer-provided user ID, if different from the Device ID. */
- (void) setUserID:(NSString*)xid;

/** @name Application information */

/** Indicates the store URL for the mobile application. */
- (void) setAppStoreMarketURL:(NSString*)url;

/** @name Location and connection information */

/** For US locations, indicates the end-user's Designated Market Area. For example: dma=803. */
- (void) setDMA:(NSString*)dma; 
/** The IP address of the carrier gateway. If this is not present, then OpenX retrieves it from the request header. */
- (void) setIP:(NSString*)ip;
/** Indicates the GPS location coordinates, in decimal form, of the end-user. */
- (void) setCoordinates:(CLLocationCoordinate2D)coordinates; 
/** Mobile carrier - Defined by the Mobile Country Code (MCC) and Mobile Network Code (MNC), using the format: <MCC>-<MNC>. For example: crr=310-410. */
- (void) setCarrier:(NSString*)crr; 
/** User Geo Country. Format must be ISO 3166-1 (two letter, upper case). */
- (void) setCountry:(NSString*)cnt; 
/** Indicates the end-user's city location. */
- (void) setCity:(NSString*)cty; 
/** Indicates the end-user's state location. */
- (void) setState:(NSString*)stt; 
/** Indicates the US ZIP or postal code for the end-user. */
- (void) setZipCode:(NSString*)zip;
/** Indicates the end-user's network connection type. For a wireless network, use net=wifi. */
- (void) setNetworkType:(OXMNetworkType)net;

/** @name Other OpenX parameters */

/** This method allows to add new OpenX param by name and set needed value.
 
 If some ad call parameter doesn't exist in this SDK, you can always set it manually using this method.
 */
- (void) addParam:(NSString*)value withName:(NSString*)name;

/** @name Custom developer parameters */

/** Custom user parameters, a dictionary of name-value parameter pairs, where each param name will be prepended with ‘c.’.
 
 So for example parameter with name ‘xxx’ will be turned into ‘c.xxx’ when request will be sent.
 */
- (void) setCustomParams:(NSMutableDictionary*)params;

/** A convenient method to add custom params one by one, here name will also be auto-prepended with ‘c.’.
 
 Make sure to provide the plain name of the param, like ‘xxx’.
 */
- (void) addCustomParam:(NSString*)value withName:(NSString*)name;

@end