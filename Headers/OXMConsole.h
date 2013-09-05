//
//  OXMConsole.h
//  OpenX_iOS_SDK
//
//  Created by Oleg Kovtun on 22.12.11.
//  Copyright (c) 2011 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

/** 
    Set this global variable to true and you will get console debugging information,
    such as delegate calls failures etc. in your xCode console
 */
extern BOOL OXM_CONSOLE_DEBUG;

/**
   This class manages SDK debug logging.
 */

@protocol OXMConsoleDelegate;
@interface OXMConsole : NSObject {
}

/** Set the console delegate.
 
 If you set console delegate to your object, don't forget to set it to nil when you don't need it (for example in your dealloc method). 
 @see OXMConsoleDelegate
 */
@property (nonatomic,unsafe_unretained) NSObject<OXMConsoleDelegate>* consoleDelegate;

/** Shared debug console instance.
 @return Singleton instance
 */
+ (OXMConsole*) instance;

/** Enable full logging. This is only recommended when you are debugging your application. Something like this in your app delegate:
   #if DEBUG
     [[OXMConsole instance] enableLog];
   #endif
**/
- (void) enableLog;

/** Get full debug logging.
 @return The cumulative SDK log messages over the application execution
 */
- (NSString*) fullLog;

/** Clear debug console. */
- (void) clear;

@end


/**
 This delegate method informs when an SDK log message is generated.
 */

@protocol OXMConsoleDelegate <NSObject>

/** Called when added some new information in debug logging. 
 @param message New message in log
 */
- (void) latestMessage:(NSString*) message;

@end