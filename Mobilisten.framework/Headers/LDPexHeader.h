//
//  LDPexHeader.h
//  LiveChat
//
//  Created by Shanmuga Sundaram G on 05/05/16.
//  Copyright © 2016 Zoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDPEXLibrary.h"

@interface LDPexHeader : LDPEXLibrary
+ (void)setAppKey:(NSString *)appKey;
+ (void)setPexHeader:(NSString *)agentHeader;

+ (void)setMessageHandler:(LDMessageHandler *)handler;
+ (void)setAVMessageHandler:(AVMessageHandler *)handler;
+ (void)sendMessage:(NSDictionary *)data andHandler:(id<LDPEXEventHandler>)handler ;
+ (void)clearUnreadChats:(NSString *)chids andHandler:(id<LDPEXEventHandler>)handler;
@end
