//
//  LDWmsService.h
//  LDZohoMessenger
//
//  Created by Balaji Sankar on 05/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 The LDWmsService class stores the list of product codes associated with each Zoho Product
 */
@interface LDWmsService : NSObject
/**
 The method initWithPrd is used to initialize a LDWmsService instance
 Usage :
     LDWmsService *wmsService=[[LDWmsService alloc] initWithPrd:@"BA"];
 @param productCode Product code of the service.
 @warning Use this method only for csez set up and the product code must be a valid entry present in the WmsServer
 */
- (id)initWithPrd:(NSString *)productCode;

- (NSString *)getPrd;
/**
 *  Zoho CRM
 */
+ (LDWmsService *)CRM;
/**
 * Zoho Mail
 */
+ (LDWmsService *)MAIL;
/**
 * Zoho Business
 */
+ (LDWmsService *)BUSSINESS;
/**
 * Zoho Projects
 */
+ (LDWmsService *)PROJECTS;
/**
 * Zoho Sheet
 */
+ (LDWmsService *)SHEET;
/**
 * Zoho Chat
 */
+ (LDWmsService *)CHAT;
/**
 * Zoho Writer
 */
+ (LDWmsService *)WRITER;
/**
 * Zoho Show
 */
+ (LDWmsService *)SHOW;
/**
 * Zoho Meeting
 */
+ (LDWmsService *)MEETING;
/**
 * Zoho Planner
 */
+ (LDWmsService *)PLANNER;
/**
 * Zoho Notebook
 */
+ (LDWmsService *)NOTEBOOK;
/**
 * Zoho Discussions
 */
+ (LDWmsService *)FORUMS;
/**
 * Zoho IAM
 */
+ (LDWmsService *)ACCOUNTS;
/**
 * Zoho Docs
 */
+ (LDWmsService *)EXPLORER;
/**
 * Zoho Share
 */
+ (LDWmsService *)SHARE;
/**
 * Zoho Calendar
 */
+ (LDWmsService *)CALENDAR;
/**
 * Zoho Contacts
 */
+ (LDWmsService *)CONTACTS;
/**
 * Zoho Creator
 */
+ (LDWmsService *)CREATOR;
/**
 * Zoho People
 */
+ (LDWmsService *)PEOPLE;
/**
 * Zoho Connects/Gadgets
 */
+ (LDWmsService *)CONNECTS;
/**
 * Zoho Store
 */
+ (LDWmsService *)STORE;
/**
 * Zoho Search
 */
+ (LDWmsService *)SEARCH;
/**
 * Zoho Firefox Addon
 */
+ (LDWmsService *)ZOHOFOX;
/**
 * Zoho Videos
 */
+ (LDWmsService *)VIDEOS;
/**
 * Zoho Wiki
 */
+ (LDWmsService *)WIKI;
/**
 * Zoho Support
 */
+ (LDWmsService *)SUPPORT;
/**
 * Zoho Campaigns
 */
+ (LDWmsService *)CAMPAIGN;
/**
 * Zoho Desktop Client (Adobe Air)
 */
+ (LDWmsService *)DESKTOP;
/**
 * Zoho Blogs
 */
+ (LDWmsService *)BLOGS;
/**
 * Zoho Mobile Sync
 */
+ (LDWmsService *)MOBILE;
/**
 * Zoho Remote Agent for Office Suite
 */
+ (LDWmsService *)REMOTE_AGENT;
/**
 * Zoho Telephony Adapter
 */
+ (LDWmsService *)TELE_ADAPTER;
/**
 * Zoho Issue Tracker
 */
+ (LDWmsService *)ISSUE_TRACKER;
/**
 * Service Desk Plus
 */
+ (LDWmsService *)SERVICE_DESK;
/**
 * Opmanager
 */
+ (LDWmsService *)OPMANAGER;
/**
 * Zoho Contacts Manager
 */
+ (LDWmsService *)CONTACTS_MANAGER;
/**
 * Zoho Pulse
 */
+ (LDWmsService *)PULSE;
/**
 * Zoho Intranet
 */
+ (LDWmsService *)INTRANET;
/**
 * Zoho Site 24*7
 */
+ (LDWmsService *)SITE24_7;
/**
 * Zoho Reach
 */
+ (LDWmsService *)REACH;
/**
 * Activity Collation Server
 */
+ (LDWmsService *)AC_SERVER;
/**
 * LiveDesk
 */
+ (LDWmsService *)LIVEDESK;
/**
 * Jabber Server
 */
+ (LDWmsService *)JABBER_SERVER;
/**
 * Payments
 */
+ (LDWmsService *)PAYMENTS;
/**
 * PIE
 */
+ (LDWmsService *)PIE;

/**
 * Zoho Home
 */
+ (LDWmsService *)HOME;

@end


