//
//  WMSPEXAdapter.h
//  LDZohoMessenger
//
//  Created by Balaji Sankar on 04/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDChatHandler.h"
#import "LDCollaborationHandler.h"
#import "LDChannelHandler.h"
#import "LDTazHandler.h"
#import "LDEntityChatHandler.h"
#import "LDServiceChatHandler.h"
#import "LDCustomChatHandler.h"
#import "LDPresenceGroupHandler.h"
#import "LDZohoMessenger.h"
#import "LDWmsService.h"
#import "LDPEX.h"

typedef enum {
    WMSCONNECTED   = 1,
    DISCONNECTED = 0,
    WMSCONNECTING = 2,
} connectionStatus;




@interface WMSPEXAdapter : NSObject
<PEXConnectionHandler>
{
    LDMessageHandler *messageHandler;
    AVMessageHandler *avMessageHandler;

    PEX *pexInstance;
}
+ (id)getSharedInstance;
-(NSDictionary *)addAdditionalHeader:(NSMutableDictionary* )header;
- (void)setHandler:(id)handler ofType:(LDHandlerType)type;
- (void)connect:(LDPEXCredentials *)credential :(LDWmsService *)productCode :(NSString *)sessionConfig;
- (void)setConnectionHandler:(id<LDConnectionHandler>)delegate;
- (void)setMessageHandler:(LDMessageHandler *)handler;
- (void)setAVMessageHandler:(AVMessageHandler *)handler;
- (void)setContactsHandler:(ContactsHandler *)handler;
- (void)disconnect;
- (void)hold;
- (void)resume;
- (void)networkFailure;
- (void)process:(LDPEXEvent *)request;
- (BOOL)getConnectionStatus;
@property(strong) NSString * dclPfx;
@property(strong) NSString * dclBaseBomain;

@end
