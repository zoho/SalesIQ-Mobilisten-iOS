//
//  PEXHeader.h
//  LDPEXLibrary
//
//  Created by Balaji Sankar on 25/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//
#import "LDWmsService.h"
#import "LDLibProperty.h"
//#import "LibProps.h"

@class PEX;
@class LDPEXResponse;
@class LDPEXError;
@class LDPEXEvent;
@class LDPEXTaskTypes;
@class LDPEXCredentials;

@class ServiceChatApi;
@class PresenceGroupApi;
@class CustomChatApi;
@class CollaborationApi;
@class LDChatHandler;
@class CollaborationHandler;
@class ChannelHandler;
@class TazHandler;
@class EntityChatHandler;
@class LDServiceChatHandler;
@class LDCustomChatHandler;
@class PresenceGroupHandler;
@class ContactsHandler;
@class LDMessageHandler;
@class ChatApi;
@class LDWmsService;
@class AVMessageHandler;
/*! \mainpage LDPEXLibrary Documentation
 *
 * \section Links
 *
 * LDPEXLibrary     LDZohoMessenger      LDZohoService
 *
 * LDPEXRequest     PEXException      LDPEXResponse
 *
 * LDChatHandler    LDWmsConfig         LDMessageInterface
 *
 * \section install_sec Installation
 *
 * 1) Download and extract WMSApi.zip
 
 2) After Extracting add the files present inside WMSApi/SupportingFiles/ to your project
 
 3) Add "libPEXLibrary.a" present inside WMSApi/lib folder to your project
 
 4) Extend LDChatHandler, CollaborationHandler, LDMessageHandler, LDServiceChatHandler, PresenceGroupHandler, LDCustomChatHandler, ContactsHandler depending upon your need
 
 5) Add the following frameworks to your project
 
 * i)CFNetwork.framework
 
 * ii)libicucore.dylib
 
 * iii)Foundation.framework
 
 * iv)CoreFoundation.framework
 
 6) In your code, enable the required wms configurations
 example:
 
 *    #import "LDWmsConfig.h"
 
      ….
 
      ….
 
      LDWmsConfig *config=[[LDWmsConfig alloc] init];
 
      [config enablePersonalPresence];
 
      [config enableOrgPresence];
 
      [config enableChatPresence];
 
 7) In case if you extend LDChatHandler and your derived interface name is TestClass then
 
      #import "PEXHeader.h"
 
      …
 
      ...
 
      TestClass *tc=[[TestClass alloc] init];
 
      [LDZohoMessenger setChatHandler:tc];
 
      // similarly for service related operations like Collaboration
 
      #import "LDZohoService.h"
 
      [LDZohoService setCollaborationHandler:<#(CollaborationHandler *)#>]
 
 8) Your interface must follow the protocol <LDConnectionHandler> (declared in LDPEXLibrary.h) and you must implement the methods declared in that protocol in your interface i.e., onConnect,onReconnect,onDisconnect and then register your interface to LDZohoMessenger with the following code
      [LDZohoMessenger setConnectionHandler:self];
 
 9) Each product has its unique Product code , which can be retrieved from LDWmsService.h
 
 10) In WMSProperties.plist , set your wms url for the key "wmsurl" default value is wss://mms.zoho.com
 
 11) Finally, start using LDZohoMessenger Api with the following code
 
 Create a LDPEXCredentials object based on your need.. There are two types of credentials with which you can connect - LDIAMAuthToken & LDIAMTicket. For LDIAMAuthToken, it is mandatory to set iscscope, else we'll throw PEXException if insufficient credentials are supplied.
 
      [LDZohoMessenger connect:credential :[LDWmsService CHAT] :[config getConfig]];
 
 The above method might throw PEXException if Improper credentials are supplied
 
 // variable config is mentioned in Step 6
 *
 12) To Create a LDPEXRequest,
 
 First import PEXHeader.h, LDWmsService.h
 
 We Recommend using a separate interface for a particular LDPEXRequest
 
 In that interface, in any of the methods, you can create a LDPEXRequest as follows
 
       LDPEXRequest *req=[[LDPEXRequest alloc] initRequestWithType:[LDWmsService product_name] andURL:theURL anddata:dict];
 
 Here "theURL" is a relative path from the product landing directory
 
 For example in order to call http://chat.zoho.com/mpchat.do , theURL will be just @"mpchat.do"
 
 "dict" refers to the dictionary of key-value pairs that you wish to send it to the wms server along with the PEX Request
 
       [req setMethod:@"POST"]; // The method can be set as @"GET", @"PUT", @"DELETE" etc signifying the HTTP counterpart.
 
       [req setHandler:self]; // Call this method so as to receive updates about the status of the LDPEXRequest. Your interface must obey LDPEXEventHandler protocol if you are calling this method
 
 
 Obey the protocol LDPEXEventHandler to get updates about the status of the pex request.
 
 then call
 
      @try {
 
      [LDPEXLibrary process:req];
 
      }
 
      @catch (PEXException *exception) {
 
 
 
      }
 
      @finally {}
 
 
 13) Similarly for calling API methods (for chat, collaboration, service chat, presence group, custom chat), invocation must be done as follows. API methods can be invoked by getting the respective instance of these interfaces from LDZohoMessenger, LDZohoService . Initializing the API's by yourself will return nil.
 
        @try {
 
        ChatInfoMessage *cim=[ChatInfoMessage TYPING];
        
        [[LDZohoMessenger CHAT] sendInfoMessage:chid andMsg:@"hello" andChatInfoMessage:cim andHandler:nil];
 
        }
 
        @catch (PEXException *exception) {
 
        }
        
        @finally {
        
        }
 
 
 */

@class LDPEXRequest;


/**
 The class LDLibProperty is used to refer an object present in WMSProperties.plist.
 */
@interface LDLibProperty : NSObject
/**
 The method is used to initialize the LDLibProperty object with a key of WMSProperties.plist.
 @param theKey Key present in WMSProperties.plist.
 */
- (id)initWithKey:(NSString *)theKey;
/**
 This method returns the Key .
 @return The initial key.
 */
- (NSString *)getKey;
@end

/**
 enum constants
 */
typedef enum {
    LDCHAT = 1,
    LDCOLLABORATION = 2,
    LDSERVICE_CHAT = 4,
    LDCUSTOM_CHAT = 5,
    LDPRESENCE_CHAT = 6,
    LDCHANNEL = 8,
    LDTAZ = 9,
    LDENTITYCHAT = 10,
}LDHandlerType;

/**
 The protocol LDConnectionHandler declares a set of methods with which the app is notified about any change in status of connection to the WMS Server
 */
@protocol LDConnectionHandler <NSObject>
/**
 The method onConnect is invoked after establishing a connection with the server and getting a valid wmsid and session id
 @param wmsid wmsid of the user
 @param sid Session id of the session
 @param dname Dname of the user.
 @param email email id of the user.
 @param depricated status of the application.
 @param messageObject complete details from server.
 */
- (void)onConnect:(NSString *)wmsid sid:(NSString *)sid andDname:(NSString *)dname andXA:(NSString *)xA andEmail:(NSString*)email andDepricated:(NSString*)depricated andMessage:(id)messageObject;
/**
 The method onReconnect is invoked when the following sequence of events occurs
 <li>Connection is lost due to network problems or other factors
 <li>Connection is once again established successfully/
 */
- (void)onReconnect;
/**
 The method onDisconnect is called when the connection to the server is lost
 @param manual The value will be YES if the client has requested the connection to terminate by calling the method LDPEXLibrary::disconnect else NO
 @param reason Reason behind the Disconnection.
 */
- (void)onDisconnect:(BOOL)manual andReason:(NSString *)reason;

/**
 The method onNetworkUp is invoked when connection established immediately after disconnected
 */
- (void)onNetworkUp;
@end

/**
 The protocol LDPEXEventHandler declares a set of call back methods that should be implemented by the receiver, which constructs an object of LDPEXEvent class to send a request to the WMS Server, so as to get updates about the status of LDPEXEvent
 */
@protocol LDPEXEventHandler <NSObject>
/**
 The method onComplete is invoked when a LDPEXEvent is completed
 @discussion Not to be confused with onSuccess. onSuccess is generated only when a Particular LDPEXRequest is sent successfully to the server and gets back a valid response. OnComplete will also be invoked in the case where the server returns an error response denoting that the request can't be processed
 @param response LDPEXResponse object from which the actual response can be extracted
 @param success Indicates that the particular event was successful in communicating to the server and received a valid response or not. if YES the event was successful else NO
 */
- (void)onComplete:(LDPEXResponse *)response isSuccess:(BOOL)success;
/**
 The method onProgress is invoked after receiving each chunk of a progressive response
 @param response LDPEXResponse object from which the actual response can be extracted
 */
- (void)onProgress:(LDPEXResponse *)response;
/**
 The method onProgress is invoked after sending a valid request to the server and getting a valid response for that particular reques
 @param response LDPEXResponse object from which the actual response can be extracted
 */
- (void)onSuccess:(LDPEXResponse *)response;
/**
 The method onFailure is invoked when a particular request receives an error response from the server
 @param error A LDPEXError object containing the error code and the associated error message
 */
- (void)onFailure:(LDPEXError *)error;
/**
 The method onBeforeSend is invoked before PEX forwards the request to the WMSServer
 @param event LDPEXEvent object, which is about to be forwarded to the WMSServer
 */
- (void)onBeforeSend:(LDPEXEvent *)event;
/**
 The method onTimeOut is invoked if a particular LDPEXRequest doesn't get a valid response within the stipulated time.
 @param event LDPEXEvent object, which was forwarded to the server
 */
- (void)onTimeOut:(LDPEXEvent *)event;
@end


/**
 LDPEXLibrary is the base class by which connection can be established with the WMS Server and it processes LDPEXRequest and forwards it to the WMS server
 */
@interface LDPEXLibrary : NSObject
/**
 The method connect is used to establish connection with the WMS server
 @param credential A valid credential is needed to establish a connection with the Wms server.
 @param productCode A LDWmsService object indicating the respective product.
 @param sessionConfig A session config value is needed to establish a connection with the server .
 @warning Throws PEXException
 @see PEXException
 */
+ (void)connect:(LDPEXCredentials *)credential :(LDWmsService *)productCode :(NSString *)sessionConfig;
/**
 Call this method to hold the connection
 */
+ (void)hold;
/**
 Call this method to resume the connection, after holding the connection.
 */
+ (void)resume;
/**
 Call this method to network unreachable.
 */

+ (void)setDclPfx:(NSString*)name;
/**
 Call this method to network unreachable.
 */
/**
Call this method to set Multi DC base domain
*/
+ (void)setDclBaseDomain:(NSString*)name;

+ (void)networkFailure;
/**
 This method, when invoked, closes the existing connection with the WMS server
 */
+ (void)disconnect;
/**
 The method setConnectionHandler method is used to register a delegate object which obeys LDConnectionHandler protocol. Once a delegate is registered it'll receive updates during any change in connection status
 @param delegate Must be a delegate object which should have implemented the LDConnectionHandler Protocol
 */
+ (void)setConnectionHandler:(id<LDConnectionHandler>)delegate;
/**
 The method process should be called so as to send a LDPEXRequest to the WMS server.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @param request A Valid LDPEXRequest object is needed so as to forward the request to the server.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)process:(LDPEXRequest *)request;
/**
 The method connectionStatus returns a BOOL to indicate that whether the connection to the WMS server is alive or not;
 */

+ (BOOL)connectionStatus;
/**
 The method getInsWithHandler is used to register with the WMS server to get ID , which points to a device
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)getInsWithHandler:(id<LDPEXEventHandler>)handler;
/**
 The method syncContactsWithData is used to get the contacts from the wms server. Data must be previous total contact list checksum and sum of individual contacts check sums
 @param dict The NSDictionary which contains the param values.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)syncContactsWithData:(NSDictionary *)dict andHandler:(id<LDPEXEventHandler>)handler;
/**
 The method getContactInfo is used to retrieve the contact details of the list of parameters  that are supplied as parameters
 @param dict The NSDictionary containing the contact type and comma separated zuids
 Format is 
 {
    @"type":<Contact type as NSString>
    @"ulist":<Comma Separated Zuids>
 }
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)getContactInfo:(NSDictionary *)dict andHandler:(id<LDPEXEventHandler>)handler;
/**
 The method registerUnsWithDict is used to register the device by passing device specific parameters and ins id.
 @param dict The NSDictionary containing param's necessary for registering.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */

+ (void)registerUnsWithDict:(NSDictionary *)dict andHandler:(id<LDPEXEventHandler>)handler;
/**
 The method unregisterUnsWithDict is used to unregister the device by passing device specific parameters and ins id
 @param dict The NSDictionary containing param's which was supplied during registration.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)unregisterUnsWithDict:(NSDictionary *)dict andHandler:(id<LDPEXEventHandler>)handler;
/**
 Use this method to pass the push notification message intended for LDPEXLibrary, from didReceiveRemoteNotification method of the app delegate.
 @param pushNotificationMessage NSDictionary containing push notification message.
*/
+ (void)onReceivingPushNotification:(NSDictionary *)pushNotificationMessage;

@end


/**
 Zoho Messenger is extended from LDPEXLibrary. Rather than being purely connection oriented , it helps in registering listeners for Chat, Contacts and Message
 */
@interface LDZohoMessenger : LDPEXLibrary

/** 
 The method CHAT creates an instance of the class ChatApi and returns it. This object can be used for further communication with the WMS Server
 @return ChatApi instance
 */
+ (ChatApi *)CHAT;
/**
 The method setChatHandler is used to register a class which has extended (inherited from) LDChatHandler class so as to receive incoming messages intended for Chat
 @param handler A class which has extended(inherited from) LDChatHandler
 */
+ (void)setChatHandler:(LDChatHandler *)handler;
/**
 The method setContactsHandler is used to register a class which has extended (inherited from) ContactsHandler class so as to receive incoming messages intended for Contacts
 @param handler A class which has extended(inherited from) ContactsHandler
 */
+ (void)setContactsHandler:(ContactsHandler *)handler;
/**
 The method setMessageHandler is used to register a class which has extended (inherited from) LDMessageHandler class so as to receive incoming messages intended for Message
 @param handler A class which has extended(inherited from) Message
 */
+ (void)setMessageHandler:(LDMessageHandler *)handler;
/**
 The method setAVMessageHandler is used to register a class which has extended (inherited from) AVMessageHandler class so as to receive incoming messages relared to audio call
 @param handler A class which has extended(inherited from) Message
 */

+ (void)setAVMessageHandler:(AVMessageHandler *)handler;

/**
 The method sendInfoMessage is used to send Info Message across the products.
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to send an information message. 
 @param msg The message that needs to be passed.
 @param handler Handler can be any object which obeys LDPEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)sendInfoMessage:(NSString *)recipants andMsg:(id)msg andHandler:(id<LDPEXEventHandler>)handler;

@end

/**
 LDZohoService is an extension to LDPEXLibrary that  deals with chat related features
 */
@interface LDZohoService : LDPEXLibrary

/**
 The method SERVICECHAT creates an instance of the class ServiceChatApi and returns it. This object can be used for further communication with the WMS Server
 @return ServiceChatApi instance
 */
+ (ServiceChatApi *)SERVICECHAT;
/**
 The method PRESENCEGROUP creates an instance of the class PresenceGroupApi and returns it. This object can be used for further communication with the WMS Server
 @return PresenceGroupApi instance
 */
+ (PresenceGroupApi *)PRESENCEGROUP;
/**
 The method CUSTOMCHAT creates an instance of the class CustomChatApi and returns it. This object can be used for further communication with the WMS Server
 @return CustomChatApi instance
 */
+ (CustomChatApi *)CUSTOMCHAT;
/**
 The method COLLABORATION creates an instance of the class CollaborationApi and returns it. This object can be used for further communication with the WMS Server
 @return CollaborationApi instance
 */
+ (CollaborationApi *)COLLABORATION;

/**
The method setCollaborationHandler is used to register a class which has extended (inherited from) CollaborationHandler class so as to receive incoming messages intended for collaboration
@param handler A class which has extended(inherited from) CollaborationHandler
 */
+ (void)setCollaborationHandler:(CollaborationHandler *)handler;

/**
 The method setCollaborationHandler is used to register a class which has extended (inherited from) ChannelHandler class so as to receive incoming messages intended for collaboration
 @param handler A class which has extended(inherited from) ChannelHandler
 */
+ (void)setLDChannelHandler:(ChannelHandler *)handler;

/**
 The method setTazHandler is used to register a class which has extended (inherited from) TazHandler class so as to receive incoming messages intended for taz messages
 @param handler A class which has extended(inherited from) TazHandler
 */
+ (void)setTazHandler:(TazHandler *)handler;

/**
 The method setEntityChatHandler is used to register a class which has extended (inherited from) EntityChatHandler class so as to receive incoming messages intended for entity chat messages
 @param handler A class which has extended(inherited from) EntityChatHandler
 */
+ (void)setEntityChatHandler:(EntityChatHandler *)handler;

/**
 The method setServiceChatHandler is used to register a class which has extended (inherited from) LDServiceChatHandler class so as to receive incoming messages intended for ServiceChat
 @param handler A class which has extended(inherited from) LDServiceChatHandler
 */
+ (void)setServiceChatHandler:(LDServiceChatHandler *)handler;
/**
 The method setPresenceGroupHandler is used to register a class which has extended (inherited from) PresenceGroupHandler class so as to receive incoming messages intended for PresenceGroup
 @param handler A class which has extended(inherited from) PresenceGroupHandler
 */
+ (void)setPresenceGroupHandler:(PresenceGroupHandler *)handler;
/**
 The method setCustomChatHandler is used to register a class which has extended (inherited from) LDCustomChatHandler class so as to receive incoming messages intended for CustomChat
 @param handler A class which has extended(inherited from) LDCustomChatHandler
 */
+ (void)setCustomChatHandler:(LDCustomChatHandler *)handler;
//@end

@end
/**
 The class LDUserStatus holds status code and status message.
 */
@interface LDUserStatus : NSObject
/**
 The method setScode is used to set the status code.
 */
- (void)setScode:(NSString *)scode;
/**
 The method setSmsg is used to set the status message.
 */
- (void)setSmsg:(NSString *)smsg;
/**
 The method getScode returns the status code.
 * @return Returns Status code.
 */
- (NSString *)getScode;
/**
 The method getScode returns the status code.
 * @return Returns Status code.
 */
- (NSString *)getSmsg;

@end

/**
 LDPEXResponse is a class that constructs the response object using the response given in the param.
 */

@interface LDPEXResponse : NSObject
{
    int readystate;
    NSObject *response;
    NSMutableString *responseText;
    NSObject *responseObject;
    BOOL progressive;
}
@property(readonly) int readystate;
/**
 Returns the current response.
 */
@property(readonly) NSObject *response;
/**
 Returns the response object as a string.
 */
@property(readonly, strong) NSMutableString *responseText;
/**
 Returns the total response.
 */
@property(readonly) NSObject *responseObject;
/**
 Indicates whether the response is progressive or not.
 */
@property(readonly) BOOL progressive;
@end



/**
 LDPEXEvent is a base class which is used to send message to the wms server.
 */
@interface LDPEXEvent : NSObject
{
    id <LDPEXEventHandler> handler;
    
}
/**
 handler should implement LDPEXEventHandler Protocol so as to get updates about the status of the pex event.
 */
@property id <LDPEXEventHandler> handler;
/**
 The method is used to set cookie values to the LDPEXEvent message
 */
- (void)setCookie:(NSString *)cookie;
/**
 The method is used to add header values to the request
 @param key Key present in the header
 @param value value to be added for the key.
 @warning Throws PEXException if the key doesn't have the prefix @"X-"
 */
- (void)addHeader:(NSString *)key andValue:(NSString *)value;
/**
 The method is used to add configuration details to the Request
 @param key The key to denote the configuration 
 @param value Value is passed as LDLibProperty object 
 @warning Throws PEXException if the key begins with @"_" or invalid LDLibProperty value is supplied
 */
- (void)addData:(NSString *)key andValue:(LDLibProperty *)value;
@end

/**
 LDPEXRequest is extended from LDPEXEvent and it is used to send requests to the WMS Server
 */
@interface LDPEXRequest : LDPEXEvent
{
    NSString *method;
}

/**
 Specifies the method 
 For example @"POST".@"GET" etc.
 */
@property NSString *method;
/**
 This method creates a pex request for the given product with the relative url and request data.
 @param prd The Specific Zoho Product
 @param theURL url relative from the product home directory. For example to access chat.zoho.com/mpchat.do the value of theURL should be mpchat.do
 @param thedata The form data , that is to be sent with the request
 */
- (id)initRequestWithType:(LDWmsService *)theprd andURL:(NSString *)theURL anddata:(id)thedata;
/**
 This method creates a pex request for the given product with the relative url and request data abd indicate that it is a progressive request.
 @param prd The Specific Zoho Product
 @param theURL url relative from the product home directory. For example to access chat.zoho.com/mpchat.do the value of theURL should be mpchat.do
 @param thedata The form data , that is to be sent with the request
 */
- (id)initProgRequestWithType:(LDWmsService *)theprd andURL:(NSString *)theURL anddata:(id)thedata;
/**
 This method is used to add Cookie key-value pairs to the request.
 */
- (void)addCookie:(NSString *)key andValue:(NSString *)value;

@end

@interface LDPEXTaskTypes : NSObject
{
    LDPEXTaskTypes *CHAT_MSG;
    LDPEXTaskTypes *ANNON_CHAT_MSG;
    LDPEXTaskTypes *CREATE_CHAT;
    LDPEXTaskTypes *ADD_MEMBER;
    LDPEXTaskTypes *JOIN_CHAT;
    LDPEXTaskTypes *DELETE_MEMBER;
    LDPEXTaskTypes *QUIT_CHAT;
    LDPEXTaskTypes *CHAT_INFO_MSG;
    LDPEXTaskTypes *INFO_MSG;
    LDPEXTaskTypes *GET_TRANSCRIPTS;
    LDPEXTaskTypes *CREATE_GROUP_CHAT;
    LDPEXTaskTypes *SET_HISTORY;
    LDPEXTaskTypes *GET_INSID;
    LDPEXTaskTypes *REGISTER_UNS;
    LDPEXTaskTypes *ATTACHANDJOIN;
    LDPEXTaskTypes *CLEAR_UNREAD_CHATS;
    LDPEXTaskTypes *SENDATTMSG;
    LDPEXTaskTypes *SETUSERSTATUS;
    LDPEXTaskTypes *SETPNSLEEP;
    LDPEXTaskTypes *UNREGISTER_UNS;
    LDPEXTaskTypes *GETCONTACTINFO;
    LDPEXTaskTypes *BLOCKCHATNOTIFICATIONS;
    LDPEXTaskTypes *SYNC_CONTACTS;
    LDPEXTaskTypes *SET_LOCATION;
    LDPEXTaskTypes *GET_BADGE;
}
@property(readonly)LDPEXTaskTypes *GET_BADGE;
@property(readonly)LDPEXTaskTypes *SET_LOCATION;
@property(readonly)LDPEXTaskTypes *SYNC_CONTACTS;
@property(readonly)LDPEXTaskTypes *BLOCKCHATNOTIFICATIONS;
@property(readonly)LDPEXTaskTypes *UNREGISTER_UNS;
@property(readonly)LDPEXTaskTypes *CLEAR_UNREAD_CHATS;
@property(readonly)LDPEXTaskTypes *SENDATTMSG;
@property(readonly)LDPEXTaskTypes *SETUSERSTATUS;
@property(readonly)LDPEXTaskTypes *SETPNSLEEP;
@property(readonly)LDPEXTaskTypes *ATTACHANDJOIN;
@property(readonly)LDPEXTaskTypes *REGISTER_UNS;
@property(readonly)LDPEXTaskTypes *GET_INSID;
@property(readonly)LDPEXTaskTypes *GET_TRANSCRIPTS;
@property(readonly)LDPEXTaskTypes *CHAT_MSG;
@property(readonly)LDPEXTaskTypes *ANNON_CHAT_MSG;
@property(readonly)LDPEXTaskTypes *CREATE_CHAT;
@property(readonly)LDPEXTaskTypes *ADD_MEMBER;
@property(readonly)LDPEXTaskTypes *JOIN_CHAT;
@property(readonly)LDPEXTaskTypes *DELETE_MEMBER;
@property(readonly)LDPEXTaskTypes *QUIT_CHAT;
@property(readonly)LDPEXTaskTypes *CHAT_INFO_MSG;
@property(readonly)LDPEXTaskTypes *INFO_MSG;
@property(readonly)LDPEXTaskTypes *CREATE_GROUP_CHAT;
@property(readonly)LDPEXTaskTypes *SET_HISTORY;
@property(readonly)LDPEXTaskTypes *GETCONTACTINFO;

+ (LDPEXTaskTypes *)getSharedInstance;

@end

/**
 The class LDPEXErrorCodes provides a way of categorizing the errors, such that each error code denotes a particular type of error.
 */
@interface LDPEXErrorCodes : NSObject
/**
 Indicates No connection is Available
 @return Corresponding Error Code
 */
+ (int)NO_CONNECTION;
/**
 Indicates that the operation is not supported
 @return Corresponding Error Code
 */
+ (int)NOT_SUPPORTED;
/**
 Indicates that there is an error in the remote server
 @return Corresponding Error Code
 */
+ (int)REMOTE_SERVER_ERROR;
/**
 Indicates that invalid data is passed as an argument 
 @return Corresponding Error Code
 */
+ (int)INVALID_DATA;
/**
 Indicates that there is decryption error generated in the server side when processing the request
 @return Corresponding Error Code
 */
+ (int)DECRYPTION_ERROR;
/**
 Indicates that the receiver (PEX) is in a invalid state to process the request
 @return Corresponding Error Code
 */
+ (int)INVALID_STATE;
/**
 Indicates that the receiver (PEX) is supplied with invalid credential
 @return Corresponding Error Code
 */
+ (int)INVALID_CREDENTIAL;
/**
  Indicates that the receiver(PEX) has received invalid data for PEX event.
 @return Corresponding Error Code
 */
+ (int)INVALID_PEX_EVENT_DATA;
/**
 Returns the message associated with the particular error code
 @param code The error code
 @return The message corresponding to 'code'
 */
+ (NSString *)getMessage:(int)code;

@end

/**
 LDPEXError is a class that wraps around a particular PEXErrorCode and it's corresponding error message
 */
@interface LDPEXError : NSObject
{
    NSNumber *code;
    NSString *msg;
    NSDictionary *error;
}
/**
 PEXErrorCode in NSNumber format
 */
@property NSNumber *code;
/**
 Stores the error message
 */
@property NSString *msg;
/**
 Stores the remote error message
 */
@property NSDictionary *error;
@end

/**
 LDPEXCredentials class is used for authenticating a request to the WMS server.
 */
@interface LDPEXCredentials : NSObject
{
   
    NSString *username;
    NSString *displayName;
    NSString *zuid;
    NSString *osCode;
    
}
@property NSString *zuid;
@property NSString *osCode;
/**
 Stores the username
 */
@property NSString *username;
/**
 stores the display name
 */
@property NSString *displayName;
/**
 Assigns a NSDictionary of key value pairs to information related to this credential
 @param theinfo A hash map of key value pairs
 */
- (void)setInfo:(NSDictionary *)theinfo;
/**
 Sets the user Agent for the credential.
 @discussion Examples of User-Agent are @"IOS".
 @param userAgent User-Agent Value.
 */
- (void)setUserAgent:(NSString *)userAgent;
/**
 Stores the user's IP Address.
 @param ip The IP address of the current user.
 */
- (void)setIp:(NSString *)ip;
/**
 The method setInsid is used to inform WMS Server that this device has a INSID associated with it. This method should be called before calling "connect" method
 @param insid The insid to be provided to WMS Server.
 */
- (void)setInsid:(NSString *)insid;
/**
 The method addInfo adds a key value pair to the credentials information.
 @discussion Not to be confused with setInfo, which sets the entire HashMap as the Credentials. Information
 */
- (void)addInfo:(NSString *)thekey andValue:(NSString *)value;
/**
 The method getAddInfo is used to retrieve a Credential Information associated with that particular key.
 */
- (id)getAddInfo:(NSString *)key;
- (void)setUserZuid:(NSString *)wmsid;
- (void)setUserOscode:(NSString *)oscode;
- (void)setPnsKey:(NSString *)pKey;

@end

/**
 The class LDIAMTicket is extended from LDPEXCredentials.
 */
@interface LDIAMTicket : LDPEXCredentials
/**
 The method initWithTicket initializes the LDPEXCredentials with LDIAMTicket.
 @param theTicket LDIAMTicket.
 */
- (id)initWithTicket:(NSString *)theTicket;
@end

/**
 The class LDIAMAuthToken is extended from LDPEXCredentials.
 */
@interface LDIAMAuthToken : LDPEXCredentials
/**
 The method initWithToken initializes the LDPEXCredentials with IAM Authentication token.
 @param theToken IAM authentication token.
 */
- (id)initWithToken:(NSString *)theToken;
/**
 The method setISCScope is used to set ISC scope.
 @param iscscope ISCscope.
 */
- (void)setISCScope:(NSString *)iscscope;
@end


/**
 The class LDWMSAnnonUser is extended from LDPEXCredentials.
 */
@interface LDWMSAnnonUser : LDPEXCredentials
/**
 The method initWithUserName andDname initializes the LDPEXCredentials with a valid username and dname
 @param username name of the user.
 @param dispname dname of the user.
 */
- (id)initWithUserName:(NSString *)username andDname:(NSString *)dispname;
@end


/**
 The class LDIAMSSTicket is extended from LDPEXCredentials.
 */
@interface LDIAMSSTicket : LDPEXCredentials
/**
 The method initWithSSTicket initializes the LDPEXCredentials with SSTicket.
 @param ticket SSTicket.
 */
- (id)initWithSSTicket:(NSString *)ticket;
/**
 The method setDomain is used to set the domain
 @param domain domain name.
 */
- (void)setDomain:(NSString *)domain;
@end


/**
 The class LDPEXAuthToken is extended from LDPEXCredentials.
 */
@interface LDPEXAuthToken : LDPEXCredentials
/**
 The method initWithToken initializes the LDPEXCredentials with PEX Access key.
 @param accessKey PEX Access Key.
 */
- (id)initWithToken:(NSString *)accessKey;
/**
 The method setBundleId is used to set the bundle identifier
 @param bundleid Bundle Identifier.
 */
- (void)setBundleId:(NSString *)bundleid;

@end


