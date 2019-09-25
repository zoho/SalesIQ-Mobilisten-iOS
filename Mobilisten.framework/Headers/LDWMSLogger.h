//
//  WMSLogger.h
//  LDPEXLibrary
//
//  Created by Balaji Sankar on 21/04/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum {
	WMSSEVERE=1,
    WMSINFO=2,
    WMSDEBUG=3,
    WMSFINE=4,
} WMSLoggerValue;
@interface WMSLogger : NSObject
+ (void)setLoggerValue:(int)number;
+ (void)logMessageWithValue:(WMSLoggerValue)value withFormat:(NSString *)format, ...;
@end
