//
//  ApiHeaders.h
//  LDPEXLibrary
//
//  Created by Balaji Sankar on 06/03/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LCPEXHeader.h"
@class ChatInfoMessage;
/**
 CollaborationApi is used to invoke Collaboration related functions.
 It requires CollaborationHandler, which will receive incoming messages from the WMS server
 */
@interface CollaborationApi : NSObject
/**
 This method is used to join, as well as attach a session to a particular collaboration
 @param collabid The Collaboration id associated with the particular collaboration service.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)attachAndJoinWithCollabId:(NSString *)collabId handler:(id<LDPEXEventHandler>)handler;
/**
 The method sendMessage is used to send Collaboration message for a given collaboration with collabid as Collaboration Id.
 @param collabid The Collaboration id associated with the particular collaboration service.
 @param msg The message that has to be sent.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)sendMessageWithCollaborationId:(NSString *)collabid message:(NSString *)msg handler:(id<LDPEXEventHandler>)handler;
/**
 The method blockNotificationsForCollaborationId is used to block or unblock push notifications for a specific collaboration indicated by the collab id.
 @param collabId The collaboration Id.
 @param interval To unblock specify @"0", else to block specify the number of minutes , for example to block for 5 mins , give the value as @"5".
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)blockNotificationsForCollaborationId:(NSString *)collabId withInterval:(NSString *)interval andHandler:(id<LDPEXEventHandler>)handler;
/**
 The method create is used to create a new Collaboration service.
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to create a collaboration. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"].
 @param forceNew A BOOL value indicating whether a new collaboration should be created.
 @param join A BOOL Value indicating whether to join the collaboration.
 @param title The title of the new chat.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)createWithRecipients:(id)recipants forceNew:(BOOL)forceNew join:(BOOL)join title:(NSString *)title handler:(id<LDPEXEventHandler>)handler;
/**
 The method join is used to join to an existing collaboration with the collaboration id mentioned by collabid.
 @param collabid The Collaboration id associated with the particular collaboration service.
 @param uname The zuid of the user.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 
 */
- (void)joinWithCollaborationId:(NSString *)collabid uname:(NSString *)uname handler:(id<LDPEXEventHandler>)handler;
/**
 The method addMember is used add a new member to the existing collaboration service.
 @param collabid The Collaboration id associated with the particular collaboration service.
 @param recipants Denotes the zuid of the person(s), whom the user wishes to add to the collaboration. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"].
 @param details Additional Details that can be sent along with the request.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)addMemberWithCollaborationId:(NSString *)collabid recipients:(id)recipants details:(NSDictionary *)details handler:(id<LDPEXEventHandler>)handler;
/**
 The method quit is used to quit from the existing collaboration.
 @param collabid The Collaboration id associated with the particular collaboration service.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)quitWithCollaborationId:(NSString *)collabid handler:(id<LDPEXEventHandler>)handler;
/**
 The method deleteMember is used to delete a member from the existing collaboration service.
 @param collabid The Collaboration id associated with the particular collaboration service.
 @param recipants Denotes the zuid of the person(s), whom the user wishes to remove from the collaboration. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"].
 @param details Additional Details that can be sent along with the request.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)deleteMemberWithCollaborationId:(NSString *)collabid recipants:(id)recipants details:(NSDictionary *)details handler:(id<LDPEXEventHandler>)handler;
/**
 The method sendInfoMessage is used to send status information about the user. The user might be in IDLE state, or HAS ENTERED TEXT or even TYPING a message.
 @param collabid The Collaboration id associated with the particular collaboration service.
 @param msg Any status message associated with this request. (Shouldn't be left empty)
 @param chatInfoMessage A ChatInfoMessage object which can be one of the following TYPING, IDLE or HAS_ENTERED_TEXT.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)sendInfoMessageWithCollaborationId:(NSString *)collabid msg:(id)msg chatInfoMessage:(ChatInfoMessage *)chatInfoMessage handler:(id<LDPEXEventHandler>)handler;
@end
/**
 ServiceChatApi is used to invoke Service chat related functions. 
 It requires LDServiceChatHandler, which will receive incoming messages from the WMS server.
 */
@interface ServiceChatApi : NSObject
/**
 This method is used to clear unread chat counts associated with the chat id.
 @param chatids Represents the chat id's for which the unread status must be cleared. You can supply multiple chat ids by separating them with comma. eg is @"chatid1,chatid2"; 
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)clearUnreadChatsWithChatids:(NSString *)chatids handler:(id<LDPEXEventHandler>)handler;
/**
 The method blockNotificationsForChatId is used to block or unblock push notifications for a specific chat indicated by the chid
 @param chid The Chat Id.
 @param interval To unblock specify @"0", else to block specify the number of minutes , for example to block for 5 mins , give the value as @"5".
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)blockNotificationsForChatId:(NSString *)chid withInterval:(NSString *)interval andHandler:(id<LDPEXEventHandler>)handler;
/**
 This method is used to join, as well as attach a session to a particular chat
 @param collabid The Chat id associated with the particular chat.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)attachAndJoinWithChatId:(NSString *)ChatId handler:(id<LDPEXEventHandler>)handler;
/**
 The method sendMessage is used to send Service Chat message for a given chat with chid as Chat Id.
 @param chid The Chat Id of the chat.
 @param msg The message that has to be sent.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)sendMessageWithChatId:(NSString *)chid message:(NSString *)msg handler:(id<LDPEXEventHandler>)handler;

- (void)createTaskWithType:(LDPEXTaskTypes *)taskType andInfo:(id)info andHandler:(id<LDPEXEventHandler>)handler;

/**
 The method createChat is used to create a Service Chat message.
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to create a chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"].
 @param forceNew A BOOL value indicating whether a new chat should be created.
 @param join A BOOL Value indicating whether to join the chat.
 @param title The title of the new chat.
 @param isPrivate A Value of YES will disable the chat history storage for the chat, Pass NO to save the messages in the history.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)createChatWithRecipients:(id)recipants forceNew:(BOOL)forceNew join:(BOOL)join title:(NSString *)title handler:(id<LDPEXEventHandler>)handler isPrivate:(BOOL)isPrivate;
/**
 The method joinChat is used to join to an existing chat with the Chat id mentioned by chid.
 @param chid The Chat id of the chat to wish the user wishes to join.
 @param uname The zuid of the user.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 
 */
- (void)joinChatWithChatId:(NSString *)chid uname:(NSString *)uname handler:(id<LDPEXEventHandler>)handler;
/**
 The method addMember is used add a new member to the existing chat.
 @param chid The Chat id of the given chat.
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to add to the chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"].
 @param details Additional Details that can be sent along with the request.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)addMemberWithChatId:(NSString *)chid recipients:(id)recipants details:(NSDictionary *)details handler:(id<LDPEXEventHandler>)handler;
/**
 The method quitChat is used to quit from the existing chat.
 @param chid The chat id of the chat, from which the user intends to quit.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)quitChatWithChatId:(NSString *)chid handler:(id<LDPEXEventHandler>)handler;

/**
 The method deleteMember is used delete a member from the existing chat
 @param chid The Chat id of the given chat
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to remove from the chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"]
 @param details Additional Details that can be sent along with the request
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)deleteMemberWithChatId:(NSString *)chid recipients:(id)recipants details:(NSDictionary *)details handler:(id<LDPEXEventHandler>)handler;
/**
 The method sendInfoMessage is used to send status information about the user. The user might be in IDLE state, or HAS ENTERED TEXT or even TYPING a message.
 @param chid The Chat Id to which user's status should be sent.
 @param msg Any status message associated with this request. (Shouldn't be left empty)
 @param chatInfoMessage A ChatInfoMessage object which can be one of the following TYPING, IDLE or HAS_ENTERED_TEXT.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)sendInfoMessageWithChatId:(NSString *)chid msg:(id)msg chatInfoMessage:(ChatInfoMessage *)chatInfoMessage handler:(id<LDPEXEventHandler>)handler;
@end

/**
 PresenceGroupApi is used to invoke Presence chat related functions.
 It requires PresenceGroupHandler, which will receive incoming messages from the WMS server.
 */
@interface PresenceGroupApi : NSObject
/**
 This method is used to clear unread chat counts associated with the chat id.
 @param chatids Represents the chat id's for which the unread status must be cleared. You can supply multiple chat ids by separating them with comma. eg is @"chatid1,chatid2";
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)clearUnreadChatsWithChatids:(NSString *)chatids handler:(id<LDPEXEventHandler>)handler;
/**
 The method blockNotificationsForChatId is used to block or unblock push notifications for a specific chat indicated by the chid
 @param chid The Chat Id.
 @param interval To unblock specify @"0", else to block specify the number of minutes , for example to block for 5 mins , give the value as @"5".
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)blockNotificationsForChatId:(NSString *)chid withInterval:(NSString *)interval andHandler:(id<LDPEXEventHandler>)handler;
/**
 This method is used to join, as well as attach a session to a particular chat
 @param collabid The Chat id associated with the particular chat.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)attachAndJoinWithChatId:(NSString *)ChatId handler:(id<LDPEXEventHandler>)handler;
/**
 The method sendMessage is used to send Presence Chat message for a given chat with chid as Chat Id.
 @param chid The Chat Id of the chat.
 @param msg The message that has to be sent.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)sendMessageWithChatId:(NSString *)chid message:(NSString *)msg handler:(id<LDPEXEventHandler>)handler;

- (void)createTaskWithType:(LDPEXTaskTypes *)taskType andInfo:(id)info andHandler:(id<LDPEXEventHandler>)handler;


/**
 The method createChat is used to create a Presence group Chat message.
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to create a chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"].
 @param forceNew A BOOL value indicating whether a new chat should be created.
 @param join A BOOL Value indicating whether to join the chat.
 @param title The title of the new chat.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @param isPrivate A Value of YES will disable the chat history storage for the chat, Pass NO to save the messages in the history.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)createChatWithRecipients:(id)recipants forceNew:(BOOL)forceNew join:(BOOL)join title:(NSString *)title handler:(id<LDPEXEventHandler>)handler isPrivate:(BOOL)isPrivate;
/**
 The method joinChat is used to join to an existing chat with the Chat id mentioned by chid.
 @param chid The Chat id of the chat to wish the user wishes to join.
 @param uname The zuid of the user.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 
 */
- (void)joinChatWithChatId:(NSString *)chid uname:(NSString *)uname handler:(id<LDPEXEventHandler>)handler;
/**
 The method addMember is used add a new member to the existing chat.
 @param chid The Chat id of the given chat.
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to add to the chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"].
 @param details Additional Details that can be sent along with the request.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)addMemberWithChatId:(NSString *)chid recipients:(id)recipants details:(NSDictionary *)details handler:(id<LDPEXEventHandler>)handler;
/**
 The method quitChat is used to quit from the existing chat.
 @param chid The chat id of the chat, from which the user intends to quit.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)quitChatWithChatId:(NSString *)chid handler:(id<LDPEXEventHandler>)handler;
/**
 The method deleteMember is used delete a member from the existing chat
 @param chid The Chat id of the given chat
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to remove from the chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"]
 @param details Additional Details that can be sent along with the request
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)deleteMemberWithChatId:(NSString *)chid recipients:(id)recipants details:(NSDictionary *)details handler:(id<LDPEXEventHandler>)handler;
/**
 The method sendInfoMessage is used to send status information about the user. The user might be in IDLE state, or HAS ENTERED TEXT or even TYPING a message.
 @param chid The Chat Id to which user's status should be sent.
 @param msg Any status message associated with this request. (Shouldn't be left empty)
 @param chatInfoMessage A ChatInfoMessage object which can be one of the following TYPING, IDLE or HAS_ENTERED_TEXT.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)sendInfoMessageWithChatId:(NSString *)chid msg:(id)msg chatInfoMessage:(ChatInfoMessage *)chatInfoMessage handler:(id<LDPEXEventHandler>)handler;
@end

/**
 CustomChatApi is used to invoke Custom chat related functions.
 It requires LDCustomChatHandler, which will receive incoming messages from the WMS server.
 */
@interface CustomChatApi : NSObject
/**
 This method is used to clear unread chat counts associated with the chat id.
 @param chatids Represents the chat id's for which the unread status must be cleared. You can supply multiple chat ids by separating them with comma. eg is @"chatid1,chatid2";
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)clearUnreadChatsWithChatids:(NSString *)chatids handler:(id<LDPEXEventHandler>)handler;
/**
 The method blockNotificationsForChatId is used to block or unblock push notifications for a specific chat indicated by the chid
 @param chid The Chat Id.
 @param interval To unblock specify @"0", else to block specify the number of minutes , for example to block for 5 mins , give the value as @"5".
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)blockNotificationsForChatId:(NSString *)chid withInterval:(NSString *)interval andHandler:(id<LDPEXEventHandler>)handler;
/**
 This method is used to join, as well as attach a session to a particular chat
 @param collabid The Chat id associated with the particular chat.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)attachAndJoinWithChatId:(NSString *)ChatId handler:(id<LDPEXEventHandler>)handler;
/**
 The method sendMessage is used to send Custom Chat message for a given chat with chid as Chat Id.
 @param chid The Chat Id of the chat.
 @param msg The message that has to be sent.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)sendMessageWithChatId:(NSString *)chid message:(NSString *)msg handler:(id<LDPEXEventHandler>)handler;

- (void)createTaskWithType:(LDPEXTaskTypes *)taskType andInfo:(id)info andHandler:(id<LDPEXEventHandler>)handler;

/**
 The method createChat is used to create a Custom Chat message.
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to create a chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"].
 @param forceNew A BOOL value indicating whether a new chat should be created.
 @param join A BOOL Value indicating whether to join the chat.
 @param title The title of the new chat.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @param isPrivate A Value of YES will disable the chat history storage for the chat, Pass NO to save the messages in the history.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)createChatWithRecipients:(id)recipants forceNew:(BOOL)forceNew join:(BOOL)join title:(NSString *)title handler:(id<LDPEXEventHandler>)handler isPrivate:(BOOL)isPrivate;
/**
 The method joinChat is used to join to an existing chat with the Chat id mentioned by chid.
 @param chid The Chat id of the chat to wish the user wishes to join.
 @param uname The zuid of the user.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 
 */
- (void)joinChatWithChatId:(NSString *)chid uname:(NSString *)uname handler:(id<LDPEXEventHandler>)handler;
/**
 The method addMember is used add a new member to the existing chat.
 @param chid The Chat id of the given chat.
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to add to the chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"].
 @param details Additional Details that can be sent along with the request.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)addMemberWithChatId:(NSString *)chid recipients:(id)recipants details:(NSDictionary *)details handler:(id<LDPEXEventHandler>)handler;
/**
 The method quitChat is used to quit from the existing chat.
 @param chid The chat id of the chat, from which the user intends to quit.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)quitChatWithChatId:(NSString *)chid handler:(id<LDPEXEventHandler>)handler;
/**
 The method deleteMember is used delete a member from the existing chat
 @param chid The Chat id of the given chat
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to remove from the chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"]
 @param details Additional Details that can be sent along with the request
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)deleteMemberWithChatId:(NSString *)chid recipients:(id)recipants details:(NSDictionary *)details handler:(id<LDPEXEventHandler>)handler;
/**
 The method sendInfoMessage is used to send status information about the user. The user might be in IDLE state, or HAS ENTERED TEXT or even TYPING a message.
 @param chid The Chat Id to which user's status should be sent.
 @param msg Any status message associated with this request. (Shouldn't be left empty)
 @param chatInfoMessage A ChatInfoMessage object which can be one of the following TYPING, IDLE or HAS_ENTERED_TEXT.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)sendInfoMessageWithChatId:(NSString *)chid msg:(id)msg chatInfoMessage:(ChatInfoMessage *)chatInfoMessage handler:(id<LDPEXEventHandler>)handler;
@end

/**
 ChatApi is used to invoke chat related functions.
 It requires LDChatHandler, which will receive incoming messages from the WMS server.
 */
@interface ChatApi : NSObject
/**
 The method getBadgeWithHandler is used to get the current unread chats count. Should be used for syncing purposes.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)getBadgeWithHandler:(id<LDPEXEventHandler>)handler;
/**
 The method setLocation is used to set the current location of the user
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @param dict Hash table dict;
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)setLocation:(NSDictionary *)dict andHandler:(id<LDPEXEventHandler>)handler;
/**
 This method is used to clear unread chat counts associated with the chat id.
 @param chatids Represents the chat id's for which the unread status must be cleared. You can supply multiple chat ids by separating them with comma. eg is @"chatid1,chatid2";
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)clearUnreadChatsWithChatids:(NSString *)chatids handler:(id<LDPEXEventHandler>)handler;
/**
 The method blockNotificationsForChatId is used to block or unblock push notifications for a specific chat indicated by the chid
 @param chid The Chat Id.
 @param interval To unblock specify @"0", else to block specify the number of minutes , for example to block for 5 mins , give the value as @"5".
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)blockNotificationsForChatId:(NSString *)chid withInterval:(NSString *)interval andHandler:(id<LDPEXEventHandler>)handler;
/**
 This method is used to join, as well as attach a session to a particular chat
 @param collabid The Chat id associated with the particular chat.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)attachAndJoinWithChatId:(NSString *)ChatId handler:(id<LDPEXEventHandler>)handler;
/**
 The method setChatHistory is used to enable/disable chat history.
 @param enable If YES, further conversations will be stored else it won't get stored
 @param chid The chid for which chat history should be enabled/disabled.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 */

- (void)setChatHistory:(BOOL)enable chid:(NSString *)chid handler:(id<LDPEXEventHandler>)handler;

- (void)createGroupWithGroupId:(NSString *)groupId isPrivate:(BOOL)isPrivate handler:(id<LDPEXEventHandler>)handler;

/**
 The method sendMessage is used to send  Chat message for a given chat with chid as Chat Id.
 @param chid The Chat Id of the chat.
 @param msg The message that has to be sent.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @param msgid Optional messageid to uniquely identify a message
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)sendMessageWithChatId:(NSString *)chid message:(NSString *)msg handler:(id<LDPEXEventHandler>)handler andMsgId:(NSString *)msgId;

- (void)createTaskWithType:(LDPEXTaskTypes *)taskType andInfo:(id)info andHandler:(id<LDPEXEventHandler>)handler;

/**
 The method createChat is used to create a Chat message.
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to create a chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"].
 @param forceNew A BOOL value indicating whether a new chat should be created.
 @param join A BOOL Value indicating whether to join the chat.
 @param title The title of the new chat.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @param isPrivate A Value of YES will disable the chat history storage for the chat, Pass NO to save the messages in the history.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
- (void)createChatWithRecipients:(id)recipants forceNew:(BOOL)forceNew join:(BOOL)join title:(NSString *)title handler:(id<LDPEXEventHandler>)handler isPrivate:(BOOL)isPrivate;
/**
 The method joinChat is used to join to an existing chat with the Chat id mentioned by chid.
 @param chid The Chat id of the chat to wish the user wishes to join.
 @param uname The zuid of the user.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 
 */
- (void)joinChatWithChatId:(NSString *)chid uname:(NSString *)uname handler:(id<LDPEXEventHandler>)handler;
/**
 The method addMember is used add a new member to the existing chat.
 @param chid The Chat id of the given chat.
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to add to the chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"].
 @param details Additional Details that can be sent along with the request.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)addMemberWithChatId:(NSString *)chid recipients:(id)recipants details:(NSDictionary *)details handler:(id<LDPEXEventHandler>)handler;
/**
 The method quitChat is used to quit from the existing chat.
 @param chid The chat id of the chat, from which the user intends to quit.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)quitChatWithChatId:(NSString *)chid handler:(id<LDPEXEventHandler>)handler;
/**
 The method deleteMember is used delete a member from the existing chat
 @param chid The Chat id of the given chat
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to remove from the chat. For a group chat, format is @"zuid1,zuid2,zuid3" or you can supply an NSArray in the format [@"zuid1",@"zuid2",@"zuid3"]
 @param details Additional Details that can be sent along with the request
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)deleteMemberWithChatId:(NSString *)chid recipients:(id)recipants details:(NSDictionary *)details handler:(id<LDPEXEventHandler>)handler;
/**
 The method sendInfoMessage is used to send status information about the user. The user might be in IDLE state, or HAS ENTERED TEXT or even TYPING a message.
 @param chid The Chat Id to which user's status should be sent.
 @param msg Any status message associated with this request. (Shouldn't be left empty)
 @param chatInfoMessage A ChatInfoMessage object which can be one of the following TYPING, IDLE or HAS_ENTERED_TEXT.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException.
 @see PEXException.
 */
- (void)sendInfoMessageWithChatId:(NSString *)chid msg:(id)msg chatInfoMessage:(ChatInfoMessage *)chatInfoMessage handler:(id<LDPEXEventHandler>)handler;
/**
 The method getTranscripts is used to retrieve Chat conversations associtated with a particular chat id
 @param chid The Chat ID.
 @param ftime Specifies the from time from which the messages should be fetched.
 @param ttime Specifies the "To" time till which the messages have to be fetched. In case if from and to time are not known supply empty strings for both.
 @param lineslimit Specifies the number of lines.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
  @warning Throws PEXException.
 */
- (void)getTranscriptsWithChatId:(NSString *)chid fromTime:(NSString *)ftime toTime:(NSString *)ttime limit:(NSString *)lineslimit handler:(id<LDPEXEventHandler>)handler;
@end

