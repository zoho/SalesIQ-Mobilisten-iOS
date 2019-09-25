//
//  NSObject_WebSocket.h
//  LiveChat
//
//  Created by Balaji Sankar on 16/09/13.
//  Copyright (c) 2013 Balaji Sankar. All rights reserved.
//

#import "LDWMSUtil.h"
@class  SRWebSocket;
@protocol WebSocketDelegate <NSObject>
- (void)webSocket:(SRWebSocket *)webSocket onReceivingMessage:(id)message;
- (void)onConnectionOpen:(SRWebSocket *)webSocket;
- (void)onClose:(SRWebSocket *)webSocket reason:(NSString *)reason complete:(BOOL)completed;

@end


@interface WebSocket : NSObject <NSStreamDelegate>{
    NSURL *url;
    NSMutableURLRequest *request;
    NSMutableArray *protocols;
    NSInputStream *inputStream;
    NSOutputStream *outputStream;
    NSMutableDictionary *header;
}
@property id <WebSocketDelegate> delegate;
@property(nonatomic) NSURL *url;
@property(nonatomic) NSMutableURLRequest *request;
@property(nonatomic) NSMutableArray *protocols;

@property NSInputStream *inputStream;
@property NSOutputStream *outputStream;
- (id)initWithURL:(NSURL *)connecturl protocols:(NSArray *)protocolssent;
- (void) processHeaderResponse;
- (void) copyToOutstream;
- (void)addHeaders:(NSDictionary *)headers;
- (void)addCookies:(NSDictionary *)cookies;
- (void)addHeader:(NSString *)key andValue:(NSString *)value;
- (void)addCookie:(NSString *)key andValue:(NSString *)value;
- (void)sendHeader;
- (void)send:(id)data;
- (void)open;
- (void)close;
- (void)hold;
- (void)resume;
//- (NSString *)stringByBase64Encoding:(NSData *)data;
- (void)stream:(NSStream *)theStream handleEvent:(NSStreamEvent)streamEvent ;





@end
