//
//  SalesIQDataViewControllerExtension.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 07/06/23.
//

import UIKit
import Mobilisten

extension SalesIQDataViewController {
    
    func setupView() {
        self.navigationItem.title = "Fetch Details"
        view.backgroundColor = UIColor(named: "background_color")
        
        view.addSubview(scrollView)
        scrollView.addSubview(contentView)
        contentView.addSubview(chooseConversationButton)
        contentView.addSubview(chatIDTextField)
        
        let chatActionStack = horizontalStackView
        chatActionStack.addArrangedSubview(openChatViewButton)
        chatActionStack.addArrangedSubview(endChatButton)
        contentView.addSubview(chatActionStack)
        
        let attenderIDStack = horizontalStackView
        attenderIDStack.distribution = .fillProportionally
        attenderIDStack.addArrangedSubview(attenderIDTextField)
        attenderIDStack.addArrangedSubview(attenderImage)
        contentView.addSubview(attenderIDStack)
        
        contentView.addSubview(fetchAttenderImage)
        contentView.addSubview(getArticlesButton)
        
        NSLayoutConstraint.activate([
            scrollView.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor),
            scrollView.bottomAnchor.constraint(equalTo: view.bottomAnchor),
            scrollView.centerXAnchor.constraint(equalTo: view.centerXAnchor),
            scrollView.widthAnchor.constraint(equalTo: view.widthAnchor),
            
            contentView.topAnchor.constraint(equalTo: scrollView.topAnchor),
            contentView.bottomAnchor.constraint(equalTo: scrollView.bottomAnchor),
            contentView.centerXAnchor.constraint(equalTo: scrollView.centerXAnchor),
            contentView.widthAnchor.constraint(equalTo: scrollView.widthAnchor),

            chooseConversationButton.topAnchor.constraint(equalTo: contentView.topAnchor, constant: chooseConversationButtonTopPadding),
            chooseConversationButton.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: commonHorizontalPadding.left),
            chooseConversationButton.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -commonHorizontalPadding.right),
            
            chatIDTextField.topAnchor.constraint(equalTo: chooseConversationButton.bottomAnchor,constant: chatIDTextFieldTopPadding),
            chatIDTextField.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: commonHorizontalPadding.left),
            chatIDTextField.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -commonHorizontalPadding.right),
            
            chatActionStack.topAnchor.constraint(equalTo: chatIDTextField.bottomAnchor,constant: chatActionStackTopPadding),
            chatActionStack.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: commonHorizontalPadding.left),
            chatActionStack.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -commonHorizontalPadding.right),
            
            attenderIDStack.topAnchor.constraint(equalTo: chatActionStack.bottomAnchor,constant: attenderIDStackTopPadding),
            attenderIDStack.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: commonHorizontalPadding.left),
            attenderIDStack.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -commonHorizontalPadding.right),
            
            
            attenderImage.heightAnchor.constraint(equalToConstant: attenderImageSize.height),
            attenderImage.widthAnchor.constraint(equalToConstant: attenderImageSize.width),
            
            fetchAttenderImage.topAnchor.constraint(equalTo: attenderIDStack.bottomAnchor, constant: fetchAttenderImageTopPadding),
            fetchAttenderImage.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: commonHorizontalPadding.left),
            fetchAttenderImage.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -commonHorizontalPadding.right),
            
            getArticlesButton.topAnchor.constraint(equalTo: fetchAttenderImage.bottomAnchor,constant: getArticlesButtonTopPadding),
            getArticlesButton.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: commonHorizontalPadding.left),
            getArticlesButton.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -commonHorizontalPadding.right),
            getArticlesButton.bottomAnchor.constraint(lessThanOrEqualTo: contentView.bottomAnchor)
        ])
    }
    
    func addTarget() {
        chooseConversationButton.addTarget(self, action: #selector(chooseConversationType), for: .touchUpInside)
        openChatViewButton.addTarget(self, action: #selector(openChatViewAction), for: .touchUpInside)
        endChatButton.addTarget(self, action: #selector(endChatAction), for: .touchUpInside)
        getArticlesButton.addTarget(self, action: #selector(getArticleList), for: .touchUpInside)
        fetchAttenderImage.addTarget(self, action: #selector(getAttenderImage), for: .touchUpInside)
    }
}
