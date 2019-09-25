//
//  LibProps.h
//  MobileEmbed
//
//  Created by Balaji Sankar on 18/11/13.
//  Copyright (c) 2013 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LibProps : NSObject
+ (NSString *)getValue:(NSString *)key;
+ (BOOL)containsKey:(NSString *)key;
+ (void)initializeDict;
@end
