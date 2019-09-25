//
//  LDUtil.h
//  LiveChat
//
//  Created by Balaji Sankar on 22/10/13.
//  Copyright (c) 2013 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>
//#import <QuartzCore/QuartzCore.h>
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import <Security/SecCertificate.h>
//#import <QuickLook/QuickLook.h>s


@interface UTSUtil : NSObject

+ (NSString *)getStringFromNSDictionary:(NSDictionary *)dict;
+ (NSString *)getStringFromNSArray:(NSArray *)array;
+ (NSString *)applicationDocumentDirectory;
+ (NSString *)removeWhiteSpaceAndNewLineInHeadAndTail:(NSString *)str;
+ (NSInteger)wordCount:(NSString *)str;
+ (NSString *)DictionarytoJsonString:(NSDictionary *)theDictionary;
+ (NSString *)ArraytoJsonString:(NSArray *)theArray;
+ (id)JsonData:(NSString *)theString;
+ (NSString *)stripTags:(NSString *)str;
+ (CGSize)scaledImageSize:(UIImage *)sourceImage scaledToWidth:(float)i_width;
+ (UIImage*)imageWithImage_ForDocument:(UIImage*)sourceImage scaledToWidth:(float)i_width;

@end
