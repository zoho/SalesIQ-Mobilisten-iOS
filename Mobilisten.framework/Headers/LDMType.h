//
//  MType.h
//  LDZohoMessenger
//
//  Created by Balaji Sankar on 05/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MType : NSObject
+ (int)ZOHO_MSG;
+ (int)WM_MSG;
+ (int)WM_CROSSPRD_MSG;
+ (int)WM_JOIN;
+ (int)WM_QUIT;
+ (int)WM_TXT_MSG;
+ (int)WM_NFY_USERSTATUS;
+ (int)WM_NFY_MEMBERADD;
+ (int)WM_NFY_MEMBERDELETE;
+ (int)WM_NFY_INFOMSG;
+ (int)WM_NFY_TITLECHANGE;
+ (int)WM_ATT_MSG;
+ (int)WM_NFY_INVITE;
+ (int)WM_NFY_REMOVE;
+ (int)WM_STATUS_CHANGE;
+ (int)WM_CONTACTS_UPDATE;
+ (int)WM_CONTACT_INFO;
+ (int)WM_CONTACT_CHECKSUM;
+ (int)WM_AV_MSG;
+ (int)WM_ACS_MSG;
+ (int)WM_CONTACTS_MSG;
+ (int)WM_NFY_TYPING;
+ (int)WM_NFY_IDLE;
+ (int)WM_NFY_TXTENTERED;
+ (int)WM_AUTHENTICATION_FAILED;
//+ (int)WM_OAUTH_EXPIRED;
+ (int)WM_SERVER_DISCONNECT;
+ (int)WM_NETWORK_UP;
+ (int)WM_RE_REGISTER;
+ (int)WM_RECONNECT;
@end
