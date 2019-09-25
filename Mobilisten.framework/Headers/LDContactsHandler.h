//
//  ContactsHandler.h
//  LDZohoMessenger
//
//  Created by Balaji Sankar on 25/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 ContactsHandler is a class for providing the notifications of change in user's contacts.
 */
@interface ContactsHandler : NSObject
/**
 The method onAdd is invoked when a contact is added.
 @param  zuid Zuid of the contact.

 @param scode Status code of the contact.
 @param statusmsg status message of the contact.
 @param dname dname of the contact.
 @param emailid email id of the contact.
  @param stype stype of the contact.
 */
- (void)onAdd:(NSString *)zuid dname:(NSString *)dname scode:(NSString *)scode statussg:(NSString *)statusmsg emailid:(NSString *)emailid stype:(NSString *)stype;
/**
 The method onDelete is invoked when a contact is deleted.
 @param  zuid Zuid of the contact.

 @param scode Status code of the contact.
 @param statusmsg status message of the contact.
 @param dname dname of the contact.
 @param emailid email id of the contact.
  @param stype stype of the contact.
 */
- (void)onDelete:(NSString *)zuid dname:(NSString *)dname scode:(NSString *)scode statussg:(NSString *)statusmsg emailid:(NSString *)emailid stype:(NSString *)stype;
/**
 The method onInvite is invoked when a contact is invited.
 @param  zuid Zuid of the contact.

 @param scode Status code of the contact.
 @param statusmsg status message of the contact.
 @param dname dname of the contact.
 @param emailid email id of the contact.
  @param stype stype of the contact.
 */
- (void)onInvite:(NSString *)zuid dname:(NSString *)dname scode:(NSString *)scode statussg:(NSString *)statusmsg emailid:(NSString *)emailid stype:(NSString *)stype;
/** 
 The method onUserAccept is invoked when the present user who has registered with WMS accepts a contact request.
 @param  zuid Zuid of the contact.

 @param scode Status code of the contact.
 @param statusmsg status message of the contact.
 @param dname dname of the contact.
 @param emailid email id of the contact.
  @param stype stype of the contact.
 */
- (void)onUserAccept:(NSString *)zuid dname:(NSString *)dname scode:(NSString *)scode statussg:(NSString *)statusmsg emailid:(NSString *)emailid stype:(NSString *)stype;
/**
 The method onAccept is invoked when a contact request is accepted.
 @param  zuid Zuid of the contact.

 @param scode Status code of the contact.
 @param statusmsg status message of the contact.
 @param dname dname of the contact.
 @param emailid email id of the contact.
  @param stype stype of the contact.
 */
- (void)onAccept:(NSString *)zuid dname:(NSString *)dname scode:(NSString *)scode statussg:(NSString *)statusmsg emailid:(NSString *)emailid stype:(NSString *)stype;
/**
 The method onRemove is invoked when a contact request is deleted.
 @param  zuid Zuid of the contact.

 @param scode Status code of the contact.
 @param statusmsg status message of the contact.
 @param emailid email id of the contact.
 @param dname dname of the contact.
  @param stype stype of the contact.
 */
- (void)onRemove:(NSString *)zuid dname:(NSString *)dname scode:(NSString *)scode statussg:(NSString *)statusmsg emailid:(NSString *)emailid stype:(NSString *)stype;
/**
 The method onStatusChange is invoked when a contact changes updates it's status.
 @param  zuid Zuid of the contact.

 @param scode Status code of the contact.
 @param statusmsg status message of the contact.
 @param dname dname of the contact.
 @param stype stype of the contact.
 */
- (void)onStatusChange:(NSString *)zuid dname:(NSString *)dname scode:(NSString *)scode statussg:(NSString *)statusmsg stype:(NSString *)stype;
/**
 The method onUpdate is invoked everytime after registering to WMS. Contact details are sent in this method.
 @param list List of users who have updated their contact details
 */
- (void)onUpdate:(NSDictionary *)list;
- (void)onReInit:(NSDictionary *)list;
/**
 The method returns the checksum of the entire contact list.
 @param checkSum The checkSum of the entire contact list.
 */
- (void)contactsCheckSum:(NSString *)checkSum;
@end
