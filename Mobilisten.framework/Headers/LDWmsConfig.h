//
//  LDWmsConfig.h
//  TestingZohoMessenger
//
//  Created by Balaji Sankar on 05/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 LDWmsConfig class is used to enable various feature.
 */
@interface LDWmsConfig : NSObject
/**
 The method enableChat is used to enable chat.
 */
- (void)enableChat;
/**.
 The method enableChatPresence is used to enable chat Presence.
 */
- (void)enableChatPresence;
/**
 The method enablePersonalPresence is used to enable Personal Presence.
 */
- (void)enablePersonalPresence;
/**
 The method enableOrgPresence is used to enable org. presence.
 */
- (void)enableOrgPresence;
/**
 The method enableCrossProductMessage is used to enable cross product message.
 */
- (void)enableCrossProductMessage;
/**
 The method getConfig returns resultant String value after enabling various features
 @return Configuration String.
 */
- (NSString *)getConfig;
@end

