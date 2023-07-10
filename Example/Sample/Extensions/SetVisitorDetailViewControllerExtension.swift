//
//  SetVisitorDetailViewControllerExtension.swift
//  MobilistenSDK
//
//  Created by venkat-12517 on 07/06/23.
//

import UIKit
import Mobilisten

extension SetVisitorDetailViewController {
    
    func setupView() {
        self.navigationItem.title = "Set visitor details"
        view.backgroundColor = UIColor(named: "background_color")
        view.addSubview(scrollView)
        scrollView.addSubview(contentView)
        contentView.addSubview(nameTextField)
        contentView.addSubview(emailTextField)
        contentView.addSubview(contactTextField)
        contentView.addSubview(chooseDepartmentButton)
        contentView.addSubview(questionTextField)
        contentView.addSubview(visitorInfoLabel)
        contentView.addSubview(horizontalStackView)
        contentView.addSubview(setSampleVisitorLocation)
        contentView.addSubview(startChat)
        
        horizontalStackView.addArrangedSubview(visitorInfoKeyTextField)
        horizontalStackView.addArrangedSubview(visitorInfoValueTextField)
         
        NSLayoutConstraint.activate([
            scrollView.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor),
            scrollView.centerXAnchor.constraint(equalTo: view.centerXAnchor),
            scrollView.bottomAnchor.constraint(equalTo: view.bottomAnchor),
            scrollView.widthAnchor.constraint(equalTo: view.widthAnchor),
            
            contentView.topAnchor.constraint(equalTo: scrollView.topAnchor),
            contentView.bottomAnchor.constraint(equalTo: scrollView.bottomAnchor),
            contentView.centerXAnchor.constraint(equalTo: scrollView.centerXAnchor),
            contentView.widthAnchor.constraint(equalTo: scrollView.widthAnchor),

            nameTextField.topAnchor.constraint(equalTo: contentView.topAnchor,constant: nameTextFieldTopPadding),
            nameTextField.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            nameTextField.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            emailTextField.topAnchor.constraint(equalTo: nameTextField.bottomAnchor,constant: emailTextFieldTopPadding),
            emailTextField.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            emailTextField.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            contactTextField.topAnchor.constraint(equalTo: emailTextField.bottomAnchor,constant: contactTextFieldTopPadding),
            contactTextField.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            contactTextField.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            chooseDepartmentButton.topAnchor.constraint(equalTo: contactTextField.bottomAnchor,constant: chooseDepartmentButtonTopPadding),
            chooseDepartmentButton.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            chooseDepartmentButton.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            questionTextField.topAnchor.constraint(equalTo: chooseDepartmentButton.bottomAnchor,constant: questionTextFieldTopPadding),
            questionTextField.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            questionTextField.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            horizontalStackView.topAnchor.constraint(equalTo: questionTextField.bottomAnchor,constant: horizontalStackViewTopPadding),
            horizontalStackView.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            horizontalStackView.heightAnchor.constraint(equalToConstant: horizontalStackViewSize.height),
            horizontalStackView.widthAnchor.constraint(equalToConstant: horizontalStackViewSize.width),
            
            visitorInfoLabel.centerYAnchor.constraint(equalTo: horizontalStackView.centerYAnchor),
            visitorInfoLabel.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            visitorInfoLabel.trailingAnchor.constraint(equalTo: horizontalStackView.leadingAnchor,constant: visitorInfoLabelLeftPadding),
            
            setSampleVisitorLocation.topAnchor.constraint(equalTo: horizontalStackView.bottomAnchor,constant: setSampleVisitorLocationTopPadding),
            setSampleVisitorLocation.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            setSampleVisitorLocation.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            
            startChat.topAnchor.constraint(equalTo: setSampleVisitorLocation.bottomAnchor,constant: startChatTopPadding),
            startChat.leadingAnchor.constraint(equalTo: contentView.leadingAnchor,constant: commonHorizontalPadding.left),
            startChat.trailingAnchor.constraint(equalTo: contentView.trailingAnchor,constant: -commonHorizontalPadding.right),
            startChat.bottomAnchor.constraint(lessThanOrEqualTo: contentView.bottomAnchor)
        ])
        
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow(_:)), name: UIResponder.keyboardWillShowNotification, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide(_:)), name: UIResponder.keyboardWillHideNotification, object: nil)
        
    }

    
    func addTarget() {
        chooseDepartmentButton.addTarget(self, action: #selector(chooseDepartment), for: .touchUpInside)
        startChat.addTarget(self, action: #selector(startChatAction), for: .touchUpInside)
        setSampleVisitorLocation.addTarget(self, action: #selector(setLocation), for: .touchUpInside)
    }
    
    @objc func keyboardWillShow(_ notification: Notification) {
        guard let userInfo = notification.userInfo,
              let keyboardFrame = userInfo[UIResponder.keyboardFrameEndUserInfoKey] as? CGRect else {
            return
        }
        
        let keyboardHeight = keyboardFrame.size.height
        
        // Calculate the content inset that takes into account the keyboard height
        var contentInset = scrollView.contentInset
        contentInset.bottom = keyboardHeight
        
        // Set the adjusted content inset to the scroll view
        scrollView.contentInset = contentInset
        scrollView.scrollIndicatorInsets = contentInset
        
        // Get the active text field
        let activeTextField: UITextField? = {
            if nameTextField.isFirstResponder {
                return nameTextField
            } else if emailTextField.isFirstResponder {
                return emailTextField
            } else if contactTextField.isFirstResponder {
                return contactTextField
            } else if questionTextField.isFirstResponder {
                return questionTextField
            } else if visitorInfoKeyTextField.isFirstResponder {
                return visitorInfoKeyTextField
            } else if visitorInfoValueTextField.isFirstResponder {
                return visitorInfoValueTextField
            }
            return nil
        }()
        
        if let activeTextFieldFrame = activeTextField?.superview?.convert(activeTextField!.frame, to: scrollView) {
                let visibleContentHeight = scrollView.frame.height - keyboardHeight
                if activeTextFieldFrame.maxY > visibleContentHeight {
                    let scrollOffset = CGPoint(x: 0, y: activeTextFieldFrame.maxY - visibleContentHeight + 16)
                    scrollView.setContentOffset(scrollOffset, animated: true)
                }
            }
    }

    @objc func keyboardWillHide(_ notification: Notification) {
        scrollView.contentInset = originalContentInset
        scrollView.scrollIndicatorInsets = originalContentInset
    }
    
    func showDepartmentList() {
        let listVC = ListSelectionViewController(items: departmentList, title: "Choose a department")
        listVC.willDismiss = { action in
            self.chooseDepartmentButton.setTitle(action, for: .normal)
            ZohoSalesIQ.Chat.setDepartment(action)
        }
        self.present(listVC, animated: true, completion: nil)
    }
}
