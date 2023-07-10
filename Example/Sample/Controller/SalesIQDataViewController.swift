//
//  SalesIQDataViewController.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 09/04/23.
//

import UIKit
import Mobilisten

class SalesIQDataViewController: UIViewController {
    
    let scrollView: SIQCustomScrollView = {
        let scrollView = SIQCustomScrollView()
        scrollView.translatesAutoresizingMaskIntoConstraints = false
        return scrollView
    }()
    
    let contentView: UIView = {
      let view = UIView()
        view.translatesAutoresizingMaskIntoConstraints = false
        return view
    }()
    
    let endChatButton = SIQCustomButton(title: "End chat")
    let openChatViewButton = SIQCustomButton(title: "Open chat view")
    let getArticlesButton = SIQCustomButton(title: "Get all articles")
    let chooseConversationButton = SIQCustomButton(title: "Choose conversation type")
    let fetchAttenderImage = SIQCustomButton(title: "Fetch attender image")
    
    let chatIDTextField = SIQCustomTextField(placeholder: "Enter chat ID", keyboardType: .numberPad)
    let attenderIDTextField = SIQCustomTextField(placeholder: "Enter attender ID", keyboardType: .numberPad)
    
    let chatTypes: [String: ChatStatus] = ["All": .all, "Triggered": .triggered, "Proactive": .proactive, "Connected": .connected, "Waiting": .waiting, "Missed": .missed, "Closed": .closed, "Ended": .ended]
    
    var horizontalStackView: SIQCustomStackView {
        let stackView = SIQCustomStackView()
        stackView.stackSpacing = 20
        return stackView
    }

    let attenderImage: UIImageView = {
        let image = UIImageView()
        image.translatesAutoresizingMaskIntoConstraints = false
        image.image = UIImage(systemName: "person.fill")
        image.layer.cornerRadius = 21
        image.contentMode = .center
        image.clipsToBounds = true
        image.backgroundColor = UIColor(named: "light_gray")
        image.tintColor = UIColor(named: "slate_gray")
        return image
    }()
    
    let commonHorizontalPadding = UIEdgeInsets(top: 0, left: 12, bottom: 0, right: 12)
    let chooseConversationButtonTopPadding: CGFloat = 20
    let chatIDTextFieldTopPadding: CGFloat = 20
    let chatActionStackTopPadding: CGFloat = 20
    let attenderIDStackTopPadding: CGFloat = 20
    let attenderImageSize : CGSize = CGSize(width: 44, height: 44)
    let fetchAttenderImageTopPadding: CGFloat = 20
    let getArticlesButtonTopPadding: CGFloat = 16

    override func viewDidLoad() {
        super.viewDidLoad()
        setupView()
        addTarget()
    }
    
    
    /**
     This API is used to get a list of all support chats created by a visitor. The API returns a list of  SIQVisitorChat  objects which contain information for each support chat. The list of chats fetched by this API can optionally be filtered to get the desired set of conversations based on the status using the filter function parameter.
     
     [.Chat.getList()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-get-list-v3.html)
     */
    @objc func chooseConversationType() {
        let types = Array(chatTypes.keys)
        let listVC = ListSelectionViewController(items: types, title: "Choose conversation type")
        listVC.willDismiss = { action in
            guard let type = action else { return }
            self.chooseConversationButton.setTitle(action, for: .normal)
            ZohoSalesIQ.Chat.getList(filter: self.chatTypes[type] ?? ChatStatus.all) { (error, chats) in
                if chats?.count == 0 { print("No chats available for \(type)")}
                chats?.enumerated().forEach { (index, chat) in
                    DataPrintUtils.shared.chatDetails(chat)
                }
            }
        }
        self.present(listVC, animated: true, completion: nil)
    }
    
    /**
     This API is used to open the support UI for use in the custom launcher view incase the default launcher provided by Mobilisten is hidden. This API is also used to open any specific chat window by providing the  referenceID  of the chat. The  referenceID  for a chat can be obtained from various APIs, including the ZohoSalesIQ.Chat.getList()  API
     
     [.Chat.show()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-show-v3.html)
     */
    @objc func openChatViewAction() {
        guard let chatID = chatIDTextField.text, chatID.isEmpty == false else {
            chatIDTextField.shake()
            return
        }
        ZohoSalesIQ.Chat.show(referenceID: chatID)
    }
    
    /**
     This API lets you end any open chat within the SDK using its reference ID.
     
     [.Chat.endSession()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-end-chat-session-v3.html)
     */
    @objc func endChatAction() {
        guard let chatID = chatIDTextField.text, chatID.isEmpty == false else {
            chatIDTextField.shake()
            return
        }
        ZohoSalesIQ.Chat.endSession(referenceID: chatID)
    }
    
    /**
     This API can be used to fetch the list of all articles or articles belongs to a specific category from your SalesIQ knowledge base. If you skip passing  categoryID  as a function parameter, the API will fetch all articles irrespective of the category grouping. This API returns an array of SIQFAQArticle objects in the completion closure.
     
     [.FAQ.getArticles()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-faq-get-articles-v3.html)
     */
    @objc func getArticleList() {
        ZohoSalesIQ.FAQ.getArticles({ error, articles in
            articles?.enumerated().forEach { (index, article) in
                DataPrintUtils.shared.articleDetails(article)
            }
        })
    }
    
    /**
     This API can be used to fetch the attender image of any conversation. The  fetchDefaultImage  function parameter can be set if the default operator or bot images are needed incase the attender's image has not be personalized.

     This API takes a  SIQVisitorChat  class instance to fetch the attender image of the chat. You can get the  SIQVisitorChat  instance from the ZohoSalesIQ.Chat.getList() API.
     
     [.Chat.fetchAttenderImage()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-fetch-attender-image-v3.html)
     */
    @objc func getAttenderImage() {
        guard let attenderID = attenderIDTextField.text, attenderID.isEmpty == false else {
            attenderIDTextField.shake()
            return
        }
        var chatObject: SIQVisitorChat?
        ZohoSalesIQ.Chat.getList(filter: ChatStatus.all) { (error, chats) in
            guard let chats = chats, chats.count != 0 else { print("No chats available"); return }
            chatObject = (chats.filter{ $0.attenderID == attenderID }).first
        }
        guard let chatObject = chatObject else { return }
        ZohoSalesIQ.Chat.fetchAttenderImage(chat: chatObject){ [self] (error, image) in
            DispatchQueue.main.async { [self] in
                attenderImage.image = image
            }
        }
    }

}
