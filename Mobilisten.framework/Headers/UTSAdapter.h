//
//  UTSAdapter.h
//  ZohoSalesIQSDK
//
//  Created by Madhusudhan Rao on 31/05/16.
//  Copyright © 2016 Madhusudhan Rao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTS.h"
#import "UTSMessageHandler.h"

typedef enum {
    UTSCONNECTED   = 1,
    UTSDISCONNECTED = 0,
    UTSCONNECTING = 2,
} utsconnectionStatus;


@interface UTSAdapter : NSObject
+ (id)getSharedInstance;
- (void)disconnect;
- (void)hold;
- (void)resume;
- (void)networkFailure;
- (BOOL)getConnectionStatus;
- (void)setMessageHandler:(UTSMessageHandler *)handler;
-(void)writeData:(id)data;
-(void)closeConnection;
-(void)clearData;

@property(strong) NSString * dclPfx;
- (void)initWithApiKey:(NSString *)apiKey andAccessKey:(NSString *)accessKey bundleId:(NSString *)bundle useragent:(NSString *)ua domain:(NSString *)dom andtheHeader:(NSMutableDictionary *)theHeader;
@end

