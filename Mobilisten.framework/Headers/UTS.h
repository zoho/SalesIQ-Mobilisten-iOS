//
//  UTS.h
//  ZohoSalesIQSDK
//
//  Created by Madhusudhan Rao on 31/05/16.
//  Copyright © 2016 Madhusudhan Rao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDSRWebSocket.h"

@protocol UTSConnectionHandler <NSObject>
- (void)onConnect;
- (void)onDisconnect;
- (void)onMessage:(NSDictionary *)msg;
@end

@interface UTS : NSObject
{
    int timeout;
    NSString *sid;
    NSString *xa;
}
@property(nonatomic, strong)NSMutableArray *seqList;
@property BOOL isHold;
@property int timeout;
@property NSString *sid;
@property NSString *xa;
@property SRWebSocket *websocket;
@property id <UTSConnectionHandler> PexConnectionHandlerdelegate;
//- (void)initWithURL:(NSString *)theUrl andEmbedName:(NSString *)embedName ScreenName:(NSString *)screenName;
- (void)initWithApiKey:(NSString *)apiKey andAccessKey:(NSString *)accessKey bundleId:(NSString *)bundle domain:(NSString *)dom andtheHeader:(NSDictionary *)theHeader;
//- (void)process:(LDPEXEvent *)evt andEventHandler:(id)eventHandler;
//- (void)process:(LDPEXEvent *)evt;
//- (void)initWithCredentials:(PEXCredentials *)theCredentials prd:(LDWmsService *)prd andconfig:(NSString *)configs;
//- (void)initWithURL:(NSString *)theUrl andCredentials:(PEXCredentials *)theCredentials prd:(LDWmsService *)prd andconfig:(NSString *)configs;
//- (void)initWithURL:(NSString *)theUrl prd:(LDWmsService *)prd andconfig:(NSString *)configs;
//- (void)initWithURL:(NSString *)theUrl andCredentials:(PEXCredentials *)theCredentials prd:(LDWmsService *)prd andconfig:(NSString *)configs andtheHeader:(NSDictionary *)theheader;
- (void)setTimeout:(int)time;
- (void)close;
- (id)init;
- (void)hold;
- (void)resume;
- (void)reconnect:(NSNumber *)isSendSidAndXa;
- (void)clearValues;
+ (id)getSharedInstance;
@end
