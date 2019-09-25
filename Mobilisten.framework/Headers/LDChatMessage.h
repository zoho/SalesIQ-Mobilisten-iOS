//
//  ChatMessage.h
//  LDPEXLibrary
//
//  Created by Balaji Sankar on 28/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ChatMessage : NSObject
+ (ChatMessage *)TEXT;
+ (ChatMessage *)ATTACHMENT;
@end
