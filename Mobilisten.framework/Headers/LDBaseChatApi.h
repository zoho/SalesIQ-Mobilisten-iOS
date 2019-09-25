//
//  BaseChatApi.h
//  LDPEXLibrary
//
//  Created by Balaji Sankar on 17/03/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

@class ChatInfoMessage;
@interface BaseChatApi : NSObject

- (id)init;
+ (void)sendMessage:(NSString *)chid andMessage:(NSString *)msg andHandler:(id<LDPEXEventHandler>)handler andMsgId:(NSString *)msgId;
+ (void)sendMessage:(NSString *)chid andMessage:(NSString *)msg andHandler:(id<LDPEXEventHandler>)handler;
+ (void)sendTaskWithType:(LDPEXTaskTypes *)taskType andInfo:(id)info andHandler:(id<LDPEXEventHandler>)handler;
+ (void)joinAndAttachSessionWithChid:(NSString *)chid andHandler:(id<LDPEXEventHandler>)handler;
+ (void)createChat:(id)recipants andForceNew:(BOOL)forceNew andJoin:(BOOL)join andTitle:(NSString *)title andHandler:(id<LDPEXEventHandler>)handler andType:(int)type andPrivate:(BOOL)isPrivate;
+ (void)joinChat:(NSString *)chid andUname:(NSString *)uname andHandler:(id<LDPEXEventHandler>)handler;
+ (void)addMember:(NSString *)chid andRecipants:(id)recipants andDetails:(NSDictionary *)details andHandler:(id<LDPEXEventHandler>)handler;
+ (void)quitChat:(NSString *)chid andHandler:(id<LDPEXEventHandler>)handler;
+ (void)deleteMember:(NSString *)chid andRecipants:(id)recipants andDetails:(NSDictionary *)details andHandler:(id<LDPEXEventHandler>)handler;
+ (void)sendInfoMessage:(NSString *)chid andMsg:(id)msg andChatInfoMessage:(ChatInfoMessage *)chatInfoMessage andHandler:(id<LDPEXEventHandler>)handler;
+ (void)clearUnreadChats:(NSString *)chids andHandler:(id<LDPEXEventHandler>)handler;
+ (void)blockNotificationsForChatId:(NSString *)chid withInterval:(NSString *)interval andHandler:(id<LDPEXEventHandler>)handler;
+ (void)setLocation:(NSDictionary *)dict andHandler:(id<LDPEXEventHandler>)handler;
+ (void)getBadgeWithHandler:(id<LDPEXEventHandler>)handler;
@end
