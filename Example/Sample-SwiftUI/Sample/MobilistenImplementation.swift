//
//  MobilistenImplementation.swift
//  Sample
//
//  Created by Sivasankar on 26/07/23.
//

import Mobilisten
import SwiftUI

class MobilistenImplementation {
    
    /**
     Generating App and Access key for IOS:
     To generate App and Access key for IOS, navigate to Settings > Brands > Installation > IOS > Enter your bundle ID and click on Generate.
     
     [Learn more.](https://www.zoho.com/salesiq/help/developer-guides/ios-mobile-sdk-2.0.html#:~:text=How%20to%20get%20the%20app%20and%20access%20key%3F)
     */
    class func initializeSDK(appKey: String, accessKey: String) {
        ZohoSalesIQ.initWithAppKey(appKey, accessKey: accessKey) { success in
        }
    }
    
    /**
     This API is used to open the support UI for use in the custom launcher view incase the default launcher provided by Mobilisten is hidden. This API is also used to open any specific chat window by providing the  referenceID  of the chat. The  referenceID  for a chat can be obtained from various APIs, including the ZohoSalesIQ.Chat.getList()  API
     
     [.Chat.show()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-show-v3.html)
     */
    
    class func openSalesIQChat() {
        ZohoSalesIQ.Chat.show()
        
    }
    
    /**
     This API can be used to control the visibility of the SDK Launcher. You can either choose to show or hide it. The Launcher is hidden by default.
     
     [.showLauncher()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-window-launcher-v3.html)
     */
    
    
    class func showLauncher(_ status: Bool) {
        ZohoSalesIQ.showLauncher(status)
    }
    
    /**
     This API lets you toggle the function of various components in Mobilisten
     
     [.Chat.setVisibility()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-set-visibility-v3.html)
     */
    
    class func setAttenderImageVisibility(_ status: Bool) {
        ZohoSalesIQ.Chat.setVisibility(.attenderImageOnLauncher, visible:status)
    }
    
    /**
     This API allows you to register a user using a unique ID with the SalesIQ SDK. If your application has login and logout life cycles, you can enroll your visitor and their activity in the SDK will be synchronized across multiple platforms.
     
     [.registerVisitor()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-register-visitor-v3.html)
     */
    
    class func register(uniqueID:String,completion: @escaping () -> Void) {
        ZohoSalesIQ.registerVisitor(uniqueID) { success in
            completion()
        }
    }
    
    /**
     This API allows you to unregister a user once they are registered using the .registerVisitor() API. If your application has login and logout life cycles, you can unregister a visitor during a session logout which would clear any data the SDK may hold such as past conversations had by the registered user.
     
     [.unregisterVisitor()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-unregister-visitor-v3.html)
     */
    
    class func unRegister(completion: @escaping () -> Void) {
        ZohoSalesIQ.unregisterVisitor { success in
            completion()
        }
    }
    
    /**
     This API lets you configure the language preference for the embedded chat widget.
     
     [.Chat.setLanguage()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-language-v3.html)
     */
    
    class func setLanguage(_ selection: Int) {
        switch selection {
        case 0:
            ZohoSalesIQ.Chat.setLanguage(.english)
        case 1:
            ZohoSalesIQ.Chat.setLanguage(.french)
        case 2:
            ZohoSalesIQ.Chat.setLanguage(.japanese)
        default:
            break
        }
    }
    /**
     This API lets you initiate a trigger upon an action, like clicking on a button in your mobile app.
     
     shouldOpenChatWindow:
     
     When the shouldOpenChatWindow parameter is set to true, the Zoho SalesIQ’s chat window in the user's app will open directly when the API is triggered.
     
     [.Tracking.setCustomAction()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-tracking-action-v3.html)
     */
    
    class func setCustomAction(name:String) {
        ZohoSalesIQ.Tracking.setCustomAction(name,shouldOpenChatWindow: true)
    }
    
    
    /**
     This API allows you to programmatically get a list of all the departments that have been associated with the brand in which Mobilisten is configured.
     The API provides an array of instances of the SIQDepartment class to represent the list of departments asynchronously.
     
     [.Chat.getDepartments()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-get-departments-v3.html)
     */
    
    class func departmentlist(completion:DepartmentListFetchCompletionBlock?) {
        ZohoSalesIQ.Chat.getDepartments(completion: completion)
    }
    
    /**
     This API lets you set the name of the visitor
     
     [.Visitor.setName()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-visitor-name-v3.html)
     */
    class func setVisitorName(_ name: String) {
        ZohoSalesIQ.Visitor.setName(name)
    }
    
    /**
     This API lets you set the email of the visitor
     
     [.Visitor.setEmail()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-visitor-email-v3.html)
     */
    class func setVisitorEmail(_ email: String) {
        ZohoSalesIQ.Visitor.setEmail(email)
    }
    
    /**
     This API lets you set the contact number of the visitor
     
     [.Visitor.setContactNumber()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-visitor-contact-v3.html)
     */
    class  func setVisitorContactNumber(_ contact: String) {
        ZohoSalesIQ.Visitor.setContactNumber(contact)
    }
    
    /**
     This API lets you configure a pre-defined question that will automatically be sent out to the operators of your firm when the visitor clicks on the chat widget to initiate a chat.
     
     [.Chat.startChat()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-startchat-v3.html)
     */
    class func startChat(_ question: String) {
        ZohoSalesIQ.Chat.startChat(question: question)
    }
}
