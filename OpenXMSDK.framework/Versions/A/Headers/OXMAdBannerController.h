//
//  OMXAdBaseController.h
//  OpenX_iOS_SDK
//
//  Copyright (c) 2013 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Base ad controller, which will manage process of loading of an advertising. Used for usual ad banner views.
 */

@class OXMAdRequest;
@class OXMAdBannerView;
@protocol OXMAdBannerControllerDelegate;

@interface OXMAdBannerController : NSObject {
}

/** Return ad banner views which will contain advertisements.
 @return all the ad banner views (more than one only in the case of -initWithDomain:portraitAdGroupID:landscapeAdGroupID: )
 */
- (NSArray*) adBannerViews;

/** Get first ad banner view from adBannerViews array.
 @return first ad banner view from adBannerViews array
 */
- (OXMAdBannerView*) adBannerView;

/** @name Initialization methods */

/** Initialize ad controller with ad unit ids and domain. Ad unit ID - the ID for the ad unit where you want to serve an ad.
 
 a) if your app supports just one orientation - you can set needed ad unit ID and leave the other one empty.
 
 b) in case you are using the same ad unit id for both orientation - you have to set this ad unit as both portraitAdUnitID and landscapeAdUnitID.
 
 c) in case you have a different ad unit id for each orientation - set it accordingly to portraitAdUnitID and landscapeAdUnitID.
 
 @param domain is the hostname of your OpenX delivery server
 @param pAuid ad unit id for portrait orientation
 @param lAuid ad unit id for landscape orientation
 */
- (id) initWithDomain:(NSString*)domain portraitAdUnitID:(NSString*)pAuid landscapeAdUnitID:(NSString*)lAuid;

/** Initialize ad controller with ad group ids and domain. Ad unit group ID - Indicates the unique ID for the ad unit group that you want to serve ads for.
 
 This parameter is required if you are requesting ads or a predefined ad unit group.
 Set needed ad group ids the same way as shown in (see initWithDomain:portraitAdUnitID:landscapeAdUnitID: method).
 @param domain is the hostname of your OpenX delivery server
 @param pPgid ad group id for portrait orientation
 @param lPgid ad group id for landscape orientation
 */
- (id) initWithDomain:(NSString*)domain portraitAdGroupID:(NSString*)pPgid landscapeAdGroupID:(NSString*)lPgid;


/** @name Checking controller state */

/** Return YES if an advertisement is loaded, NO otherwise. 
 This property should always be checked before presenting ad modally. */
@property (nonatomic, readonly, getter=isLoaded) BOOL loaded;

/** Actions display full screen content in a modal view. Use this property to determine if an action is currently in progress. */
@property (nonatomic, readonly, getter=isActionInProgress) BOOL actionInProgress;


/** @name Customizing ad controller behavior */

/** Main delegate which will handle methods from _OXMAdBannerControllerDelegate_  protocol. */
@property (nonatomic,unsafe_unretained) NSObject<OXMAdBannerControllerDelegate>* adControllerDelegate;

/** By accessing the request object you can set optional targeting data which will be sent with the ad requests. This is also how
 you would disable the location auto-detection feature, which currently is on by default.
 **/
@property (nonatomic, readonly) OXMAdRequest* request;

/** You may enable SSL on the ad requests if desired.
 @param hasSSL if set to YES the scheme will be 'https', otherwise 'http'
 */
- (void) setSSL:(BOOL)hasSSL;

/** Set ad update interval in seconds (by default 30 seconds). 
 @param interval New ad change interval in seconds.
 */
- (void) setAdChangeInterval:(NSTimeInterval)interval;


/** @name Control ad loading */

/** Starts loading the ad from OpenX server sending it auto-detected and user-provided parameters in request. 
    Must be called when all parameters are set.
  */
- (void) startLoading;

/** Stop loading ads including a pending request (if any) and all future timer-based requests. */
- (void) stopLoading;

@end


/**
 This protocol contains delegate methods for listening to ad loading and display lifecycle. As first parameter they get an ad banner controller 
 instance.
 */

@protocol OXMAdBannerControllerDelegate <NSObject>
@optional

/** This method is invoked when the controller has a confirmation that ads have been loaded for its banner views. */
- (void) adControllerDidLoadAd:(OXMAdBannerController*)adController;

/** This method is invoked when the controller has a failed ad request. */
- (void) adController:(OXMAdBannerController*)adController didFailToReceiveAdWithError:(NSError*)error;

/** This method is invoked when some action has been started on ad banner view of ad controller.
 
 If willLeave is YES, note that the delegate method -adControllerActionDidBegin: will not be called for this event.
 @param willLeave parameter indicates whether the application will be put to background state soon, i.e. another application will be launched to handle the action.
 */
- (void) adControllerActionWillBegin:(OXMAdBannerController*)adController willLeaveApplication:(BOOL)willLeave;

/** This message is sent when a modal action has begun (in-app browser presented or MRAID ad action started). */
- (void) adControllerActionDidBegin:(OXMAdBannerController*)adController;

/** This message is sent when a modal action has completed and control is returned to the application (in-app browser closed or MRAID ad action finished). */
- (void) adControllerActionDidFinish:(OXMAdBannerController*)adController;

/** This method is sent when the user triggered action can not be executed. */
- (void) adControllerActionUnableToBegin:(OXMAdBannerController*)adController;

@end