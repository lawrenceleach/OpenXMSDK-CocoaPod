//
//  OXMAdBannerView.h
//  OpenX_iOS_SDK
//
//  Created by Oleg Kovtun on 06.12.11.
//  Copyright (c) 2011 OpenX. All rights reserved.
//

#import <UIKit/UIKit.h>

/** A view used to display the advertisement creative. 
 You are responsible for adding it as a subview in the view hierarchy if you are using _OXMAdBannerController_ directly.
 If you are using _OXMAdBanner_, that class encapsulates this view as well as the _OXMAdBannerController_.
 */

@interface OXMAdBannerView : UIView {
}

- (void) presentAdInView:(UIView *)v __attribute__((unavailable("This method is no longer provided. Please add OXMAdBannerView to your view hierarchy using UIView methods.")));

- (void) presentModalAd __attribute__((unavailable("This method is no longer provided. Please use -[OXMAdInterstitialController presentLoadedAd]")));

- (void) dismissModalAd __attribute__((unavailable("This method is no longer provided. There is no replacement at this time.")));

@end