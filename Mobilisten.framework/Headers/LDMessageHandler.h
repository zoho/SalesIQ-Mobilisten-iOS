//
//  LDMessageHandler.h
//  LDZohoMessenger
//
//  Created by Balaji Sankar on 25/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LCPEXHeader.h"
/**
 LDMessageHandler is a class which is used for delivering the custom ,crossproduct ,info messages and acs messages.
 */
@interface LDMessageHandler : NSObject
/**
 Invoked when an unhandled mtype is received.
 @param msg message object.
 @param mtype mtype of the message
 */
- (void)onMessage:(id)msg withType:(NSNumber *)mtype;
/**
 Invoked when a custom message is received.
 @param msg Custom message object.
 */
- (void)onCustomMessage:(id)msg;
/**
 Invoked when a cross product message is received.
 @param prd Product code of the message.
 @param data The body of the message.
 */
- (void)onCrossProductMessage:(LDWmsService *)prd andmsg:(id)data;
/**
 Invoked when a info message is received.
 @param prd Product code of the message.
 @param messsage data of the message.
 @param url url of the message.
 @param urlstring urlstring of the message.
 @param category category of the message.
 @param sender sender who sends the message.
 @param attachments attachments included in the message.
 @param params parameters included in the message.
 @param mid id of the message.
 @param dname dname of the message.
 @param orgs orgs for which the message is sent.
 @param groups groups for which the message is sent.
 */
- (void)onZohoMessage:(LDWmsService *)prd message:(id)message url:(NSString *)url urlstring:(NSString *)urlstring category:(NSString *)category sender:(NSString *)sender attachments:(NSString *)attachments params:(NSString *)params ID:(NSString *)mid dname:(NSString *)dname orgs:(NSString *)orgs groups:(NSString *)groups;
/**
 Invoked when an acs message is received.
 @param type Type of the message.
 @param data Data of the message.
 */
- (void)onACSMessage:(NSString *)type andData:(id)data;
@end
