//
//  EntityChatHandler.h
//  LDPEXLibrary
//
//  Created by Shanmuga Sundaram G on 02/02/16.
//  Copyright © 2016 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDMessageInterface.h"
/**
 EntityChatHandler is a class for providing the notifications of messages. The event chat messages will be available in all the connections and services. The event chat messages will have a storage in the services.
 */
@interface EntityChatHandler : NSObject
<LDMessageInterface>
/**
 * Invoked after receiving join message.
 * @param chid The chat id of the chat in which the user has joined.
 * @param title Title of the chat.
 * @param users List of users in the chat.
 * @param addInfo Additional info along with the message, required for IAM groups.
 * @param history If @"1" history should be stored, else history isn't stored
 * @param messageInfo complete details from server
 * @param messageInfo complete details from server
 */
- (void)onJoin:(NSString *)chid withTitle:(NSString *)title addInfo:(NSString *)addInfo pCount:(NSString*)pCount andUsers:(NSArray *)users history:(NSString *)history messageDict:(NSDictionary*)messageInfo;
/**
 * Invoked after receiving a message.
 * @param chid The chat id of the chat in which the user has joined.
 * @param sender Sender of the message.
 * @param dname dname field in the message.
 * @param msg Message body.
 * @param stime Server time of the message.
 * @param newChat Indicates whether this message is the beginning of a new chat.
 * @param addInfo Additional info along with the message, required for IAM groups.
 * @param msgid The message Id of a particular message.
 * @param history A value of @"0" indicates that the messages are not stored in the app server. A value of nil or any other string indicates that the messages are stored in the app server
 * @param messageInfo complete details from server
 */
- (void)onMessage:(NSString *)chid sender:(NSString *)sender dname:(NSString *)dname time:(NSString *)stime newChat:(NSString *)newChat addInfo:(NSString *)addInfo andMessage:(id)msg andMessageID:(NSString *)msgid andHistory:(NSString *)history lastMsgTime:(NSString *)lmTime messageDict:(NSDictionary*)messageInfo;
/**
 * Invoked when members are added.
 * @param chid The chat id of the chat in which the user has joined.
 * @param addedBy One who has added new members.
 * @param addedBydname dname of the person who has added new members.
 * @param users The list of users added.
 @param time The time of the info message.
 */
- (void)onMembersAdded:(NSString *)chid addedBy:(NSString *)addedBy addedBydName:(NSString *)addedBydname andUsers:(NSArray *)users andTime:(NSString *)time;
/**
 * Invoked when members are deleted.
 * @param chid The chat id of the chat in which the user has joined.
 * @param deletedBy One who has deleted members.
 * @param deletedBydname dname of the person who has deleted members.
 * @param users The list of users deleted.
 @param time The time of the info message.
 */
- (void)onMembersDeleted:(NSString *)chid deletedBy:(NSString *)deletedBy deletedBydName:(NSString *)deletededBydname andUsers:(NSArray *)users andTime:(NSString *)time;
/**
 * Invoked when the user is invited
 * @param chid The chid of the chat, to which the user is invited.
 * @param addedBy Identifier of the person who has invited the user.
 * @param addedBydname dname of the person who has invited the user.
 */
- (void)onInvite:(NSString *)chid addedBy:(NSString *)addedBy addedBydName:(NSString *)addedBydname sTime:(NSString*)sTime;
/**
 * Invoked when the user is removed
 * @param chid The chid of the chat, from which the user is removed.
 * @param deletedBy Identifier of the person who has removed the user.
 * @param deletedBydname dname of the person who has removed the user.
 */
- (void)onRemove:(NSString *)chid deletedBy:(NSString *)deletedBy deletedBydName:(NSString *)deletededBydname sTime:(NSString*)sTime;
/**
 * Invoked when an user joins a chat
 * @param chid The chid of the chat, to which the user has joined.
 * @param wmsid The wmsid of the user who has joined.
 * @param dname dname of the user who has joined the chat.
 * @param status User Status of the user who has joined the chat.
 */
- (void)onMemberIn:(NSString *)chid wmsId:(NSString *)wmsid dname:(NSString *)dname andUserStatus:(LDUserStatus *)status;
/**
 * Invoked when an user is removed/quits a chat
 * @param chid The chid of the chat, from which the user has exited.
 * @param wmsid The wmsid of the user who has exited.
 * @param dname dname of the user who has exited the chat.
 * @param status User Status of the user who has exited the chat.
 */
- (void)onMemberOut:(NSString *)chid wmsId:(NSString *)wmsid dname:(NSString *)dname andUserStatus:(LDUserStatus *)status;
/**
 * Invoked after receiving an info message
 * @param chid The entity chat id.
 * @param sender Sender of the message.
 * @param dname dname field in the message.
 * @param msg Info message body(user list).
 * @param time The server time of the message.
 * @param addInfo The additional info supplied with the message.
 * @param mode The mode mentioned in the message.
 * @param messageInfo complete details from server
 */
- (void)onInfoMessageForChid:(NSString *)chid sender:(NSString *)sender dname:(NSString *)dname time:(NSString *)time addInfo:(NSString *)addInfo andMode:(NSString *)mode lastMsgTime:(NSString *)lmTime messageDict:(NSDictionary*)messageInfo;
/**
 * Invoked when an user starts typing.
 * @param chid The chat id of the chat in which the user has joined.
 * @param wmsid The wmsid of the user.
 */
- (void)onTyping:(NSString *)chid wmsId:(NSString *)wmsid;
/**
 * Invoked when an user/entity becomes idle.
 * @param chid The chat id of the chat in which the user has joined.
 * @param wmsid The wmsid of the user.
 */
- (void)onIdle:(NSString *)chid wmsId:(NSString *)wmsid;
/**
 * Invoked when an user has entered the text.
 * @param chid The chat id of the chat in which the user has joined.
 * @param wmsid The wmsid of the user.
 */
- (void)onTextEntered:(NSString *)chid wmsId:(NSString *)wmsid;
/**
 * Invoked after receiving an attachment message.
 * @param chid The chat id of the chat in which the user has joined.
 * @param wmsid The wmsid of the user.
 * @param msg Message body.
 */
- (void)onAttachment:(NSString *)chid wmsId:(NSString *)wmsid andMessage:(id)msg;
/**
 * Invoked after title is changed.
 * @param chid The chat id of the chat in which the user has joined.
 * @param wmsid The wmsid of the user.
 * @param title The new title.
 */
- (void)onTitleChange:(NSString *)chid wmsId:(NSString *)wmsid andTitle:(id)title;
@end
