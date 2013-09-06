//
//  OXMAdInterstitialController.h
//  OpenX_iOS_SDK
//
//  Created by Oleg Kovtun on 03.02.12.
//  Copyright (c) 2012 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    OXMInterstitialClosePositionScreenTopRight, // Display the close widget at the top right corner of the screen; the default.
    OXMInterstitialClosePositionScreenTopLeft,  // Display the close widget at the top left corner of the screen.
    OXMInterstitialClosePositionAdTopRight,     // Display the close widget at the top right corner of the ad, like a lightbox.
    OXMInterstitialClosePositionAdTopLeft,      // Display the close widget at the top left corner of the ad, like a lightbox.
} OXMInterstitialClosePosition;

/**
 Ad controller for interstitial ads.
 
 This controller will load and display modal advertisements with a UI that occupies most or all of the screen. Note that the -loadAd method
 will load an interstitial a single time. Make sure that -loadAd is called before every time you want to display an interstitial.
 */

@class OXMAdRequest;
@protocol OXMAdInterstitialControllerDelegate;

@interface OXMAdInterstitialController : NSObject {
}

/** @name Initialization methods */

/** Initialize interstitial controller with ad unit ids and domain. Ad unit ID indicates the ID for the ad unit where you want to serve an ad.

 You can use a single controller to support both orientations if you are at a point in your app where you can display an interstitial in either orientation.
 a) if your app supports just one orientation - you can set needed ad unit ID and leave the other one empty.
 
 b) in case you are using the same ad unit id for both orientation - you have to set this ad unit as both portraitAdUnitID and landscapeAdUnitID. (Note that images will be scaled down if they do not fit the current orientation, so this configuration isn't common for interstitials.)
 
 c) in case you have a different ad unit id for each orientation - set it accordingly to portraitAdUnitID and landscapeAdUnitID.
 
 @param domain is the hostname of your OpenX delivery server
 @param pAuid ad unit id for portrait orientation
 @param lAuid ad unit id for landscape orientation
 */
- (id) initWithDomain:(NSString*)domain portraitAdUnitID:(NSString*)pAuid landscapeAdUnitID:(NSString*)lAuid;


/** @name Loading, presenting interstitials and checking interstitial display state */

/**
 */
- (void) loadAd;

/** Check whether this controller has a loaded ad ready to present. */
@property (nonatomic, readonly, getter=isLoaded) BOOL loaded;

/** Present an interstitial ad modally.
 
 This method should be used to present the full screen interstitial ad.
 It will only display an ad if isLoaded == YES.
 */
- (void) presentLoadedAd;

/**
 Indicates whether a modal interstitial is being presented through any instance of this class.
 
 IMPORTANT! Any view controllers that are capable of using this class to display interstitials with useOverlay=YES
 must utilize this method in their shouldAutorotate implementations.
 */
+ (BOOL) isModalAdPresented;


/** @name Customizing appearance */

/** Set this property before calling -presentLoadedAd to customize the position of the close button. */
@property (nonatomic, assign) OXMInterstitialClosePosition closePosition;

/** Set this property before calling -presentLoadedAd to customize the opacity of the translucent background. */
@property (nonatomic, assign) CGFloat backgroundOpacity;

/** Use an overlay style.
 
 When NO, this controller will present a view controller modally over the application's current view controller.
 When YES, the controller will inject views into the current view controller's view.
 
 The default, NO, provides compatibility with previous behavior.
 
 Set this property before calling -presentLoadedAd.
 
 See the documentation for more details about whether your view controllers are compatible with the new overlay presentation.
 */
@property (nonatomic, assign) BOOL useOverlay;


/** @name Customizing ad controller behavior */

/** Main delegate which will handle methods from _OXMAdInterstitialControllerDelegate_ protocol. */
@property (nonatomic,unsafe_unretained) NSObject<OXMAdInterstitialControllerDelegate>* interstitialDelegate;

/** By accessing the request object you can set optional targeting data which will be sent with the ad requests. This is also how
 you would disable the location auto-detection feature, which currently is on by default.
 */
@property (nonatomic, readonly) OXMAdRequest* request;

/** You may enable SSL on the ad requests if desired.
 @param hasSSL if set to YES the scheme will be 'https', otherwise 'http'
 */
- (void) setSSL:(BOOL)hasSSL;


/** @name Supporting rotation during interstitial display when you enable useOverlay */

/** Your view controller should delegate to this method when an interstitial is presented and you are using useOverlay.
 
 If you enable useOverlay then you are responsible from calling these methods inside your own VC's implementation of these methods.
 Your methods should contain code like this:
 
    if ([OXMAdInterstitialController isModalAdPresented]) {
        return [myAdInterstitialController shouldAutorotate];
    } else {
        your normal logic 
    }
 
 @return whether the displayed interstitial ad wants to allow rotation
 */
- (BOOL) shouldAutorotate;

/** If you support < iOS 6 then you should also delegate to this method.
 @return whether the displayed interstitial ad wants to allow rotation for iOS 4.3 or 5
 */
- (BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;

@end


/**
 This protocol contains delegate methods which will be invoked for the interstitial ad events.
 */

@protocol OXMAdInterstitialControllerDelegate <NSObject>
@optional

/** This method is invoked when the interstitial ad has been loaded. 
 @param adController The controller sending the notification
*/
- (void) interstitialDidLoad:(OXMAdInterstitialController*)adController;

/** This method is invoked when the interstitial controller has a failed ad request.
 @param adController The controller sending the notification
*/
- (void) interstitial:(OXMAdInterstitialController*)adController didFailToReceiveAdWithError:(NSError*)error;

/** This method is invoked when an interstitial view controller has been presented or the overlay has been placed.

 You will not receive this method after calling -presentLoadedAd if, for example, the interstitial failed to load.
 @param adController The controller sending the notification
 */
- (void) interstitialDidBegin:(OXMAdInterstitialController*)adController;

/** This method is invoked if the ad will open another application.
 @param adController The controller sending the notification
*/
- (void) interstitialWillLeaveApplication:(OXMAdInterstitialController*)adController;

@required

/** This method will be invoked when interaction with an interstitial is finished. Your application may resume control. 
 @param adController The controller sending the notification
 */
- (void) interstitialDidFinish:(OXMAdInterstitialController*)adController;

@end
