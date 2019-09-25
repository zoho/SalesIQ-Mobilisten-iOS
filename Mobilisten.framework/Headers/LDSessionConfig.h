//
//  SessionConfig.h
//  TestingZohoMessenger
//
//  Created by Balaji Sankar on 05/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SessionConfig : NSObject
+ (long)CHAT_ENABLED;
+ (long)PRESENCE_CHAT;
+ (long)PRESENCE_PERSONAL;
+ (long)PRESENCE_ORG;
+ (long)CROSS_PRD_MSG_ENABLED;
@end
