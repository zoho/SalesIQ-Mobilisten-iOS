//
//  MainViewController.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 09/04/23.
//

import UIKit
import Mobilisten

class MainViewController: UIViewController {
    
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

    let siqLogoImageView: UIImageView = {
      let imageView = UIImageView()
        imageView.translatesAutoresizingMaskIntoConstraints = false
        imageView.image = UIImage(named: "salesiq_logo")
        return imageView
    }()

    let LauncherVisibilityToggleView: SIQToggleView = {
        let view = SIQToggleView()
        view.setup(type: .launcherVisibility)
        view.translatesAutoresizingMaskIntoConstraints = false
        return view
    }()

    let agentOnImageLauncherToggleView: SIQToggleView = {
        let view = SIQToggleView()
        view.setup(type: .agentImageOnLauncher)
        view.translatesAutoresizingMaskIntoConstraints = false
        return view
    }()

    let openSupportButton = SIQCustomButton(title: "Open SalesIQ support")
    let visitorIDTextField = SIQCustomTextField(placeholder: "Enter visitor ID")
    let loginButton = SIQCustomButton(title: "Login")
    let logoutButton = SIQCustomButton(title: "Logout")
    let trackVisitorActivityButton = SIQCustomButton(title: "Track Visitor Activity")
    let setVisitorDetailButton = SIQCustomButton(title: "Set visitor details")
    let fetchSalesIQDataButton = SIQCustomButton(title: "Fetch SalesIQ data")

    let sessionHorizontalStackView: SIQCustomStackView = {
      let stackView = SIQCustomStackView()
        stackView.stackSpacing = 16
        return stackView
    }()
    
    let supportLanguageToggleView: SIQToggleView = {
        let view = SIQToggleView()
        view.setup(type: .supportLanguage)
        view.translatesAutoresizingMaskIntoConstraints = false
        return view
    }()

    var separatorLineView: UIView {
      let lineView = UIView()
        lineView.translatesAutoresizingMaskIntoConstraints = false
        lineView.backgroundColor = UIColor(named: "seperator")
        return lineView
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        setupView()
        addTarget()
    }
    
    let siqLogoTopPadding: CGFloat = 10
    let siqLogoSize: CGSize = CGSize(width: 100, height: 100)
    
    let commonHorizontalPadding: UIEdgeInsets = UIEdgeInsets(top: 0, left: 12, bottom: 0, right: 12)
    let openSupportButtonTopPadding: CGFloat = 10
    let LauncherVisibilityToggleViewTopPadding: CGFloat = 20
    let agentOnImageLauncherToggleViewTopPadding: CGFloat = 20
    
    let separatorLineViewTopPadding: CGFloat = 20
    let separatorLineViewHeight: CGFloat = 1
    
    let visitorIDTextFieldTopPadding: CGFloat = 20
    
    let sessionHorizontalStackViewTopPadding: CGFloat = 20
    let sessionHorizontalStackViewHeight: CGFloat = 40
    
    let setVisitorDetailButtonTopPadding:  CGFloat = 20
    
    let supportLanguageToggleViewTopPadding:  CGFloat = 20
    let trackVisitorActivityButtonTopPadding:  CGFloat = 20
    let fetchSalesIQDataButtonTopPadding:  CGFloat = 16
    
    
    /**
     This API is used to open the support UI for use in the custom launcher view incase the default launcher provided by Mobilisten is hidden. This API is also used to open any specific chat window by providing the  referenceID  of the chat. The  referenceID  for a chat can be obtained from various APIs, including the ZohoSalesIQ.Chat.getList()  API
     
      [.Chat.show()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-show-v3.html)
     */
    @objc func openSupportAction() {
        ZohoSalesIQ.Chat.show()
    }

    /**
     This API can be used to control the visibility of the SDK Launcher. You can either choose to show or hide it. The Launcher is hidden by default.
     
     [.showLauncher()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-window-launcher-v3.html)
     */
    @objc func showLauncherAction(_ segmentedControl: UISegmentedControl) {
        let show = segmentedControl.selectedSegmentIndex == 0 ? true : false
        ZohoSalesIQ.showLauncher(show)
    }
    
    /**
     This API lets you toggle the function of various components in Mobilisten
     
      [.Chat.setVisibility()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-set-visibility-v3.html)
     */
    @objc func showagentImageOnLauncherAction(_ segmentedControl: UISegmentedControl) {
        let show = segmentedControl.selectedSegmentIndex == 0 ? true : false
        ZohoSalesIQ.Chat.setVisibility(.attenderImageOnLauncher, visible: show)
    }
    
    /**
     This API allows you to register a user using a unique ID with the SalesIQ SDK. If your application has login and logout life cycles, you can enroll your visitor and their activity in the SDK will be synchronized across multiple platforms.
     
     [.registerVisitor()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-register-visitor-v3.html)
     */
    @objc func registerVisitorAction() {
        guard let id = visitorIDTextField.text, id.isEmpty == false else {
            visitorIDTextField.shake()
            return
        }
        loginButton.showLoading()
        ZohoSalesIQ.registerVisitor(id, completion: {_ in
            self.loginButton.hideLoading()
        })
    }
    
    /**
     This API allows you to unregister a user once they are registered using the .registerVisitor() API. If your application has login and logout life cycles, you can unregister a visitor during a session logout which would clear any data the SDK may hold such as past conversations had by the registered user.
     
     [.unregisterVisitor()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-unregister-visitor-v3.html)
     */
    @objc func UnregisterVisitorAction() {
        logoutButton.showLoading()
        ZohoSalesIQ.unregisterVisitor(completion: {_ in
            self.logoutButton.hideLoading()
        })
    }
    
    /**
     This API would let you track specified custom actions if performed by the visitors in your mobile application.
     
     [.Tracking.setCustomAction()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-tracking-action-v3.html)
     */
    @objc func customAction() {
        ZohoSalesIQ.Tracking.setCustomAction("Zylkar")
    }
    
    
    /**
     This API lets you configure the language preference for the embedded chat widget.
     
     [.Chat.setLanguage()](https://www.zoho.com/salesiq/help/developer-section/ios-sdk-chat-language-v3.html)
     */
    @objc func supportLanguageAction(_ segmentedControl: UISegmentedControl) {
        switch segmentedControl.selectedSegmentIndex {
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

    @objc func setVisitorDetails() {
        let vc = SetVisitorDetailViewController()
        self.navigationController?.pushViewController(vc, animated: true)
    }
    
    @objc func fetchData() {
        let vc = SalesIQDataViewController()
        self.navigationController?.pushViewController(vc, animated: true)
    }

}
