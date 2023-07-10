//
//  SetVisitorDetailViewController.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 09/04/23.
//

import UIKit
import Mobilisten

class SetVisitorDetailViewController: UIViewController, UIViewControllerTransitioningDelegate {
    
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
    
    let visitorInfoLabel: UILabel = {
      let label = UILabel()
        label.text = "Visitor info:"
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()
    
    let nameTextField = SIQCustomTextField(placeholder: "Enter your name")
    
    let emailTextField = SIQCustomTextField(placeholder: "Enter your email address", keyboardType: .emailAddress)
    
    let contactTextField = SIQCustomTextField(placeholder: "Enter your contact number", keyboardType: .numberPad)
    
    let chooseDepartmentButton = SIQCustomButton(title: "Choose a department")
    
    let questionTextField = SIQCustomTextField(placeholder: "Enter your question here")
    
    let horizontalStackView = SIQCustomStackView()
    
    let visitorInfoKeyTextField = SIQCustomTextField(placeholder: "Key")
    
    let visitorInfoValueTextField = SIQCustomTextField(placeholder: "Value")
    
    let setSampleVisitorLocation = SIQCustomButton(title: "Set sample visitor location")
    
    let startChat = SIQCustomButton(title: "Start chat")
    
    var departmentList: [String] = []
     
    let commonHorizontalPadding = UIEdgeInsets(top: 0, left: 12, bottom: 0, right: 12)
    let originalContentInset: UIEdgeInsets = UIEdgeInsets(top: 0, left: 0, bottom: 0, right: 0)
    let nameTextFieldTopPadding: CGFloat = 20
    let emailTextFieldTopPadding: CGFloat = 20
    let contactTextFieldTopPadding: CGFloat = 20
    let chooseDepartmentButtonTopPadding: CGFloat = 20
    let questionTextFieldTopPadding: CGFloat = 20
    let horizontalStackViewTopPadding: CGFloat = 20
    let horizontalStackViewSize: CGSize = CGSize(width: 200, height: 50)
    let visitorInfoLabelLeftPadding: CGFloat = 12
    let setSampleVisitorLocationTopPadding: CGFloat = 20
    let startChatTopPadding: CGFloat = 16

    override func viewDidLoad() {
        super.viewDidLoad()
        setupView()
        addTarget()
    }
    
    /**
     This API allows you to programmatically get a list of all the departments that have been associated with the brand in which Mobilisten is configured.
     The API provides an array of instances of the SIQDepartment class to represent the list of departments asynchronously.
     
     [.Chat.getDepartments()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-get-departments-v3.html)
     */
    @objc func chooseDepartment() {
        if departmentList.count == 0 {
            chooseDepartmentButton.showLoading()
            ZohoSalesIQ.Chat.getDepartments { (error, departments) in
                if let departmentList = departments {
                    for department in departmentList {
                        self.departmentList.append(department.name)
                    }
                    self.showDepartmentList()
                    self.chooseDepartmentButton.hideLoading()
                }
            }
        } else {
            showDepartmentList()
        }
    }
    
    /**
     This API allows you to set a secondary location for a visitor. The secondary location set using this API will be visible within the visitor information page under the Secondary Location section.
     The setLocation API takes an instance of the SIQVisitorLocation class representing the visitor's location as a parameter.
     
     [.Visitor.setLocation()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-visitor-location-v3.html)
     */
    
    @objc func setLocation() {
        let loc = SIQVisitorLocation()
        loc.country = "India"
        loc.latitude = 8.9025
        loc.longitude = 77.3358
        loc.countryCode = "IN"
        ZohoSalesIQ.Visitor.setLocation(loc)
    }
    
    /**
     This API lets you set the name of the visitor
     
     [.Visitor.setName()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-visitor-name-v3.html)
     */
    func setVisitorName(_ name: String) {
        ZohoSalesIQ.Visitor.setName(name)
    }
    
    /**
     This API lets you set the email of the visitor
     
     [.Visitor.setEmail()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-visitor-email-v3.html)
     */
    func setVisitorEmail(_ email: String) {
        ZohoSalesIQ.Visitor.setEmail(email)
    }
    
    /**
     This API lets you set the contact number of the visitor
     
     [.Visitor.setContactNumber()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-visitor-contact-v3.html)
     */
    func setVisitorContactNumber(_ contact: String) {
        ZohoSalesIQ.Visitor.setContactNumber(contact)
    }
    
    /**
     This API would let you add additional information about the visitors and display it to the operators of your firm in the pane right beside their chat windows while conversing with the visitors.
     
     [.Visitor.addInfo()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-visitor-info-v3.html)
     */
    func updateVisitorInfo(_ key: String, _ value: String) {
        ZohoSalesIQ.Visitor.addInfo(key, value: value)
    }
    
    
    /**
     This API lets you configure a pre-defined question that will automatically be sent out to the operators of your firm when the visitor clicks on the chat widget to initiate a chat.
     
     [.Chat.startChat()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-startchat-v3.html)
     */
    func startChat(_ question: String?) {
        ZohoSalesIQ.Chat.startChat(question: question ?? "")
    }
    
    @objc func startChatAction() {
        if let name = nameTextField.text { setVisitorName(name) }
        if let email = emailTextField.text { setVisitorEmail(email) }
        if let contact = contactTextField.text { setVisitorContactNumber(contact) }
        if let key = visitorInfoKeyTextField.text, let value = visitorInfoValueTextField.text { updateVisitorInfo(key, value) }
        startChat(questionTextField.text ?? "")
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    
}
