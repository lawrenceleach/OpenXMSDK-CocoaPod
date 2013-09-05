//
//  OXMAdBanner.h
//  OpenX_iOS_SDK
//
//  Created by Oleg Kovtun on 07.02.12.
//  Copyright (c) 2012 OpenX. All rights reserved.
//

#import <UIKit/UIKit.h>


/** Ad banner component, which manages the process of loading and displaying of advertisements.
 Can be easily integrated with interface builder.
 */

@class OXMAdRequest;
@class OXMAdBannerView;
@protocol OXMAdBannerDelegate;
@interface OXMAdBanner : UIView {    
}

/** @name Checking banner state */

/** Returns YES if an advertisement is loaded, NO otherwise. */
@property (nonatomic, readonly, getter=isLoaded) BOOL loaded;
/** Actions display full screen content in a modal view. Use this property to determine if an action is currently in progress. */
@property (nonatomic, readonly, getter=isActionInProgress) BOOL actionInProgress;

/** @name Customizing ad banner behavior */

/** By accessing the request object you can set optional targeting data which will be sent with the ad requests. This is also how
 you would disable the location auto-detection feature, which currently is on by default.
 @see OXMAdRequest
 */
@property (nonatomic, readonly) OXMAdRequest* request;

/** Delegate which will handle methods from _OXMAdBannerDelegate_ protocol. */
@property (nonatomic, unsafe_unretained) NSObject<OXMAdBannerDelegate>* adBannerDelegate;

/** This needs to be called to specify ad unit ids and domain. Ad unit ID - Indicates the unique ID for the ad unit where you want to serve an ad.
 
 a) if your app supports just one orientation - you can set needed ad unit ID and leave the other one empty.
 
 b) in case you are using the same ad unit id for both orientation - you have to set this ad unit as both portraitAdUnitID and landscapeAdUnitID.
 
 c) in case you have a different ad unit id for each orientation - set it accordingly to portraitAdUnitID and landscapeAdUnitID.
 @param domain is the hostname of your OpenX delivery server
 @param pAuid ad unit id for portrait orientation
 @param lAuid ad unit id for landscape orientation
 */
- (void) setDomain:(NSString*)domain portraitAdUnitID:(NSString*)pAuid landscapeAdUnitID:(NSString*)lAuid;

/** You may enable SSL on the ad requests if desired.
 
 @param hasSSL if YES it will be 'https' protocol otherwise 'http'
 */
- (void) setSSL:(BOOL)hasSSL; 

/** Set ad change interval in seconds (by default 30 seconds).
 @param interval New ad change interval in seconds. 
 */
- (void) setAdChangeInterval:(NSTimeInterval)interval;


/** @name Control ad loading
 Methods to be called after you have customized your banner as desired. 
 */

/** Starts loading ads from OpenX server sending it auto-detected and user-provided parameters in request. 
 
 Must be called when all parameters are set.
 */
- (void) startLoading;

/** Stop loading ads in model. */
- (void) stopLoading;

@end


/**
 This protocol contains delegate methods for controlling ad loading process, and handling ad banner views actions.
 */

@protocol OXMAdBannerDelegate <NSObject>
@optional

/** This method is invoked when the banner has confirmation that an ad has loaded in a webview-container.
 It is also called after device rotation if the ad changes due to different orientation ad unit id.
*/
- (void) adBannerDidLoadAd:(OXMAdBanner*)adBanner;

/** This method is invoked when an ad has failed to load. */
- (void) adBanner:(OXMAdBanner*)adBanner didFailToReceiveAdWithError:(NSError*)error;

/** This method is invoked when some action was initiated by the user.
 @param willLeave parameter indicates whether the application will be put to background state soon, i.e. another application will be launched to handle the action.
 */
- (void) adBannerActionWillBegin:(OXMAdBanner*)adBanner willLeaveApplication:(BOOL)willLeave;

/** This message is sent when a modal action has begun (in-app browser presented or MRAID ad action started). */
- (void) adBannerActionDidBegin:(OXMAdBanner*)adBanner;

/** This message is sent when a modal action has completed and control is returned to the application (in-app browser closed or MRAID ad action finished). */
- (void) adBannerActionDidFinish:(OXMAdBanner*)adBanner;

/** This method is invoked when the user triggered action can not be executed. */
- (void) adBannerActionUnableToBegin:(OXMAdBanner*)adBanner;

@end
