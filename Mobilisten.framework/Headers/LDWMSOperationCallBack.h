//
//  LDOperationCallBack.h
//  LiveChat
//
//  Created by Balaji Sankar on 23/10/13.
//  Copyright (c) 2013 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WMSOperationCallBack : NSObject
+ (void)doCallBackOnMessage:(id)delegateobj :(NSString *)selector, ...;
@end
