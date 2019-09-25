//
//  ChatInfoMessage.h
//  LDPEXLibrary
//
//  Created by Balaji Sankar on 28/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ChatInfoMessage : NSObject
/**
 The method TYPING creates an instance of ChatInfoMessage which can be used to denote that user is typing a message.
 */
+ (ChatInfoMessage *)TYPING;
/**
 The method IDLE creates an instance of ChatInfoMessage which can be used to denote that user is idle.
 */
+ (ChatInfoMessage *)IDLE;
/**
 The method HAS_ENTERED_TEXT creates an instance of ChatInfoMessage which can be used to denote that user has entered the text.
 */
+ (ChatInfoMessage *)HAS_ENTERED_TEXT;
- (int)mType;

@end
