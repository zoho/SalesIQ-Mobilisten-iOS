//
//  UTSMessageHandler.h
//  ZohoSalesIQSDK
//
//  Created by Madhusudhan Rao on 02/06/16.
//  Copyright © 2016 Madhusudhan Rao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UTSMessageHandler : NSObject
- (void)onMessage:(NSNumber *)o data:(id)data ;
- (void)onNewVisit:(id)data;
- (void)onReVisit:(id)data;
- (void)onConnect:(id)data;

@end
