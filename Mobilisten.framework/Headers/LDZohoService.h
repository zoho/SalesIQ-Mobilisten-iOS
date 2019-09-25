//
//  LDZohoService.h
//  LDZohoMessenger
//
//  Created by Balaji Sankar on 25/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//


#import "LDPEXLibrary.h"



/**
 The method setCollaborationHandler is used to register a class which has extended (inherited from) CollaborationHandler class so as to receive incoming messages intended for collaboration
 @param handler A class which has extended(inherited from) CollaborationHandler
 */
//+ (void)setCollaborationHandler:(CollaborationHandler *)handler;
/**
 The method setServiceChatHandler is used to register a class which has extended (inherited from) LDServiceChatHandler class so as to receive incoming messages intended for ServiceChat
 @param handler A class which has extended(inherited from) LDServiceChatHandler
 */
//+ (void)setServiceChatHandler:(LDServiceChatHandler *)handler;
/**
 The method setPresenceGroupHandler is used to register a class which has extended (inherited from) PresenceGroupHandler class so as to receive incoming messages intended for PresenceGroup
 @param handler A class which has extended(inherited from) PresenceGroupHandler
 */
//+ (void)setPresenceGroupHandler:(PresenceGroupHandler *)handler;
/**
 The method setCustomChatHandler is used to register a class which has extended (inherited from) LDCustomChatHandler class so as to receive incoming messages intended for CustomChat
 @param handler A class which has extended(inherited from) LDCustomChatHandler
 */
//+ (void)setCustomChatHandler:(LDCustomChatHandler *)handler;
//@end
